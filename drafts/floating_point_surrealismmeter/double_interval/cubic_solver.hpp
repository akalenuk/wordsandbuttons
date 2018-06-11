#include <array>
#include <cmath>
#include <limits>
#include <algorithm>


// find roots for ax^3 + bx^2 + cx + d = 0
std::array<double, 3> solve_cubic(std::array<double, 4> abcd) {
    double PI = std::atan(1.) * 4.;

    double a1 = abcd[1] / abcd[0];
    double a2 = abcd[2] / abcd[0];
    double a3 = abcd[3] / abcd[0];
    double q = (a1 * a1 - 3. * a2) / 9.;
    double sq = -2. * std::sqrt(q);
    double r = (2. * a1 * a1 * a1 - 9. * a1 * a2 + 27. * a3) / 54.0;
    double z = r * r - q * q * q;

    std::array<double, 3> roots;
    if(z <= 0.) {
        double t = std::acos(r / std::sqrt(q * q * q));
        roots[0] = sq * std::cos(t / 3.) - a1 / 3.;
        roots[1] = sq * std::cos((t + 2. * PI) / 3.) - a1 / 3.;
        roots[2] = sq * std::cos((t + 4. * PI) / 3.) - a1 / 3.;
    } else {
        roots[0] = pow(std::sqrt(z) + std::abs(r) , 1. / 3.);
        roots[0] += q / roots[0];
        roots[0] *= ( r < 0. ) ? 1 : -1;
        roots[0] -= a1 / 3.;
        roots[1] = std::numeric_limits<double>::quiet_NaN();
        roots[2] = std::numeric_limits<double>::quiet_NaN();
    }
    return roots;
}

// find polynomial coefficients  b, c, and d (a is always 1) for the roots
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

