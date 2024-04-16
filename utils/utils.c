#include "../include/utils.h"

/* Register counter */
long
rdtsc ()
{
  long a, d;
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

/* sort function */
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

/* sort function */
void
sort_uint64 (long *a)
{
  int i, j;
  for (i = 0; i < 33; i++)
    for (j = i + 1; j < 33; j++)
      if (a[i] > a[j])
        {
          long tmp = a[i];

          a[i] = a[j];
          a[j] = tmp;
        }
}

/* computed the mean of samples */
double
mean (double *a)
{
  double m = 0.0;
  int i;
  for (i = 0; i < 33; i++)
    m += a[i];

  return m / 33.;
}

/* return the standard deviation of computed samples */
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

/* not used, alternative of stddev */
double
med_min (double med, double min)
{
  return (med - min) / min;
}

/* debug function print matrix n*m */
void
print_matrix (double *a, int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        printf ("%lf ", a[i * n + j]);
      printf ("\n");
    }
}

/* debug function set identity matrix n*m */
void
set_identity_matrix (double *identity, int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        {
          if (i == j)
            {
              identity[i * n + j] = 1.0;
            }
          else
            {
              identity[i * n + j] = 0.0;
            }
        }
    }
}
