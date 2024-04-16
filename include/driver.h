#pragma once
#include "utils.h"

/// BENCHMARK
void driver_fp32_benchmark (char *title, char *buffer,
                            void (*kernel) (float *, float *, float *, int),
                            struct data *data, int matrix_size);

void driver_fp32_vector_benchmark (char *title, char *buffer,
                                   void (*kernel) (float *, float *, int),
                                   struct data *data, int matrix_size);

void driver_fp64_benchmark (char *title, char *buffer,
                            void (*kernel) (double *, double *, double *, int),
                            struct data *data, int matrix_size);

/// ACCURACY
void driver_inv_matrix_accuracy (char *title, char *buffer,
                                 void (*kernel) (double *, double *, int),
                                 struct accuracy *accuracy, int matrix_size);

void driver_compare_accuracy (char *title, char *buffer,
                              void (*kernel1) (double *, int),
                              void (*kernel2) (double *, int),
                              struct accuracy *accuracy, int matrix_size);
