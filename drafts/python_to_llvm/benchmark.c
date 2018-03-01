#include "stdio.h"

#define N 5

int main() {
    double sum_x[N] = {0., 0., 0., 0., 0.};
    for(int i = 0; i < 1000000; ++i) {
        double a[N*N] = {
         6.80, -2.11,  5.66,  5.97,  8.23,
        -6.05, -3.30,  5.36, -4.44,  1.08,
        -0.45,  2.58, -2.70,  0.27,  9.04,
         8.32,  2.71,  4.35, -7.17,  2.14,
        -9.67, -5.14, -7.26,  6.08, -6.87
        };
        double b[N] = {
            4.02,  6.19, -8.22, -7.57, -3.03,
        };
        double x[N];

        solve_5(a, b, x);
         
        for(int j = 0; j < 5; ++j){
            sum_x[j] += x[j];
        }
    }
    printf("%f, %f, %f, %f, %f\n", sum_x[0], sum_x[1], sum_x[2], sum_x[3], sum_x[4]);
}

