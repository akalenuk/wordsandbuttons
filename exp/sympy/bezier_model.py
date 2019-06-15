from sympy import *
from math import pi

ax, bx, cx, dx, ay, by, cy, dy, t = symbols('ax bx cx dx ay by cy dy t')
x1, y1, x2, y2, x3, y3, x4, y4 = symbols('x1 y1 x2 y2 x3 y3 x4 y4')

xt = ax*t**3 + bx*t**2 + cx*t + dx
yt = ay*t**3 + by*t**2 + cy*t + dy

the_x_system = [
    xt.subs(t, 0.) - x1,
    diff(xt, t).subs(t, 0.) - (x2 - x1) / 3.,
    xt.subs(t, 1.) - x4,
    diff(xt, t).subs(t, 1.) + (x3 - x4) / 3.
]

the_y_system = [
    yt.subs(t, 0.) - y1,
    diff(yt, t).subs(t, 0.) - (y2 - y1) / 3.,
    yt.subs(t, 1.) - y4,
    diff(yt, t).subs(t, 1.) + (y3 - y4) / 3.
]

resx = solve(the_x_system, (ax, bx, cx, dx))
resy = solve(the_y_system, (ay, by, cy, dy))

for var, exp in resx.items():
    print(var, srepr(exp))
    print('')

for var, exp in resy.items():
    print(var, srepr(exp))
    print('')
