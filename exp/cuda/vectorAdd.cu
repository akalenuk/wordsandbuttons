#include <iostream>
#include <cuda_runtime.h>


__global__ void add(const float *A, const float *B, float *C, int numElements) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (i < numElements) {
		C[i] = A[i] + B[i];
	}
}

int main(void)
{
	// prepare the data
	using TheType = float;
	constexpr auto TheSize = 65536;
	std::mt19937 rng(0);
	std::uniform_real_distribution<float> distribution(0.f, 1.f);
	std::vector<TheType> xs(TheSize);
	std::vector<TheType> ys(TheSize);
	std::vector<TheType> zs(TheSize);
	for (TheType &number : xs) number = distribution(rng);
	for (TheType &number : ys) number = distribution(rng);


	// do the allocations
	cudaError_t status = cudaSuccess;
	float *d_xs = nullptr;
	float *d_yx =  nullptr;
	float *d_zx =  nullptr;
	status = cudaMalloc((void **)&d_xs, size);
	status = cudaMalloc((void **)&d_ys, size);
	status = cudaMalloc((void **)&d_zs, size);

	// and copying
	err = cudaMemcpy(d_xs, xs, theSize*sizeof(float), cudaMemcpyHostToDevice);
	err = cudaMemcpy(d_zs, zs, theSize*sizeof(float), cudaMemcpyHostToDevice);

	// run it
	int threadsPerBlock = 256;
	int blocksPerGrid = (numElements + threadsPerBlock - 1) / threadsPerBlock;
	add<<<blocksPerGrid, threadsPerBlock>>>(d_xs, d_ys, d_zx, theSize);
	err = cudaGetLastError();

	// back
	err = cudaMemcpy(zs, d_zs, theSize*sizeof(float), cudaMemcpyDeviceToHost);

	// verification
	for (auto i = 0u; i < the_size; ++i)
		if (std::fabs(xs[i] + ys[i] - za[i]) > 1e-5)
			std::cout << "Not verified\n";
			return -1;
		}
	}

	err = cudaFree(d_xs);
	err = cudaFree(d_ys);
	err = cudaFree(d_zs);
	return 0;
}

