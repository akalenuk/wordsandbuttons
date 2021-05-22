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
		res += xs1[i+j] + xs2[i+j];
	}
	ys[i] = res;
}

__global__ void mul(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		res += xs1[i+j] * xs2[i+j];
	}
	ys[i] = res;
}

__global__ void div(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		res += xs1[i+j] / xs2[i+j];
	}
	ys[i] = res;
}

__global__ void std_sqrt(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		res += std::sqrt(xs1[i+j]);
	}
	ys[i] = res;
}

__global__ void std_sin(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		res += std::sin(xs1[i+j]);
	}
	ys[i] = res;
}

__global__ void poly_sin(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		const auto x = xs1[i+j];
		res += -0.000182690409228785*x*x*x*x*x*x*x+0.00830460224186793*x*x*x*x*x-0.166651012143690*x*x*x+x;
	}
	ys[i] = res;
}

__global__ void poly_sin2(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		const auto x = xs1[i+j];
		res += x*x*x*(x*x*(-0.000182690409228785*x*x+0.00830460224186793)-0.166651012143690)+x;
	}
	ys[i] = res;
}

__global__ void poly_sin3(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		const auto x = xs1[i+j];
		res += -0.000182690409228785f*x*x*x*x*x*x*x+0.00830460224186793f*x*x*x*x*x-0.166651012143690f*x*x*x+x;
	}
	ys[i] = res;
}

__global__ void poly_sin4(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	auto res = 0.f;
	for(auto j = 0u; j < TheInnerLoop; ++j) {
		const auto x = xs1[i+j];
		res += x*x*x*(x*x*(-0.000182690409228785f*x*x+0.00830460224186793f)-0.166651012143690f)+x;
	}
	ys[i] = res;
}

__global__ void logical_and(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	bool all_gt = true;
	for(auto j = 0u; j < TheInnerLoop - 3; ++j) {
		all_gt = all_gt && (xs1[i+j] > xs1[i+j]) && (xs1[i+j+1] > xs1[i+j+1]) && (xs1[i+j+2] > xs1[i+j]+2) && (xs1[i+j+3] > xs1[i+j+3]);
	}
	ys[i] = all_gt ? 1.f : 0.f;
}

__global__ void bit_and(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	bool all_gt = true;
	for(auto j = 0u; j < TheInnerLoop - 3; ++j) {
		all_gt = all_gt & (xs1[i+j] > xs1[i+j]) & (xs1[i+j+1] > xs1[i+j+1]) & (xs1[i+j+2] > xs1[i+j]+2) & (xs1[i+j+3] > xs1[i+j+3]);
	}
	ys[i] = all_gt ? 1.f : 0.f;
}

__global__ void mul_and(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	bool all_gt = true;
	for(auto j = 0u; j < TheInnerLoop - 3; ++j) {
		all_gt = all_gt * (xs1[i+j] > xs1[i+j]) * (xs1[i+j+1] > xs1[i+j+1]) * (xs1[i+j+2] > xs1[i+j]+2) * (xs1[i+j+3] > xs1[i+j+3]);
	}
	ys[i] = all_gt ? 1.f : 0.f;
}

#define swap(a, b) {auto c = a; a = b; b = c;}

__global__ void sort(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	float checksum = 0.;
	for(auto j = 0u; j < TheInnerLoop - 2; ++j) {
		double s[3] = {xs1[i+j], xs1[i+j+1], xs1[i+j+2]};
		if(s[0] > s[1])
			swap(s[0], s[1]);
		if(s[1] > s[2])
			swap(s[1], s[2]);
		if(s[0] > s[1])
			swap(s[0], s[1]);
		checksum += s[0] + 2*s[1] + 3*s[3];
	}
	ys[i] = checksum;
}

__global__ void nano_sort(const float *xs1, const float *xs2, float *ys, int size) {
	int i = (blockDim.x * blockIdx.x + threadIdx.x);
	float checksum = 0.;
	for(auto j = 0u; j < TheInnerLoop - 2; ++j) {
		double sortable[3] = {xs1[i+j], xs1[i+j+1], xs1[i+j+2]};
		const auto a = sortable[0];
		const auto b = sortable[1];
		const auto c = sortable[2];
		sortable[int(a > b) + int(a > c)] = a;
		sortable[int(b >= a) + int(b > c)] = b;
		sortable[int(c >= a) + int(c >= b)] = c;
		checksum += sortable[0] + 2*sortable[1] + 3*sortable[3];
	}
	ys[i] = checksum;
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
	measure(std_sqrt);
	measure(std_sin);
	measure(poly_sin);
	measure(poly_sin2);
	measure(poly_sin3);
	measure(poly_sin4);
	measure(logical_and);
	measure(bit_and);
	measure(mul_and);
	measure(sort);
	measure(nano_sort);

	// back (for debug, don't really want it)
	attempt(cudaMemcpy(zs.data(), d_zs, TheSizeInBytes, cudaMemcpyDeviceToHost));

	attempt(cudaFree(d_xs));
	attempt(cudaFree(d_ys));
	attempt(cudaFree(d_zs));
	return 0;
}

