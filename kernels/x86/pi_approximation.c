#include "../../include/utils.h"
#define TOT_DART 1e6

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
          x = (double)rand () / (RAND_MAX);
          y = (double)rand () / (RAND_MAX);
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
          x = (float)rand () / (float)(RAND_MAX);
          y = (float)rand () / (float)(RAND_MAX);
          inside += is_inside (x, y);
        }
      vector[k] = (4. * inside / TOT_DART);
    }
}
