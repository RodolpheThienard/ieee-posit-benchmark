#pragma once
#include "utils.h"

extern void driver_fp32 (char *, void (*) (), struct data *, float *, float *,
                         float *, uint64_t);
extern void driver_fp32_vector (char *, void (*) (), struct data *, float *,
                                float *, uint64_t);

extern void driver_fp64 (char *, void (*) (), struct data *, double *,
                         double *, double *, uint64_t);
