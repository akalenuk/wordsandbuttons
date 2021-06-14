from sympy import *

# matrix = [[a, b], [c, d]]

a, b, c, d, ev = symbols('a b c d ev')


eigenvalues_eq = [
    (ev - a) / b - c / (ev - d)
]

eigenvalues = solve(eigenvalues_eq, (ev))

print(eigenvalues)
