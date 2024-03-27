#pragma once
#include "utils.h"

void ieee_32bits_add (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_mul (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_dp (float *a, float *b, float *c, uint64_t n);
void ieee_32bits_gemm (float *a, float *b, float *c, uint64_t n);

void ieee_64bits_add (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_mul (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_dp (double *a, double *b, double *c, uint64_t n);
void ieee_64bits_gemm (double *a, double *b, double *c, uint64_t n);
