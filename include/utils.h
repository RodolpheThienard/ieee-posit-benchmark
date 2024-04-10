#pragma once

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)

#define ALLOC(X, n)                                                           \
  do                                                                          \
    {                                                                         \
      X = malloc (sizeof (*X) * n);                                           \
      if (!X)                                                                 \
        {                                                                     \
          perror ("malloc");                                                  \
          exit (1);                                                           \
        }                                                                     \
      memset (X, 0, sizeof (*X) * n);                                         \
    }                                                                         \
  while (0)

#define INIT(a, size)                                                         \
  for (int i = 0; i < size; i++)                                              \
    a[i] = (drand48 ());

struct data
{
  uint32_t repetition, matrice_size, type;
  double samples[33], mean, stddev;
  uint64_t RC[33];
};

extern double get_elapsedtime (void);
extern void sort_double (double *restrict);
extern void sort_uint64 (uint64_t *restrict);
extern double mean (double *restrict);
extern double stddev (double *restrict, double);
extern void print_data (char *, struct data *);
extern uint64_t rdtsc ();
extern void print_header (long);
