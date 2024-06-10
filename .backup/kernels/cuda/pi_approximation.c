#include "../../include/utils.h"
#define TOT_DART 1e7
#define PI 3.1415926535
#define is_inside(x, y) (x * x + y * y) <= 1 ? 1 : 0

__global__ void
pi_approximation (float *input, float *output, int n)
{
#pragma omp target teams map(to : n, inside_cuda[:n]) map(tofrom : pi)
  {
    int block_size = n / omp_get_num_teams ();

#pragma omp distribute
    for (int i = 0; i < n; i += block_size)
      {
        int inside = 0;
        float x, y;
#pragma omp parallel for reduction(+ : pi)
        for (int j = i; j < i + block_size; j++)
          {
            x = (float)drand48 ();
            y = (float)drand48 ();
            inside += is_inside (x, y);
            output[j] = (4. * inside / TOT_DART);
          }
      }
  }
}
