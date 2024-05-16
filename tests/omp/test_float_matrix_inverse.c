
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
  char buffer[1000];
  memset (buffer, 0, 1000);
  data->type = sizeof (double);
  struct bench_s bench = { data, accuracy, 100, 200, 100 };

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      int _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;
      float *a, *b, *c;
      double *aa, *bb, *c_host, *c_device;
      ALLOC (a, _matrix_size_2);
      ALLOC (b, _matrix_size_2);
      ALLOC (c, _matrix_size_2);
      ALLOC (aa, _matrix_size_2);
      ALLOC (c_host, _matrix_size_2);
      ALLOC (c_device, _matrix_size_2);
      ALLOC (bb, _matrix_size_2);
      ALLOC (c_device, _matrix_size_2);
      INIT (aa, _matrix_size_2);
      // copying init values
      for (int indice = 0; indice < _matrix_size_2; indice++)
        {
          aa[indice] = drand48 ();
        }
      for (int ll = 0; ll < _matrix_size_2; ll++)
        {
          a[ll] = aa[ll];
        }

      driver_inverse_gauss_jordan (inve_matrix_gauss_jordan, i, a, b, &bench);
      conversion_into_double (b, c_device, _matrix_size_2);

      host_inve_matrix_gauss_jordan (aa, c_host, i);
      driver_accuracy (_matrix_size_2, c_host, c_device, &bench);
      print_data_accuracy (buffer, bench.accuracy);

      save_data (NULL, buffer);
    }

  free (data);

  return error_accuracy (&bench);
}
