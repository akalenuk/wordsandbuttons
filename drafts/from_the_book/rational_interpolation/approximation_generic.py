import numpy as np

N = 5
M = 2
points = np.array([[1., 2.],[2., 3.],[3., 5.],[4., 7.],[5., 8.],[6., 5.],[7., 3.],[8., 2.],[9., 1.]])

# f = (ax^2 + bx + c) / (dx + 1)
# (ax^2 + bx + c) / (dx + 1) = y  => ax^2 + bx + c - dxy = y

A = np.zeros((len(points), N+M))
B = np.zeros((len(points), 1))
for i in range(len(points)):
    x = points[i][0]
    y = points[i][1]
    for j in range(N):
        A[i][j] = x**j 
    for j in range(M):
        A[i][N+j] = y*(x**(j+1))
    B[i][0] = y

AMN = np.matmul(np.transpose(A), A)
BMN = np.matmul(np.transpose(A), B)

coefs = np.linalg.solve(AMN, BMN)

f = lambda x: sum([coefs[j] * x**j for j in range(N)]) + sum([coefs[N+j] * y * x**(j+1) for j in range(M)])


# the plotting code
import numpy as np
import matplotlib.pyplot as plt

import matplotlib
matplotlib.interactive(True)
matplotlib.use('WebAgg')
Pxs = np.arange(0., 10., 1./32.)
Pys = f(Pxs)

fig, ax = plt.subplots()
ax.plot(Pxs, Pys)
ax.set(xlabel='x', ylabel='y', title='Approximating rational function')
ax.grid()
xs,ys = np.hsplit(points, 2)
plt.scatter(xs, ys)
# save a picture if you want
#fig.savefig("approximation.png")
plt.show()
