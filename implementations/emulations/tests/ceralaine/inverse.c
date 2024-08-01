#include "softposit.h"
#include "softposit_types.h"
#include <math.h>
#include <stdlib.h>

void
host_inve_matrix_gauss_jordan (posit32_t *mat, posit32_t *inv, int n)
{
  posit32_t temp[n * n];
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
              inv[i * n + j] = convertFloatToP32 (1.0);
            }
          else
            {
              inv[i * n + j] = convertFloatToP32 (0.0);
            }
        }
    }

  // Gauss-Jordan elimination
  for (int i = 0; i < n; i++)
    {
      // get pivot
      posit32_t pivot = temp[i * n + i];

      // Dividing by pivot
      for (int j = 0; j < n; j++)
        {
          temp[i * n + j] = p32_div (temp[i * n + j], pivot);
          inv[i * n + j] = p32_div (inv[i * n + j], pivot);
        }

      // remove other elements
      for (int k = 0; k < n; k++)
        {
          if (k != i)
            {
              posit32_t coeff = temp[k * n + i];
              for (int j = 0; j < n; j++)
                {
                  temp[k * n + j] = p32_sub (temp[k * n + j],
                                             p32_mul (coeff, temp[i * n + j]));
                  inv[k * n + j] = p32_sub (inv[k * n + j],
                                            p32_mul (coeff, inv[i * n + j]));
                }
            }
        }
    }
}
double
compute_err_accuracy (double *a, double *b, int n)
{
  int i = 0;
  double err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += a[i] - b[i];
    }
  return (err / n);
}

double
sqrt_bisection (double x)
{
  double low = 0, high = x, mid;
  double epsilon = 1e-8; // précision souhaitée

  while ((high - low) > epsilon)
    {
      mid = (low + high) / 2.0;
      if (mid * mid > x)
        {
          high = mid;
        }
      else
        {
          low = mid;
        }
    }
  return (low + high) / 2.0;
}

double
RMS (double *a, double *b, int n)
{
  int i = 0;
  double err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) * (a[i] - b[i]);
    }
  err /= n;
  return sqrt (err);
}
void
print_matrix (double *a, int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        printf ("%lf ", a[i * n + j]);
      printf ("\n");
    }
}

/* A-Ã/A */
double
forward_error (double *a, double *b, int n)
{
  double x = 0.0;
  double x_err = 0.0;

  // norm X
  for (int i = 0; i < n; i++)
    x += a[i] * a[i];
  x = (double)sqrt (x);

  for (int i = 0; i < n; i++)
    x_err += (a[i] - b[i]) * (a[i] - b[i]);
  x_err = (double)sqrt (x);

  return x_err / x;
}

int
main (int argc, char *argv[])
{
  int _matrix_size = 100;
  long _matrix_size_2 = _matrix_size * _matrix_size;
  posit32_t a_p[_matrix_size_2];
  posit32_t b_p[_matrix_size_2];
  posit32_t c_p[_matrix_size_2];
  float a[_matrix_size_2], b[_matrix_size_2], c[_matrix_size_2];
  double a_out[_matrix_size_2], b_out[_matrix_size_2];
  // copying init values
  for (int ll = 0; ll < _matrix_size_2; ll++)
    {
      a[ll] = (float)((double)rand () / (double)RAND_MAX * 10);
      a_p[ll] = convertFloatToP32 (a[ll]);
    }

  host_inve_matrix_gauss_jordan (a_p, c_p, _matrix_size);
  host_inve_matrix_gauss_jordan (c_p, b_p, _matrix_size);

  for (int ll = 0; ll < _matrix_size_2; ll++)
    {
      a_out[ll] = convertP32ToDouble (a_p[ll]);
      b_out[ll] = convertP32ToDouble (b_p[ll]);
    }
  print_matrix (a_out, 2, 2);
  print_matrix (b_out, 2, 2);
  double res = compute_err_accuracy (a_out, b_out, _matrix_size_2);
  double rms = RMS (a_out, b_out, _matrix_size_2);
  double forward = forward_error (a_out, b_out, _matrix_size_2);

  printf ("res = %lf, rms = %lf, forward = %lf\n", res, rms, forward);
  return 0;
}
