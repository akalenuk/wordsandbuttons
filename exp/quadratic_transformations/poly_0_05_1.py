from sympy import *

y1, y2, y3, a, b, c = symbols('y1 y2 y3 a b c')

print(solve([
    c - y1,
    a * 0.25 + b * 0.5 + c - y2,
    a + b + c - y3,
    ], (a, b, c)))
