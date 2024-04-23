#include "../../include/utils.h"

void
conversion_double_float (double *input, double *output, int n)
{
  float tmp[n];
#pragma omp for
  for (int i = 0; i < n; i++)
    {
      tmp[i] = (float)input[i];
      output[i] = (double)tmp[i];
    }
}

void
useless_function (double *input, double *output, int n)
{
}
