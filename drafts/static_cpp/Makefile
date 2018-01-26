all: flame
	g++ -O2 -std=c++14 -finline-limit=10 exp_no_inline.cpp -o exp_no_inline
	g++ -O2 -std=c++14 -finline-limit=10 exp_no_inline.cpp -S -o exp_no_inline.s
	g++ -O2 -std=c++14 exp_forced_inline.cpp -o exp_forced_inline
	g++ -O2 -std=c++14 exp_forced_inline.cpp -S -o exp_forced_inline.s
	g++ -O2 -std=c++14 -march=native exp_forced_inline_march_native.cpp -o exp_forced_inline_march_native
	g++ -O2 -std=c++14 -march=native exp_forced_inline_march_native.cpp -S -o exp_forced_inline_march_native.s
	ls -l *.s
.PHONY: flame
flame:
	gcc -O2 -std=c11 exp_flame.c -I /home/okaleniuk/flame/include -L/home/okaleniuk/flame/lib -lflame -o exp_flame
.PHONY: measurements
measurements:
	perf stat ./exp_no_inline
	perf stat ./exp_forced_inline
	perf stat ./exp_forced_inline_march_native
	perf stat ./exp_flame
clean:
	rm exp_no_inline
	rm exp_no_inline.s
	rm exp_forced_inline
	rm exp_forced_inline.s
	rm exp_forced_inline_march_native
	rm exp_forced_inline_march_native.s
	rm exp_flame
