#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <iostream>

namespace linear_equations{
    namespace semi_static{
        template <int I, int J, int K, int N>
        __attribute__((always_inline)) inline static double aij(const std::array<std::array<double, N>, N>& a){
            if(K == N) return a[I][J];
            return aij<I, J, K+(K<N), N>(a) * aij<K, K, K+(K<N), N>(a) - aij<I, K, K+(K<N), N>(a) * aij<K, J, K+(K<N), N>(a);
        }

        template <int I, int K, int N>
        __attribute__((always_inline)) inline static double bi(const std::array<std::array<double, N>, N>& a, const std::array<double, N>& b){
            if(K == N) return b[I];
            return aij<K, K, K+(K<N), N>(a) * bi<I, K+(K<N), N>(a, b) - aij<I, K, K+(K<N), N>(a) * bi<K, K+(K<N), N>(a, b);
        }

        template <int J, int I, int N>
        __attribute__((always_inline)) inline static void d_for(double& d, const std::array<std::array<double, N>, N>& a, std::array<double, N>& x){
            if(J < I){
                d -= aij<I, J, I+(J<I), N>(a) * x[J];
                d_for<J+(J<I), I, N>(d, a, x);
            }
        }

        template <int I, int N>
        __attribute__((always_inline)) inline static double di(const std::array<std::array<double, N>, N>& a, const std::array<double, N>& b, std::array<double, N>& x){
            double d = bi<I, I+1, N>(a, b);
            d_for<0, I, N>(d, a, x);
            return d;
        }

        template <int I, int N>
        __attribute__((always_inline)) inline static void x_for(const std::array<std::array<double, N>, N>& a, const std::array<double, N>& b, std::array<double, N>& x){
            if(I < N){
                double d = di<I, N>(a, b, x);
                double aiji = aij<I, I, I+1, N>(a);
                x[I] = d / aiji;
                x_for<I+(I<N), N>(a, b, x);
            }
        }

        template <int N>
        __attribute__((always_inline)) inline static void solve(const std::array<std::array<double, N>, N>& a, const std::array<double, N>& b, std::array<double, N>& x){
            x_for<0, N>(a, b, x);
        }
    }
}

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


