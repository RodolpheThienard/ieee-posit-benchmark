#pragma once
#include "utils.h"

/// BENCHMARK
// IEEE
void ieee_32bits_add (float *matrix1, float *matrix2, float *matrix3,
                      int size);
void ieee_32bits_mul (float *matrix1, float *matrix2, float *matrix3,
                      int size);
void ieee_32bits_div (float *matrix1, float *matrix2, float *matrix3,
                      int size);
void ieee_32bits_sqrt (float *matrix1, float *matrix2, float *matrix3,
                       int size);
void ieee_32bits_dp (float *matrix1, float *matrix2, float *matrix3, int size);
void ieee_32bits_gemm (float *matrix1, float *matrix2, float *matrix3,
                       int size);

void ieee_64bits_add (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void ieee_64bits_mul (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void ieee_64bits_div (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void ieee_64bits_sqrt (double *matrix1, double *matrix2, int size);
void ieee_64bits_dp (double *matrix1, double *matrix2, double *matrix3,
                     int size);
void ieee_64bits_gemm_ijk (double *matrix1, double *matrix2, double *matrix3,
                           int size);
void ieee_64bits_gemm_jik (double *matrix1, double *matrix2, double *matrix3,
                           int size);
void ieee_64bits_gemm_bloc (double *matrix1, double *matrix2, double *matrix3,
                            int size);

/// ACCURACY
void inve_matrix_gauss_jordan (double *matrix1, double *matrix2, int size);
void logarithm_taylor (double *vector, int size);
void log_libmath (double *vector, int size);
void conversion_double_float (double *vector, int size);
void useless_function (double *vector, int size);
void square_root_newton_raphson (double *input, double *output, int size);
void sqrt_libmath (double *input, double *output, int size);
void sinus_maclaurin (double *input, double *output, int size);
void sinus_libmath (double *input, double *output, int size);
void monte_carlo_option_pricing_fp64 (double *vector, int n);
void monte_carlo_option_pricing_fp32 (float *vector, int n);
void pi_approximation_fp64 (double *vector, int n);
void pi_approximation_fp32 (float *vector, int n);
void real_pi (double *vector, int n);
