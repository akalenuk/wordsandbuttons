from sympy import *

y1, y2, y3, y4, a, b, c, d = symbols('y1 y2 y3 y4 a b c d')

print(solve([
    d - y1,
    a * 1/27 + b * 1/9 + c * 1/ 3 + d - y2,
    a * 8/27 + b * 4/9 + c * 2/ 3 + d - y3,
    a + b + c + d - y4,
    ], (a, b, c, d)))
