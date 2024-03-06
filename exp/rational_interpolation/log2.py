from sympy import *

a, b, c, d, N, D, R = symbols('a b c d N D R')
x = symbols('x')
N = a*x*x + b*x + c
D = d*x
R = N/D

# R(0) = -inf
# R(1) = 0 <=> N(1) = 0
# R(2) = 1 <=> N(2) - D(2) = 0
# R(4) = 2 <=> N(4) - 2*D(4) = 0

eqs = [
d - 1,
D.subs(x, 0),
N.subs(x, 1),
(N - D).subs(x, 2),
(N - 2*D).subs(x, 4)
]

sol = solve(eqs, (a, b, c, d))

print(sol)
