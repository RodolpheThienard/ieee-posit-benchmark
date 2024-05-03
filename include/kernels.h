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
void host_square_root_newton_raphson (double *input, double *output, int size);
void host_sqrt_libmath (double *input, double *output, int size);
void host_sinus_maclaurin (double *input, double *output, int size);
void host_sinus_libmath (double *input, double *output, int size);
void host_monte_carlo_option_pricing (double *input, double *output, int size);
void host_pi_approximation (double *input, double *output, int size);
void host_real_pi (double *input, double *output, int size);

/// Kernels API
void vector_add (float *matrix1, float *matrix2, float *matrix3, int size);
void vector_mul (float *matrix1, float *matrix2, float *matrix3, int size);
void vector_div (float *matrix1, float *matrix2, float *matrix3, int size);
void vector_sqrt (float *matrix1, float *matrix2, int size);
void vector_reduction (float *matrix1, float *matrix2, float *matrix3,
                       int size);
void sgemm (float *matrix1, float *matrix2, float *matrix3, int size);

// Matrix inversion
void inve_matrix_gauss_jordan (float *matrix1, float *matrix2, int size);

// Logaritm calculation
void logarithm_taylor (float *input, float *output, int size);
void log_libmath (float *input, float *output, int size);

// Square root calculation
void square_root_newton_raphson (float *input, float *output, int size);
void sqrt_libmath (float *input, float *output, int size);

// Sinus calculation
void sinus_maclaurin (float *input, float *output, int size);
void sinus_libmath (float *input, float *output, int size);

// Pi calculation
void pi_approximation (float *input, float *output, int size);
void real_pi (float *input, float *output, int size);

// App pricing determination
void monte_carlo_option_pricing (float *input, float *output, int size);
