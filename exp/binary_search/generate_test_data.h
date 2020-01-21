#include <algorithm>
#include <random>
#include <vector>


vector<int> generate_uniform_random(size_t how_much, int from, int to) {
    vector<int> ints(how_much);
    std::random_device rng;
    std::uniform_int_distribution<int> randoms(from, to);
    for(auto& i : ints)
        i = randoms(rng);
    std::sort(ints.begin(), ints.end());
    return ints;
}

