from sympy import *

x0, y0, r, t = symbols('x0 y0 r t')

arc_x = x0 + sin(t) * r
arc_y = y0 + cos(t) * r
x1, y1, dyx1, x2, y2, dyx2, t1, t2, tl = symbols('x1 y1 dyx1 x2 y2 dyx2 t1 t2 tl')


res = solve(
   [arc_x.subs(t, t1) - x1, 
    arc_y.subs(t, t1) - y1, 
    (diff(arc_y, t) / diff(arc_x, t)).subs(t, t1) - dyx1,
    arc_x.subs(t, t2) - (x2 + tl) , 
    arc_y.subs(t, t2) - (y2 + tl*dyx2), 
    (diff(arc_y, t) / diff(arc_x, t)).subs(t, t2) - dyx2
], (t1, t2, tl, x0, y0, r))

for exp in  res:
    print(srepr(exp))
