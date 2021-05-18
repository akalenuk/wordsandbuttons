all:
	nvcc -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
all_flags:
	nvcc -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	nvcc --use_fast_math -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	nvcc --ftz=true -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	nvcc --prec-div=false -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	nvcc --prec-sqrt=false -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
	nvcc --fmad=false -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 benchmark.cu -o benchmark
	./benchmark
s:
	cuobjdump -sass ./benchmark > benchmark.s
clean:
	rm -f benchmark
	rm -f benchmark.s

