all:
	/usr/local/cuda-11.2/bin/nvcc -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	rm -f benchmark
clean:
	rm -f benchmark

