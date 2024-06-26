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

#define INIT(value, size)                                                     \
  do                                                                          \
    {                                                                         \
      for (int indice = 0; indice < size; indice++)                           \
        {                                                                     \
          value[indice] = drand48 ();                                         \
        }                                                                     \
    }                                                                         \
  while (0)

struct data
{
  int repetition, matrice_size, type;
  double samples[33], mean, stddev;
  long RC[33];
};

struct accuracy
{
  double accuracy, RMS, forward_error;
};

struct bench_s
{
  struct data *data;
  struct accuracy *accuracy;
  int start_size, end_size, step_size;
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
extern void print_header_benchmark (char *buffer);
extern void print_header_diff (char *buffer);
extern void formatting_data (struct data *data);
extern void print_matrix (double *matrix, int row, int column);
extern void set_identity_matrix (float *matrix, int row, int column);
extern void print_header_accuracy (char *buffer);
extern void print_data_accuracy (char *buffer, struct accuracy *accuracy);
extern void print_diff_accuracy (char *title, char *buffer,
                                 struct bench_s *bench, struct data *data);
extern double compute_err_accuracy (double *vector1, double *vector2,
                                    int size);
extern double RMS (double *vector1, double *vector2, int size);
extern double forward_error (double *vector1, double *vector2, int size);
extern float compute_err_accuracy_float (float *vector1, float *vector2,
                                         int size);
extern float RMS_float (float *vector1, float *vector2, int size);
extern float forward_error_float (float *vector1, float *vector2, int size);
extern void conversion_into_double (float *src, double *dst, int n);
extern int error_accuracy (struct bench_s *bench);
extern void open_image (char *src, float *dst, int width, int height);
