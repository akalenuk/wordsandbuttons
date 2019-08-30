""" multivariative simplicial weighted interpolation and extrapolation.

This is an implementation of four different interpolation
and extrapolation technics.

F_w - is for average weighted interpolation, also called baricentric.
It is a global scheme.

F_b - is a baricentric weighted simplicial interpolation. It is local and does
not provide derivative continuousness. Neigher it has a extrapolation method
implemented.

F_l - is for linear simplicial weighted interpolation. It is a local scheme, so it
needs simplicial complex, given as a list of simplexes, to operate. Note that
while interpolation function itself is continuous, its derivatives may not be
that way.

F_s - simplicial weighted interpolation. It is local, and being used with
appropriate weighting function and basis functions, it can provide derivative
continuousness up to any choosen level.
"""

__authors__ = [
  '"Alexandr Kalenuk" <akalenuk@gmail.com>'
]

import operator
import math

###################### data functions section

def make_vector(n):
    ''' Makes n-dimmentional vector '''
    return [0.0]*n

    
def copy_vector(V):
    ''' Copies input vector '''
    return [Vi for Vi in V]


def make_matrix(n):
    ''' Makes square n-dimensional matrix '''
    return [[0.0 for j in xrange(0,n)] for i in xrange(0,n)]

    
def copy_matrix(M):
    ''' Copies rectangular matrix '''
    return [[Mij for Mij in Mi] for Mi in M]

    
def make_n_vectors(k,n):
    ''' Makes k-sized list of n-dimmentional vectors '''
    return [[0.0 for j in xrange(0,n)] for i in xrange(0,k)]

    
###################### algebra section

def v_add(a,b):
    ''' Vector sum'''
    return map(lambda s,d: s+d, a,b)

    
def v_sub(a,b):
    ''' Vector sub '''
    return map(lambda s,d: s-d, a,b)


def v_dot(a,b):
    ''' Vector dot product '''
    return sum(map(lambda s,d: s*d, a,b))

    
def v_len(a):
    ''' Vector length'''
    return math.sqrt(sum(map(lambda s: s**2, a)))

    
def v_smul(s,a):
    ''' Multiplication by a scalar '''
    return [s*ai for ai in a]

    
def v__E(a):
    ''' Levi-Civita symbol '''
    n=0
    t=[]
    for ti in a:
        t.append(ti)
    for i in xrange(0,len(a)):
        for j in xrange(0,len(a)-i-1):
            if t[j]==t[j+1]:
                return 0
            elif t[j]>t[j+1]:
                n+=1
                t.insert(j+1,t.pop(j))
    if n%2==0:return 1
    return -1


def v_cross(A):
    ''' n-dimensional cross product on (n-1) vectors in list A '''
    for a in A:
        if len(a)!=len(A[0]):
            print "Vector size mismatch in 'v_cross'"
    DIMM=len(A[0])
    N=len(A)
    if N!=DIMM-1:
        print "Vector number mismatch in 'v_cross'"
        A[100][100]=0.0
    v_res=[]
    for i in xrange(0,DIMM):
        v_res.append(0.0)
        for jk in xrange(0,DIMM**N):
            v_ijk=[i]
            for j in xrange(0,N):
                v_ijk.append((jk/(DIMM**(N-j-1)))%DIMM)
            t_res=v__E(v_ijk)
            if t_res!=0:
                for k in xrange(0,N):
                    t_res*=A[k][v_ijk[k+1]]
                v_res[i]+=t_res
    return v_res


def v_mixed(A):
    ''' n-dimensional triple product of n vectors in list A '''
    for i in xrange(1,len(A)):
        if len(A[i])!=len(A[i-1]):
            print "Vector size mismatch in 'v_cross'"
    DIMM=len(A[0])
    N=len(A)
    if N!=DIMM:print "Vector number mismatch in 'v_cross'"
    v_res=0.0
    for jk in xrange(0,DIMM**N):
        v_ijk=[]
        for j in xrange(0,N):
            v_ijk.append((jk/(DIMM**(N-j-1)))%DIMM)
        t_res=v__E(v_ijk)
        if t_res!=0:
            for k in xrange(0,N):
                t_res*=A[k][v_ijk[k]]
            v_res+=t_res
    return v_res


###################### linear equations section

