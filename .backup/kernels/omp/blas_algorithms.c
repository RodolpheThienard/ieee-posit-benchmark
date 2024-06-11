
#include "../../include/kernels.h"

void
vector_add (float *a, float *b, float *c, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    c[i] = a[i] + b[i];
}

void
vector_mul (float *a, float *b, float *c, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    c[i] = a[i] * b[i];
}

void
vector_div (float *a, float *b, float *c, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    c[i] = a[i] / b[i];
}

void
vector_sqrt (float *a, float *b, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    b[i] = sqrt (a[i]);
}

void
vector_reduction (float *restrict a, float *restrict b, float *restrict c,
                  int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    c[i] += a[i] * b[i];
}

void
sgemm (float *restrict a, float *restrict b, float *restrict c, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
        {
          const float _a_ = a[i * n + k];

#pragma omp simd
          for (int j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}
