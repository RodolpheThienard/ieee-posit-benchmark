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

  // driver_compare_accuracy ("LOG libmath & Taylor", accuracy_buffer,
  //                          logarithm_taylor, log_libmath, accuracy,
  //                          _matrix_size);

  // driver_compare_accuracy ("Conversion FP32 & FP64", accuracy_buffer,
  //                          useless_function, conversion_double_float,
  //                          accuracy, _matrix_size);

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
  data->type = sizeof (double);
  bench->end_size = 200;
  bench->pitch_size = 100;
  bench->start_size = 100;

  // KERNEL 2
  benchmark ("sinus_libmath", "sinus_macclaurin", NULL, sinus_libmath,
             sinus_maclaurin, bench, KERNEL2, _matrix_size);
  benchmark ("SQRT libmath", "SQRT newton", NULL, sqrt_libmath,
             square_root_newton_raphson, bench, KERNEL2, _matrix_size);

  // INVERSE MATRIX
  benchmark ("gauss jordan", NULL, NULL, inve_matrix_gauss_jordan, NULL, bench,
             INVERSION, _matrix_size);

  // KERNEL 1
  benchmark ("SQRT BLAS", NULL, NULL, ieee_64bits_sqrt, NULL, bench, KERNEL1,
             _matrix_size);

  free (data);

  return 0;
}
