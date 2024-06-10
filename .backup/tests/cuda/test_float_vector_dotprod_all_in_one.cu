
#include <cublas_v2.h>
#include <cuda_runtime.h>
#include <stdlib.h>
#include <stdio.h>

__global__ void
vector_dotprod (float *A, float *B, int N)
{
  extern __shared__ float S[];
  int tid = threadIdx.x ;
  int i = blockDim.x * blockIdx.x + threadIdx.x;
  if (i < N) {
    S[tid] = A[i];
    __syncthreads();
    // Reduce in shared memory
    for (int t = blockDim.x/2; t > 0; t>>=1) {
      if (tid < t) {
        S[tid] += S[tid + t];
      }
      __syncthreads();
    }
    if (tid == 0) B[blockIdx.x] = S[0];
  }
}

__global__ void reduction(float *g_idata, float* g_odata, int n){
  extern __shared__ float sdata[];
  // each thread loads one element from global to shared mem
  unsigned int tid = threadIdx.x;
  unsigned int i = blockIdx.x*blockDim.x + threadIdx.x;
  sdata[tid] = g_idata[i];
  __syncthreads();
  // do reduction in shared mem
  for(unsigned int s=1; s < blockDim.x; s *= 2) {
    if (tid % (2*s) == 0) {
      sdata[tid] += sdata[tid + s];
    }
    __syncthreads();
  }
  // write result for this block to global mem
  if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

void
initializevector (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx]
          = (float)drand48 () * i / 100; // warning, requires posix standard.
    }
}

double
doubledotproduct (double *pv1, double *pv2, int n)
{
  double res = 0.0;
  for (int i = 0; i < n; i++)
    res += pv1[i];

  return res;
}
float
floatdotproduct (float *pv1, float *pv2, int n)
{

  float res = 0.0;
  for (int i = 0; i < n; i++)
    res += pv1[i];

  return res;
}
void
transfertodouble (double *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = (double)fv[idx];
    }
}
void
transfertocuda (float *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = fv[idx];
    }
}

int
main (int argc, char *argv[])
{

float *f1, *f2, *c1, *d_c1, *d_c2;
double *d1, *d2;
  FILE *file;
  file = fopen ("result.dat", "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      int n = 1000;
      f1 = (float*)malloc (sizeof (float) * n);
      f2 = (float*)malloc (sizeof (float) * n);

      c1 = (float *)malloc (sizeof (float) * n);

      cudaMalloc (&d_c1, n * sizeof (float));
      cudaMalloc (&d_c2, n * sizeof (float));

      d1 = (double *)malloc (sizeof (double) * n);
      d2 = (double *)malloc (sizeof (double) * n);

      initializevector (f1, n, i);
      initializevector (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);


      cudaMemcpy (d_c1, f1, n * sizeof (float),
                  cudaMemcpyHostToDevice);

      reduction<<<1255/n, n/2>>>(d_c1, d_c2, n);

      cudaMemcpy (c1, d_c2, n * sizeof (float),
                  cudaMemcpyDeviceToHost);

      float f_res = floatdotproduct (f1, f2, n);
      float cuda_res = c1[0];
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)cuda_res, d_res,
               ((double)cuda_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  return 0;
}
