#include "../include/driver.h"

/// Utility macro defining the body of a driver function that benchmarks a
/// given routine.
#define DRIVER_BODY(fn, ...)                                                  \
  double init_time, end_time;                                                 \
  uint64_t begin_register, end_register;                                      \
  for (uint32_t stability = 0; stability < 33; stability++)                   \
    {                                                                         \
      init_time = get_elapsedtime ();                                         \
      begin_register = rdtsc ();                                              \
      for (uint32_t rep = 0; rep < data->repetition; rep++)                   \
        {                                                                     \
          kernel (__VA_ARGS__);                                               \
        }                                                                     \
      end_register = rdtsc ();                                                \
      end_time = get_elapsedtime ();                                          \
      data->RC[stability]                                                     \
          = (end_register - begin_register) / data->repetition;               \
      data->samples[stability] = (end_time - init_time) / data->repetition;   \
    }

//
void
driver_fp32 (char *title, char *buffer, void (*kernel) (), struct data *data,
             float *restrict a_32, float *restrict b_32, float *restrict c_32,
             uint64_t matrix_size)
{
  DRIVER_BODY (kernel, a_32, b_32, c_32, matrix_size);
  formatting_data (data);
  print_data (title, data, buffer);
}

//
void
driver_fp32_vector (char *title, char *buffer, void (*kernel) (),
                    struct data *data, float *restrict a_32,
                    float *restrict b_32, uint64_t matrix_size)
{
  DRIVER_BODY (kernel, a_32, b_32, matrix_size);
  formatting_data (data);
  print_data (title, data, buffer);
}

//
void
driver_fp64 (char *title, char *buffer, void (*kernel) (), struct data *data,
             double *restrict a_64, double *restrict b_64,
             double *restrict c_64, uint64_t matrix_size)
{
  DRIVER_BODY (kernel, a_64, b_64, c_64, matrix_size);
  formatting_data (data);
  print_data (title, data, buffer);
}
