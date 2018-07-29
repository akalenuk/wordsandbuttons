all:
	g++ -O2 -std=c++14 -march=native exp_forced_inline.cpp -o exp_forced_inline_march_native
	g++ -O2 -std=c++14 -march=native exp_forced_inline.cpp -S -o exp_forced_inline_march_native.s
clean:
	rm exp_forced_inline_march_native
	rm exp_forced_inline_march_native.s

