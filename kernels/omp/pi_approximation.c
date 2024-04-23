#include "../../include/utils.h"
#define TOT_DART 1e6
#define PI 3.1415926535
#define is_inside(x, y) (x * x + y * y) <= 1 ? 1 : 0

void
pi_approximation_fp64 (double *input, double *output, int n)
{
#pragma omp for
  for (int k = 0; k < n; k++)
    {
      int inside = 0;
      double x, y;
      for (int i = 0; i < TOT_DART; i++)
        {
          x = (double)drand48 ();
          y = (double)drand48 ();
          inside += is_inside (x, y);
        }
      output[k] = (4. * inside / TOT_DART);
    }
}

void
pi_approximation_fp32 (float *input, float *output, int n)
{
#pragma omp for
  for (int k = 0; k < n; k++)
    {
      int inside = 0;
      float x, y;
      for (int i = 0; i < TOT_DART; i++)
        {
          x = (float)drand48 ();
          y = (float)drand48 ();
          inside += is_inside (x, y);
        }
      output[k] = (4. * inside / TOT_DART);
    }
}

void
real_pi (double *input, double *output, int n)
{
#pragma omp for
  for (int k = 0; k < n; k++)
    output[k] = (double)PI;
}
