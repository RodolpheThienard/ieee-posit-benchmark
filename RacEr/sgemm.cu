#include <cuda_runtime.h>
#include <cublas_v2.h>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)


void
init (float *A, float *B, float *C, int size)
{
  int i = 0, j = 0;

  srand (2019);

  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
        {
          A[i * size + j] = (float)(rand () % 10) + 0.01 * (rand () % 5);
          B[i * size + j] = (float)(rand () % 10) + 0.01 * (rand () % 5);
          C[i * size + j] = 0.0;
        }
    }
}
__global__ void
sgemm_jik (float *A, float *B, float *C, int N)
{
  int j = blockIdx.x * blockDim.x + threadIdx.x;
  // Col
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  float sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}
__global__ void
sgemm_ijk (float *A, float *B, float *C, int N)
{
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  // Col
  int j = blockIdx.y * blockDim.y + threadIdx.y;
  float sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}

__global__ void 
sgemm_bloc(float *A, float *B, float *C, int N)
{
     int i = blockIdx.x * blockDim.x + threadIdx.x;
     int j = blockIdx.y * blockDim.y + threadIdx.y;

    __shared__ float a[32][32];
    __shared__ float b[32][32];

    float sum = 0;
    for (int k = 0; k < N; k += 32) {
        a[threadIdx.y][threadIdx.x] = A[j * N + k + threadIdx.x];
        b[threadIdx.y][threadIdx.x] = B[(k + threadIdx.y) * N + i];

        __syncthreads();

        for (int l = 0; l < 32; l++)
            sum += a[threadIdx.y][l] * b[l][threadIdx.x];

        __syncthreads();
    }
    C[j * N + i] = sum;
}
float
get_elapsedtime (void)
{
  struct timespec st;
  int err = gettime (&st);
  if (err != 0)
    return 0;
  return (float)st.tv_sec + get_sub_seconde (st);
}

int
main (int argc, char *argv[])
{
  int N = 1 << 20;
  float *A, *B, *C, *d_A, *d_B, *d_C, t1, t0;

  N = (argc < 2) ? 1000 : atoi (argv[1]);
  // fprintf (stdout, "Matrix Multiplication\n  Size: %dx%d\n", N, N);

  // Memory allocation
  A = (float *)malloc (sizeof (float) * N * N);
  B = (float *)malloc (sizeof (float) * N * N);
  C = (float *)malloc (sizeof (float) * N * N);

  // float *ms = (float*)malloc(sizeof(float));
  float ms=0;
  
  init (A, B, C, N);

  cublasHandle_t handle;
  cublasCreate(&handle);
  cudaMalloc (&d_A, N * N * sizeof (float));
  cudaMalloc (&d_B, N * N * sizeof (float));
  cudaMalloc (&d_C, N * N * sizeof (float));

  cudaMemcpy (d_A, A, N * N * sizeof (float), cudaMemcpyHostToDevice);
  cudaMemcpy (d_B, B, N * N * sizeof (float), cudaMemcpyHostToDevice);
  float un = 1;

  // Kernel invocation
  dim3 threadsPerBlock (32, 32);
  dim3 numBlocks (N / threadsPerBlock.x, N / threadsPerBlock.y);

  // Perform SAXPY on 1M elements
  cudaEvent_t start_event, end_event;
  cudaEventCreate(&start_event);
  cudaEventCreate(&end_event);

  cudaEventRecord(start_event, 0);
  sgemm_bloc<<<numBlocks, threadsPerBlock>>> (d_A, d_B, d_C, N);
  cudaEventRecord(end_event, 0);
  cudaEventSynchronize(end_event);

  cudaError_t err = cudaGetLastError();
  cudaMemcpy (C, d_C, N * sizeof (float), cudaMemcpyDeviceToHost);

  cudaEventElapsedTime(&ms, start_event, end_event);
  // Pretty print
  long long N_u64 = (long long)N;
  long long nb_op = N_u64 * N_u64 * N_u64;
  // fprintf (stdout, "Performance results: \n");
  // fprintf (stdout, "  Time: %e ms\n", ms);
  // fprintf (stdout, "  MFlops: %.2f\n", (nb_op / ms*1e3) * 1E-6);
  fprintf(stdout, "%d; %f; %.2f\n",N, ms, ((nb_op/(ms*1e-3))*1e-9));

  cudaFree (d_A);
  cudaFree (d_B);
  cudaFree (d_C);
  free (A);
  free (B);
  free (C);
}
