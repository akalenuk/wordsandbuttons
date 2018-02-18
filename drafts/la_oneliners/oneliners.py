def scaled(A, x):
	return [ai*x for ai in A]

def sum_of(A, B):
	return [ai+bi for (ai, bi) in zip(A, B)]

def dot_of(A, B):
	return sum([ai*bi for (ai, bi) in zip(A, B)])

def length_of(A):
	return pow(dot_of(A, A), 0.5)

def normalized(A):
	return scaled(A, 1.0 / length_of(A))

def identity_of_dim(n):
	return [[1.0 if i==j else 0.0 for j in range(n)] for i in range(n)]

def transposed(A):
	return [list(aj) for aj in zip(*A)]

def multiplication_of(A, X):
	return [dot_of(ai, X) for ai in A]

def vector(P1, P2):
	return sum_of(scaled(P1, -1.), P2)

def projected_on_plane(A, Pn, Pd):
	return sum_of(A, scaled(Pn, (Pd - dot_of(Pn, A)) / dot_of(Pn, Pn)))

def distance_between(A, B):
	return pow(dot_of( *(vector(A, B), )*2 ), 0.5)

def solution_for(A, B):
	return solution_iteration(A, B, [0. for bi in B], 0)

def solution_iteration(A, B, Xi, i):
	return Xi if distance_between(multiplication_of(A, Xi), B) < 1e-5 else solution_iteration(A, B, projected_on_plane(Xi, A[i % len(B)], B[i % len(B)]), i+1)

def inverted(A):
	return transposed([solution_for(A, ort) for ort in identity_of_dim(len(A))])


if __name__ == "__main__":
	A = [[0.78, -0.42, 0.59], [0.95, 0.31, 0.26], [-0.44, -0.1, -0.38]]
	B = [1.0, 2.0, 3.0]
	print 'A, B:', A, B
	X = solution_for(A, B)
	err = distance_between(multiplication_of(A, X), B)
	print 'X, error:', X, err
	Ai = inverted(A)
	print 'A^-1:', Ai
	Aii = inverted(Ai)
	print '(A^-1)^-1:',Aii
	print B
	X = multiplication_of(Ai, B)
	err = distance_between(multiplication_of(A, X), B)
	print 'Ai*B, error:', X, err
