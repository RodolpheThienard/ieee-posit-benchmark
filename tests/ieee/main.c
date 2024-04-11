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
  uint64_t _matrix_size = atoll (argv[1]);
  uint64_t _repetition = atoll (argv[2]);

  uint64_t _matrix_size_2 = _matrix_size * _matrix_size;

  float *a_32, *b_32, *c_32;
  ALLOC (a_32, _matrix_size_2);
  ALLOC (b_32, _matrix_size_2);
  ALLOC (c_32, _matrix_size_2);

  INIT (a_32, _matrix_size);
  INIT (b_32, _matrix_size);

  double *a_64, *b_64, *c_64;
  ALLOC (a_64, _matrix_size_2);
  ALLOC (b_64, _matrix_size_2);
  ALLOC (c_64, _matrix_size_2);

  INIT (a_64, _matrix_size);
  INIT (b_64, _matrix_size);

  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char *output_buffer = malloc (sizeof (char) * 200 * 11);
  print_header (output_buffer, _matrix_size_2 * 2);

  data->type = sizeof (float);
  driver_fp32 ("IEEE 32bits add", output_buffer, ieee_32bits_add, data, a_32,
               b_32, c_32, _matrix_size);
  driver_fp32 ("IEEE 32bits mul", output_buffer, ieee_32bits_mul, data, a_32,
               b_32, c_32, _matrix_size);
  driver_fp32 ("IEEE 32bits sqrt", output_buffer, ieee_32bits_sqrt, data, a_32,
               b_32, c_32, _matrix_size);
  driver_fp32 ("IEEE 32bits dp", output_buffer, ieee_32bits_dp, data, a_32,
               b_32, c_32, _matrix_size_2);
  driver_fp32 ("IEEE 32bits gemm", output_buffer, ieee_32bits_gemm, data, a_32,
               b_32, c_32, _matrix_size);

  data->type = sizeof (double);
  driver_fp64 ("IEEE 64bits add", output_buffer, ieee_64bits_add, data, a_64,
               b_64, c_64, _matrix_size);
  driver_fp64 ("IEEE 64bits mul", output_buffer, ieee_64bits_mul, data, a_64,
               b_64, c_64, _matrix_size);
  driver_fp64 ("IEEE 64bits sqrt", output_buffer, ieee_64bits_sqrt, data, a_64,
               b_64, c_64, _matrix_size);
  driver_fp64 ("IEEE 64bits dp", output_buffer, ieee_64bits_dp, data, a_64,
               b_64, c_64, _matrix_size_2);
  driver_fp64 ("IEEE 64bits gemm", output_buffer, ieee_64bits_gemm, data, a_64,
               b_64, c_64, _matrix_size);

  save_data ("test.csv", output_buffer);

  free (a_32);
  free (b_32);
  free (c_32);
  free (a_64);
  free (b_64);
  free (c_64);
  free (data);

  return 0;
}
