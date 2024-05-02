#pragma once
#include "utils.h"

void driver_sgemm (void (*function) (float *, float *, float *, int), int size,
                   float *a, float *b, float *c, struct bench_s bench[]);

void driver_inverse_gauss_jordan (void (*function) (float *, float *, int,
                                                    int),
                                  int size, float *a, float *b, int i,
                                  struct bench_s bench[]);

void driver_fp64_benchmark (char *title, char *buffer,
                            void (*kernel) (double *, double *, double *, int),
                            struct data *data, int matrix_size);

void driver_sgemm_racer (char *function, int size, float *a, float *b,
                         float *c, struct bench bench[], int block_size_x,
                         int block_size_y);

/// ACCURACY
void driver_inv_matrix_accuracy (char *title, char *buffer,
                                 void (*kernel) (double *, double *, int),
                                 struct accuracy *accuracy, int matrix_size);

void driver_compare_accuracy (char *title, char *buffer,
                              void (*kernel1) (double *, int),
                              void (*kernel2) (double *, int),
                              struct accuracy *accuracy, int matrix_size);

void driver_compare_accuracy_fp64_fp32 (char *title, char *buffer,
                                        void (*kernel1) (double *, int),
                                        void (*kernel2) (float *, int),
                                        struct accuracy *accuracy,
                                        int matrix_size);
void driver_accuracy (int size, double *c_host, double *c_device,
                      struct bench_s bench[]);

/// API
void benchmark (char *name_kernel, char *name_kernel_2, char *filename,
                void (*kernel) (double *, double *, int),
                void (*kernel_2) (double *, double *, int),
                struct bench *bench, enum benchmark_type type,
                int matrix_size);
