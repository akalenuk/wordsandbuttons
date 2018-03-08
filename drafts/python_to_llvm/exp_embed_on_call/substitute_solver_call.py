import sys
import re

POSSIBLE_CHARS_NUMBER_FOLLOWS_WITH = [' ', '\n', ')', ',']

# this is basically the whole LLVM layer (well, excluding the head and tail that are very specific)
g_instruction_no = 0
g_stack = []

def array_to_stack(a_no, i):
    global g_instruction_no, g_stack
    load = "%" + str(g_instruction_no+1) + " = getelementptr inbounds double, double* "+ a_no +", i64 " + str(i) + "\n"
    load += "%" + str(g_instruction_no+2) + " = load double, double* %" + str(g_instruction_no+1) + ", align 8\n"
    g_instruction_no += 2
    g_stack += [g_instruction_no]   
    return load;

def stack_to_array(a_no, i):
    global g_instruction_no, g_stack
    store = "%" + str(g_instruction_no+1) + " = getelementptr inbounds double, double* "+ a_no +", i64 " + str(i) + "\n"
    store += "store double %" + str(g_instruction_no) + ", double* %" + str(g_instruction_no+1) + ", align 8\n"
    g_instruction_no += 1
    g_stack = g_stack[:-1]
    return store;

def compute(a, operator, b):
    global g_instruction_no, g_stack
    operation = a + b;
    operation += "%" + str(g_instruction_no+1) + " = f" + operator + " double %" + str(g_stack[-2]) + ", %" + str(g_stack[-1]) + "\n";
    g_instruction_no += 1
    g_stack = g_stack[:-2] + [g_instruction_no]
    return operation;

# this generates n-solver in LLVM code. No actual LLVM stuff
def generate_solver(a_no, b_no, x_no, n_value):
    generated = ""       
   
    def a(i, j, n):
        if n==n_value: 
            return array_to_stack(a_no, i * n + j)
        return compute( compute(a(i,j,n+1), 'mul', a(n,n,n+1)), 'sub', compute(a(i,n,n+1), 'mul', a(n,j,n+1)) )

    def b(i, n):
        if n==n_value: 
            return array_to_stack(b_no, i)
        return compute( compute(a(n,n,n+1), 'mul', b(i,n+1)), 'sub', compute(a(i,n,n+1), 'mul', b(n,n+1)) )

    def x(i):
        d = b(i,i+1)
        for j in xrange(i): 
            d = compute(d, 'sub', compute(a(i,j,i+1), 'mul', array_to_stack(x_no, j) ) )
        return compute(d, 'div', a(i,i,i+1))

    for k in xrange(n_value):
        generated += x(k) + stack_to_array(x_no, k)

    return generated
    
# this replaces the function call and updates all the instruction indices   
def replace_call(text, line, params):
    global g_instruction_no, g_stack
    g_instruction_no = int(''.join([xi for xi in params[2] if xi.isdigit()])) # '%12 ' -> 12
    first_instruction_to_replace = g_instruction_no + 1
    g_stack = []
    replacement = generate_solver(params[0], params[1], params[2], 5)
    delta_instruction = g_instruction_no - first_instruction_to_replace + 1
    for i in xrange(first_instruction_to_replace, sys.maxint):
        not_found = sum([text.find('%' + str(i) + c) == -1 for c in POSSIBLE_CHARS_NUMBER_FOLLOWS_WITH])
        if not_found == 4:  # the last instruction has already been substituted
            break
        new_i = i + delta_instruction
        for c in POSSIBLE_CHARS_NUMBER_FOLLOWS_WITH: # substitute instruction number
            text = text.replace('%' + str(i) + c, '%' + str(new_i) + c)
    return text.replace(line, replacement)

if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    text = f.read()
    lines = text.split('\n')
    f.close()
    replacements = []
    for line in lines:
        if line.find('call void @solve_5') != -1: # the function's type is expected, not specified
            params = [chunk.split(' ')[-1] for chunk in line.replace(')', ',').split(',')][:-1]
            replacements += [(line, params)]
    for (line, params) in replacements:
        text = replace_call(text, line, params)
    f = open(sys.argv[1], 'w')
    f.write(text)
    f.close()

