#pragma once

#include <array>
#include <string>
#include <vector>

namespace Trie {
    template <unsigned int RADIX_BITS> 
    struct ConstantsFor {
        static_assert(RADIX_BITS == 1 || RADIX_BITS == 2 || RADIX_BITS == 4 || RADIX_BITS == 8, "Radix size should be power of 2 and not bigger than 8");
        constexpr static unsigned int mask(unsigned int radix_bits){
            return (radix_bits == 1) ? 1 : (1 + (mask(radix_bits - 1) << 1));
        }
        constexpr static unsigned int pow_of_2(unsigned int exp){
            return (exp == 1) ? 2 : (2 * pow_of_2(exp - 1));
        }
        constexpr static unsigned int radix_mask = mask(RADIX_BITS);
        constexpr static unsigned int steps_in_byte = 8 / RADIX_BITS;
        constexpr static unsigned int subtrie_size = pow_of_2(RADIX_BITS);
    };



    template <unsigned int RADIX_BITS> 
    struct Set : public ConstantsFor <RADIX_BITS>{
        std::array<Set*, ConstantsFor<RADIX_BITS>::subtrie_size> subtries = {{nullptr}};
        unsigned int elements_counter = 0u;

        ~Set(){
            for(auto trie : subtries)
                if(trie != nullptr)
                    delete trie;
        }

        void store(const std::string& key){
            Set* trie = this;
            for(auto i = 0u; i < key.size(); ++i) {
                for(auto j = 0u; j < ConstantsFor<RADIX_BITS>::steps_in_byte; ++j){
                    const int shifted_c = key[i] >> (8 - (j + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if(trie->subtries[radix0] == nullptr){
                        trie->subtries[radix0] = new Set();
                    }
                    trie = trie->subtries[radix0];
                }
            }
            ++trie->elements_counter;
        }

        bool contains(const std::string& key){
            Set* trie = this;
            for(auto i = 0u; i < key.size(); ++i) {
                for(auto j = 0u; j < ConstantsFor<RADIX_BITS>::steps_in_byte; ++j){
                    const int shifted_c = key[i] >> (8 - (j + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if (trie->subtries[radix0] == nullptr)
                        return false;
                    trie = trie->subtries[radix0];
                }
            }
            return true;
        }


        static void fill_vector_sorted(Set* trie, std::vector<std::string>& sorted) {
            std::string key;
            key.resize(256);
            fill_vector_sorted(trie, sorted, key, 0);
        }

private:
        static void fill_vector_sorted(Set* trie, std::vector<std::string>& sorted, std::string& key, int depth) {
            const auto byte_idx = depth / ConstantsFor<RADIX_BITS>::steps_in_byte;
            const auto radix_idx = depth % ConstantsFor<RADIX_BITS>::steps_in_byte;
            for(auto i = 0u; i < trie->elements_counter; ++i) {
                sorted.emplace_back(key.begin(), key.begin() + byte_idx);
            }
            for(auto i = 0u; i < ConstantsFor<RADIX_BITS>::subtrie_size; ++i) {
                if(trie->subtries[i] != nullptr) {
                    int c = key[byte_idx];
                    c  >>= ((ConstantsFor<RADIX_BITS>::steps_in_byte - radix_idx) * RADIX_BITS);
                    c <<= RADIX_BITS;
                    c |= i;
                    c <<= (ConstantsFor<RADIX_BITS>::steps_in_byte - radix_idx - 1) * RADIX_BITS;
                    key[byte_idx] = static_cast<char>(c);
                    fill_vector_sorted(trie->subtries[i], sorted, key, depth + 1);
                }
            }
        }
    };



    template <class T, unsigned int RADIX_BITS> 
    struct Map : public ConstantsFor <RADIX_BITS>{
        std::array<Map*, ConstantsFor<RADIX_BITS>::subtrie_size> subtries = {{nullptr}};
        T value;

        ~Map(){
            for(auto trie : subtries)
                if(trie != nullptr)
                    delete trie;
        }

        void store(const std::string& key, T value){
            Map* trie = this;
            for(auto i = 0u; i < key.size(); ++i) {
                for(auto j = 0; j < ConstantsFor<RADIX_BITS>::steps_in_byte; ++j){
                    const int shifted_c = key[i] >> (8 - (j + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if(trie->subtries[radix0] == nullptr){
                        trie->subtries[radix0] = new Map();
                    }
                    trie = trie->subtries[radix0];
                }
            }
            trie->value = value;
        }

        std::pair<bool, T> retrieve(const std::string& key){
            Map* trie = this;
            for(auto i = 0; i < key.size(); ++i){
                for(auto j = 0; j < ConstantsFor<RADIX_BITS>::steps_in_byte; ++j){
                    const int shifted_c = key[i] >> (8 - (j + 1) * RADIX_BITS);
                    const int radix0 = shifted_c & ConstantsFor<RADIX_BITS>::radix_mask;
                    if (trie->subtries[radix0] == nullptr)
                        return {false, T()};
                    trie = trie->subtries[radix0];
                }
            }
            return {true, trie->value};
        }
    };
}

