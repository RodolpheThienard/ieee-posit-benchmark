#include "../../include/utils.h"

void
conversion_double_float (double *a, int n)
{
  float tmp[n];
  for (int i = 0; i < n; i++)
    {
      tmp[i] = (float)a[i];
      a[i] = (double)tmp[i];
    }
}

void
useless_function (double *a, int i)
{
}
