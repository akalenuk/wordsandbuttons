from sympy import *
from math import pi

a, b, c, d, e, f, g, x = symbols('a b c d e f g x')

sine = a*x**6 + b*x**5 + c*x**4 + d*x**3 + e*x**2 + f*x + g
sine_d = diff(sine, x)
sine_i = integrate(sine, x)

the_system = [
    sine_i.subs(x, pi) - sine_i.subs(x, 0) - 1,  
    sine_d.subs(x, 0) - 1, 
    sine_d.subs(x, pi / 2), 
    sine_d.subs(x, pi) + 1, 
    sine.subs(x, 0), 
    sine.subs(x, pi / 2) - 1, 
    sine.subs(x, pi) 
]

res = solve(the_system, (a, b, c, d, e, f, g))

for var, exp in res.items():
    print(var, srepr(exp))
    print('')
