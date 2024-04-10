#include "../include/utils.h"

/* Register counter */
uint64_t
rdtsc ()
{
  uint64_t a, d;
  __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
  return (d << 32) | a;
}

/* return time in second */
double
get_elapsedtime (void)
{
  struct timespec st;
  int err = gettime (&st);
  if (err != 0)
    return 0;
  return (double)st.tv_sec + get_sub_seconde (st);
}

//
void
sort_double (double *a)
{
  int i, j;
  for (i = 0; i < 33; i++)
    for (j = i + 1; j < 33; j++)
      if (a[i] > a[j])
        {
          double tmp = a[i];

          a[i] = a[j];
          a[j] = tmp;
        }
}

//
void
sort_uint64 (uint64_t *a)
{
  int i, j;
  for (i = 0; i < 33; i++)
    for (j = i + 1; j < 33; j++)
      if (a[i] > a[j])
        {
          uint64_t tmp = a[i];

          a[i] = a[j];
          a[j] = tmp;
        }
}

//
double
mean (double *a)
{
  double m = 0.0;
  int i;
  for (i = 0; i < 33; i++)
    m += a[i];

  return m / 33.;
}

//
double
stddev (double *a, double mean)
{
  double d = 0.0;
  int i;
  for (i = 0; i < 33; i++)
    d += (a[i] - mean) * (a[i] - mean);

  d /= 32.;

  return sqrt (d);
}

void
print_header (long _matrix_size)
{
  printf ("%20s;  %13s; %13s; %13s; %13s; %13s; %13s; %13s; %13s; %13s\n",
          "title", (_matrix_size > (1 << 20)) ? "MiB" : "KiB", "min (s)",
          "max (s)", "median (s)", "mean (s)", "dev %", "MiB/s", "Cycles",
          "Cycles/element");
}

//
void
print_data (char *title, struct data *data)
{

  double _min = data->samples[0];
  double _max = data->samples[32];
  double _median = data->samples[(34) >> 1];
  double _mean = data->mean;
  double _stddev = data->stddev;
  double _stddevp = (_stddev * 100.0) / _mean;
  double _matrix_size = data->matrice_size;
  double _data_size = data->type;
  uint64_t _rc = data->RC[(34) >> 1] / data->repetition;
  double _rc_elem = _rc / _matrix_size;
  double _bw
      = ((double)_matrix_size / (1024.0 * 1024)) / _mean * data->repetition;

  printf ("%20s; %13.3lf; %13.3e; %13.3e; %13.3e; %13.3e; %13.3lf; "
          "%13.3lf; %13.3lu; %13.3lf\n",
          title,
          (_matrix_size > (1 << 20))
              ? _matrix_size * _data_size / (1024.0 * 1024.0)
              : _matrix_size * _data_size / 1024.0,
          _min, _max, _median, _mean, _stddevp, _bw, _rc, _rc_elem);

  return;
}
