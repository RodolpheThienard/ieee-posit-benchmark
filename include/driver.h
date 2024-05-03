#pragma once
#include "utils.h"

void driver_sgemm (void (*function) (float *, float *, float *, int), int size,
                   float *a, float *b, float *c, struct bench_s bench[]);

void driver_inverse_gauss_jordan (void (*function) (float *, float *, int,
                                                    int),
                                  int size, float *a, float *b, int i,
                                  struct bench_s bench[]);

void driver_sgemm_racer (char *function, int size, float *a, float *b,
                         float *c, struct bench_s bench[], int block_size_x,
                         int block_size_y);

void driver_accuracy (int size, double *c_host, double *c_device,
                      struct bench_s bench[]);
