from sympy import *
from sympy.printing import print_ccode
from math import pi

a, b, c, d, e, x = symbols('a b c d e x')

sine = (a*x**2 + b*x + c + d*x**-1 + e*x**-2)
sine_d = diff(sine, x)
sine_i = integrate(sine, x)

the_system = [
    sine_i.subs(x, pi) - sine_i.subs(x, -pi/2) - 1,
    sine_d.subs(x, pi) + 1,
    sine_d.subs(x, pi / 2),
	sine.subs(x, pi) - 0,
    sine.subs(x, pi / 2) - 1
]

res = solve(the_system, (a, b, c, d, e))

for var, exp in res.items():
    print(var, exp)
