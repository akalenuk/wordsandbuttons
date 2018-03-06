import sys
import re

# this is basically the whole LLVM layer (well, excluding the head and tail that are very specific)
g_instruction_no = 0
g_stack = []

def array_to_stack(a_name, i):
    global g_instruction_no, g_stack
    load = "%" + str(g_instruction_no+1) + " = alloca double*, align 8\n"
    load += "store double* %" + a_name + ", double** %" + str(g_instruction_no+1) +", align 8\n"
    load += "%" + str(g_instruction_no+2) + " = load double*, double** %" + str(g_instruction_no+1) + ", align 8\n"
    load += "%" + str(g_instruction_no+3) + " = getelementptr inbounds double, double* %"+ str(g_instruction_no+2) +", i64 " + str(i) + "\n"
    load += "%" + str(g_instruction_no+4) + " = load double, double* %" + str(g_instruction_no+3) + ", align 8\n"
    g_instruction_no += 4
    g_stack += [g_instruction_no]   
    return load;

def stack_to_array(a_name, i):
    global g_instruction_no, g_stack
    store = "%" + str(g_instruction_no+1) + " = alloca double*, align 8\n"
    store += "store double* %" + a_name + ", double** %" + str(g_instruction_no+1) +", align 8\n"
    store += "%" + str(g_instruction_no+2) + " = load double*, double** %" + str(g_instruction_no+1) + ", align 8\n"
    store += "%" + str(g_instruction_no+3) + " = getelementptr inbounds double, double* %"+ str(g_instruction_no+2) +", i64 " + str(i) + "\n"
    store += "store double %" + str(g_instruction_no) + ", double* %" + str(g_instruction_no+3) + ", align 8\n"
    g_instruction_no += 3
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
def generate_solver(a_name, b_name, x_name, n_value):
    generated = ""       
   
    def a(i, j, n):
        if n==n_value: 
            return array_to_stack(a_name, i * n + j)
        return compute( compute(a(i,j,n+1), 'mul', a(n,n,n+1)), 'sub', compute(a(i,n,n+1), 'mul', a(n,j,n+1)) )

    def b(i, n):
        if n==n_value: 
            return array_to_stack(b_name, i)
        return compute( compute(a(n,n,n+1), 'mul', b(i,n+1)), 'sub', compute(a(i,n,n+1), 'mul', b(n,n+1)) )

    def x(i):
        d = b(i,i+1)
        for j in xrange(i): 
            d = compute(d, 'sub', compute(a(i,j,i+1), 'mul', array_to_stack(x_name, j) ) )
        return compute(d, 'div', a(i,i,i+1))

    for k in xrange(n_value):
        generated += x(k) + stack_to_array(x_name, k)

    return generated

    
if __name__ == '__main__':
    f = open(sys.argv[1], 'r')
    lines = f.read().split('\n')
    f.close()
    replacements = []
    for line in lines:
        if line.find('call void @solve_5') != -1:
            params = [chunk.split(' ')[-1] for chunk in line.replace(')', ',').split(',')][:-1]
            replacements += [(line, params)]
    print replacements

