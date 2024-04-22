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
  char *benchmark_buffer;
  char *accuracy_buffer;
  ALLOC (benchmark_buffer, 200 * 20);
  ALLOC (accuracy_buffer, 200 * 10);

  print_header_benchmark (benchmark_buffer, _matrix_size_2 * 2);

  // data->type = sizeof (float);
  // driver_fp32_benchmark ("IEEE 32bits add", benchmark_buffer,
  // ieee_32bits_add,
  //                        data, _matrix_size);
  // driver_fp32_benchmark ("IEEE 32bits mul", benchmark_buffer,
  // ieee_32bits_mul,
  //                        data, _matrix_size);
  // driver_fp32_benchmark ("IEEE 32bits sqrt", benchmark_buffer,
  //                        ieee_32bits_sqrt, data, _matrix_size);
  // driver_fp32_benchmark ("IEEE 32bits dp", benchmark_buffer, ieee_32bits_dp,
  //                        data, _matrix_size_2);
  // driver_fp32_benchmark ("IEEE 32bits gemm", benchmark_buffer,
  //                        ieee_32bits_gemm, data, _matrix_size);

  data->type = sizeof (double);
  // driver_fp64_benchmark ("IEEE 64bits add", benchmark_buffer,
  // ieee_64bits_add,
  //                        data, _matrix_size);
  // driver_fp64_benchmark ("IEEE 64bits mul", benchmark_buffer,
  // ieee_64bits_mul,
  //                        data, _matrix_size);
  // driver_fp64_benchmark ("IEEE 64bits sqrt", benchmark_buffer,
  //                        ieee_64bits_sqrt, data, _matrix_size);
  // driver_fp64_benchmark ("IEEE 64bits dp", benchmark_buffer, ieee_64bits_dp,
  //                        data, _matrix_size_2);
  // driver_fp64_benchmark ("IEEE 64bits gemm", benchmark_buffer,
  //                        ieee_64bits_gemm_jik, data, _matrix_size);

  // save_data (NULL, benchmark_buffer);

  // puts ("\n");

  struct accuracy *accuracy;
  ALLOC (accuracy, 1);

  // print_header_accuracy (accuracy_buffer);

  // driver_inv_matrix_accuracy ("Inversion Gauss-Jordan", accuracy_buffer,
  //                             inve_matrix_gauss_jordan, accuracy,
  //                             _matrix_size);

  // driver_compare_accuracy ("LOG libmath & Taylor", accuracy_buffer,
  //                          logarithm_taylor, log_libmath, accuracy,
  //                          _matrix_size);

  // driver_compare_accuracy ("Conversion FP32 & FP64", accuracy_buffer,
  //                          useless_function, conversion_double_float,
  //                          accuracy, _matrix_size);

  // driver_compare_accuracy ("SQRT libmath & newton", accuracy_buffer,
  //                          square_root_newton_raphson, sqrt_libmath,
  //                          accuracy, _matrix_size);
  // driver_compare_accuracy ("Sin libmath & Maclaurin", accuracy_buffer,
  //                          sinus_maclaurin, sinus_libmath, accuracy,
  //                          _matrix_size);
  // driver_compare_accuracy_fp64_fp32 (
  //     "monte carlo finance", accuracy_buffer,
  //     monte_carlo_option_pricing_fp64, monte_carlo_option_pricing_fp32,
  //     accuracy, _matrix_size);
  // driver_compare_accuracy ("Monte carlo PI FP64", accuracy_buffer, real_pi,
  //                          pi_approximation_fp64, accuracy, _matrix_size);

  // driver_compare_accuracy_fp64_fp32 ("Monte carlo PI FP32", accuracy_buffer,
  //                                    real_pi, pi_approximation_fp32,
  //                                    accuracy, _matrix_size);

  struct bench *bench;
  ALLOC (bench, 1);
  bench->accuracy = accuracy;
  bench->data = data;
  benchmark ("sinus_libmath", "sinus_macclaurin", accuracy_buffer,
             sinus_libmath, sinus_maclaurin, bench, KERNEL2, _matrix_size);
  benchmark ("SQRT libmath", "SQRT newton", accuracy_buffer, sqrt_libmath,
             square_root_newton_raphson, bench, KERNEL2, _matrix_size);
  benchmark ("gauss jordan", NULL, accuracy_buffer, inve_matrix_gauss_jordan,
             NULL, bench, INVERSION, _matrix_size);

  benchmark ("SQRT BLAS", NULL, accuracy_buffer, ieee_64bits_sqrt, NULL, bench,
             KERNEL1, _matrix_size);

  save_data (NULL, accuracy_buffer);

  free (data);

  return 0;
}