def Solve(A, B):
    ''' Linear system solving for AX=B. Returns vector X '''
    N=len(B)
    X=[0]*N
    
    def a(i, j, n):
        if n==N: return A[i][j]
        return a(i,j,n+1)*a(n,n,n+1)-a(i,n,n+1)*a(n,j,n+1)

    def b(i, n):
        if n==N: return B[i]
        return a(n,n,n+1)*b(i,n+1)-a(i,n,n+1)*b(n,n+1)

    def x(i):
        d=b(i,i+1)
        for j in xrange(i): d-=a(i,j,i+1)*X[j]
        return d/a(i,i,i+1)

    for k in xrange(N):
        X[k]=x(k)

    return X


def Gauss(A, B):
    ''' Gauss method implementation for linear system solving.
        Args:
            A: matrix,
            B: vector
            for equation AX=B

        Returns:
            X for AX=B '''
    N=len(B)
    X=[0]*N
    gA=[]
    for i in xrange(0,len(A)):
        ga=[]
        for j in xrange(0,len(A[i])):
            ga.append(float(A[i][j]))
        gA.append(ga)
    gB=[]
    for i in xrange(0,len(B)):
        gB.append(float(B[i]))
    r=0.0
    for k in xrange(0, N): X[k]=0.0
    for k in xrange(0, N-1):
        for j in xrange(0, k+1):
            if gA[j][j]==0.0: gA[j][j]=0.000000001
            r=gA[k+1][j]/gA[j][j]
            gA[k+1][j]=0.0
            for bJ in xrange(j+1,N):
                gA[k+1][bJ]=gA[k+1][bJ]-gA[j][bJ]*r
            gB[k+1]=gB[k+1]-gB[j]*r
            
    if gA[N-1][N-1]==0: gA[N-1][N-1]=0.00000001
    X[N-1]=gB[N-1]/gA[N-1][N-1]

    for i in xrange(N-2,-1,-1):
        s=0.0
        for j in xrange(i,N):
            s=s+gA[i][j]*X[j]
        if gA[i][j]==0: gA[i][j]=0.0000001
        X[i]=(gB[i]-s)/gA[i][i]
    return X


###################### projection

def v_proj(a,S):
    ''' Projection on a simplex plane.

        Args:
            a: Projecting point.
            S: Simplex given by a list of points.
            
        Returns:
            Point, which is an 'a' projection on 'S' simplex plane.
            
    '''
    for b in S:
        if len(b)!=len(a): print "Vector sizes mismatch in v_proj"
    if len(S)==1:
        return S[0]
    elif len(S)==2:
        a0=v_sub(a,S[0])
        v01=v_sub(S[1],S[0])
        Ei=0.0
        E=0.0
        for i in xrange(0,len(a)):
            Ei+=v01[i]*v01[i]
            E+=a0[i]*v01[i]
        return v_add(S[0],v_smul(float(E)/Ei,v01))
    elif len(S)>2:
        N=len(S)-1
        a0=v_sub(a,S[0])
        v0i=[]
        for i in xrange(0,N):
            v0i.append(v_sub(S[i+1],S[0]))
        A=make_matrix(N)
        B=make_vector(N)
        for k in xrange(0,len(a)):
            for i in xrange(0,N):
                for j in xrange(0,N):
                    A[i][j]+=v0i[j][k]*v0i[i][k]
                B[i]+=a0[k]*v0i[i][k]
        I=Gauss(A,B)
        to_ret=copy_vector(S[0])
        for i in xrange(0,N):
            to_ret=v_add(to_ret,v_smul(I[i],v0i[i]))
        return to_ret

def v_proj_or(a,S, p0):
    ''' Projection on a simplex inner space. If a projection on a simplex plane
        does not lie in its inner space, function returns p0

        Args:
            a: Point to project.
            S: Simplex given by a list of its points.

    Returns:
        Point of projection or p0 if projection does not lie in a 
            simplex inner space
    '''
    ret=make_vector(len(a))
    ret[0]=p0

    for b in S:
        if len(b)!=len(a): print "Vector sizes mismatch in v_proj"
    if len(S)==1:
        return S[0]
    elif len(S)==2:
        a0=v_sub(a,S[0])
        v01=v_sub(S[1],S[0])
        Ei=0.0
        E=0.0
        for i in xrange(0,len(a)):
            Ei+=v01[i]*v01[i]
            E+=a0[i]*v01[i]
        k=float(E)/Ei
        if k<0 or k>1.0:
            return ret
        return v_add(S[0],v_smul(k,v01))
    elif len(S)>2:
        N=len(S)-1
        a0=v_sub(a,S[0])
        v0i=[]
        for i in xrange(0,N):
            v0i.append(v_sub(S[i+1],S[0]))
        A=make_matrix(N)
        B=make_vector(N)
        for k in xrange(0,len(a)):
            for i in xrange(0,N):
                for j in xrange(0,N):
                    A[i][j]+=v0i[j][k]*v0i[i][k]
                B[i]+=a0[k]*v0i[i][k]
        I=Gauss(A,B)
        sum_I=0
        for i in I:
            if i<0 or i>1: return ret
            sum_I+=i
        if sum_I<0 or sum_I>1: return ret
        to_ret=copy_vector(S[0])
        for i in xrange(0,N):
            to_ret=v_add(to_ret,v_smul(I[i],v0i[i]))
        return to_ret


