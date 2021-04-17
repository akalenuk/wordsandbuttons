all:
	/usr/local/cuda-11.2/bin/nvcc -ccbin g++ -m64 -gencode arch=compute_61,code=sm_61 vectorAdd.cu -o vectorAdd
clean:
	rm -f vectorAdd

