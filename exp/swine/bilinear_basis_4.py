from sympy import *

x1, y1, z1 = symbols('x1 y1 z1')
x2, y2, z2 = symbols('x2 y2 z2')
x3, y3, z3 = symbols('x3 y3 z3')
x4, y4, z4 = symbols('x4 y4 z4')
a, b, c, d = symbols('a b c d')
print(solve([
    a * x1 * y1 + b * x1 + c * y1 + d - z1,
    a * x2 * y2 + b * x2 + c * y2 + d - z2,
    a * x3 * y3 + b * x3 + c * y3 + d - z3,
    a * x4 * y4 + b * x4 + c * y4 + d - z4,
    ], (a, b, c, d)))
