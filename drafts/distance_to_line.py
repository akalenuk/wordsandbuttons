from sympy import *
from sympy.vector import *

x, y, x1, y1, x2, y2, a = symbols('x y x1 y1 x2 y2 a')

N = CoordSys3D('N')
p = x*N.i + y*N.j
l1 = x1*N.i + y1*N.j
l2 = x2*N.i + y2*N.j

the_a = solve([
	dot(l1 + (l2 - l1) * a - p, l2 - l1)
], (a))

print (jscode(the_a))
