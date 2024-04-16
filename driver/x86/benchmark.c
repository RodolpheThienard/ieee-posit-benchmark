#include "../../include/driver.h"

/// Utility macro defining the body of a driver function that benchmarks a
/// given routine.
#define DRIVER_BODY_BENCHMARK(fn, ...)                                        \
  double init_time, end_time;                                                 \
  long begin_register, end_register;                                          \
  for (int stability = 0; stability < 33; stability++)                        \
    {                                                                         \
      init_time = get_elapsedtime ();                                         \
      begin_register = rdtsc ();                                              \
      for (int rep = 0; rep < data->repetition; rep++)                        \
        {                                                                     \
          fn (__VA_ARGS__);                                                   \
        }                                                                     \
      end_register = rdtsc ();                                                \
      end_time = get_elapsedtime ();                                          \
      data->RC[stability]                                                     \
          = (end_register - begin_register) / data->repetition;               \
      data->samples[stability] = (end_time - init_time) / data->repetition;   \
    }

//
void
driver_fp32_benchmark (char *title, char *buffer, void (*kernel) (),
                       struct data *data, int matrix_size)
{

  // initialisation matrix
  long _matrix_size_2 = matrix_size * matrix_size;
  float *a_32, *b_32, *c_32;
  ALLOC (a_32, _matrix_size_2);
  ALLOC (b_32, _matrix_size_2);
  ALLOC (c_32, _matrix_size_2);
  INIT (a_32, matrix_size);
  INIT (b_32, matrix_size);

  DRIVER_BODY_BENCHMARK (kernel, a_32, b_32, c_32, matrix_size);
  formatting_data (data);
  print_data_benchmark (title, data, buffer);

  free (a_32);
  free (b_32);
  free (c_32);
}

//
void
driver_fp32_vector_benchmark (char *title, char *buffer, void (*kernel) (),
                              struct data *data, int matrix_size)
{
  // initialisation matrix
  long _matrix_size_2 = matrix_size * matrix_size;
  float *a_32, *b_32;
  ALLOC (a_32, _matrix_size_2);
  ALLOC (b_32, _matrix_size_2);
  INIT (a_32, matrix_size);
  INIT (b_32, matrix_size);

  DRIVER_BODY_BENCHMARK (kernel, a_32, b_32, matrix_size);
  formatting_data (data);
  print_data_benchmark (title, data, buffer);

  free (a_32);
  free (b_32);
}

//
void
driver_fp64_benchmark (char *title, char *buffer, void (*kernel) (),
                       struct data *data, int matrix_size)
{
  // initialisation matrix
  long _matrix_size_2 = matrix_size * matrix_size;
  double *a_64, *b_64, *c_64;
  ALLOC (a_64, _matrix_size_2);
  ALLOC (b_64, _matrix_size_2);
  ALLOC (c_64, _matrix_size_2);
  INIT (a_64, matrix_size);
  INIT (b_64, matrix_size);

  DRIVER_BODY_BENCHMARK (kernel, a_64, b_64, c_64, matrix_size);
  formatting_data (data);
  print_data_benchmark (title, data, buffer);

  free (a_64);
  free (b_64);
  free (c_64);
}
