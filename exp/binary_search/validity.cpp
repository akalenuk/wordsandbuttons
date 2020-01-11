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
    std::sort(ints.begin(), ints.end());
    return ints;
}

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where, size_t from, size_t to) {
    if(where[from] == what)
        return from;
    if(to - from < 1)
        return NONE;
    size_t mid = from + (to - from) * percent / 100;
    mid = std::max(mid, from);
    mid = std::min(mid, to);
    if(where[mid] < what)
        return find_if_any<percent>(what, where, mid + 1, to);
    return find_if_any<percent>(what, where, from, mid);
}

template <int percent>
size_t find_if_any(const int what, const std::vector<int>& where) {
    return find_if_any<percent>(what, where, 0, where.size() - 1);
}

size_t find_if_any_ip(const int what, const std::vector<int>& where, size_t from, size_t to, size_t depth = 0) {
    if (where[from] == what)
        return from;
    if (where[to] == what)
        return to;
    double t = static_cast<double>(what - where[from]) / static_cast<double>(where[to] - where[from]);
    t = std::max(t, 0.);
    t = std::min(t, 1.);
    size_t mid = from + static_cast<size_t>((to - from) * t);
    if (mid == to || mid == from)
        return NONE;
    if (where[mid] < what)
        return find_if_any_ip(what, where, mid + 1, to, depth + 1);
    return find_if_any_ip(what, where, from, mid, depth + 1);
}

size_t find_if_any_ip(const int what, const std::vector<int>& where) {
    return find_if_any_ip(what, where, 0, where.size() - 1);
}


int main() {
    const auto test_data = uniform_random(10, 0, 10-1);
    std::cout << "\n";
    for(auto i = 0; i < 10; ++i) {
        auto index = find_if_any<50>(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "false positive!";
        if(index == NONE)
            for(auto j = 0u; j < 10; ++j)
                if(test_data[j] == i)
                   std::cout << "false negative!";
    }
    for(auto i = 0; i < 10; ++i) {
        auto index = find_if_any_ip(i, test_data);
        if(index != NONE && test_data[index] != i)
            std::cout << "false positive!";
        if(index == NONE)
            for(auto j = 0u; j < 10; ++j)
                if(test_data[j] == i)
                   std::cout << "false negative!";
    }
    return 0;
}