###################### common functions section

def v_k(vx, s_k):
    ''' Weight function for 'vx' vector
        Args:
            vx: vector to weight.
            s_k: scalar weight function.

        Returns:
            Weight of the vector
    '''
    return reduce(operator.mul, [s_k(x) for x in vx])


def coords_in_simplex(sx,dot,pnt, xyz,Sx,  crd=[]):
    ''' Determines if a point is in simplex

        Args:
            dot: point coordinates in an a basis set by simplex 1-edges.
            sx: index for basic simplex in an array of simplexes 'Sx'.
            pnt: index of an origin point in simplex.
            xyz: list of points,
            Sx: list of point indexes, representing simplicial complex.
            crd: the return value for calculated coordinates.

        Returns:
            'True' if point is in a simplex, 'False' otherwise.
    '''
    DIMM=len(dot)
    A=make_matrix(DIMM)
    B=make_vector(DIMM)
    
    crd=make_vector(DIMM)
    
    cnt=0
    p_pnt=Sx[sx][pnt]-1
    for i in xrange(0,DIMM+1):
        p_i=Sx[sx][i]-1
        if p_i!=p_pnt:
            for j in xrange(0,DIMM):
                A[j][cnt]=xyz[p_i][j]-xyz[p_pnt][j]
            cnt+=1
    if cnt!=DIMM: print "WTF error: not enough points in simplex"
    for j in xrange(0,DIMM):
        B[j]=dot[j]-xyz[p_pnt][j]
        
    crd=Gauss(A,B)
  
    res=True
    summ=0.0
    for j in xrange(0,DIMM):
        if not 1>=crd[j]>=0: res=False
        summ+=crd[j]
    if 1>=summ>=0 and res:
        return True
    else:
        return False


def get_nearest_simplex(dot,xyz,Sx,sx, best_pack):
    ''' Finds a simplex which is the nearest to a 'dot' point.
        Args:
            sx: A candiate simplex.
            xyz: List of all points forming simplicial complex.
            Sx: List of point indexes, representing simplicial complex.
            best_pack: Structure for passing found data recoursively.

        Returns:
            List, first element of which represents nearest simplex index.
    '''
    new_pack=[best_pack[0],copy_vector(best_pack[1]),copy_vector(best_pack[2])]
    new_S=[]
    for i in sx:
        new_S.append(xyz[i-1])
    new_prj=v_proj_or(dot,new_S, 1.e10)
    new_l=v_len(v_sub(new_prj,dot))
    if new_l<best_pack[0]:
        best_pack[0]=new_l
        best_pack[1]=copy_vector(new_prj)
        best_pack[2]=copy_vector(sx)

    if len(sx)>1:
        for i in xrange(0,len(sx)):
            c_sx=copy_vector(sx)
            c_sx[i:i+1]=[]
            best_pack=get_nearest_simplex(dot,xyz,Sx,c_sx, best_pack)
    return best_pack


def get_constant_functions(xyz,f,Sx):
    ''' Determines a list of constant basis functions

        Args:
            xyz: Point set.
            f: Corresponding array of function values.
            Sx: List of simplexes 

        Returns:
            List of basis functions
    '''
    def fi(i):
        return lambda dot: f[i]
    return [fi(i) for i in xrange(len(xyz))]


