#include "../../include/utils.h"

__global__ void
conversion_double_float (double *a, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  float tmp;
      tmp = (float)a[tid];
      a[tid] = (double)tmp;
}

__global__ void
useless_function (double *a, int i)
{
}

