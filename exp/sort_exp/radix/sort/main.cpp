#include "trie.h"

#include <iostream>
#include <vector>
#include <string>


int main() {
    std::vector<std::string> unsorteds = {"cat", "pat", "bed"};
    Trie::Map<std::string, 4> trie;
    for(const auto& s : unsorteds)
        trie.store(s.c_str(), s);

    for(const auto& s : unsorteds)
        std::cout << trie.retrieve(s.c_str()).second << "\n";
    return 0;
}

