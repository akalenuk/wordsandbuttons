#include "static_loops.h"
#include "static_recursion.h"

RECURSIVE_4_CALLS(double aijn, (double* a, double* b, int i, int j, int n, int m){ 
  return (n == m) ? a[i*m+j] : 
    aijn, (a, b, i, j, n+1, m) * aijn, (a, b, n, n, n+1, m) - 
    aijn, (a, b, i, n, n+1, m) * aijn, (a, b, n, j, n+1, m); 
}, (double* a, double* b, int i, int j, int n, int m){return 1.;})

RECURSIVE_4_CALLS(double bin, (double* a, double* b, int i, int n, int m){ 
  return (n == m) ? b[i] : 
    aijn, (a, b, n, n, n+1, m) * bin, (a, b, i, n+1, m) - 
    aijn, (a, b, i, n, n+1, m) * bin, (a, b, n, n+1, m);
}, (double* a, double* b, int i, int n, int m){return 1.;})

#define SOLVE_X(A, B, X, I, M) \
  double d = bin_0(A, B, I, (I+1), M); \
  LOOP_TO(j, 0, (I)-1, d-=aijn_0(A, B, I, j, (I+1), M)*X[j];); \
  X[I] = d / aijn_0(A, B, I, I, (I+1), M);

#define STATIC_SOLVE(A, B, X) \
  int m = sizeof(X) / sizeof(X[0]); \
  LOOP_TO(k, 0, m-1, SOLVE_X(A, B, X, k, m););

#include "stdio.h"
#include "stdlib.h"

int main(){
  double a[9] = {
    1., -2.,  3., 
    2.,  1.,  1., 
   -3.,  2., -2.
  };
  double b[3] = {
    7.,  4.,  -10.
  };
  double x[3]; // 2, -1, 1
  STATIC_SOLVE(a, b, x);
  printf("%f, %f, %f\n", x[0], x[1], x[2]);
}

