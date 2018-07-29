#ifndef TRIE_4_H_INCLUDED
#define TRIE_4_H_INCLUDED

typedef void** Trie;

Trie new_trie();
void put_pointer_to_trie(char* key, void* pointer, Trie trie);
void* get_pointer_from_trie(char* key, Trie trie);
void delete_trie(Trie trie);

#endif // TRIE_4_H_INCLUDED
