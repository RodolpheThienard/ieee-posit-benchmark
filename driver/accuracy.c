#include "../include/kernels.h"
#include "../include/utils.h"

// TODO
#define DRIVER_BODY_ACCURACY(fn, ...) kernel (__VA_ARGS__);

// generic error calculation function
#define compute_err_accuracy(a, b, N, err)                                    \
  int i = 0;                                                                  \
  err = 0.0;                                                                  \
  for (i = 0; i < N; i++)                                                     \
    {                                                                         \
      err += a[i] - b[i];                                                     \
    }                                                                         \
  err /= N;

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

  ieee_64bits_gemm (a_64, b_64, c_64, matrix_size);
  set_identity_matrix (d_64, matrix_size, matrix_size);
  compute_err_accuracy (c_64, d_64, _matrix_size_2, accuracy->accuracy);

  print_data_accuracy (title, buffer, accuracy);

  free (a_64);
  free (b_64);
  free (c_64);
  free (d_64);
}
