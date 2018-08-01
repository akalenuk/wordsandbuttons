#include "trie.h"

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

int main() {
    std::vector<std::string> unsorteds = {"cat", "pat", "bed"};
    // primitive tests for set
    Trie::Set<4> trie_set;
    for(const auto& s : unsorteds)
        trie_set.store(s.c_str());

    for(const auto& s : unsorteds)
        assert(trie_set.contains(s.c_str()));

    assert(! trie_set.contains("not"));

    // primitive tests for map
    Trie::Map<std::string, 4> trie_map;
    for(const auto& s : unsorteds)
        trie_map.store(s.c_str(), s);

    for(const auto& s : unsorteds)
        assert(s == trie_map.retrieve(s.c_str()).second);
    
    assert(! trie_map.retrieve("not").first);
    assert( trie_map.retrieve("not").second == "");

    // sort test
    std::vector<std::string> sorted;
    Trie::Set<4>::fill_vector_sorted(&trie_set, sorted);
    for(const auto& s : sorted)
        std::cout << s << "\n";
    return 0;
}

