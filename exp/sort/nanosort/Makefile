all:
	g++ benchmark.cpp -std=c++14 -O3 -o benchmark
clang:
	clang++ benchmark.cpp -std=c++14 -O3 -o benchmark
measurements:
	valgrind --tool=cachegrind ./benchmark
clean:
	rm benchmark

