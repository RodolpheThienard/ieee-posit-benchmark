#include "../../include/utils.h"

__device__ double 
factorial(int n) {
    double result = 1.0;
    int i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

__global__ void
sinus_maclaurin (double *vector, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  int  j;
      double result = 0.0;
      for (j = 0; j < 10; j++)
        {
          int sign = (j % 2 == 0) ? 1 : -1;
          int exponent = 2 * j + 1;
          double term
              = sign * pow (vector[tid], exponent) / factorial(exponent);
          result += term;
        }
      vector[tid] = result;
    
}

__global__ void
sinus_libmath (double *vector, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
      vector[tid] = sin (vector[tid]);
}
