#include "../../include/utils.h"
#include <stdlib.h>
#define TOT_DART 1e7
#define PI 3.1415926535

#define is_inside(x, y) (x * x + y * y) <= 1 ? 1 : 0

void
host_pi_approximation (double *input, double *output, int n)
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
      output[k] = (4. * inside / TOT_DART);
    }
}
