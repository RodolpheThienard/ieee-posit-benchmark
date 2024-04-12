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

  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char *benchmark_buffer;
  char *accuracy_buffer;
  ALLOC (benchmark_buffer, 200 * 11);
  ALLOC (accuracy_buffer, 200 * 1);
  print_header_benchmark (benchmark_buffer, _matrix_size_2 * 2);

  data->type = sizeof (float);
  driver_fp32_benchmark ("IEEE 32bits add", benchmark_buffer, ieee_32bits_add,
                         data, _matrix_size);
  driver_fp32_benchmark ("IEEE 32bits mul", benchmark_buffer, ieee_32bits_mul,
                         data, _matrix_size);
  driver_fp32_benchmark ("IEEE 32bits sqrt", benchmark_buffer,
                         ieee_32bits_sqrt, data, _matrix_size);
  driver_fp32_benchmark ("IEEE 32bits dp", benchmark_buffer, ieee_32bits_dp,
                         data, _matrix_size);
  driver_fp32_benchmark ("IEEE 32bits gemm", benchmark_buffer,
                         ieee_32bits_gemm, data, _matrix_size);

  data->type = sizeof (double);
  driver_fp64_benchmark ("IEEE 64bits add", benchmark_buffer, ieee_64bits_add,
                         data, _matrix_size);
  driver_fp64_benchmark ("IEEE 64bits mul", benchmark_buffer, ieee_64bits_mul,
                         data, _matrix_size);
  driver_fp64_benchmark ("IEEE 64bits sqrt", benchmark_buffer,
                         ieee_64bits_sqrt, data, _matrix_size);
  driver_fp64_benchmark ("IEEE 64bits dp", benchmark_buffer, ieee_64bits_dp,
                         data, _matrix_size);
  driver_fp64_benchmark ("IEEE 64bits gemm", benchmark_buffer,
                         ieee_64bits_gemm, data, _matrix_size);

  save_data (NULL, benchmark_buffer);

  struct accuracy *accuracy;
  ALLOC (accuracy, 1);

  print_header_accuracy (accuracy_buffer);

  driver_inv_matrix_accuracy ("Matrix inversion", accuracy_buffer,
                              inve_matrix_gauss_jordan, accuracy,
                              _matrix_size);

  save_data (NULL, accuracy_buffer);

  free (data);

  return 0;
}
