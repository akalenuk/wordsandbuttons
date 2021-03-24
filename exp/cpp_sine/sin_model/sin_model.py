from sympy import *
from sympy.printing import print_ccode
from math import pi

a, b, c, d, x = symbols('a b c d x')

sine = a*x**7 + b*x**5 + c*x**3 + d*x
sine_d = diff(sine, x)
sine_i = integrate(sine, x)

the_system = [
    sine_i.subs(x, pi / 2) - sine_i.subs(x, 0) - 1,
    sine_d.subs(x, 0) - 1,
    sine_d.subs(x, pi / 2),
    sine.subs(x, pi / 2) - 1,
	# implicitly: sine.subs(x, 0) - 0
]

res = solve(the_system, (a, b, c, d))

for var, exp in res.items():
    print(var, exp)
