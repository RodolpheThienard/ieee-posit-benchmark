#pragma once
#include "utils.h"

/// BENCHMARK
// ieee
extern void driver_fp32_benchmark (char *, char *, void (*) (), struct data *,
                                   uint64_t);

extern void driver_fp32_vector_benchmark (char *, char *, void (*) (),
                                          struct data *, uint64_t);

extern void driver_fp64_benchmark (char *, char *, void (*) (), struct data *,
                                   uint64_t);

// Cuda
extern void driver_cuda_fp64_benchmark (char *, char *,
                                        void (*) (double *, double *, double *,
                                                  int),
                                        struct data *, int);

/// ACCURACY
extern void driver_inv_matrix_accuracy (char *, char *, void (*) (),
                                        struct accuracy *, int);

extern void driver_compare_accuracy (char *, char *, void (*) (), void (*) (),
                                     struct accuracy *, uint64_t);
