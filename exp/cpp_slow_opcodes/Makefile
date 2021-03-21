all:
	clang++ -O2 -std=c++14 -march=native div_vs_mul.cpp -o div_vs_mul
	./div_vs_mul
	rm ./div_vs_mul
	clang++ -O2 -std=c++14 -march=native div_vs_mul_array.cpp -o div_vs_mul_array
	./div_vs_mul_array
	rm ./div_vs_mul_array
	clang++ -O2 -std=c++14 -march=native sin_vs_lookup.cpp -o sin_vs_lookup
	./sin_vs_lookup
	rm ./sin_vs_lookup
s:
	clang++ -O2 -std=c++14 -march=native -S div_vs_mul.cpp -o div_vs_mul.s
	clang++ -O2 -std=c++14 -march=native -S div_vs_mul_array.cpp -o div_vs_mul_array.s
	clang++ -O2 -std=c++14 -march=native -S sin_vs_lookup.cpp -o sin_vs_lookup.s
clean:
	rm ./div_vs_mul.s
	rm ./div_vs_mul_array.s
	rm ./sin_vs_lookup

