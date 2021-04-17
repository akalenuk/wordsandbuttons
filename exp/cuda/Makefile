all:
	/usr/local/cuda-11.2/bin/nvcc -ccbin g++ -I../../common/inc -m64 --threads 0 -gencode arch=compute_61,code=sm_61 vectorAdd.cu -o vectorAdd
clean:
	rm -f vectorAdd

