#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

double sum(const std::vector<double>& xs) {
    return std::accumulate(xs.begin(), xs.end(), 0.);
}

double sorted_sum(const std::vector<double>& xs) {
    std::vector<double> sorted_xs(xs);
    std::sort(sorted_xs.begin(), sorted_xs.end());
    return std::accumulate(sorted_xs.begin(), sorted_xs.end(), 0.);
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
    // compare kahan sum with simple sum and sorted sum
    const auto ks = kahan_sum(xs);
    const auto s = sum(xs);
    const auto ss = sorted_sum(xs);
    std::cout << "Kahan sum: " << ks << "\n";
    std::cout << "accumulated sum: " << s << "\n";
    std::cout << "accumulated sorted sum: " << s << "\n\n";
    std::cout << "difference between Kahan and sum: " << std::abs(s - ks) << "\n";
    std::cout << "difference between Kahan and sorted sum: " << std::abs(ss - ks) << "\n";
    std::cout << "difference between sum and sorted sum: " << std::abs(s - ss) << "\n";
}

