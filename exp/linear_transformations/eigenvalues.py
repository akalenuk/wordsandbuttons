from sympy import *

# matrix = [[a, b], [c, d]]

a, b, c, d, ev = symbols('a b c d ev')


eigenvalues_eq = [
    (ev - a) / b - c / (ev - d)
]

eigenvalues = solve(eigenvalues_eq, (ev))

print(eigenvalues)

e1 = eigenvalues[0][0]
e2 = eigenvalues[1][0]
print([e1 - d , c])
print([e2 - d , c])
print([b , e1 - a])
print([b , e2 - a])
