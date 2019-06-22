from sympy import *
from math import pi

a, b, c, d, e, f, x, px, py = symbols('a b c d e f x px py')

sine = a*x**5 + b*x**4 + c*x**3 + d*x**2 + e*x + f
sine_d = diff(sine, x)
sine_i = integrate(sine, x)

the_system = [
    sine_d.subs(x, 0) - 1, 
    sine_d.subs(x, pi / 2), 
    sine_d.subs(x, pi) + 1, 
    sine.subs(x, 0), 
    sine.subs(x, px) - py, 
    sine.subs(x, pi) 
]

res = solve(the_system, (a, b, c, d, e, f))

for var, exp in res.items():
    print(var, srepr(exp))
    print('')
