#pragma once
#include "utils.h"

/// BENCHMARK
// ieee
extern void driver_fp32_benchmark (char *title, char *buffer,
                                   void (*kernel) (), struct data *data,
                                   uint64_t matrix_size);

extern void driver_fp32_vector_benchmark (char *title, char *buffer,
                                          void (*kernel) (), struct data *data,
                                          uint64_t matrix_size);

extern void driver_fp64_benchmark (char *title, char *buffer,
                                   void (*kernel) (), struct data *data,
                                   uint64_t matrix_size);

// Cuda
extern void
driver_cuda_fp64_benchmark (char *title, char *buffer,
                            void (*kernel) (double *, double *, double *, int),
                            struct data *data, uint64_t matrix_size);

/// ACCURACY
extern void driver_inv_matrix_accuracy (char *title, char *buffer,
                                        void (*kernel) (),
                                        struct accuracy *accuracy,
                                        uint64_t matrix_size);

extern void driver_compare_accuracy (char *title, char *buffer,
                                     void (*kernel1) (), void (*kernel2) (),
                                     struct accuracy *accuracy,
                                     uint64_t matrix_size);
