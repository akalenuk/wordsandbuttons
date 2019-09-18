from sympy import *

x1, y1, x2, y2, a, b = symbols('x1 y1 x2 y2 a b')
print(solve([
    a * x1 + b - y1,
    a * x2 + b - y2
    ], (a, b)))
