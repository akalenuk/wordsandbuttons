#include "trie.h"

#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <chrono>


void functional_tests() {
    std::vector<std::string> unsorted = {"cat", "pat", "bed", "test", "test but longer", "test"};
    std::vector<std::string> std_sorted(unsorted.begin(), unsorted.end());
    std::sort(std_sorted.begin(), std_sorted.end());
    Trie::Set<4> trie_set;
    for(const auto& s : unsorted)
        trie_set.store(s.c_str());

    // sort test
    std::vector<std::string> sorted;
    Trie::Set<4>::fill_vector_sorted(&trie_set, sorted);
    for(auto i =0u; i < unsorted.size(); ++i)
        assert(sorted[i] == std_sorted[i]);

    // primitive tests for set
    for(const auto& s : unsorted)
        assert(trie_set.contains(s.c_str()));

    assert(! trie_set.contains("not"));

    // primitive tests for map
    Trie::Map<std::string, 4> trie_map;
    for(const auto& s : unsorted)
        trie_map.store(s.c_str(), s);

    for(const auto& s : unsorted)
        assert(s == trie_map.retrieve(s.c_str()).second);
    
    assert(! trie_map.retrieve("not").first);
    assert( trie_map.retrieve("not").second == "");
}

template <unsigned int RADIX_BITS> 
void radix_sort_performance_print(const std::vector<std::string>& words) {
    auto radix_start = std::chrono::high_resolution_clock::now();
    Trie::Set<RADIX_BITS> trie;
    for(const auto& word : words)
        trie.store(word.c_str());
    std::vector<std::string> sorted_words;
    sorted_words.reserve(words.size());
    Trie::Set<RADIX_BITS>::fill_vector_sorted(&trie, sorted_words);
    auto radix_sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - radix_start).count();
    std::cout << "   radix " << RADIX_BITS << " sort - " << radix_sort_duration << "\n";
 }


void sort_performance_prints() {
    // load a dictionary
    std::ifstream dict("en-US.dic");
    std::vector<std::string> reversed_words;
    std::string word;
    while (std::getline(dict, word)) {
        std::string reversed_word(word.rbegin(), word.rend());
        reversed_words.push_back(reversed_word);
    }
    // inflate 64 times
    for(auto i = 0u; i < 6; ++i) {
        auto halfsize = reversed_words.size();
        for(auto j = 0u; j < halfsize; ++j)
            reversed_words.push_back(reversed_words[j]);
    }
    

    // std::sort
    auto std_start = std::chrono::high_resolution_clock::now();
    std::vector<std::string> std_sorted_reversed_words(reversed_words.begin(), reversed_words.end());
    std::sort(std_sorted_reversed_words.begin(), std_sorted_reversed_words.end());
    auto std_duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - std_start).count();
    std::cout << "   std::sort - " << std_duration << "\n";

    // radix sort
    radix_sort_performance_print<1>(reversed_words);
    radix_sort_performance_print<2>(reversed_words);
    radix_sort_performance_print<4>(reversed_words);
    radix_sort_performance_print<8>(reversed_words);
}

int main() {
    functional_tests();
    sort_performance_prints();
      
    return 0;
}