def get_linear_functions(xyz,f,Sx):
    ''' Determines a list of linear basis functions

        Args:
            xyz: Point set.
            f: Corresponding array of function values.
            Sx: List of simplexes 

        Returns:
            List of basis functions
    '''
    if len(xyz)==0:
        return []
    dimm=len(xyz[0])
    simplex_linears=make_n_vectors(len(Sx),dimm+1)
    point_linears=make_n_vectors(len(xyz),dimm+1)
    
    for i in xrange(0,len(Sx)):
        A=make_matrix(dimm+1)
        B=make_vector(dimm+1)
        for j in xrange(dimm+1):
            pnt=Sx[i][j]-1
            for k in xrange(dimm):
                A[j][k]=xyz[pnt][k]
            A[j][dimm]=1.0
            B[j]=f[pnt]
        simplex_linears[i]=Gauss(A,B)

    for i in xrange(len(xyz)):
        sx_N=0
        for j in xrange(0,len(Sx)):
            for k in xrange(0,dimm+1):
                if Sx[j][k]==i+1:
                    sx_N+=1
                    for l in xrange(0,dimm+1):
                        point_linears[i][l]+=simplex_linears[j][l]
                    break
        if sx_N==0: print "error: point is not in simplex"
        point_linears[i]=map(lambda a:a/sx_N, point_linears[i])

    def fi(i):
        return lambda dot: sum([point_linears[i][j]*dot[j] for j in xrange(dimm)])+point_linears[i][dimm]
    return [fi(i) for i in xrange(len(xyz))]


###################### interpolation and extrapolation section

def F_w(dot, xyz,Sx,base_f,s_k):
    ''' Average weighted interpolation
        
        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, which is excessive 
                for this particular algorithm yet let for consistancy.
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of interpolation function.
    '''
    Up=0.0
    Dn=0.0
    for i in xrange(0,len(xyz)):
        k=s_k(v_len(v_sub(xyz[i],dot)))
        Up=Up+base_f[i](dot)*k
        Dn=Dn+k
    return Up/Dn


def F_l(dot, xyz,Sx,base_f,s_k):
    ''' Simplicial linear interpolation.
        
        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, represeting simplicial complex
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of interpolation function.
    '''
    DIMM=len(dot)
    Up=0.0
    Dn=0.0
    for sx in xrange(0,len(Sx)):
        crd=make_n_vectors(DIMM+1,DIMM)
        if coords_in_simplex(sx,dot,0,xyz,Sx,  crd[0]):
            for i in xrange(1,DIMM+1):
                coords_in_simplex(sx,dot,i,xyz,Sx,  crd[i])
            Up=0.0
            Dn=0.0
            for i in xrange(0,DIMM+1):
                Up+=base_f[Sx[sx][i]-1](dot)*v_k(crd[i], s_k)
                Dn+=v_k(crd[i], s_k)
            return Up/Dn 
            
    return F_lex(dot,xyz,Sx,base_f,s_k)


def F_lex(dot, xyz,Sx,base_f,s_k):
    ''' Simplicial linear extrapolation
        
        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, represeting simplicial complex
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of extrapolation function.
    '''
    best_pack=[100000000,[],[]]    # I probably should make this better
    for sx in Sx:
        for i in xrange(0,len(sx)):
            c_sx=copy_vector(sx)
            c_sx[i:i+1]=[]
            best_pack=get_nearest_simplex(dot,xyz,Sx,c_sx, best_pack)
    dot2=copy_vector(best_pack[1])
    dot2[0]+=0.2
    dot2[1]+=0.2
    DIMM=len(dot)
    Up=0.0
    Dn=0.0
    for sx in xrange(0,len(Sx)):
        n=0
        for i1 in best_pack[2]:
            for i2 in Sx[sx]:
                if i1==i2:
                    n+=1
        if n==len(best_pack[2]):
            crd=make_n_vectors(DIMM+1,DIMM)
            for i in xrange(0,DIMM+1):
                coords_in_simplex(sx,dot2,i,xyz,Sx,  crd[i])
            Up=0.0
            Dn=0.0
            for i in xrange(0,DIMM+1):
                Up+=base_f[Sx[sx][i]-1](dot)*v_k(crd[i], s_k)
                Dn+=v_k(crd[i], s_k)
            return Up/Dn
    return 0


def F_s(dot, xyz,Sx,base_f,s_k):
    ''' Simplicial weighted interpolation.

        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, represeting simplicial complex
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of interpolation function.
    '''

    DIMM=len(dot)
    for sx in xrange(0,len(Sx)):
        crd=make_vector(DIMM)
        if coords_in_simplex(sx,dot,0,xyz,Sx,  crd):
            pnt_set=[]
            for pnt in Sx[sx]:
                pnt_set.append(pnt-1)
            return get_inS(dot,dot,pnt_set,  xyz,Sx,base_f,s_k)
    return F_sex(dot,xyz,Sx,base_f,s_k)


