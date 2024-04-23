#include "../../include/utils.h"

__global__ void
square_root_newton_raphson (double *input, double *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  double approx = input[tid] * .5;
  if (input[tid] < 0)
    {
      return;
    }
  if (input[tid] > 0)
    {
      do
        {
          approx = (approx + (input[tid] / approx)) / 2;
        }
      while (((approx * approx) - input[tid]) > 1e-8);
    }
  output[tid] = approx;
}

__global__ void
sqrt_libmath (double *input, double *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
    output[tid] = sqrt (input[tid]);
}
