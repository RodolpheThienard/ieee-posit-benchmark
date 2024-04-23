#include "../../include/utils.h"

double
factorial (int n)
{
  double result = 1.0;
  int i;
  for (i = 2; i <= n; i++)
    {
      result *= i;
    }
  return result;
}

void
sinus_maclaurin (double *input, double *output, int n)
{
  int i, j;
#pragma omp for
  for (i = 0; i < n; i++)
    {
      double result = 0.0;
      for (j = 0; j < 10; j++)
        {
          int sign = (j % 2 == 0) ? 1 : -1;
          int exponent = 2 * j + 1;
          double term = sign * pow (input[i], exponent) / factorial (exponent);
          result += term;
        }
      output[i] = result;
    }
}

void
sinus_libmath (double *input, double *output, int n)
{
  int i;
#pragma omp for
  for (i = 0; i < n; i++)
    {
      output[i] = sin (input[i]);
    }
}
