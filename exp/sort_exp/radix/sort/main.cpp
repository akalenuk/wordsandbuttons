#include "trie.h"

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> unsorteds = {"cat", "pat", "bed"};
    Trie<std::string, 4> trie;
    for(const auto& s : unsorteds)
        trie.set(s.c_str(), s);

    for(const auto& s : unsorteds)
        std::cout << trie.get(s.c_str());
    return 0;
}

