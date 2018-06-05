#include <array>
#include <cmath>
#include <iostream>
#include <limits>

#include "double_interval.hpp"

const double PI = std::atan(1.) * 4.;

#define double DoubleInterval

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

int main() {
    auto roots = solve_cubic({-4., -3., 2., 1.});
    std::cout << "actual: " << roots[0] << " " << roots[1] << " " << roots[2] << "\n";
    std::cout << "error: " << roots[0].to - roots[0].from << " " << roots[1].to - roots[1].from << " " << roots[2].to - roots[2].from << "\n";
    std::cout << "expected: -1 0.640388 -0.390388" << "\n";
}

