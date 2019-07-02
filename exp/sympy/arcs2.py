from sympy import *

xc1, yc1, xc2, yc2, r, t = symbols('xc1 yc1 xc2 yc2 r t')

arc1_x = xc1 + sin(t) * r
arc1_y = yc1 + cos(t) * r
arc2_x = xc2 + sin(t) * r
arc2_y = yc2 + cos(t) * r

x1, y1, dyx1, x2, y2, dyx2, t1, t2 = symbols('x1 y1 dyx1 x2 y2 dyx2 t1 t2')



solution = solve(
   [
    t1 - t2 - pi,
    x1 + r - xc1,
    y1 + r * dyx1 - yc1,
    x2 + r - xc2,
    y2 + r * dyx2 - yc2,
    arc1_x.subs(t, t1) - arc2_x.subs(t, t2), 
    arc1_y.subs(t, t1) - arc2_y.subs(t, t2) 
], (t1, xc1, yc1, t2, xc2, yc2, r))

for var, exp in solution.items():
    print('var ' + jscode(var) + ' = ' + jscode(exp))
