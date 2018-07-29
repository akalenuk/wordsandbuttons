#ifndef TRIE_128_H_INCLUDED
#define TRIE_128_H_INCLUDED

typedef void** Trie;    // array of pointers. Each pointer corresponds to a certain radix value but 0. 0 means EOL and end of key, therefore used to store value

Trie new_trie();
void put_pointer_to_trie(char* key, void* pointer, Trie trie);
void* get_pointer_from_trie(char* key, Trie trie);
void delete_trie(Trie trie);

#endif // TRIE_128_H_INCLUDED
