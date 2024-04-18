#include "../../include/utils.h"
#include <stdlib.h>
#define TOT_DART 1e6
#define PI 3.1415926535

#define is_inside(x, y) (x * x + y * y) <= 1 ? 1 : 0

void
pi_approximation_fp64 (double *vector, int n)
{
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
      vector[k] = (4. * inside / TOT_DART);
    }
}

void
pi_approximation_fp32 (float *vector, int n)
{
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
      vector[k] = (4. * inside / TOT_DART);
    }
}

void
real_pi (double *vector, int n)
{
  for (int k = 0; k < n; k++)
    vector[k] = (double)PI;
}
