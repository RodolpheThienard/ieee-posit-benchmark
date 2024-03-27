#include "kernels.h"
#include <stdint.h>

void
ieee_32bits_add (float *a, float *b, float *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] + b[i * n + j];
}

void
ieee_32bits_mul (float *a, float *b, float *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] * b[i * n + j];
}

void
ieee_32bits_dp (float *restrict a, float *restrict b, float *restrict c,
                uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
ieee_32bits_gemm (float *restrict a, float *restrict b, float *restrict c,
                  uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    {
      for (uint64_t k = 0; k < n; k++)
        {
          const float _a_ = a[i * n + k];

          for (uint64_t j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}

void
ieee_64bits_add (double *a, double *b, double *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] + b[i * n + j];
}

void
ieee_64bits_mul (double *a, double *b, double *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] * b[i * n + j];
}

void
ieee_64bits_dp (double *restrict a, double *restrict b, double *restrict c,
                uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
ieee_64bits_gemm (double *restrict a, double *restrict b, double *restrict c,
                  uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    {
      for (uint64_t k = 0; k < n; k++)
        {
          const double _a_ = a[i * n + k];

          for (uint64_t j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}
