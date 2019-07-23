from sympy import *

# input
x1, y1, dx1, dy1 = symbols('x1 y1 dx1 dy1')
x2, y2, dx2, dy2 = symbols('x2 y2 dx2 dy2')

# intermediate: arcs
ax1, ay1, ax2, ay2 = symbols('ax1 ay1 ax2 ay2')

# output: arc radiuses
r1, r2 = symbols('r1 r2')

solutions = solve(
   [
    r2 - r1,  # radiuses are equal
    x1 - r1*dy1 - ax1,
    y1 + r1*dx1 - ay1,
    x2 + r2*dy2 - ax2,
    y2 - r2*dx2 - ay2,
    (ax1-ax2)**2 + (ay1-ay2)**2 - (r1+r2)**2
], (ax1, ay1, ax2, ay2, r1, r2))

for solution in solutions:
    print('var ax1 = ' + jscode(solution[0]))
    print('var ay1 = ' + jscode(solution[1]))
    print('var ax2 = ' + jscode(solution[2]))
    print('var ay2 = ' + jscode(solution[3]))
    print('var r1 = ' + jscode(solution[4]))
    print('var r2 = ' + jscode(solution[5]))
    print('')

