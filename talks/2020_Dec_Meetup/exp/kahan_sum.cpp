#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

double sum(const std::vector<double>& xs) {
    return std::accumulate(xs.begin(), xs.end(), 0.);
}

double kahan_sum(const std::vector<double>& xs) {
    double sum = 0.;
    double c = 0.;
    for (auto x : xs) {
        double y = x - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

int main() {
    constexpr auto TheSize = 1'000'000;
    using TheType = double;

    std::mt19937 rng(0);
    std::uniform_real_distribution<TheType> distribution(0, 1'000'000);
    std::vector<TheType> xs(TheSize);
    for (TheType &x : xs) {
        x = distribution(rng);
    }
    const auto ks = kahan_sum(xs);
    const auto s = sum(xs);
    const auto error = std::abs(s - ks);
    std::cout << "Kahan sum: " << ks << "\n";
    std::cout << "accumulated sum: " << s << "\n";
    std::cout << "error: " << error << "\n";
}

