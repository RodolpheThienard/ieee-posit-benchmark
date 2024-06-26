#include "../include/utils.h"

// generic error calculation function
/* sum(A-B)/n */
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

/* sqrt (sum(A-B)²/n) */
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

/* A-Ã/A */
double
forward_error (double *a, double *b, int n)
{
  int i = 0;
  double err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) / a[i];
    }
  return (err);
}
float
compute_err_accuracy_float (float *a, float *b, int n)
{
  int i = 0;
  float err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += a[i] - b[i];
    }
  return (err / n);
}

/* sqrt (sum(A-B)²/n) */
float
RMS_float (float *a, float *b, int n)
{
  int i = 0;
  float err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) * (a[i] - b[i]);
    }
  err /= n;
  return sqrt (err);
}

/* A-Ã/A */
float
forward_error_float (float *a, float *b, int n)
{
  int i = 0;
  float err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) / a[i];
    }
  return (err);
}

void
conversion_into_double (float *src, double *dst, int n)
{
  int i = 0;
  for (i = 0; i < n; i++)
    dst[i] = (double)src[i];
}

int
error_accuracy (struct bench_s *bench)
{
  double err = bench->accuracy->accuracy;
  return (err > 1E-6 || err < -1E-6) ? 1 : 0;
}
