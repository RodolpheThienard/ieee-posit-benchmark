#include "../../include/utils.h"

void
host_square_root_newton_raphson (double *input, double *output, int n)
{
  for (int i = 0; i < n; i++)
    {
      double approx = input[i] * .5;
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
host_sqrt_libmath (double *input, double *output, int n)
{
  for (int i = 0; i < n; i++)
    output[i] = sqrt (input[i]);
}
