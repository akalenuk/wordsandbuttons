#define LOOP_TO_0(ID, N, BODY) {int ID; switch(N){\
case 7: ID=7;{BODY};\
case 6: ID=6;{BODY};\
case 5: ID=5;{BODY};\
case 4: ID=4;{BODY};\
case 3: ID=3;{BODY};\
case 2: ID=2;{BODY};\
case 1: ID=1;{BODY};\
case 0: ID=0;{BODY};\
}}

#define LOOP_TO(ID, START, END, BODY) \
  LOOP_TO_0(ID, (END)-(START), ID=(END)-ID; BODY)

#define LOOP_DOWNTO(ID, START, END, BODY) \
  LOOP_TO_0(ID, (START)-(END), ID=(END)+ID; BODY)

double aijn(double* a, double* b, int i, int j, int n, int m){
  return (n == m) ? a[i*m+i] : 
    aijn(a, b, i, j, n+1, m) * aijn(a, b, n, n, n+1, m) - 
    aijn(a, b, i, n, n+1, m) * aijn(a, b, n, j, n+1, m);
}

double bin(double* a, double* b, int i, int n, int m){ 
  return (n == m) ? b[i] : 
    aijn(a, b, n, n, n+1, m) * bin(a, b, i, n+1, m) - 
    aijn(a, b, i, n, n+1, m) * bin(a, b, n, n+1, m);
}

#define SOLVE_X(A, B, X, I, M) \
  double d = bin(A, B, I, I+1, M); \
  LOOP_TO(j, 0, I-1, d-=aijn(A, B, I, j, I+1, M)*X[j];); \
  X[I] = d / aijn(A, B, I, I, I+1, M);

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

