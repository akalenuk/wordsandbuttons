from sympy import *

# input
x1, y1, dx1, dy1 = symbols('x1 y1 dx1 dy1')
x2, y2, dx2, dy2 = symbols('x2 y2 dx2 dy2')

# output
x12, y12, t1, t2 = symbols('x12 y12 t1 t2')


solution = solve(
   [
    x1 + dx1 * t1 - x12,  # intersection point is on the tangent line of (x1, y1)
    y1 + dy1 * t1 - y12,  #
    x2 + dx2 * t2 - x12,  # intersection point is on the tangent line of (x2, y2)
    y2 + dy2 * t2 - y12,  #
], (x12, y12, t1, t2))


for var, expr in solution.items():
    print('var ' + jscode(var) + ' = ' + jscode(expr))

