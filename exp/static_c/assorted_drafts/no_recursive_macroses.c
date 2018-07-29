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

#define SOLVE_A(A, B, I, J, N) \
  ((N == sizeof(B)/sizeof(B[0])) ? A[I][I] : \
    SOLVE_A(A, B, I, J, N+1) * SOLVE_A(A, B, N, N, N+1) - \
    SOLVE_A(A, B, I, N, N+1) * SOLVE_A(A, B, N, J, N+1))

#define SOLVE_B(A, B, I, N) \
  ((N == sizeof(B)/sizeof(B[0])) ? B[I] : \
    SOLVE_A(A, B, N, N, N+1) * SOLVE_B(A, B, I, N+1) - \
    SOLVE_A(A, B, I, N, N+1) * SOLVE_B(A, B, N, N+1))

#define SOLVE_X(A, B, X, I) \
  double d = SOLVE_B(A, B, I, I+1); \
  LOOP_TO(j, 0, I-1, d-=SOLVE_A(A, B, I, j, I+1)*X[j];); \
  X[I] = d / SOLVE_A(A, B, I, I, I+1);

#define STATIC_SOLVE(A, B, X) \
  LOOP_TO(k, 0, sizeof(X)/sizeof(X[0])-1, SOLVE_X(A, B, X, k););

#include "stdio.h"
#include "stdlib.h"

int main(){
  double a[3][3] = {{4., 2., 5.}, {1., 6., 4.}, {6.,2.,7.}};
  double b[3] = {5., 3., 1.};
  double x[3];
  STATIC_SOLVE(a, b, x);
  printf("%f %f %f", x[0], x[1], x[2]);
}

