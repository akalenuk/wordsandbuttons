import sys
import re

POSSIBLE_CHARS_NUMBER_FOLLOWS_WITH = [' ', '\n', ')', ',']

# this is basically the whole LLVM layer (well, excluding the head and tail that are very specific)
I = 0
STACK = []

class LLVMCode:
    def __init__(self, io, code = ''): # the only constructor for now is by double* instruction
        self.io = io
        self.code = code
    def __getitem__(self, i): 
        global I, STACK
        copy_code = "%" + str(I+1) + " = getelementptr inbounds double, double* "+ self.io +", i64 " + str(i) + "\n"
        copy_code += "%" + str(I+2) + " = load double, double* %" + str(I+1) + ", align 8\n"
        I += 2
        STACK += [I]
        return LLVMCode(self.io, copy_code)
    def __setitem__(self, i, other_llvcode):
        global I, STACK
        self.code += other_llvcode.code
        self.code += "%" + str(I+1) + " = getelementptr inbounds double, double* "+ self.io +", i64 " + str(i) + "\n"
        self.code += "store double %" + str(I) + ", double* %" + str(I+1) + ", align 8\n"
        I += 1
        STACK = STACK[:-1]
        return self
    def general_arithmetics(self, operator, other_llvcode):
        global I, STACK
        self.code += other_llvcode.code;
        self.code += "%" + str(I+1) + " = f" + operator + " double %" + str(STACK[-2]) + ", %" + str(STACK[-1]) + "\n";
        I += 1
        STACK = STACK[:-2] + [I]
        return self
    def __add__(self, other_llvcode):
        return self.general_arithmetics('add', other_llvcode)
    def __sub__(self, other_llvcode):
        return self.general_arithmetics('sub', other_llvcode)
    def __mul__(self, other_llvcode):
        return self.general_arithmetics('mul', other_llvcode)    
    def __div__(self, other_llvcode):
        return self.general_arithmetics('div', other_llvcode)    

# this generates n-solver in LLVM code with LLVMCode objects. No actual LLVM stuff, just completely Pythonic solution
def solve_linear_system(a_array, b_array, x_array, n_value):
    def a(i, j, n):
        if n == n_value: 
            return a_array[i * n_value + j]
        return a(i, j, n+1) * a(n, n, n+1) - a(i, n, n+1) * a(n, j, n+1)

    def b(i, n):
        if n == n_value: 
            return b_array[i]
        return a(n, n, n+1) * b(i, n+1) - a(i, n, n+1) * b(n, n+1)

    def x(i):
        d = b(i,i+1)
        for j in range(i): 
            d -= a(i, j, i+1) * x_array[j]
        return d / a(i, i, i+1)

    for k in range(n_value):
        x_array[k] = x(k)

    return x_array
    
# this replaces the function call and updates all the instruction indices   
def replace_call(text, line, params):
    global I, STACK
    I = int(''.join([xi for xi in params[2] if xi.isdigit()])) # '%12 ' -> 12
    first_instruction_to_replace = I + 1
    STACK = []
    replacement = solve_linear_system(LLVMCode(params[0]), LLVMCode(params[1]), LLVMCode(params[2]), 5).code
    delta_instruction = I - first_instruction_to_replace + 1
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

