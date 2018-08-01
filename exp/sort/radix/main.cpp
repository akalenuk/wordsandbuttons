#include "trie.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

int main() {
    std::vector<std::string> unsorted = {"cat", "pat", "bed", "test", "test but longer"};
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

    return 0;
}

