#include "../../include/kernels.h"
#include "../../include/utils.h"

// TODO
#define DRIVER_BODY_ACCURACY(fn, ...)                                         \
  {                                                                           \
    _Pragma ("omp parallel") { fn (__VA_ARGS__); }                            \
    accuracy->accuracy = compute_err_accuracy (a_64, b_64, _matrix_size_2);   \
    accuracy->RMS = RMS (a_64, b_64, _matrix_size_2);                         \
    accuracy->forward_error = forward_error (a_64, b_64, _matrix_size_2);     \
  }

#define DRIVER_BODY_COMPARE_ACCURACY(fn, fn2, a, b, size)                     \
  {                                                                           \
    _Pragma ("omp parallel") { fn (a, size); }                                \
    _Pragma ("omp parallel") { fn2 (b, size); }                               \
    accuracy->accuracy = compute_err_accuracy (a_64, b_64, size);             \
    accuracy->RMS = RMS (a_64, b_64, size);                                   \
    accuracy->forward_error = forward_error (a_64, b_64, size);               \
  }

/* driver for inv matrix computation
   Alloc and init matrix
   compute with given kernel
   compute identity matrix from A * A⁻¹
   check error between computed identity matrix and real identity matrix */
void
driver_inv_matrix_accuracy (char *title, char *buffer, void (*kernel) (),
                            struct accuracy *accuracy, int matrix_size)
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

  set_identity_matrix (c_64, matrix_size, matrix_size);
  ieee_64bits_gemm_jik (c_64, b_64, d_64, matrix_size);
  DRIVER_BODY_ACCURACY (kernel, d_64, b_64, matrix_size);

  print_data_accuracy (title, buffer, accuracy);

  free (a_64);
  free (b_64);
  free (c_64);
  free (d_64);
}

/* driver to compare 2 vectors/matrix
   Alloc and init vector/matrix
   compute with given kernels
   check error between the two kernels  */
void
driver_compare_accuracy (char *title, char *buffer, void (*kernel) (),
                         void (*kernel_2) (), struct accuracy *accuracy,
                         int matrix_size)
{
  double *a_64, *b_64;
  ALLOC (a_64, matrix_size);
  ALLOC (b_64, matrix_size);
  INIT (a_64, matrix_size);

  // copying init values
  for (int i = 0; i < matrix_size; i++)
    {
      a_64[i] += drand48 ();
      b_64[i] = a_64[i];
    }

  DRIVER_BODY_COMPARE_ACCURACY (kernel, kernel_2, a_64, b_64, matrix_size);

  print_data_accuracy (title, buffer, accuracy);

  free (a_64);
  free (b_64);
}
