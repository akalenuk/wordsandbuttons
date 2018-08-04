all:
	clang++ -std=c++14 -O2 -o trie_tests tests.cpp
debug:
	clang++ -std=c++14 -g -O0 -o trie_tests tests.cpp
profile:
	g++ -std=c++14 -pg -O2 -o trie_tests tests.cpp
disassembly:
	clang++ -std=c++14 -g -O2 -S -o trie_tests.s tests.cpp
clean:
	rm trie_tests
