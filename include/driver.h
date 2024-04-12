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
