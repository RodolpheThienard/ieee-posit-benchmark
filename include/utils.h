#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)
#define STRINGIFY(name) (#name)

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
  int repetition, matrice_size, type;
  double samples[33], mean, stddev;
  long RC[33];
};

struct accuracy
{
  double accuracy, RMS, forward_error, backward_error;
};

struct bench
{
  struct data *data;
  struct accuracy *accuracy;
  int pitch_size, end_size, start_size;
};

enum benchmark_type
{
  INVERSION,
  KERNEL2,
  KERNEL1,
};

extern double get_elapsedtime (void);
extern void sort_double (double *samples);
extern void sort_uint64 (long *samples);
extern double mean (double *samples);
extern double stddev (double *samples, double mean);
extern void print_data_benchmark (char *title, struct data *data,
                                  char *buffer);
extern void save_data (char *title, char *buffer);
extern long rdtsc (void);
extern void print_header_benchmark (char *buffer, long matrix_size);
extern void print_header_diff (char *buffer, long matrix_size);
extern void formatting_data (struct data *data);
extern void print_matrix (double *matrix, int row, int column);
extern void set_identity_matrix (double *matrix, int row, int column);
extern void print_header_accuracy (char *buffer);
extern void print_data_accuracy (char *title, char *buffer,
                                 struct accuracy *accuracy);
extern void print_diff_accuracy (char *title, char *buffer,
                                 struct bench *bench, struct data *data);
extern double compute_err_accuracy (double *vector1, double *vector2,
                                    int size);
extern double RMS (double *vector1, double *vector2, int size);
extern double forward_error (double *vector1, double *vector2, int size);
