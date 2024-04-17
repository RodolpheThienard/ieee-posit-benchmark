#include "../../include/utils.h"

__global__ void
square_root_newton_raphson (double *vector, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  double approx = vector[tid] * .5;
  if (vector[tid] < 0)
    {
      return;
    }
  if (vector[tid] > 0)
    {
      do
        {
          approx = (approx + (vector[tid] / approx)) / 2;
        }
      while (((approx * approx) - vector[tid]) > 1e-8);
    }
  vector[tid] = approx;
}

__global__ void
sqrt_libmath (double *x, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
    x[tid] = sqrt (x[tid]);
}
