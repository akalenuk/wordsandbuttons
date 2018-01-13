#incude "static_loops.h"
#incude "static_recursion.h"

RECURSIVE_4_CALLS(double aijn, (double* a, double* b, int i, int j, int n, int m){ 
  return (n == m) ? a[i*m+i] : 
    aijn, (a, b, i, j, n+1, m) * aijn, (a, b, n, n, n+1, m) - 
    aijn, (a, b, i, n, n+1, m) * aijn, (a, b, n, j, n+1, m); 
}, (double* a, double* b, int i, int j, int n, int m){return 0.})

RECURSIVE_4_CALLS(double bin, (double* a, double* b, int i, int n, int m){ 
  return (n == m) ? b[i] : 
    aijn, (a, b, n, n, n+1, m) * bin, (a, b, i, n+1, m) - 
    aijn, (a, b, i, n, n+1, m) * bin, (a, b, n, n+1, m);
}, (double* a, double* b, int i, int n, int m){return 0.})

#define SOLVE_X(A, B, X, I, M) \
  double d = bin(A, B, I, (I+1), M); \
  LOOP_TO(j, 0, I-1, d-=aijn(A, B, I, j, (I+1), M)*X[j];); \
  X[I] = d / aijn(A, B, I, I, (I+1), M);

#define STATIC_SOLVE(A, B, X) \
  int m = sizeof(X) / sizeof(X[0]); \
  LOOP_TO(k, 0, m-1, SOLVE_X(&A[0][0], B, X, k, m););

#include "stdio.h"
#include "stdlib.h"

int main(){
  double a[3][3] = {{4., 2., 5.}, {1., 6., 4.}, {6. ,2. ,7. }};
  double b[3] = {5., 3., 1.};
  double x[3];
  STATIC_SOLVE(a, b, x);
  printf("%f %f %f", x[0], x[1], x[2]);
}

