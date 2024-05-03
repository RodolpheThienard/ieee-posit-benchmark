#pragma once
#include "utils.h"

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
void inve_matrix_gauss_jordan_cuda (float *matrix1, float *matrix2, int size);

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
