#pragma once

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

#define INIT(matrix, n, seed)                                                 \
  for (uint32_t i = 0; i < n; i++)                                            \
    {                                                                         \
      for (uint32_t j = 0; j < n; j++)                                        \
        {                                                                     \
          matrix[i * n + j] = drand48 ();                                     \
        }                                                                     \
    }

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
