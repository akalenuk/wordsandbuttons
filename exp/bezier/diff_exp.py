from sympy import *

#f = Function('f')
#eq = Derivative(f(x), x) + 1
#res = dsolve(eq, f(x), ics={f(0):0})
#print(res)

x = Function('x')
y = Function('y')
t = symbols('t')
x1, y1, x2, y2, yx1, yx2 = symbols('x1 y1 x2 y2 yx1 yx2')

# constant speed
eq = Derivative(Derivative(x(t), t)**2 + Derivative(y(t), t)**2, t)
res = dsolve(eq, (x(t), y(t)), ics={x(0):x1, y(0):y1, x(1):x2, y(1):y2, y(0)/x(0):yx1, y(1)/x(1):yx2})

print (res)
