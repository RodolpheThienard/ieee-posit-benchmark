#include "../../include/utils.h"
#include <stdio.h>

void
square_root_newton_raphson (double *vector, int n)
{
  for (int i = 0; i < n; i++)
    {
      double approx = vector[i] * .5;
      if (vector[i] < 0)
        {
          perror ("Negative sqare root");
          exit (1);
        }
      if (vector[i] > 0)
        {
          do
            {
              approx = (approx + (vector[i] / approx)) / 2;
            }
          while (((approx * approx) - vector[i]) > 1e-8);
        }
      vector[i] = approx;
    }
}

void
sqrt_libmath (double *x, int n)
{
  for (int i = 0; i < n; i++)
    x[i] = sqrt (x[i]);
}
