#pragma once
#include "utils.h"

/// BENCHMARK
// IEEE
void ieee_32bits_add (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_mul (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_div (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_sqrt (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_dp (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_gemm (float *a, float *b, float *c, uint64_t n);

void ieee_64bits_add (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_mul (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_div (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_sqrt (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_dp (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_gemm (double *a, double *b, double *c, uint64_t n);

// CUDA
void cuda_64bits_gemm_ijk (double *a, double *b, double *c, int n);
void cuda_64bits_gemm_jik (double *A, double *B, double *C, int N);
void cuda_64bits_gemm_bloc (double *A, double *B, double *C, int N);
