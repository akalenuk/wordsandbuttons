from sympy import *

a, b, c, d, N, D, R = symbols('a b c d N D R')
x = symbols('x')
N = a*x*x + b*x + c
D = d*x
R = N/D

# R(0) = -inf
# R(1/4) = -2 <=> N(0.25) + 2*D(0.25) = 0
# R(1) = 0 <=> N(1) = 0
# R(2) = 1 <=> N(2) - D(2) = 0

eqs = [
d - 1,
(N + 2*D).subs(x, 0.25),
(N - 0*D).subs(x, 1),
(N - 1*D).subs(x, 2),
]

sol = solve(eqs, (a, b, c, d))

print(sol)
