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
  struct bench_s bench = { data, accuracy, 100, 200, 100 };
  char buffer[1000];
  memset (buffer, 0, 1000 * sizeof (char));

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
      ALLOC (bb, _matrix_size_2);
      ALLOC (c_host, _matrix_size_2);
      ALLOC (c_device, _matrix_size_2);
      for (int indice = 0; indice < _matrix_size_2; indice++)
        {
          aa[indice] = drand48 ();
          bb[indice] = drand48 ();
        }
      // copying init values
      for (int ll = 0; ll < _matrix_size_2; ll++)
        {
          a[ll] = aa[ll];
          b[ll] = bb[ll];
        }

      driver_vector_add (vector_add, _matrix_size_2, a, b, c, &bench);
      conversion_into_double (c, c_device, _matrix_size_2);

      host_vector_add (aa, bb, c_host, _matrix_size_2);
      driver_accuracy (_matrix_size_2, c_host, c_device, &bench);
      print_data_accuracy (buffer, bench.accuracy);

      save_data (NULL, buffer);
    }

  return error_accuracy (&bench);
}
