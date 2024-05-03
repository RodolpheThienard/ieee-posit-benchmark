
#include "../../include/driver.h"
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

  // ≃ 200 per kernel

  struct accuracy *accuracy;
  ALLOC (accuracy, 1);

  data->type = sizeof (double);
  struct bench_s bench = { data, accuracy, 100, 200, 100 };

  // INVERSE MATRIX
  // benchmark ("SQRT BLAS", NULL, NULL, ieee_64bits_sqrt, NULL, &bench,
  // KERNEL1, _matrix_size);

  free (data);

  return 0;
}
