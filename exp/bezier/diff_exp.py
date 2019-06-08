from sympy import *
from sympy.abc import x

f = Function('f')
eq = Derivative(f(x), x) + 1
res = dsolve(eq, f(x), ics={f(0):0})
print(res)
