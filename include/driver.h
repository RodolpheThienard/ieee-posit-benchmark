#pragma once
#include "utils.h"

void driver_sgemm (void (*function) (float *, float *, float *, int), int size,
                   float *a, float *b, float *c, struct bench_s bench[]);

void driver_vector_add (void (*function) (float *, float *, float *, int),
                        int size, float *a, float *b, float *c,
                        struct bench_s bench[]);
void driver_vector_div (void (*function) (float *, float *, float *, int),
                        int size, float *a, float *b, float *c,
                        struct bench_s bench[]);
void driver_vector_sqrt (void (*function) (float *, float *, int), int size,
                         float *a, float *b, struct bench_s bench[]);

void driver_inverse_gauss_jordan (void (*function) (float *, float *, int),
                                  int size, float *a, float *b,
void driver_pi_approximation (void (*function) (float *, float *, int),
                              int size, float *a, float *b,
                              struct bench_s bench[]);

                                  struct bench_s bench[]);

void driver_sgemm_racer (char *function, int size, float *a, float *b,
                         float *c, struct bench_s bench[], int block_size_x,
                         int block_size_y);

void driver_accuracy (int size, double *c_host, double *c_device,
                      struct bench_s bench[]);
