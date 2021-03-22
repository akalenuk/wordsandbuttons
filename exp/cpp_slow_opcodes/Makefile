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
	clang++ -O2 -std=c++14 -march=native sin_vs_big_lookup.cpp -o sin_vs_big_lookup
	./sin_vs_big_lookup
	rm ./sin_vs_big_lookup
	clang++ -O2 -std=c++14 -march=native dsin_vs_fsin.cpp -o dsin_vs_fsin
	./dsin_vs_fsin
	rm ./dsin_vs_fsin
	clang++ -O2 -std=c++14 -march=native fsin_vs_stdfsin.cpp -o fsin_vs_stdfsin
	./fsin_vs_stdfsin
	rm ./fsin_vs_stdfsin
	clang++ -O2 -std=c++14 -march=native sin_vs_polynomial.cpp -o sin_vs_polynomial
	./sin_vs_polynomial
	rm ./sin_vs_polynomial
s:
	clang++ -O2 -std=c++14 -march=native -S div_vs_mul.cpp -o div_vs_mul.s
	clang++ -O2 -std=c++14 -march=native -S div_vs_mul_array.cpp -o div_vs_mul_array.s
	clang++ -O2 -std=c++14 -march=native -S sin_vs_lookup.cpp -o sin_vs_lookup.s
	clang++ -O2 -std=c++14 -march=native -S sin_vs_big_lookup.cpp -o sin_vs_big_lookup.s
	clang++ -O2 -std=c++14 -march=native -S dsin_vs_fsin.cpp -o dsin_vs_fsin.s
	clang++ -O2 -std=c++14 -march=native -S fsin_vs_stdfsin.cpp -o fsin_vs_stdfsin.s
	clang++ -O2 -std=c++14 -march=native -S sin_vs_polynomial.cpp -o sin_vs_polynomial.s
clean:
	rm ./div_vs_mul.s
	rm ./div_vs_mul_array.s
	rm ./sin_vs_lookup.s
	rm ./sin_vs_big_lookup.s
	rm ./dsin_vs_fsin.s
	rm ./fsin_vs_stdfsin.s
	rm ./fsin_vs_polynomial.s
