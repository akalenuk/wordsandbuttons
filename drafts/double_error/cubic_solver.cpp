#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>

#include "double_interval.hpp"

#define double DoubleInterval

// calculation part
const double PI = std::atan(1.) * 4.;

std::array<double, 4> cubic_for_roots(std::array<double, 3> xs) {
    // ax^3 + bx^2 + cx + d = 0 ; a = 1
    // (x - x1)(x - x2)(x - x3) = 0
    // x^3 - x^2 x1 - x^2 x2 - x^2 x3 + x x1 x2 + x x1 x3 + x x2 x3 - x1 x2 x3 = 0
    // x^3 - (x1 + x2 + x3) x^2 + (x1x2 + x2x3 + x3x1) x - x1x2x3 = 0
    return {1.
    , - (xs[0] + xs[1] + xs[2])
    , + (xs[0] * xs[1] + xs[1] * xs[2] + xs[2] * xs[0])
    , - (xs[0] * xs[1] * xs[2])};
}

std::array<double, 3> solve_cubic(std::array<double, 4> abcd) {
    double a1 = abcd[1] / abcd[0];
    double a2 = abcd[2] / abcd[0];
    double a3 = abcd[3] / abcd[0];
    double q = (a1 * a1 - 3. * a2) / 9.;
    double sq = -2. * std::sqrt(q);
    double r = (2. * a1 * a1 * a1 - 9. * a1 * a2 + 27. * a3) / 54.0;
    double z = r * r - q * q * q;

    std::array<double, 3> roots;
    if(z <= 0) {
        double t = std::acos(r / std::sqrt(q * q * q));
        roots[0] = sq * std::cos(t / 3.) - a1 / 3.;
        roots[1] = sq * std::cos((t + 2. * PI) / 3.) - a1 / 3.;
        roots[2] = sq * std::cos((t + 4. * PI) / 3.) - a1 / 3.;
    } else {
        roots[0] = pow(std::sqrt(z) + std::abs(r) , 1. / 3.);
        roots[0] += q / roots[0];
        roots[0] *= ( r < 0 ) ? 1 : -1;
        roots[0] -= a1 / 3.;
        roots[1] = std::numeric_limits<double>::quiet_NaN();
        roots[2] = std::numeric_limits<double>::quiet_NaN();
    }
    return roots;
}


// testing part
void test_roots(std::array<double, 3> xs) {
    auto roots_back = solve_cubic(cubic_for_roots(xs));
    std::sort(roots_back.begin(), roots_back.end());
    std::cout << "roots before: " << xs[0] << " " << xs[1] << " " << xs[2] << "\n";
    std::cout << "roots after: " << roots_back[0] << " " << roots_back[1] << " " << roots_back[2] << "\n";
    std::cout << "factial error: " << std::abs(roots_back[0] - xs[0]) << " " << std::abs(roots_back[1] - xs[1]) << " " << std::abs(roots_back[2] - xs[2]) << "\n";
    std::cout << "prognosed error: " << roots_back[0].to - roots_back[0].from << " " << roots_back[1].to - roots_back[1].from << " " << roots_back[2].to - roots_back[2].from << "\n";    
    std::cout << "\n";
}

int main() {
    test_roots({1., 2., 3.});
    test_roots({0.1, 2., 30.});
    test_roots({0.01, 2., 300.});
    test_roots({0.001, 2., 3000.});
    test_roots({0.0001, 2., 30000.});
    test_roots({0.00001, 2., 300000.});
    test_roots({0.000001, 2., 3000000.});
    test_roots({0.0000001, 2., 30000000.});
    test_roots({0.00000001, 2., 300000000.});
    test_roots({0.000000001, 2., 3000000000.});    
}

