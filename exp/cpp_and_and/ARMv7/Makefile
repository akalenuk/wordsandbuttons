all:
	clang++ -O2 -std=c++14 -march=native andand.cpp -o andand
	./andand
	rm ./andand
	clang++ -O2 -std=c++14 -march=native and.cpp -o and
	./and
	rm ./and
	clang++ -O2 -std=c++14 -march=native mul.cpp -o mul
	./mul
	rm ./mul
	clang++ -O2 -std=c++14 -march=native minus_mul_plus.cpp -o minus_mul_plus
	./minus_mul_plus
	rm ./minus_mul_plus
	clang++ -O2 -std=c++14 -march=native minus_abs_plus.cpp -o minus_abs_plus
	./minus_abs_plus
	rm ./minus_abs_plus
	clang++ -O2 -std=c++14 -march=native andand_double.cpp -o andand_double
	./andand_double
	rm ./andand_double
	clang++ -O2 -std=c++14 -march=native andand_float.cpp -o andand_float
	./andand_float
	rm ./andand_float
	clang++ -O2 -std=c++14 -march=native minus_mul_plus_double.cpp -o minus_mul_double_plus
	./minus_mul_double_plus
	rm ./minus_mul_double_plus
	clang++ -O2 -std=c++14 -march=native compare_zero.cpp -o compare_zero
	./compare_zero
	rm compare_zero
s:
	clang++ -O2 -std=c++14 -march=native -S andand.cpp -o andand.s
	clang++ -O2 -std=c++14 -march=native -S and.cpp -o and.s
	clang++ -O2 -std=c++14 -march=native -S mul.cpp -o mul.s
	clang++ -O2 -std=c++14 -march=native -S minus_mul_plus.cpp -o minus_mul_plus.s
	clang++ -O2 -std=c++14 -march=native -S minus_abs_plus.cpp -o minus_abs_plus.s
	clang++ -O2 -std=c++14 -march=native -S andand_double.cpp -o andand_double.s
	clang++ -O2 -std=c++14 -march=native -S andand_float.cpp -o andand_float.s
	clang++ -O2 -std=c++14 -march=native -S minus_mul_plus_double.cpp -o minus_mul_double_plus.s
	clang++ -O2 -std=c++14 -march=native -S compare_zero.cpp -o compare_zero.s
clean:
	rm ./andand.s
	rm ./and.s
	rm ./mul.s
	rm ./minus_mul_plus.s
	rm ./minus_abs_plus.s
	rm ./andand_double.s
	rm ./andand_float.s
	rm ./minus_mul_double_plus.s
	rm ./compare_zero.s
