all:
	clang++ -O2 -std=c++14 -march=native div_vs_mul.cpp -o div_vs_mul
	./div_vs_mul
	rm ./div_vs_mul
s:
	clang++ -O2 -std=c++14 -march=native -S div_vs_mul.cpp -o div_vs_mul.s
clean:
	rm ./div_vs_mul.s

