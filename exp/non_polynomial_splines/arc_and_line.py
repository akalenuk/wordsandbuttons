from sympy import *

# input
x1, y1, dx1, dy1 = symbols('x1 y1 dx1 dy1')
x2, y2, dx2, dy2 = symbols('x2 y2 dx2 dy2')

ix, iy = symbols('ix, iy')

ax1, ay1, r1, t2 = symbols('ax1 ay1 r1 t2')

solutions = solve(
   [
    x1 - r1*dy1 - ax1,
    y1 + r1*dx1 - ay1,
    x2 + dx2 * t2 - ix,
    y2 + dy2 * t2 - iy,
    (ix-ax1)**2 + (iy-ay1)**2 - r1**2,
    (ix-ax1)*(ix-x2) + (iy-ay1)*(iy-y2)
], (ax1, ay1, r1, t2, ix, iy))

for solution in solutions:
    print('var ax1 = ' + jscode(solution[0]))
    print('var ay1 = ' + jscode(solution[1]))
    print('var r1 = ' + jscode(solution[2]))
    print('var t2 = ' + jscode(solution[3]))
    print('var ix = ' + jscode(solution[4]))
    print('var iy = ' + jscode(solution[5]))
    print('')

