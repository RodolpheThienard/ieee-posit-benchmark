
#include <cublas_v2.h>
#include <cuda_runtime.h>
#include <stdlib.h>
#include <stdio.h>
#define BLOCK_SIZE 256

__global__ void reduce(float *input, float *output, int n) {
    extern __shared__ float sharedData[];
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x * 2 + threadIdx.x;

    // Chargement des données de l'entrée globale à la mémoire partagée
    if (i < n) {
        sharedData[tid] = input[i] + (i + blockDim.x < n ? input[i + blockDim.x] : 0);
    } else {
        sharedData[tid] = 0;
    }
    __syncthreads();

    // Réduction en parallèle dans la mémoire partagée
    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) {
            sharedData[tid] += sharedData[tid + s];
        }
        __syncthreads();
    }

    // Le premier thread écrit le résultat dans la mémoire globale
    if (tid == 0) {
        output[blockIdx.x] = sharedData[0];
    }
}

// Fonction d'appel pour la réduction
float reduceVector(float *h_input, int n) {
    float *d_input, *d_output;
    int numBlocks = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;

    cudaMalloc(&d_input, n * sizeof(float));
    cudaMalloc(&d_output, numBlocks * sizeof(float));

    cudaMemcpy(d_input, h_input, n * sizeof(int), cudaMemcpyHostToDevice);

    // Premier passage de réduction
    reduce<<<numBlocks, BLOCK_SIZE, BLOCK_SIZE * sizeof(float)>>>(d_input, d_output, n);

    // Si plus d'un bloc, il faut encore réduire les résultats intermédiaires
    while (numBlocks > 1) {
        n = numBlocks;
        numBlocks = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
        reduce<<<numBlocks, BLOCK_SIZE, BLOCK_SIZE * sizeof(float)>>>(d_output, d_output, n);
    }

    float result;
    cudaMemcpy(&result, d_output, sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_input);
    cudaFree(d_output);

    return result;
}

void
initializevector (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx]
          = (float)drand48 () * i /1e1 ; // warning, requires posix standard.
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

float *f1, *f2;
double *d1, *d2;
  FILE *file;
  file = fopen ("result.dat", "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      int n = 1000;
      f1 = (float*)malloc (sizeof (float) * n);
      f2 = (float*)malloc (sizeof (float) * n);

      d1 = (double *)malloc (sizeof (double) * n);
      d2 = (double *)malloc (sizeof (double) * n);

      initializevector (f1, n, i);
      initializevector (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      float cuda_res = reduceVector(f1, n);
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)cuda_res, d_res,
               ((double)cuda_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  return 0;
}
