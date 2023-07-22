import numpy as np

points = np.array([[1., 2.],[2., 3.],[3., 5.],[4., 7.],[5., 8.],[6., 5.],[7., 3.],[8., 2.],[9., 1.]])

# f = (ax^2 + bx + c) / (dx + 1)
# (ax^2 + bx + c) / (dx + 1) = y  => ax^2 + bx + c - dxy = y

A = np.zeros((len(points), 4))
B = np.zeros((len(points), 1))
for i in range(len(points)):
    x = points[i][0]
    y = points[i][1]
    A[i][0] = x*x
    A[i][1] = x
    A[i][2] = 1
    A[i][3] = -x*y
    B[i][0] = y

A4 = np.matmul(np.transpose(A), A)
B4 = np.matmul(np.transpose(A), B)

abcd = np.linalg.solve(A4, B4)

f = lambda x: abcd[0]*x*x + abcd[1]*x + abcd[2] - abcd[3]*x*y


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
