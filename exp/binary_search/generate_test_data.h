#include <algorithm>
#include <random>
#include <vector>

const double PI = 3.141592653589793;

std::vector<int> uniform(size_t how_much, int from, int to) {
    std::vector<int> ints(how_much);
    for(auto i = 0u; i < how_much; ++i)
        ints[i] = from + static_cast<int>(static_cast<int64_t>(to - from) * (i + 1) / how_much);
    return ints;
}

std::vector<int> uniform_random(size_t how_much, int from, int to) {
    std::vector<int> ints(how_much);
    std::random_device rng;
    std::uniform_int_distribution<int> randoms(from, to);
    for(auto& i : ints)
        i = randoms(rng);
    std::sort(ints.begin(), ints.end());
    return ints;
}

std::vector<int> skewed_to_high_end_random(size_t how_much, int from, int to) {
    std::vector<int> ints(how_much);
    std::random_device rng;
    std::uniform_real_distribution<double> randoms(0., 1.);
    for(auto& i : ints) {
        double d = sin(randoms(rng) * PI / 2.);
        i = static_cast<int>(from + (to - from) * d);
        }
    std::sort(ints.begin(), ints.end());
    return ints;
}

std::vector<int> less_in_the_middle_random(size_t how_much, int from, int to) {
    std::vector<int> ints(how_much);
    std::random_device rng;
    std::uniform_real_distribution<double> randoms(0., 1.);
    for(auto& i : ints) {
        double d = (sin(randoms(rng) * PI - PI / 2.) + 1.) / 2.;
        i = static_cast<int>(from + (to - from) * d);
        }
    std::sort(ints.begin(), ints.end());
    return ints;
}

