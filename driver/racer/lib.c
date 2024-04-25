#include "../../include/kernels.h"
#include "../../include/utils.h"

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
            RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim, fn, 3,        \
                                     kernel_args);                            \
            RacEr_mc_device_tile_groups_execute (&device);                    \
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
kernel2 (char *name_kernel, char *name_kernel_2,
         void (*kernel) (double *, double *, int),
         void (*kernel_2) (double *, double *, int), char *filename,
         struct bench *bench, int matrix_size)
{
  char buffer[1000];
  print_header_diff (buffer);

  // SET TO 2x2 on aws
  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };
  RacEr_mc_dimension_t grid_dim = { .x = _matrice_size / block_size_x,
                                    .y = _matrice_size / block_size_y };
  // Define device
  RacEr_mc_device_t device;

  for (int i = bench->start_size; i < bench->end_size; i += bench->step_size)
    {
      int _matrix_size = i;
      bench->data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;
      double *a, *b, *c, *d, *d_a, *d_b, *d_c, *d_d;
      a = (double *)malloc (sizeof (double) * _matrix_size_2);
      b = (double *)malloc (sizeof (double) * _matrix_size_2);
      c = (double *)malloc (sizeof (double) * _matrix_size_2);
      d = (double *)malloc (sizeof (double) * _matrix_size_2);

      // Alloc memory on device
      RacEr_mc_device_malloc (&device, _matrix_size_2 * sizeof (double), d_a);
      RacEr_mc_device_malloc (&device, _matrix_size_2 * sizeof (double), d_b);
      RacEr_mc_device_malloc (&device, _matrix_size_2 * sizeof (double), d_c);
      RacEr_mc_device_malloc (&device, _matrix_size_2 * sizeof (double), d_d);

      // copying init values
      for (int j = 0; j < _matrix_size; j++)
        {
          a[j] += drand48 ();
          c[j] = a[j];
        }
      RacEr_mc_device_memcpy (&device, d_a, a,
                              _matrix_size_2 * sizeof (double),
                              HB_MC_MEMCPY_TO_DEVICE);

      RacEr_mc_device_memcpy (&device, d_c, c,
                              _matrix_size_2 * sizeof (double),
                              HB_MC_MEMCPY_TO_DEVICE);

      int kernel_args[] = { d_a, d_b, _matrix_size };
      DRIVER_BODY (name_kernel);

      RacEr_mc_device_memcpy (&device, b, d_b,
                              _matrix_size_2 * sizeof (double),
                              HB_MC_MEMCPY_TO_HOST);

      formatting_data (bench->data);

      print_data_benchmark (name_kernel, bench->data, buffer);

      int kernel_args[] = { d_c, d_d, _matrix_size };

      DRIVER_BODY (name_kernel_2);

      RacEr_mc_device_memcpy (&device, d, d_d,
                              _matrix_size_2 * sizeof (double),
                              HB_MC_MEMCPY_TO_HOST);

      struct data data_2 = *bench->data;
      formatting_data (bench->data);
      print_data_benchmark (name_kernel_2, bench->data, buffer);

      bench->accuracy->accuracy = compute_err_accuracy (d, b, _matrix_size);
      bench->accuracy->RMS = RMS (d, b, _matrix_size);
      bench->accuracy->forward_error = forward_error (d, b, _matrix_size);

      print_diff_accuracy ("Comparaison", buffer, bench, &data_2);

      free (a);
      free (b);
      free (c);
      free (d);
      save_data (filename, buffer);
    }
}
