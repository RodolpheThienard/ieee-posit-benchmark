#include "../../include/utils.h"

__device__ float 
factorial(int n) {
    float result = 1.0;
    int i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

__global__ void
sinus_maclaurin (float *input, float *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  int  j;
      float result = 0.0;
      for (j = 0; j < 10; j++)
        {
          int sign = (j % 2 == 0) ? 1 : -1;
          int exponent = 2 * j + 1;
          float term
              = sign * pow (input[tid], exponent) / factorial(exponent);
          result += term;
        }
      output[tid] = result;
    
}

__global__ void
sinus_libmath (float *input, float *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
      output[tid] = sin (input[tid]);
}
