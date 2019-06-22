from sympy import *
from math import pi

a, b, c, d, x, px, py = symbols('a b c d x px py')

sine = a*x**3 + b*x**2 + c*x + d
sine_d = diff(sine, x)

the_system = [
    sine_d.subs(x, px), 
    sine.subs(x, 0), 
    sine.subs(x, px) - py, 
    sine.subs(x, pi) 
]

res = solve(the_system, (a, b, c, d))

for var, exp in res.items():
    print(var, srepr(exp))
    print('')
