#include "../../include/driver.h"
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
        for (int rep = 0; rep < bench.data->repetition; rep++)                \
          {                                                                   \
            fn (__VA_ARGS__);                                                 \
          }                                                                   \
        end_register = rdtsc ();                                              \
        end_time = get_elapsedtime ();                                        \
        bench.data->RC[stability]                                             \
            = (end_register - begin_register) / bench.data->repetition;       \
        bench.data->samples[stability]                                        \
            = (end_time - init_time) / bench.data->repetition;                \
      }                                                                       \
  }

int
main (int argc, char *argv[])
{
  if (argc < 3)
    {
      perror ("Not enough parameters");
      exit (1);
    };

  struct data *data;
  ALLOC (data, 1);
  long _matrix_size = atoll (argv[1]);
  long _repetition = atoll (argv[2]);

  long _matrix_size_2 = _matrix_size * _matrix_size;

  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  struct accuracy *accuracy;
  ALLOC (accuracy, 1);

  data->type = sizeof (double);
  struct bench bench = { data, accuracy, 100, 200, 100 };
  char buffer[1000];
  print_header_benchmark (buffer);

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      int _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;
      double *a, *b, *c;
      ALLOC (a, _matrix_size_2);
      ALLOC (b, _matrix_size_2);
      ALLOC (c, _matrix_size_2);

      // copying init values
      for (int i = 0; i < _matrix_size; i++)
        {
          a[i] += drand48 ();
          b[i] = a[i];
        }
      DRIVER_BODY (ieee_64bits_gemm_jik, a, b, c, _matrix_size);
      formatting_data (bench.data);
      print_data_benchmark ("ieee_64bits_gemm_ijk", bench.data, buffer);
      save_data (NULL, buffer);
    }

  free (data);

  return 0;
}