def F_sex(dot, xyz,Sx,base_f,s_k):
    ''' Simplex weighted extrapolation

        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, represeting simplicial complex
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of extrapolation function.
    '''
    best_pack=[10000000,[],[]]
    for sx in Sx:
        for i in xrange(0,len(sx)):
            c_sx=copy_vector(sx)
            c_sx[i:i+1]=[]
            best_pack=get_nearest_simplex(dot,xyz,Sx,c_sx, best_pack)
    pnt_set=[]
    for i in best_pack[2]:
        pnt_set.append(i-1)
    return get_inS(dot,best_pack[1],pnt_set,  xyz,Sx,base_f,s_k)


def get_inS(dot,prj,pnt_set,  xyz,Sx,base_f,s_k):
    ''' Gets a simplex interpolated value in a subsimplex
      
        Args:
            dot: Argument of interpolation function.
            prj: Current level projection of a 'dot'.
            pnt_set: Point set representing current level simplex.
            xyz: Data point set.
            Sx: Simplicial complex.
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Iterpolation value for 'dot' projection on a subsimplex
    ''' 
    PSL=len(pnt_set)
    if PSL==1:
        return base_f[pnt_set[0]](dot)
    elif PSL>1:
        Up=0.0
        Dn=0.0
        for i in xrange(0,PSL):
            new_pnt_set=[]
            new_S=[]
            for j in xrange(0,PSL):
                if j!=i:
                    new_pnt_set.append(pnt_set[j])
                    new_S.append(xyz[pnt_set[j]])            
            new_prj=v_proj(prj,new_S)
            cur_k=s_k(v_len(v_sub(new_prj,prj)))
            ud=get_inS(dot,new_prj,new_pnt_set,  xyz,Sx,base_f,s_k)
            Up+=ud*cur_k
            Dn+=cur_k
        return Up/Dn
    elif PSL<0:
        print "WTF error in get_inS"
        return -1


def F_b(dot, xyz,Sx,base_f,s_k):
    ''' Baricentric simplicial interpolation.

        Args:
            dot: Argument for interpolation function 
                 given by a list of variables
            xyz: Data points.
            Sx: List of simplexes, represeting simplicial complex
            base_f: Corresponding to 'xyz' list of basic functions.
            s_k: Scalar weight function. 

        Returns:
            Value of interpolation function.
    ''' 
    DIMM=len(dot)
    for sx in xrange(0,len(Sx)):
        crd=make_vector(DIMM)
        if coords_in_simplex(sx,dot,0,xyz,Sx,  crd):
            up=0.0
            down=0.0
            for i in xrange(0,len(Sx[sx])):
                newS=[]
                for j in xrange(0,len(Sx[sx])):
                    if i!=j:
                        newS.append(xyz[Sx[sx][j]-1])
                newP=v_proj(dot,newS)
                cur_k=s_k(v_len(v_sub(dot,newP)))
                up=up+base_f[Sx[sx][i]-1](dot)*cur_k
                down=down+cur_k
            return up/down
    return 0


