
#include "static_linear_solver.hpp"

#include <iostream>

int main() {
    const auto a = std::array<std::array<double, 5>, 5>{{
        { 6.80, -6.05, -0.45,  8.32, -9.67},
        {-2.11, -3.30,  2.58,  2.71, -5.14},
        { 5.66,  5.36, -2.70,  4.35, -7.26},
        { 5.97, -4.44,  0.27, -7.17,  6.08},
        { 8.23,  1.08,  9.04,  2.14, -6.87}
    }};    
    const auto b = std::array<double, 5>
        {4.02,  6.19, -8.22, -7.57, -3.03};
    auto x = std::array<double, 5> {};
    auto ss_solved = linear_equations::semi_static::solve<5>(a, b, x);
    if(!ss_solved)
        return 1;
    
    std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << ' ' << x[4] << '\n';
    return 0;
}

