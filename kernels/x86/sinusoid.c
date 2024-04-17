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
sinus_maclaurin (double *vector, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      double result = 0.0;
      for (j = 0; j < 10; j++)
        {
          int sign = (j % 2 == 0) ? 1 : -1;
          int exponent = 2 * j + 1;
          double term
              = sign * pow (vector[i], exponent) / factorial (exponent);
          result += term;
        }
      vector[i] = result;
    }
}

void
sinus_libmath (double *vector, int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      vector[i] = sin (vector[i]);
    }
}
