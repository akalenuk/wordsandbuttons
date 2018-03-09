import sys
import re

POSSIBLE_CHARS_NUMBER_FOLLOWS_WITH = [' ', '\n', ')', ',']

# this is basically the whole LLVM layer (well, excluding the head and tail that are very specific)
g_instruction_no = 0
g_stack = []

class LLVMCode:
    def __init__(self, io): # the only constructor for now is by double* instruction
        self.m_io = io
        self.m_code = ''
    def __getitem__(self, i):
        global g_instruction_no, g_stack
        self.m_code += "%" + str(g_instruction_no+1) + " = getelementptr inbounds double, double* "+ self.m_io +", i64 " + str(i) + "\n"
        self.m_code += "%" + str(g_instruction_no+2) + " = load double, double* %" + str(g_instruction_no+1) + ", align 8\n"
        g_instruction_no += 2
        g_stack += [g_instruction_no]   
        return self
    def __setitem__(self, i):
        global g_instruction_no, g_stack
        self.m_code += "%" + str(g_instruction_no+1) + " = getelementptr inbounds double, double* "+ self.m_io +", i64 " + str(i) + "\n"
        self.m_code += "store double %" + str(g_instruction_no) + ", double* %" + str(g_instruction_no+1) + ", align 8\n"
        g_instruction_no += 1
        g_stack = g_stack[:-1]
        return self
    def general_arithmetics(self, operator, other_llvm_code):
        global g_instruction_no, g_stack
        self.m_code += self.m_code + other_llvm_code.m_code;
        self.m_code += "%" + str(g_instruction_no+1) + " = f" + operator + " double %" + str(g_stack[-2]) + ", %" + str(g_stack[-1]) + "\n";
        g_instruction_no += 1
        g_stack = g_stack[:-2] + [g_instruction_no]
        return self
    def __add__(self, other_llvm_code):
        return self.general_arithmetics('add', other_llvm_code)
    def __sub__(self, other_llvm_code):
        return self.general_arithmetics('sub', other_llvm_code)
    def __mul__(self, other_llvm_code):
        return self.general_arithmetics('mul', other_llvm_code)    
    def __div__(self, other_llvm_code):
        return self.general_arithmetics('div', other_llvm_code)    

# this generates n-solver in LLVM code with LLVMCode objects. No actual LLVM stuff, just completely Pythonic solution
def solve_linear_system(a_array, b_array, x_array, n_value):
    generated = ""
   
    def a(i, j, n):
        if n == n_value: 
            return a_array[i * n_value + j]
        return a(i,j,n+1) * a(n,n,n+1) - a(i,n,n+1) * a(n,j,n+1)

    def b(i, n):
        if n == n_value: 
            return b_array[i]
        return a(n,n,n+1) * b(i,n+1) - a(i,n,n+1) * b(n,n+1)

    def x(i):
        d = b(i,i+1)
        for j in range(i): 
            d -=a (i,j,i+1)*x_array[j]
        return d/a(i,i,i+1)

    for k in range(n_value):
        x_array[k] = x(k)

    return x_array
    
# this replaces the function call and updates all the instruction indices   
def replace_call(text, line, params):
    global g_instruction_no, g_stack
    g_instruction_no = int(''.join([xi for xi in params[2] if xi.isdigit()])) # '%12 ' -> 12
    first_instruction_to_replace = g_instruction_no + 1
    g_stack = []
    replacement = solve_linear_system(LLVMCode(params[0]), LLVMCode(params[1]), LLVMCode(params[2]), 5).m_code
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

