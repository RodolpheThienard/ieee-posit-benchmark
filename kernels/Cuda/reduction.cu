#include <cstddef>
#include <cstdlib>
#include <cublas_v2.h>
#include <cuda_runtime.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)

__global__ void reduction(int *output, int *input, int n) {
    extern __shared__ int sdata[];

    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < n) {
        sdata[tid] = input[i];
    } else {
        sdata[tid] = 0; 
    }
    __syncthreads();

    for (unsigned int s = blockDim.x / 2; s > 32; s /= 2) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    if (tid == 0) {
        output[0] = sdata[0];
    }
}


__device__ void
warpReduce4 (volatile int *sdata, int tid)
{
  sdata[tid] += sdata[tid + 32];
  sdata[tid] += sdata[tid + 16];
  sdata[tid] += sdata[tid + 8];
  sdata[tid] += sdata[tid + 4];
  sdata[tid] += sdata[tid + 2];
  sdata[tid] += sdata[tid + 1];
}

__global__ void
reduce (int *g_odata, int *g_idata, int n)
{
  extern __shared__ int sdata[];

  unsigned int tid = threadIdx.x;
  unsigned int i = blockIdx.x * (blockDim.x * 2) + threadIdx.x;

  sdata[tid] = g_idata[i] + g_idata[i + blockDim.x];
  __syncthreads ();

  for (unsigned int s = blockDim.x / 2; s > 32; s >>= 1)
    {
      if (tid < s)
        sdata[tid] += sdata[tid + s];
      __syncthreads ();
    }
  if (tid < 32)
    warpReduce4 (sdata, tid);

  if (tid == 0)
    g_odata[blockIdx.x] = sdata[0];

}

int
ma (int argc, char *argv[])
{
  cudaError_t err = cudaGetLastError ();
  int N = 2 << 10;
  int *h_input, *d_input, *h_output, *d_output;

  h_input = (int *)malloc (sizeof (int) * N);
  h_output = (int *)malloc (sizeof (int) * N);

  // init host values
  for (int i = 0; i < N; i++)
    {
      h_input[i] = 1;
      h_output[i] = 0;
    }

  cudaMalloc (&d_input, sizeof (int) * N);
  cudaMalloc (&d_output, sizeof (int) * N);

  cudaMemcpy (d_input, h_input, N * sizeof (int), cudaMemcpyHostToDevice);
  cudaMemcpy (d_output, h_output, N * sizeof (int), cudaMemcpyHostToDevice);

  dim3 threadsPerBlock (32);
  dim3 numBlocks ((N+31)/32);

  reduction<<<numBlocks, threadsPerBlock>>> (d_output, d_input, N);

  cudaMemcpy (h_output, d_output, N * sizeof (int), cudaMemcpyDeviceToHost);

  err = cudaGetLastError ();
  printf ("ERROR : %s\n", cudaGetErrorString (err));

  printf ("Data gathered : %d; %d\n", h_input[0], h_output[0]);

  cudaFree (d_input);
  cudaFree (d_output);
  free (h_input);
  free (h_output);
  return 0;
}
