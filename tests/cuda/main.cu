extern "C" {
  #include "../../include/utils.h"
}
  #include "../../include/driver.h"
  #include "../../include/cuda.h"
  #include "../../include/kernels.h"

int
main (int argc, char *argv[])
{
  struct data *data;
  data = (struct data *)malloc (sizeof (struct data));
  struct accuracy *accuracy;
  accuracy = (struct accuracy *)malloc (sizeof (struct accuracy));

  long _matrix_size = atoll (argv[1]);
  long _repetition = atoll (argv[2]);

  long _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  data->type = sizeof (double);
  struct bench bench = { data, accuracy, 100, 200, 100 };

               
  benchmark ("sinus_libmath", "sinus_macclaurin", NULL, sinus_libmath,
             sinus_maclaurin, &bench, KERNEL2, _matrix_size);
  // benchmark ("SQRT libmath", "SQRT newton", NULL, sqrt_libmath,
  //            square_root_newton_raphson, &bench, KERNEL2, _matrix_size);
  // benchmark ("Log libmath", "Log Taylor", NULL, log_libmath,
  // logarithm_taylor,
  //            &bench, KERNEL2, _matrix_size);

  // benchmark ("FP32", "FP64", NULL, conversion_double_float,
  // useless_function,
  //            &bench, KERNEL2, _matrix_size);
  // benchmark ("Monte-carlo-FP32", "Monte-carlo-FP64", NULL,
  //            monte_carlo_option_pricing_fp32,
  //            monte_carlo_option_pricing_fp64, &bench, KERNEL2,
  //            _matrix_size);
  // benchmark ("PI FP64", "PI FP32", NULL, pi_approximation_fp64,
  //            pi_approximation_fp32, &bench, KERNEL2, _matrix_size);
  // benchmark ("PI FP64", "Real PI", NULL, pi_approximation_fp64, real_pi,
  //            &bench, KERNEL2, _matrix_size);

  // INVERSE MATRIX
  // benchmark ("gauss jordan", NULL, "gauss.dat", inve_matrix_gauss_jordan,
  // NULL, &bench, INVERSION, _matrix_size);

  // KERNEL 1
  // benchmark ("SQRT BLAS", NULL, NULL, ieee_64bits_sqrt, NULL, &bench,
  // KERNEL1,
  //            _matrix_size);

  free (data);
  return 0;
}
