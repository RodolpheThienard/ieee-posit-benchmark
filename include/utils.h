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

struct accuracy
{
  double accuracy, RMS, forward_error, backward_error;
};

extern double get_elapsedtime (void);
extern void sort_double (double *restrict);
extern void sort_uint64 (uint64_t *restrict);
extern double mean (double *restrict);
extern double stddev (double *restrict, double);
extern void print_data_benchmark (char *, struct data *, char *);
extern void save_data (char *, char *);
extern uint64_t rdtsc ();
extern void print_header_benchmark (char *, long);
extern void formatting_data (struct data *);
extern void print_matrix (double *, int, int);
extern void set_identity_matrix (double *, int, int);
extern void print_header_accuracy (char *);
extern void print_data_accuracy (char *, char *, struct accuracy *);
extern double compute_err_accuracy (double *a, double *b, int n);
extern double RMS (double *a, double *b, int n);
extern double forward_error (double *a, double *b, int n);
