all:
	clang++ -std=c++14 -O2 -o test main.cpp
debug:
	clang++ -std=c++14 -g -O0 -o test main.cpp
profile:
	g++ -std=c++14 -pg -O2 -o test main.cpp
disassembly:
	clang++ -std=c++14 -g -O2 -S -o test.s main.cpp
clean:
	rm test
