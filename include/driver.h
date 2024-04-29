#pragma once
#include "utils.h"

void driver_sgemm (void (*function) (float *, float *, float *, int), int size,
                   float *a, float *b, float *c, struct bench_s bench[]);

void driver_inverse_gauss_jordan (void (*function) (float *, float *, int),
                                  int size, float *a, float *b,
                                  struct bench_s bench[]);

void driver_accuracy (int size, double *c_host, double *c_device,
                      struct bench_s bench[]);

/// API
void benchmark (char *name_kernel, char *name_kernel_2, char *filename,
                void (*kernel) (double *, double *, int),
                void (*kernel_2) (double *, double *, int),
                struct bench *bench, enum benchmark_type type,
                int matrix_size);
