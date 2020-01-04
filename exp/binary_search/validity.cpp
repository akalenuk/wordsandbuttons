#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <chrono>
#include <map>
#include <random>

using namespace std::chrono;
using namespace std;

static const size_t NONE = std::numeric_limits<size_t>::max();

vector<int> uniform_random(size_t how_much, int from, int to) {
    vector<int> ints(how_much);
    std::random_device rng;
    std::uniform_int_distribution<int> randoms(from, to);
    for(auto& i : ints)
        i = randoms(rng);
    return ints;
}

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where, size_t from, size_t to) {
    if(where[from] == what)
        return from;
    if(to - from <= 1)      
      return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to-1);
    if(where[mid] < what)
        return find_if_any<percent>(what, where, mid + 1, to);
    return find_if_any<percent>(what, where, from, mid);
}

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where) {
    return find_if_any<percent>(what, where, 0, where.size() - 1);
}

int main() {
    const auto test_data = uniform_random(10, 0, 10-1);
    for(auto i = 0; i < 10; ++i)
        std::cout << test_data[i] << " ";
    std::cout << "\n";
    for(auto i = 0; i < 10; ++i) {
        auto index = find_if_any<50>(i, test_data);
        std::cout << i << " is in " << index << "\n";
    }
    return 0;
}

