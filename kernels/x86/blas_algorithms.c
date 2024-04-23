#include "../../include/kernels.h"

void
ieee_32bits_add (float *a, float *b, float *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] + b[i * n + j];
}

void
ieee_32bits_mul (float *a, float *b, float *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] * b[i * n + j];
}

void
ieee_32bits_div (float *a, float *b, float *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] / b[i * n + j];
}

void
ieee_32bits_sqrt (float *a, float *b, float *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = sqrt (a[i * n + j]);
}

void
ieee_32bits_dp (float *restrict a, float *restrict b, float *restrict c, int n)
{
  for (int i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
ieee_32bits_gemm (float *restrict a, float *restrict b, float *restrict c,
                  int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
        {
          const float _a_ = a[i * n + k];

          for (int j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}

void
ieee_64bits_add (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] + b[i * n + j];
}

void
ieee_64bits_mul (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] * b[i * n + j];
}

void
ieee_64bits_div (double *a, double *b, double *c, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] / b[i * n + j];
}

void
ieee_64bits_sqrt (double *a, double *b, int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      b[i * n + j] = sqrt (a[i * n + j]);
}
void
ieee_64bits_dp (double *restrict a, double *restrict b, double *restrict c,
                int n)
{
  for (int i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
ieee_64bits_gemm_jik (double *restrict a, double *restrict b,
                      double *restrict c, int n)
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
