#include "../../include/kernels.h"

void
host_vector_add (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    c[i] = a[i] + b[i];
}

void
host_vector_mul (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    c[i] = a[i] * b[i];
}

void
host_vector_div (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    c[i] = a[i] / b[i];
}

void
host_vector_sqrt (double *a, double *b, int n)
{
  for (int i = 0; i < n; i++)
    b[i] = sqrt (a[i]);
}

void
host_vector_dp (double *restrict a, double *restrict b, double *restrict c,
                int n)
{
  for (int i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
host_dgemm (double *restrict a, double *restrict b, double *restrict c, int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
        {
          const double _a_ = a[i * n + k];

          for (int j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}
