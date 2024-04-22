#include "../../include/kernels.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <string.h>

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
  print_header_benchmark (buffer, matrix_size);
  DRIVER_BODY (kernel, a, b, matrix_size);
  formatting_data (bench->data);

  print_data_benchmark (name_kernel, bench->data, buffer);
  DRIVER_BODY (kernel_2, c, d, matrix_size);
  formatting_data (bench->data);
  print_data_benchmark (name_kernel_2, bench->data, buffer);
  print_header_accuracy (buffer);

  bench->accuracy->accuracy = compute_err_accuracy (d, b, matrix_size);
  bench->accuracy->RMS = RMS (d, b, matrix_size);
  bench->accuracy->forward_error = forward_error (d, b, matrix_size);

  print_data_accuracy ("test", buffer, bench->accuracy);

  free (a);
  free (b);
  free (c);
  free (d);
}

void
kernel1 (char *name_kernel, void (*kernel) (), char *filename,
         struct bench *bench, int matrix_size)
{
  for (int i = bench->start_size; i < bench->end_size; i += bench->pitch_size)
    {
      char buffer[1000];
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
      save_data (filename, buffer);
    }
}

void
inversion (char *name_kernel, void (*kernel) (), char *filename,
           struct bench *bench, int matrix_size)
{
  char buffer[1000];
  print_header_benchmark (buffer, matrix_size);
  for (int i = bench->start_size; i < bench->end_size; i += bench->pitch_size)
    {
      long matrix_size_2 = i * i;

      double *a, *b, *c, *d;
      ALLOC (a, matrix_size_2);
      ALLOC (b, matrix_size_2);
      ALLOC (c, matrix_size_2);
      ALLOC (d, matrix_size_2);

      INIT (a, matrix_size_2);
      INIT (b, matrix_size_2);

      DRIVER_BODY (kernel, a, b, i);

      set_identity_matrix (c, i, i);
      ieee_64bits_gemm_jik (c, b, d, i);
      DRIVER_BODY (kernel, d, b, i);
      formatting_data (bench->data);
      print_data_benchmark (name_kernel, bench->data, buffer);
      // print_header_accuracy (buffer);

      bench->accuracy->accuracy = compute_err_accuracy (a, b, i);
      bench->accuracy->RMS = RMS (a, b, i);
      bench->accuracy->forward_error = forward_error (a, b, i);

      print_data_accuracy ("Accuracy measure", buffer, bench->accuracy);
      free (a);
      free (b);
      free (c);
      free (d);
      save_data (filename, buffer);
    }
}
/* API to run benchmark
   need to choose the accuracy driver */
void
benchmark (char *name_kernel, char *name_kernel_2, char *filename,
           void (*kernel) (), void (*kernel_2) (), struct bench *bench,
           enum benchmark_type type, int matrix_size)
{
  switch (type)
    {
    case INVERSION:
      inversion (name_kernel, kernel, filename, bench, matrix_size);
      break;
    case KERNEL1:
      kernel1 (name_kernel, kernel, filename, bench, matrix_size);
      break;
    case KERNEL2:
      kernel2 (name_kernel, name_kernel_2, kernel, kernel_2, filename, bench,
               matrix_size);
      break;
    }
}