if __name__ == '__main__':
    ''' testing and demonstration part '''
    # data for 1-variable function / curve
    t = [[1], [2], [3], [4], [5], [6], [7]]      # parameter set
    x = [55, 180, 220, 45, 55, 180, 220]         # coordinates
    y = [50, 45, 190, 220, 50, 45, 190]        
    s1 = [[1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7]]   # 1-simplex complex
    
    # data for 2-variable function / surface graphic
    xy = [[10, 10], [90, 10], [90, 90], [10, 90]]       # point set
    f_xy = [120, 60, 80, 90]        # corresponding data 
    s2 = [[1, 2, 3], [3, 4, 1]]     # 2-simplex complex

    # data for 3-variable function / 3-manifold
    xyz=[[10, 10, 10],[90 , 10, 10 ],[90 ,90 , 10],[10, 90, 10],[50, 50, 90]]
    f_xyz=[20,90,60,150,180]
    s3=[[1,2,3,5],[3,4,1,5]]

     
    def k(x):   # weight function
        if x!=0:
            return 1/float(x)
        else:
            return 1.0e5  # to avoid zero division


    def colors(n):
        if n == -1: return "#000000"
        elif n % 5 == 0: return "#006600"
        elif n % 5 == 1: return "#000077"
        elif n % 5 == 2: return "#770000"
        elif n % 5 == 3: return "#003377"
        elif n % 5 == 4: return "#440077"

    
    import time     # for productivity measurement



    def test_1d():
        canvas1 = Canvas(root, height = 256, width = 256, background = "white")
        start_time = time.time()
        ox='none'
        oy='none'
        for i in xrange(len(s1)):    # for all simplexes
            the_fill = colors(i)
            if i>0 and i<len(s1)-1: # these simplexes are to grant smoothness only
                for j in xrange(21):
                    ti1 = t[s1[i][0]-1][0]
                    ti2 = t[s1[i][1]-1][0]
                    ti = ti1 + j*(ti2 - ti1)/20.0
                    F_x=F([ti], t, s1, fxi, k)
                    F_y=F([ti], t, s1, fyi, k)
                    if ox!='none' and oy!='none':
                        canvas1.create_line(F_x, F_y, ox, oy, fill=the_fill, width=2)
                    ox = F_x
                    oy = F_y
                canvas1.create_line(x[i]-2, y[i]-2, x[i]+2, y[i]+2, fill="#cc0000", width=2)
                canvas1.create_line(x[i]-2, y[i]+2, x[i]+2, y[i]-2, fill="#cc0000", width=2)
                
        finish_time=time.time()     # geting and printing calculation time
        the_time = finish_time - start_time
        print 'curve calculated and drawn in: ', the_time, ' seconds'
          
        canvas1.pack({"side": "left"})


        
    def test_2d():
        canvas2 = Canvas(root, height = 256, width = 256, background = "white")
        start_time = time.time()

        for i in xrange(100): # quasi-isometric plot
            for j in xrange(100):
                p = [i, j]
                F_xy = F(p, xy, s2, fi, k)
                xb = 128 + i - j
                yb = 140 + (i + j) / 2
                canvas2.create_line(xb, yb, xb, yb-F_xy, fill="#880000")
                
                current_simplex = -1    # determining in which simplex p lies
                for s in xrange(len(s2)):
                    if coords_in_simplex(s, p, 0,  xy, s2):
                        current_simplex = s

                the_fill = colors(current_simplex)
                canvas2.create_line(xb, yb-F_xy, xb, yb-F_xy-1, fill=the_fill)


        finish_time=time.time()     # geting and printing calculation time
        the_time = finish_time - start_time
        print '100x100 surface calculated and drawn in: ', the_time, ' seconds'
            
        canvas2.pack({"side": "left"})



    def test_3d():
        def red(x, y):
            x=round(x/16)*16
            if x>255: x=255
            if x<0: x=0
            return ("#%02X" % x) + ("%02X" % y) + ("%02X" % y)

        canvas3 = Canvas(root, height = 256, width = 256, background = "white")
        start_time = time.time()

        for i in xrange(100): 
            for j in xrange(100):
                p = [j, i, 100]
                F_xyz = F(p, xyz, s3, fi, k)
                xb = 128 + i - j
                yb = 29 + (i + j) / 2
                canvas3.create_line(xb, yb, xb, yb+1, fill=red(F_xyz, 50))

                p = [100-i, 100, 100-j]
                F_xyz = F(p, xyz, s3, fi, k)
                xb = 128 + i
                yb = 128 + j - i / 2
                canvas3.create_line(xb, yb, xb, yb-1, fill=red(F_xyz, 30))

                p = [100, 100-i, 100-j]
                F_xyz = F(p, xyz, s3, fi, k)
                xb = 128 - i
                yb = 128 + j - i / 2
                canvas3.create_line(xb, yb, xb, yb-1, fill=red(F_xyz, 0))

        finish_time=time.time()     # geting and printing calculation time
        the_time = finish_time - start_time
        print '100x100x3 manifold calculated and drawn in: ', the_time, ' seconds'
            
        canvas3.pack({"side": "left"})


    # setup and test
    from Tkinter import *   # initializing graphics
    root = Tk()

    F = F_s       # interpolation scheme
    fxi = get_linear_functions(t, x, s1)    # basis functions
    fyi = get_linear_functions(t, y, s1)    # basis functions
    test_1d()   # curve test

    F = F_s       # interpolation scheme
    fi = get_linear_functions(xy, f_xy, s2) # basis functions
    test_2d()   # surface test

    F = F_s       # interpolation scheme
    fi = get_linear_functions(xyz, f_xyz, s3) # basis functions
    test_3d()   # 3-manifold test

    root.mainloop()

