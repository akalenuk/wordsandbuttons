from sympy import *

x1, y1, x2, y2, x3, y3, a, b, c = symbols('x1 y1 x2 y2 x3 y3 a b c')

print(solve([
    a * x1 * x1 + b * x1 + c - y1,
    a * x2 * x2 + b * x2 + c - y2,
    a * x3 * x3 + b * x3 + c - y3,
    ], (a, b, c)))
