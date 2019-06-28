from sympy import *

x0, y0, r, t = symbols('x0 y0 r t')

arc_x = x0 + sin(t) * r
arc_y = y0 + cos(t) * r
x1, y1, dyx1, x2, y2, dyx2, t1, t2, tl = symbols('x1 y1 dyx1 x2 y2 dyx2 t1 t2 tl')


t1t2 = solve(
   [(diff(arc_y, t) / diff(arc_x, t)).subs(t, t1) - dyx1,
    (diff(arc_y, t) / diff(arc_x, t)).subs(t, t2) - dyx2
], (t1, t2))

print('var t1 = ' + jscode(t1t2[-1][0])) 
print('var t2 = ' + jscode(t1t2[-1][1])) 

tlx0y0r = solve(
   [arc_x.subs(t, t1) - x1, 
    arc_y.subs(t, t1) - y1, 
    arc_x.subs(t, t2) - (x2 + tl) , 
    arc_y.subs(t, t2) - (y2 + tl*dyx2), 
], (tl, x0, y0, r))

for var, exp in tlx0y0r.items():
    print('var ' + jscode(var) + ' = ' + jscode(exp))
