all:
	nvcc -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
s:
	cuobjdump -sass ./benchmark > benchmark.s
clean:
	rm -f benchmark
	rm -f benchmark.s

