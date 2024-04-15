#include "../../include/kernels.h"
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
ieee_32bits_div (float *a, float *b, float *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] / b[i * n + j];
}

void
ieee_32bits_sqrt (float *a, float *b, float *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = sqrt (a[i * n + j]);
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
ieee_64bits_div (double *a, double *b, double *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = a[i * n + j] / b[i * n + j];
}

void
ieee_64bits_sqrt (double *a, double *b, double *c, uint64_t n)
{
  for (uint64_t i = 0; i < n; i++)
    for (uint64_t j = 0; j < n; j++)
      c[i * n + j] = sqrt (a[i * n + j]);
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

void
inve_matrix_gauss_jordan (double *restrict mat, double *restrict inv, int n)
{
  double *temp = malloc (n * n * sizeof (double));
  for (int i = 0; i < n * n; i++)
    {
      temp[i] = mat[i];
    }

  // init identity matrix
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (i == j)
            {
              inv[i * n + j] = 1.0;
            }
          else
            {
              inv[i * n + j] = 0.0;
            }
        }
    }

  // Gauss-Jordan elimination
  for (int i = 0; i < n; i++)
    {
      // get pivot
      double pivot = temp[i * n + i];

      // Dividing by pivot
      for (int j = 0; j < n; j++)
        {
          temp[i * n + j] /= pivot;
          inv[i * n + j] /= pivot;
        }

      // remove other elements
      for (int k = 0; k < n; k++)
        {
          if (k != i)
            {
              double coeff = temp[k * n + i];
              for (int j = 0; j < n; j++)
                {
                  temp[k * n + j] -= coeff * temp[i * n + j];
                  inv[k * n + j] -= coeff * inv[i * n + j];
                }
            }
        }
    }

  // free memory
  free (temp);
}

void
log_libmath (double *x, int n)
{
  for (int i = 0; i < n; i++)
    x[i] = log (x[i]);
}

void
logarithm_taylor (double *x, int n)
{
  int iter = 100;
  for (int j = 0; j < n; j++)
    {
      if (x[j] <= 0)
        {
          printf ("Erreur : Le logarithme ne peut être calculé pour des "
                  "valeurs négatives ou nulles.\n");
          continue; // Passe à la valeur suivante si x[j] est négatif ou nul
        }

      double result = 0.0;
      double term = x[j] - 1.0; // Premier terme de la série de Taylor

      for (int i = 1; i <= iter; i++)
        {
          if (i % 2 == 0)
            {
              result -= term / i;
            }
          else
            {
              result += term / i;
            }
          term *= (x[j] - 1.0);
        }
      x[j] = result;
    }
}
