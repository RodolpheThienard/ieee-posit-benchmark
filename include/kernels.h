#pragma once
#include "utils.h"

/// BENCHMARK
// IEEE
void ieee_32bits_add (float *matrix1, float *matrix2, float *matrix3,
                      uint64_t size);
void ieee_32bits_mul (float *matrix1, float *matrix2, float *matrix3,
                      uint64_t size);
void ieee_32bits_div (float *matrix1, float *matrix2, float *matrix3,
                      uint64_t size);
void ieee_32bits_sqrt (float *matrix1, float *matrix2, float *matrix3,
                       uint64_t size);
void ieee_32bits_dp (float *matrix1, float *matrix2, float *matrix3,
                     uint64_t size);
void ieee_32bits_gemm (float *matrix1, float *matrix2, float *matrix3,
                       uint64_t size);

void ieee_64bits_add (double *matrix1, double *matrix2, double *matrix3,
                      uint64_t size);
void ieee_64bits_mul (double *matrix1, double *matrix2, double *matrix3,
                      uint64_t size);
void ieee_64bits_div (double *matrix1, double *matrix2, double *matrix3,
                      uint64_t size);
void ieee_64bits_sqrt (double *matrix1, double *matrix2, double *matrix3,
                       uint64_t size);
void ieee_64bits_dp (double *matrix1, double *matrix2, double *matrix3,
                     uint64_t size);
void ieee_64bits_gemm (double *matrix1, double *matrix2, double *matrix3,
                       uint64_t size);

// CUDA
void cuda_64bits_gemm_ijk (double *matrix1, double *matrix2, double *matrix3,
                           int size);
void cuda_64bits_gemm_jik (double *matrix1, double *matrix2, double *matrix3,
                           int size);
void cuda_64bits_gemm_bloc (double *matrix1, double *matrix2, double *matrix3,
                            int size);

/// ACCURACY
// IEEE
void inve_matrix_gauss_jordan (double *matrix1, double *matrix2, int size);
void logarithm_taylor (double *vector, int size);
void log_libmath (double *vector, int size);

// CUDA
// void cuda_inve_matrix_gauss_jordan (double *matrix1, double *matrix2,
// int size);
// void log_libmath_cuda (double *x, int n);
// void logarithm_taylor_cuda (double *x, int n);
