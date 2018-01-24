
#include "static_linear_solver.hpp"

#include <iostream>

int main() {
    auto sum_x = std::array<double, 5> {0., 0., 0., 0., 0.};
    for(auto i = 0u; i < 1000 * 1000; ++i){
        auto v_a = std::array<std::array<volatile double, 5>, 5>{{
            { 6.80, -6.05, -0.45,  8.32, -9.67},
            {-2.11, -3.30,  2.58,  2.71, -5.14},
            { 5.66,  5.36, -2.70,  4.35, -7.26},
            { 5.97, -4.44,  0.27, -7.17,  6.08},
            { 8.23,  1.08,  9.04,  2.14, -6.87}
        }};    
        auto v_b = std::array<volatile double, 5>
            {4.02,  6.19, -8.22, -7.57, -3.03};
            
        const auto a = std::array<std::array<double, 5>, 5>{{
            {v_a[0][0], v_a[0][1], v_a[0][2], v_a[0][3], v_a[0][4]},
            {v_a[1][0], v_a[1][1], v_a[1][2], v_a[1][3], v_a[1][4]},
            {v_a[2][0], v_a[2][1], v_a[2][2], v_a[2][3], v_a[2][4]},
            {v_a[3][0], v_a[3][1], v_a[3][2], v_a[3][3], v_a[3][4]},
            {v_a[4][0], v_a[4][1], v_a[4][2], v_a[4][3], v_a[4][4]}
        }};    
        const auto b = std::array<double, 5>
            {v_b[0], v_b[1], v_b[2], v_b[3], v_b[4]};
        auto x = std::array<double, 5> {};
        linear_equations::semi_static::solve<5>(a, b, x);
             
        for(auto j = 0u; j < 5; ++j)
            sum_x[j] += x[j];
    } 
    std::cout << sum_x[0] << ' ' << sum_x[1] << ' ' << sum_x[2] << ' ' << sum_x[3] << ' ' << sum_x[4] << '\n';
    return 0;
}

