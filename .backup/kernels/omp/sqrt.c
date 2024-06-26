#include "../../include/utils.h"

void
square_root_newton_raphson (float *input, float *output, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    {
      float approx = input[i] * .5;
      if (input[i] < 0)
        {
          perror ("Negative sqare root");
          exit (1);
        }
      if (input[i] > 0)
        {
          do
            {
              approx = (approx + (input[i] / approx)) / 2;
            }
          while (((approx * approx) - input[i]) > 1e-8);
        }
      output[i] = approx;
    }
}

void
sqrt_libmath (float *input, float *output, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    output[i] = sqrt (input[i]);
}
