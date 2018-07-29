#include "stdio.h"
#include "static_linear_solver.h"

int main() {
    double sum_x[5] = {0., 0., 0., 0., 0.};
    for(int i = 0; i < 1000000; ++i) {
        double a[5*5] = {
            6.80, -6.05, -0.45,  8.32, -9.67,
           -2.11, -3.30,  2.58,  2.71, -5.14,
            5.66,  5.36, -2.70,  4.35, -7.26,
            5.97, -4.44,  0.27, -7.17,  6.08,
            8.23,  1.08,  9.04,  2.14, -6.87
        };
        volatile double v_b[5] = {
            4.02,  6.19, -8.22, -7.57, -3.03,
        };    
        double b[5] = {
            v_b[0],  v_b[1], v_b[2], v_b[3], v_b[4],
        };
        
        double x[5];

        STATIC_SOLVE(a, b, x);
        for(int j = 0; j < 5; ++j){
            sum_x[j] += x[j];
        }
    }
    printf("%f, %f, %f, %f, %f\n", sum_x[0], sum_x[1], sum_x[2], sum_x[3], sum_x[4]);
}

