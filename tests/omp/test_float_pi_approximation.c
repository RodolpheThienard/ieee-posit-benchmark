
#include "../../include/driver.h"
#include "../../include/host_kernels.h"
#include "../../include/kernels.h"
#include "../../include/utils.h"

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

  data->type = sizeof (float);
  struct bench_s bench = { data, accuracy, 10, 20, 10 };
  char buffer[1000];
  memset (buffer, 0, 1000 * sizeof (char));

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      int _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;
      float *a, *b;
      double *aa, *b_host, *b_device;
      ALLOC (a, _matrix_size_2);
      ALLOC (b, _matrix_size_2);
      ALLOC (aa, _matrix_size_2);
      ALLOC (b_host, _matrix_size_2);
      ALLOC (b_device, _matrix_size_2);

      driver_pi_approximation (pi_approximation, _matrix_size_2, a, b, &bench);
      conversion_into_double (b, b_device, _matrix_size_2);

      host_pi_approximation (aa, b_host, _matrix_size_2);
      driver_accuracy (_matrix_size_2, b_host, b_device, &bench);
      print_data_accuracy (buffer, bench.accuracy);

      save_data (NULL, buffer);
    }

  return error_accuracy (&bench);
}
