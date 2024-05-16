extern "C"
{
  #include "../../include/utils.h"
}
#include <curand_kernel.h>
#define TOT_DART 1e7
#define PI 3.1415926535
#define is_inside(x, y) (x * x + y * y) <= 1 ? 1 : 0

__global__ void
pi_approximation (float *input, float *output, int n)
{

  int j = blockIdx.x * blockDim.x + threadIdx.x;
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  if (j+i > n)return;
  int inside = 0;
  float x, y;
  curandState state;
  curand_init (j, i, 0, &state);
  for (int k = 0; k < TOT_DART; k++)
    {
      x = (float)curand_uniform (&state);
      y = (float)curand_uniform (&state);
      inside += is_inside (x, y);
    }
      output[i+j] = (4. * inside / TOT_DART);
}
