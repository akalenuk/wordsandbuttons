#include "stdio.h"

double aijn(double* a, double* b, int i, int j, int n, int m){
  return (n == m) ? a[i*m+j] : 
    aijn(a, b, i, j, n+1, m) * aijn(a, b, n, n, n+1, m) - 
    aijn(a, b, i, n, n+1, m) * aijn(a, b, n, j, n+1, m);
}

double bin(double* a, double* b, int i, int n, int m){ 
  return (n == m) ? b[i] : 
    aijn(a, b, n, n, n+1, m) * bin(a, b, i, n+1, m) - 
    aijn(a, b, i, n, n+1, m) * bin(a, b, n, n+1, m);
}

void solve_xi(double* a, double* b, double* x, int i, int m){
  double d = bin(a, b, i, i+1, m); 
  for(int j = 0; i < i-1; ++j)
    d-=aijn(a, b, i, j, i+1, m)*x[j];
  x[i] = d / aijn(a, b, i, i, i+1, m);
}

void runtime_solve(double* a, double * b, double* x, int m){
  for(int k = 0; k < m-1; ++k)
    solve_xi(a, b, x, k, m);
}

int main() {
    double a[5*5] = {
        6.80, -6.05, -0.45,  8.32, -9.67,
       -2.11, -3.30,  2.58,  2.71, -5.14,
        5.66,  5.36, -2.70,  4.35, -7.26,
        5.97, -4.44,  0.27, -7.17,  6.08,
        8.23,  1.08,  9.04,  2.14, -6.87
    };
    double b[5] = {
        4.02,  6.19, -8.22, -7.57, -3.03,
    };
    
    double x[5];

    runtime_solve(a, b, x, sizeof(x) / sizeof(x[0]));
    printf("%f, %f, %f, %f, %f\n", x[0], x[1], x[2], x[3], x[4]);
}

