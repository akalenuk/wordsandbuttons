all:
	g++ -O2 -std=c++14 exp_inline.cpp -o exp_inline
	g++ -O2 -std=c++14 exp_inline.cpp -S -o exp_inline.s
	g++ -O2 -std=c++14 exp_forced_inline.cpp -o exp_forced_inline
	g++ -O2 -std=c++14 exp_forced_inline.cpp -S -o exp_forced_inline.s
	g++ -O2 -std=c++14 -march=native exp_forced_inline_march_native.cpp -o exp_forced_inline_march_native
	g++ -O2 -std=c++14 -march=native exp_forced_inline_march_native.cpp -S -o exp_forced_inline_march_native.s
	ls -l *.s
.PHONY: measurements
measurements:
	perf stat ./exp_inline
	perf stat ./exp_forced_inline
	perf stat ./exp_forced_inline_march_native
clean:
	rm exp_inline
	rm exp_inline.s
	rm exp_forced_inline
	rm exp_forced_inline.s
	rm exp_forced_inline_march_native
	rm exp_forced_inline_march_native.s
