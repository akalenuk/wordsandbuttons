#include <chrono>
#include <iostream>
#include <random>
#include <array>

const double pi = std::atan(1) * 4.;
const double tau = 2.*pi;

int main() {
    constexpr auto n = 10000000;
    std::mt19937 rng(0);
    std::uniform_real_distribution<double> distribution(-10., 10.);
    std::vector<double> xs(n);
    for (auto &x : xs) {
        x = distribution(rng);
    }

    constexpr auto lookup_n = 100;
    std::array<double, lookup_n> lookup;
    for(auto i = 0u; i < lookup_n; ++i)
        lookup[i] = sin(static_cast<double>(i) / static_cast<double>(lookup_n));

    if(true) {
        auto start = std::chrono::system_clock::now();
        double sum  = 0.;
        for (auto i = 0u; i < n; ++i)
            sum += std::sin(xs[i]);
        auto end = std::chrono::system_clock::now();
        std::cout << "sin time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
    }
    if(true) {
        auto start = std::chrono::system_clock::now();
        double sum  = 0.;
        for (auto i = 0u; i < n; ++i) {
            const auto xi = xs[i];
            const auto in_2pi = (xi / tau - std::floor(xi / tau))*tau;
            const auto abs_in_2pi = std::abs(in_2pi);
            float sign_in_2pi = in_2pi < 0 ? -1.f: 1.f;
            float x = 0.f;
            if(abs_in_2pi > 1.5*pi) {
                x = static_cast<float>(pi/2. - (abs_in_2pi - 1.5*pi));
                sign_in_2pi *= -1.f;
            } else if(abs_in_2pi > 1.*pi) {
                x = static_cast<float>(abs_in_2pi - 1.*pi);
                sign_in_2pi *= -1.f;
            } else if(abs_in_2pi > 0.5*pi) {
                x = static_cast<float>(pi - abs_in_2pi);
            } else {
                x = static_cast<float>(abs_in_2pi);
            }
            const auto sine = ((-0.000182690409228785f*x*x+0.00830460224186793f)*x*x-0.166651012143690f)*x*x*x+x;
            sum += sine;
        }
        auto end = std::chrono::system_clock::now();
        std::cout << "polynomial time: " << (end-start).count() * 1e-9  << "  sum: " << sum << "\n";
    }
}
