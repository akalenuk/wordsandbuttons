#include <iostream>
#include <vector>
#include <random>
#include <cuda_runtime.h>


using TheType = float;
constexpr auto TheSize = 65536u*128u;
constexpr auto TheSizeInBytes = TheSize*sizeof(TheType);
constexpr auto TheInnerLoop = 256u;
	
__global__ void add(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		if (i < size) {
			res += xs1[i+j] + xs2[i+j];
		}
	}
	ys[i] = res;
}

__global__ void mul(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		if (i < size) {
			res += xs1[i+j] * xs2[i+j];
		}
	}
	ys[i] = res;
}

__global__ void div(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		if (i < size) {
			res += xs1[i+j] / xs2[i+j];
		}
	}
	ys[i] = res;
}

__global__ void std_sin(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		if (i < size) {
			res += std::sin(xs1[i+j]);
		}
	}
	ys[i] = res;
}

__global__ void poly_sin(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		if (i < size) {
			const auto x = xs1[i+j];
			res += -0.000182690409228785*x*x*x*x*x*x*x+0.00830460224186793*x*x*x*x*x+-0.166651012143690*x*x*x+x;
		}
	}
	ys[i] = res;
}


#define attempt(smth) {auto s=(smth);if(s!=cudaSuccess){std::cout << cudaGetErrorString(s) << " at " << __LINE__ << "\n"; return -1;}}

#define measure(smth) {\
	/*timestamp start*/\
	cudaEvent_t start;\
	cudaEventCreate(&start);\
	cudaEventRecord(start, 0);\
	cudaEvent_t stop;\
	cudaEventCreate(&stop); /*here so it wouldn't interfere with the measurement*/\
\
	/* run it*/\
	int threadsPerBlock = 256;\
	int blocksPerGrid = (TheSize - TheInnerLoop + threadsPerBlock - 1) / threadsPerBlock;\
	smth<<<blocksPerGrid, threadsPerBlock>>>(d_xs, d_ys, d_zs, TheSize);\
	attempt(cudaGetLastError());\
	attempt(cudaDeviceSynchronize());\
\
	/* timestamp stop*/\
	cudaEventRecord(stop, 0); \
	cudaEventSynchronize(stop);\
	float elapsedTime;\
	cudaEventElapsedTime(&elapsedTime, start, stop);\
	std::cout << "Time of " << #smth << ": " << elapsedTime << "\n";}\


int main(void)
{
	// prepare the data
	std::mt19937 rng(0);
	std::uniform_real_distribution<TheType> distribution(0.f, 1.f);
	std::vector<TheType> xs(TheSize);
	std::vector<TheType> ys(TheSize);
	std::vector<TheType> zs(TheSize);
	for (TheType &number : xs) number = distribution(rng);
	for (TheType &number : ys) number = distribution(rng);


	// do the allocations
	float *d_xs = nullptr;
	float *d_ys = nullptr;
	float *d_zs = nullptr;
	attempt(cudaMalloc((void **)&d_xs, TheSizeInBytes));
	attempt(cudaMalloc((void **)&d_ys, TheSizeInBytes));
	attempt(cudaMalloc((void **)&d_zs, TheSizeInBytes));

	// and copying
	attempt(cudaMemcpy(d_xs, xs.data(), TheSizeInBytes, cudaMemcpyHostToDevice));
	attempt(cudaMemcpy(d_ys, ys.data(), TheSizeInBytes, cudaMemcpyHostToDevice));

	measure(add);
	measure(mul);
	measure(div);
	measure(std_sin);
	measure(poly_sin);

	// back (for debug, don't really want it)
	attempt(cudaMemcpy(zs.data(), d_zs, TheSizeInBytes, cudaMemcpyDeviceToHost));

	attempt(cudaFree(d_xs));
	attempt(cudaFree(d_ys));
	attempt(cudaFree(d_zs));
	return 0;
}

