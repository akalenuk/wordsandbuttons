all:
	g++ benchmark.cpp -std=c++14 -O3 -o benchmark_gcc
	clang++ benchmark.cpp -std=c++14 -O3 -o benchmark_clang
measurements:
	./benchmark_gcc
	./benchmark_clang
clean:
	rm benchmark_gcc
	rm benchmark_clang

