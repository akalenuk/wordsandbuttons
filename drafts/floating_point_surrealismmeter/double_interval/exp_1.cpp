#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>

#include "double_interval.hpp"

// substitute double with DoubleInterval and include the unsuspecting solver
#define double DoubleInterval
#include "cubic_solver.hpp"


// test
void test_roots(std::array<double, 3> xs) {
    auto roots = xs;
    std::sort(roots.begin(), roots.end());
    auto roots_back = solve_cubic(cubic_for_roots(roots));
    std::sort(roots_back.begin(), roots_back.end());
    std::cout << "roots before: " << roots[0].original << " " << roots[1].original << " " << roots[2].original << "\n";
    std::cout << "roots after: " << roots_back[0].original << " " << roots_back[1].original << " " << roots_back[2].original << "\n";
    std::cout << "factial error: " << std::abs(roots_back[0].original - roots[0].original) << " " << std::abs(roots_back[1].original - roots[1].original) << " " << std::abs(roots_back[2].original - roots[2].original) << "\n";
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

