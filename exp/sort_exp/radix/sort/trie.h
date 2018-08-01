#pragma once

#include <array>

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
        constexpr static unsigned int subtree_size = pow_of_2(RADIX_BITS);
    };

    template <class T, unsigned int RADIX_BITS> 
    struct Map : public ConstantsFor <RADIX_BITS>{
        std::array<Map*, ConstantsFor<RADIX_BITS>::subtree_size> subtries{nullptr};
        T value;

        ~Map(){
            for(auto trie : subtries){
                if(trie != nullptr){
                    delete trie;
                }
            }
        }

        void set(const char* key, T value){
            Map* trie = this;
            while(key[0] != '\0'){
                char c = key[0];
                for(unsigned int i = 0; i < ConstantsFor<RADIX_BITS>::steps_in_byte; i++){
                    int radix0 = c & ConstantsFor<RADIX_BITS>::radix_mask;
                    c = c >> RADIX_BITS;
                    if(trie->subtries[radix0] == nullptr){
                        trie->subtries[radix0] = new Map();
                    }
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            trie->value = value;
        }

        T get(const char* key){
            Map* trie = this;
            while(key[0] != '\0'){
                char c = key[0];
                for(unsigned int i = 0; i < ConstantsFor<RADIX_BITS>::steps_in_byte; i++){
                    int radix0 = c & ConstantsFor<RADIX_BITS>::radix_mask;
                    c = c >> RADIX_BITS;
                    trie = trie->subtries[radix0];
                }
                key++;
            }
            return trie->value;
        }
    };
}

