#include "driver.h"
#include "kernels.h"
#include "utils.h"
#include <stdio.h>

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
  uint64_t _matrix_size = atoll (argv[1]);
  uint64_t _repetition = atoll (argv[2]);

  uint64_t _matrix_size_2 = _matrix_size * _matrix_size;

  float *a_32, *b_32, *c_32;
  ALLOC (a_32, _matrix_size_2);
  ALLOC (b_32, _matrix_size_2);
  ALLOC (c_32, _matrix_size_2);

  INIT (a_32, _matrix_size, 42);
  INIT (b_32, _matrix_size, 41);

  double *a_64, *b_64, *c_64;
  ALLOC (a_64, _matrix_size_2);
  ALLOC (b_64, _matrix_size_2);
  ALLOC (c_64, _matrix_size_2);

  INIT (a_64, _matrix_size, 42);
  INIT (b_64, _matrix_size, 41);

  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  printf ("%20s;  %13s; %13s; %13s; %13s; %13s; %13s; %13s; %13s; %13s\n",
          "title", (_matrix_size_2 > (1 << 20)) ? "MiB" : "KiB", "min (s)",
          "max (s)", "median (s)", "mean (s)", "dev %", "MiB/s", "Cycles",
          "Cycles/element");

  data->type = 4;
  driver_fp32 ("IEEE 32bits add", ieee_32bits_add, data, a_32, b_32, c_32,
               _matrix_size);
  driver_fp32 ("IEEE 32bits mul", ieee_32bits_mul, data, a_32, b_32, c_32,
               _matrix_size);
  driver_fp32 ("IEEE 32bits dp", ieee_32bits_dp, data, a_32, b_32, c_32,
               _matrix_size_2);
  driver_fp32 ("IEEE 32bits gemm", ieee_32bits_gemm, data, a_32, b_32, c_32,
               _matrix_size);

  data->type = 8;
  driver_fp64 ("IEEE 64bits add", ieee_64bits_add, data, a_64, b_64, c_64,
               _matrix_size);
  driver_fp64 ("IEEE 64bits mul", ieee_64bits_mul, data, a_64, b_64, c_64,
               _matrix_size);
  driver_fp64 ("IEEE 64bits dp", ieee_64bits_dp, data, a_64, b_64, c_64,
               _matrix_size_2);
  driver_fp64 ("IEEE 64bits gemm", ieee_64bits_gemm, data, a_64, b_64, c_64,
               _matrix_size);

  free (a_32);
  free (b_32);
  free (c_32);
  free (a_64);
  free (b_64);
  free (c_64);
  free (data);

  return 0;
}
