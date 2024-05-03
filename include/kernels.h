#pragma once
#include "utils.h"

// Default kernel
void host_dgemm (double *matrix1, double *matrix2, double *matrix3, int size);
void host_vector_add (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void host_vector_mul (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void host_vector_div (double *matrix1, double *matrix2, double *matrix3,
                      int size);
void host_vector_sqrt (double *matrix1, double *matrix2, int size);
void host_vector_reduction (double *matrix1, double *matrix2, double *matrix3,
                            int size);
void host_inve_matrix_gauss_jordan (double *matrix1, double *matrix2,
                                    int size);
void host_logarithm_taylor (double *input, double *output, int size);
void host_log_libmath (double *input, double *output, int size);
void host_conversion_double_float (double *input, double *output, int size);
void host_useless_function (double *input, double *output, int size);
void host_square_root_newton_raphson (double *input, double *output, int size);
void host_sqrt_libmath (double *input, double *output, int size);
void host_sinus_maclaurin (double *input, double *output, int size);
void host_sinus_libmath (double *input, double *output, int size);
void host_monte_carlo_option_pricing (double *input, double *output, int size);
void host_pi_approximation (double *input, double *output, int size);
void host_real_pi (double *input, double *output, int size);

/// Kernels API
void sgemm (float *matrix1, float *matrix2, float *matrix3, int size);

void inve_matrix_gauss_jordan (float *matrix1, float *matrix2, int size);
void inve_matrix_gauss_jordan_2 (float *matrix1, float *matrix2, int size,
                                 int i);
