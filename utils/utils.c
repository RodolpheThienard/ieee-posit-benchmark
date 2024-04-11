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

double
med_min (double med, double min)
{
  return (med - min) / min;
}

void
print_header (char *buffer, long _matrix_size)
{
  sprintf (
      buffer, "%s %20s; %13s; %13s; %13s; %13s; %13s; %9s; %13s; %13s; %16s\n",
      buffer, "title", (_matrix_size > (1 << 20)) ? "buf (MiB)" : "buf (KiB)",
      "min (s)", "max (s)", "median (s)", "mean (s)", "dev %", "MiB/s",
      "Cycles", "Cycles/m-element");
}

void
formatting_data (struct data *data)
{
  sort_double (data->samples);
  sort_uint64 (data->RC);
  data->mean = mean (data->samples);
  data->stddev = stddev (data->samples, data->mean);
}

void
save_data (char *filename, char *buffer)
{
  if (filename == NULL)
    fprintf (stdout, "%s", buffer);
  else
    {
      FILE *file = fopen (filename, "w");
      fprintf (file, "%s", buffer);
      fclose (file);
    }
}

double
convertion (double number)
{
  return (number > (1 << 20)) ? number / 1024.0 / 1024.0 : number / 1024.0;
}

//
void
print_data (char *title, struct data *data, char *buffer)
{

  double _min = data->samples[0];
  double _max = data->samples[32];
  double _median = data->samples[16];
  double _mean = data->mean;
  double _stddev = data->stddev;
  double _matrix_size = data->matrice_size;
  double _data_size = data->type;
  double _repetition = data->repetition;
  uint64_t _rc = data->RC[16];

  double _stddevp = (_stddev * 100.0) / _mean;
  double _rc_elem = _rc / _matrix_size;
  double _bw = ((double)_matrix_size / (1024.0 * 1024)) / _mean;

  sprintf (buffer,
           "%s %20s; %13.3lf; %13.3e; %13.3e; %13.3e; %13.3e; %9.3lf; "
           "%13.3lf; %13.3lu; %16.3lf \n",
           buffer, title, convertion (_matrix_size * _data_size), _min, _max,
           _median, _mean, _stddevp, _bw, _rc, _rc_elem);
  return;
}
