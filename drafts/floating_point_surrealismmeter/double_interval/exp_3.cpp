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
double get_prognosed_worst_relative_error(std::array<double, 3> xs) {
    auto roots = xs;
    std::sort(roots.begin(), roots.end());
    auto roots_back = solve_cubic(cubic_for_roots(xs));
    std::sort(roots_back.begin(), roots_back.end());
    double worst_relative_error = 0.;
    for(auto i = 0u; i < 3; ++i) {
        if (std::isnan(roots_back[i]))
            return -1.; // root lost
        double absolute_error = std::abs(roots_back[i].to - roots_back[i].from);
        double relative_error = absolute_error / roots[i].original;
        worst_relative_error = std::max(worst_relative_error, relative_error);
    }
    return worst_relative_error;
}

int main() {
   for(auto i1 = 0; i1 <= 10; ++i1) {
       std::cout << "[\n";
       for(auto i2 = 0; i2 <= 10; ++i2) {
          std::cout << "[";
           for(auto i3 = 0; i3 <= 10; ++i3) {
               auto roots = std::array<double, 3> {{
                   1. * std::pow(100., i1 - 5), 
                   2. * std::pow(100., i2 - 5), 
                   3. * std::pow(100., i3 - 5) 
               }};
               std::cout << get_prognosed_worst_relative_error(roots) << ((i3 < 10) ? ",\t" : "");
           }   
           std::cout << "]" << ((i2 < 10) ? ", \n" : "\n");
       }
       std::cout << "]" << ((i1 < 10) ? ", \n" : "\n");
   }
   return 0;
}

