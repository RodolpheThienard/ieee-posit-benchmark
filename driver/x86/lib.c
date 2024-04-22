#include "../../include/kernels.h"
#include "../../include/utils.h"
#include <stdio.h>

#define DRIVER_BODY(fn, ...)                                                  \
  {                                                                           \
    double init_time, end_time;                                               \
    long begin_register, end_register;                                        \
    for (int stability = 0; stability < 33; stability++)                      \
      {                                                                       \
        init_time = get_elapsedtime ();                                       \
        begin_register = rdtsc ();                                            \
        for (int rep = 0; rep < bench->data->repetition; rep++)               \
          {                                                                   \
            fn (__VA_ARGS__);                                                 \
          }                                                                   \
        end_register = rdtsc ();                                              \
        end_time = get_elapsedtime ();                                        \
        bench->data->RC[stability]                                            \
            = (end_register - begin_register) / bench->data->repetition;      \
        bench->data->samples[stability]                                       \
            = (end_time - init_time) / bench->data->repetition;               \
      }                                                                       \
  }

void
kernel2 (char *name_kernel, char *name_kernel_2, void (*kernel) (),
         void (*kernel_2) (), char *buffer, struct bench *bench,
         int matrix_size)
{
  long matrix_size_2 = matrix_size * matrix_size;
  double *a, *b, *c, *d;
  ALLOC (a, matrix_size_2);
  ALLOC (b, matrix_size_2);
  ALLOC (c, matrix_size_2);
  ALLOC (d, matrix_size_2);

  // copying init values
  for (int i = 0; i < matrix_size; i++)
    {
      a[i] += drand48 ();
      c[i] = a[i];
    }
  print_header_diff (buffer, matrix_size);

  DRIVER_BODY (kernel, a, b, matrix_size);
  formatting_data (bench->data);
  print_data_benchmark (name_kernel, bench->data, buffer);
  struct data kernel1 = *bench->data;

  DRIVER_BODY (kernel_2, c, d, matrix_size);
  formatting_data (bench->data);
  print_data_benchmark (name_kernel_2, bench->data, buffer);

  bench->accuracy->accuracy = compute_err_accuracy (d, b, matrix_size);
  bench->accuracy->RMS = RMS (d, b, matrix_size);
  bench->accuracy->forward_error = forward_error (d, b, matrix_size);

  print_diff_accuracy ("Comparaison", buffer, bench, &kernel1);

  free (a);
  free (b);
  free (c);
  free (d);
}

void
kernel1 (char *name_kernel, void (*kernel) (), char *buffer,
         struct bench *bench, int matrix_size)
{
  long matrix_size_2 = matrix_size * matrix_size;
  double *a, *b;
  ALLOC (a, matrix_size_2);
  ALLOC (b, matrix_size_2);

  // copying init values
  for (int i = 0; i < matrix_size; i++)
    {
      a[i] += drand48 ();
      b[i] = a[i];
    }
  print_header_benchmark (buffer, matrix_size);
  DRIVER_BODY (kernel, a, b, matrix_size);
  formatting_data (bench->data);
  print_data_benchmark (name_kernel, bench->data, buffer);
}

void
inversion (char *name_kernel, void (*kernel) (), char *buffer,
           struct bench *bench, int matrix_size)
{
  long matrix_size_2 = matrix_size * matrix_size;
  double *a, *b, *c, *d;
  ALLOC (a, matrix_size_2);
  ALLOC (b, matrix_size_2);
  ALLOC (c, matrix_size_2);
  ALLOC (d, matrix_size_2);

  INIT (a, matrix_size_2);
  INIT (b, matrix_size_2);

  print_header_benchmark (buffer, matrix_size);
  DRIVER_BODY (kernel, a, b, matrix_size);

  set_identity_matrix (c, matrix_size, matrix_size);
  ieee_64bits_gemm_jik (c, b, d, matrix_size);
  DRIVER_BODY (kernel, d, b, matrix_size);
  formatting_data (bench->data);
  print_data_benchmark (name_kernel, bench->data, buffer);
  print_header_accuracy (buffer);

  bench->accuracy->accuracy = compute_err_accuracy (a, b, matrix_size);
  bench->accuracy->RMS = RMS (a, b, matrix_size);
  bench->accuracy->forward_error = forward_error (a, b, matrix_size);

  print_data_accuracy ("Accuracy measure", buffer, bench->accuracy);
  free (a);
  free (b);
  free (c);
  free (d);
}
/* API to run benchmark
   need to choose the accuracy driver */
void
benchmark (char *name_kernel, char *name_kernel_2, char *buffer,
           void (*kernel) (), void (*kernel_2) (), struct bench *bench,
           enum benchmark_type type, int matrix_size)
{
  switch (type)
    {
    case INVERSION:
      inversion (name_kernel, kernel, buffer, bench, matrix_size);
      break;
    case KERNEL1:
      kernel1 (name_kernel, kernel, buffer, bench, matrix_size);
      break;
    case KERNEL2:
      kernel2 (name_kernel, name_kernel_2, kernel, kernel_2, buffer, bench,
               matrix_size);
      break;
    }
}
