from sympy import *

xc1, yc1, xc2, yc2, r, t = symbols('xc1 yc1 xc2 yc2 r t')

arc1_x = xc1 + sin(t) * r
arc1_y = yc1 + cos(t) * r
arc2_x = xc2 + sin(t) * r
arc2_y = yc2 + cos(t) * r

x1, y1, dyx1, x2, y2, dyx2, t1, t2, r1, r2 = symbols('x1 y1 dyx1 x2 y2 dyx2 t1 t2 r1 r2')



solutions = solve(
   [
    t1 - t2 - pi,
    x1 + r1 - xc1,
    y1 + r1 * dyx1 - yc1,
    x2 + r2 - xc2,
    y2 + r2 * dyx2 - yc2,
    (r1 - xc1)**2 + (r1*dyx1 - xc1)**2 - r**2,
    (r2 - xc2)**2 + (r2*dyx2 - xc2)**2 - r**2,
    arc1_x.subs(t, t1) - arc2_x.subs(t, t2), 
    arc1_y.subs(t, t1) - arc2_y.subs(t, t2), 
], (t1, xc1, yc1, t2, xc2, yc2, r1, r2, r))

for solution in solutions:
    print('var t1 = ' + jscode(solution[0]))
    print('var xc1 = ' + jscode(solution[1]))
    print('var yc1 = ' + jscode(solution[2]))
    print('var t2 = ' + jscode(solution[3]))
    print('var xc2 = ' + jscode(solution[4]))
    print('var yc2 = ' + jscode(solution[5]))
    print('var r1 = ' + jscode(solution[6]))
    print('var r2 = ' + jscode(solution[7]))
    print('var r = ' + jscode(solution[8]))
