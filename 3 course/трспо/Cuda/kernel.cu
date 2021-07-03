#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cuda.h>
#include <device_functions.h>
#include <cuda_runtime_api.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <chrono>
#include <iomanip>

__global__ void find_foo_kernel(float step, unsigned int n) {
	unsigned int index = threadIdx.x + blockIdx.x * blockDim.x;
	unsigned int stride = gridDim.x * blockDim.x;
	unsigned int offset = 0;
	float x = 0, foo = 0;

	while (index + offset < n) {
		x = 1 + float(index + offset) * (step);
		foo = 2 * (1 / tan(3 * x)) - (1 / (pow(12 * x, 2) + 7 * x - 5));
		offset += stride;
	}

}
__global__ void find_minimum_kernel(const float* array, float* min, int* mutex, unsigned int n) {
	unsigned int index = threadIdx.x + blockIdx.x * blockDim.x;
	unsigned int stride = gridDim.x * blockDim.x;
	unsigned int offset = 0;
	__shared__ float cache[256];

	float temp = RAND_MAX + 1;
	while (index + offset < n) {
		temp = fminf(temp, array[index + offset]);
		offset += stride;
	}

	cache[threadIdx.x] = temp;

	__syncthreads();

	unsigned int i = blockDim.x / 2;
	while (i != 0) {
		if (threadIdx.x < i) {
			cache[threadIdx.x] = fminf(cache[threadIdx.x], cache[threadIdx.x + i]);
		}

		__syncthreads();
		i /= 2;
	}

	__syncthreads();

	if (threadIdx.x == 0) {
		while (atomicCAS(mutex, 0, 1) == 1) {
			if (*min > cache[0]) {
				*min = cache[0];
			}
		}
		atomicExch(mutex, 0);
	}
}

int main() {
	unsigned int N = pow(10,7);
	float* h_array;
	float* d_array;
	float* h_min;
	float* d_min;
	int* d_mutex;
	h_array = (float*)malloc(N * sizeof(float));
	h_min = (float*)malloc(sizeof(float));
	cudaMalloc((void**)&d_array, N * sizeof(float));
	cudaMalloc((void**)&d_min, sizeof(float));
	cudaMalloc((void**)&d_mutex, sizeof(int));
	cudaMemset(d_min, RAND_MAX + 1, sizeof(float));
	cudaMemset(d_mutex, 0, sizeof(float));

	srand(time(NULL));
	for (unsigned int i = 0; i < N; i++) {
		h_array[i] = ((double(rand()) / double(RAND_MAX)) * (RAND_MAX - -RAND_MAX)) + -RAND_MAX;
	}

	float gpu_elapsed_time;
	cudaEvent_t gpu_start, gpu_stop;
	cudaEventCreate(&gpu_start);
	cudaEventCreate(&gpu_stop);
	cudaMemcpy(d_array, h_array, N * sizeof(float), cudaMemcpyHostToDevice);

	dim3 gridSize = 256;
	dim3 blockSize = 256;

	cudaEventRecord(gpu_start, 0);

	find_minimum_kernel << < gridSize, blockSize >> > (d_array, d_min, d_mutex, N);
	cudaMemcpy(h_min, d_min, sizeof(float) * 1, cudaMemcpyDeviceToHost);
	
	cudaEventRecord(gpu_stop, 0);
	cudaEventSynchronize(gpu_stop);
	cudaEventElapsedTime(&gpu_elapsed_time, gpu_start, gpu_stop);
	cudaEventDestroy(gpu_start);
	cudaEventDestroy(gpu_stop);

	std::cout << "Min number found on gpu was: " << *h_min << std::endl;
	std::cout << "The gpu took: " << gpu_elapsed_time / 1000 << " seconds" << std::endl;

	auto start = std::chrono::system_clock::now();
	*h_min = RAND_MAX;
	for (unsigned int i = 0; i < N; i++) {
		if (h_array[i] < *h_min) {
			*h_min = h_array[i];
		}
	}
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "Min number found on cpu was: " << *h_min << std::endl;
	std::cout << "elapsed time: " << std::fixed << std::setprecision(20) << elapsed_seconds.count() << "s\n\n";

	free(h_array);
	free(h_min);
	cudaFree(d_array);
	cudaFree(d_min);
	cudaFree(d_mutex);


	//	task 1
	N = 21 * pow(10,1);
	float step = float(21) / float(N);
	cudaEventCreate(&gpu_start);
	cudaEventCreate(&gpu_stop);
	cudaEventRecord(gpu_start, 0);

	find_foo_kernel << < gridSize, blockSize >> > (step, N);

	cudaEventRecord(gpu_stop, 0);
	cudaEventSynchronize(gpu_stop);
	cudaEventElapsedTime(&gpu_elapsed_time, gpu_start, gpu_stop);
	cudaEventDestroy(gpu_start);
	cudaEventDestroy(gpu_stop);
	std::cout << "The gpu took: " << gpu_elapsed_time / 1000 << " seconds" << std::endl;

	start = std::chrono::system_clock::now();
	for (unsigned int i = 0; i < N; i++) {
		float x = 1 + float(i * step);
		float foo = 2 * (1 / tan(3 * x)) - (1 / (pow(12 * x, 2) + 7 * x - 5));
	}
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << std::fixed << std::setprecision(20) << elapsed_seconds.count() << "s\n\n";


	system("pause");
}



