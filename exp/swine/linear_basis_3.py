from sympy import *

x1, y1, z1 = symbols('x1 y1 z1')
x2, y2, z2 = symbols('x2 y2 z2')
x3, y3, z3 = symbols('x3 y3 z3')
a, b, c = symbols('a b c')
print(solve([
    a * x1 + b * y1 + c - z1,
    a * x2 + b * y2 + c - z2,
    a * x3 + b * y3 + c - z3,
    ], (a, b, c)))
