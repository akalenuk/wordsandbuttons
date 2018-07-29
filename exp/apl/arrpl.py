#!/usr/bin/python

## primitives (inspired by Ferdinand Jamitzky)

class _Function:
    def __init__(self, monadic, diadic, fun = None):
        self.monadic = monadic
        self.diadic = diadic
        self.fun = fun
    def __neg__(self):
        if not isinstance(self, Diadic): # for operator calls
            self.fun = self.monadic
        return self
    def __rsub__(self, left):
        self.fun = lambda x: self.diadic(left, x)
        self.left = left
        return self
    def __sub__(self, right):
        return self.fun(right)
    def __call__(self, right):
        return self.fun(right) 

class Monadic(_Function):
    def __init__(self, monadic):
        self.monadic = monadic

class Diadic(_Function):
    def __init__(self, diadic):
        self.diadic = diadic

class Nomadic(_Function):
    def __init__(self, monadic, diadic):
        self.monadic = monadic
        self.diadic = diadic


class Operator:
    def __init__(self, body, fun = None):
        self.body = body
        self.fun = fun
    def __radd__(self, left):
        return Operator(self.body, left)
    def __add__(self, right):
        return _Function(None, None, lambda x: self.body(self.fun, right, x))
    def __sub__(self, right):
        return self.body(self.fun, right)
   

class DomainError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)


## generic functions

def _D_(on_scalar, error_message):
    def _d_(A, B):
        if isinstance(A, list) and isinstance(B, list):
            if(len(A) != len(B)):
                raise DomainError("Domain error in " + error_message)
            else:
                return [_d_(a, b) for (a, b) in zip(A, B)]
        elif isinstance(A, list) and not isinstance(B, list):
            return [_d_(a, B) for a in A]
        elif not isinstance(A, list) and isinstance(B, list):
            return [_d_(A, b) for b in B]
        else:
            return on_scalar(A, B)
    return _d_

def _M_(on_list, on_scalar):
    def _m_(A):
        if isinstance(A, list):
            return on_list(A)
        else:
            return on_scalar(A)
    return _m_


## functions

_d_plus = _D_(lambda A, B: A+B, "'PLUS'")
_d_minus = _D_(lambda A, B: A-B, "'MINUS'")
_d_mul = _D_(lambda A, B: A*B, "'MUL'")
_d_div = _D_(lambda A, B: A/B, "'DIV'")
_d_pow = _D_(lambda A, B: A**B, "'POW'")
_d_mod = _D_(lambda A, B: A%B, "'MOD'")

_m_plus = _M_(lambda A: [_m_add(a) for a in A], lambda A: A)
_m_minus = _M_(lambda A: [_m_sub(a) for a in A], lambda A: -A)
_m_div = _M_(lambda A: [_m_div(a) for a in A], lambda A: 1.0/A)
_m_mirror = _M_(lambda A: [_m_wirror(a) for a in A], lambda A: A)
_m_wirror = _M_(lambda A: A[::-1], lambda A: A)
_m_transpose = _M_(lambda A: [list(row) for row in zip(*A)], lambda A: A)
_m_not = _M_(lambda A: [_m_not(a) for a in A], lambda A: int(not A))
_m_rank = _M_(lambda A: [len(A)] + _m_rank(A[0]), lambda A: [])


## function exceptions (and hacks)        

def _d_rank(r, A):
    if not isinstance(A, list):
        return _d_rank(r, [A])
    n = reduce(lambda x,y: x*y, r)
    d = n / r[0]
    if len(A) != n:
        A = (A * (n / len(r) + 1) )[:n]
    if len(r) == 1:
        return A
    return [_d_rank(r[1:], A[i*d: (i+1)*d]) for i in range(r[0])]

def _m_index(r, rs=[]):
    if r==[]:
        return rs
    else:
        return [_m_index(r[1:], rs+[i]) for i in range(r[0])]

def _d_index(A, r):
    ixs = []
    for i in r:
        try:
            ixs += [A.index(i)]
        except ValueError:
            ixs += [-1]
    return ixs

def _d_select(A, B):
    if isinstance(A, list) and isinstance(B, list) and len(A) == len(B):
        return [a for (a, b) in zip(A, B) if b == 1]
    else:
        raise DomainError("Domain error in 'SELECT'")
  
def _do_inner(A, lf, rf, B):	# I don't like it
    if isinstance(A[0], list):
    	return [[reduce(lf, rf(a, b)) for a in _m_transpose(A)] for b in B] 
    else:
        return reduce(lf, rf(A, B))


## interface

PLUS = Nomadic(_m_plus, _d_plus)
MINUS = Nomadic(_m_minus, _d_minus)
MUL = Diadic(_d_mul)
DIV = Nomadic(_m_div, _d_div)
MOD = Diadic(_d_mod)
POW = Diadic(_d_pow)

RANK = Nomadic(_m_rank, _d_rank)
INDEX = Nomadic(_m_index, _d_index)
MIRROR = Monadic(_m_mirror)
WIRROR = Monadic(_m_wirror)
TRANSPOSE = Monadic(_m_transpose)

NOT = Monadic(_m_not)
AND = Diadic(_D_(lambda A, B: int(A and B), 'AND'))
OR = Diadic(_D_(lambda A, B: int(A or B), 'OR'))
LT = Diadic(_D_(lambda A, B: int(A < B), 'LT'))
LE = Diadic(_D_(lambda A, B: int(A <= B), 'LE'))
EQ = Diadic(_D_(lambda A, B: int(A == B), 'EQ'))
GT = Diadic(_D_(lambda A, B: int(A > B), 'GT'))
GE = Diadic(_D_(lambda A, B: int(A >= B), 'GE'))
NE = Diadic(_D_(lambda A, B: int(A != B), 'NE'))

SELECT = Diadic(_d_select)

MAP = Operator(lambda fun, xs: [fun(x) for x in xs])
REDUCE = Operator(lambda fun, xs: reduce(fun.diadic ,xs))
INNER = Operator(lambda lf, rf, xs: _do_inner(lf.left, lf.diadic, rf.diadic, xs))
OUTER = Operator(lambda fun, xs: [[fun.diadic(x, y) for y in fun.left] for x in xs])


## test
if __name__ == '__main__':
    ''' testing and demonstration part '''
    A = [[1,2],[3,4]]
    B = [7,8]
    C = [2,1]

    assert (B -PLUS+INNER+MUL- C) == 22
    assert (A -PLUS+INNER+MUL- A) == [[7, 10],[15,22]]
    assert ((-MINUS- 1) -PLUS- 2 -MUL- 3 -PLUS- [1, 2, 3]) == [4, 5, 6]
    assert -PLUS+REDUCE- [1,2,3] == 6
    assert -MUL+REDUCE- [1,2,3,4] == 24
    assert 4 -MINUS+MAP- [1,2,3] == [3,2,1]

    S = []
    while True:
        S += [eval(raw_input("      "))]
        print S[-1]
