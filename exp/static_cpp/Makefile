all: factorial
	g++ -O2 -std=c++14 -fno-inline exp_default_inline.cpp -o exp_no_inline
	g++ -O2 -std=c++14 -fno-inline exp_default_inline.cpp -S -o exp_no_inline.s
	g++ -O2 -std=c++14 -fno-inline -march=native exp_default_inline.cpp -o exp_no_inline_march_native
	g++ -O2 -std=c++14 -fno-inline -march=native exp_default_inline.cpp -S -o exp_no_inline_march_native.s
	g++ -O2 -std=c++14 exp_forced_inline.cpp -o exp_forced_inline
	g++ -O2 -std=c++14 exp_forced_inline.cpp -S -o exp_forced_inline.s
	g++ -O2 -std=c++14 -march=native exp_forced_inline.cpp -o exp_forced_inline_march_native
	g++ -O2 -std=c++14 -march=native exp_forced_inline.cpp -S -o exp_forced_inline_march_native.s
	g++ -O2 -std=c++14 -march=native exp_triangular_matrix.cpp -o exp_triangular_matrix
	g++ -O2 -std=c++14 -march=native exp_triangular_matrix.cpp -S -o exp_triangular_matrix.s	
	ls -l *.s
.PHONY: measurements
measurements:
	perf stat ./exp_no_inline
	perf stat ./exp_no_inline_march_native
	perf stat ./exp_forced_inline
	perf stat ./exp_forced_inline_march_native
	perf stat ./exp_triangular_matrix
.PHONY: factorial
factorial:
	g++ -O2 -std=c++14 factorial.cpp -o factorial
	g++ -O2 -std=c++14 factorial.cpp -S -o factorial.s	
clean:
	rm exp_no_inline
	rm exp_no_inline.s
	rm exp_no_inline_march_native
	rm exp_no_inline_march_native.s
	rm exp_forced_inline
	rm exp_forced_inline.s
	rm exp_forced_inline_march_native
	rm exp_forced_inline_march_native.s
	rm exp_triangular_matrix
	rm exp_triangular_matrix.s
	rm factorial
	rm factorial.s
