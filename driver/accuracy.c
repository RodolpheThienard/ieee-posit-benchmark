#include "../include/kernels.h"
#include "../include/utils.h"

// TODO
#define DRIVER_BODY_ACCURACY(fn, ...) kernel (__VA_ARGS__);

// generic error calculation function
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

double
forward_error (double *a, double *b, int n)
{
  int i = 0;
  double err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) / b[i];
    }
  return (err);
}

double
backward_error (double *a, double *b, double *c, int n)
{
  return 0;
}

/* driver for inv matrix computation
   Alloc and init matrix
   compute with given kernel
   compute identity matrix from A * A⁻¹
   check error between computed identity matrix and real identity matrix */
void
driver_inv_matrix_accuracy (char *title, char *buffer, void (*kernel) (),
                            struct accuracy *accuracy, uint64_t matrix_size)
{
  // initialisation matrix
  long _matrix_size_2 = matrix_size * matrix_size;
  double *a_64, *b_64, *c_64, *d_64;
  ALLOC (a_64, _matrix_size_2);
  ALLOC (b_64, _matrix_size_2);
  ALLOC (c_64, _matrix_size_2);
  ALLOC (d_64, _matrix_size_2);
  INIT (a_64, _matrix_size_2);
  INIT (b_64, _matrix_size_2);

  DRIVER_BODY_ACCURACY (kernel, a_64, b_64, matrix_size);
  fprintf (stdout, "%3.13lf; %3.13lf; %3.13lf; %3.13lf\n", a_64[0], b_64[0],
           c_64[0], d_64[0]);

  set_identity_matrix (c_64, matrix_size, matrix_size);
  ieee_64bits_gemm (c_64, b_64, d_64, matrix_size);
  DRIVER_BODY_ACCURACY (kernel, d_64, b_64, matrix_size);

  accuracy->accuracy = compute_err_accuracy (a_64, b_64, _matrix_size_2);
  accuracy->RMS = RMS (a_64, b_64, _matrix_size_2);

  accuracy->forward_error = forward_error (a_64, b_64, _matrix_size_2);
  accuracy->backward_error = backward_error (a_64, b_64, c_64, _matrix_size_2);

  fprintf (stdout, "%3.13lf; %3.13lf; %3.13lf; %3.13lf\n", a_64[0], b_64[0],
           c_64[0], d_64[0]);

  print_data_accuracy (title, buffer, accuracy);

  free (a_64);
  free (b_64);
  free (c_64);
  free (d_64);
}
