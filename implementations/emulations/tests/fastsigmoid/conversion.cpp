#include "../../fastsigmoids/c-src/include/P32e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/posit.h"
#include <bits/types/struct_timespec.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <type_traits>

double
get_time (struct timespec t0, struct timespec t1)
{
  return (t1.tv_sec * 1e9 + t1.tv_nsec) - (t0.tv_sec * 1e9 + t0.tv_nsec);
}

int
main ()
{
  int n = 1e6;
  float tab_ieee[n], sum_ieee = 0.0;
  P32e2 tab_posit[n], sum_posit = 0.0;
  struct timespec t0, t1;

  clock_gettime (CLOCK_MONOTONIC_RAW, &t0);
  for (int i = 0; i < n; i++)
    {
      tab_ieee[i] = drand48 ();
    }
  clock_gettime (CLOCK_MONOTONIC_RAW, &t1);

  printf ("%20s: %lf\n", "IEEE", get_time (t0, t1));

  clock_gettime (CLOCK_MONOTONIC_RAW, &t0);
  for (int i = 0; i < n; i++)
    {
      tab_posit[i] = (P32e2)drand48 ();
    }
  clock_gettime (CLOCK_MONOTONIC_RAW, &t1);
  printf ("%20s: %lf\n", "Posit from lib", get_time (t0, t1));

  clock_gettime (CLOCK_MONOTONIC_RAW, &t0);
  for (int i = 0; i < n; i++)
    {
      tab_posit[i] = (P32e2)tab_ieee[i];
    }
  clock_gettime (CLOCK_MONOTONIC_RAW, &t1);
  printf ("%20s: %lf\n", "Posit from tab", get_time (t0, t1));

  clock_gettime (CLOCK_MONOTONIC_RAW, &t0);
  for (int i = 0; i < n; i++)
    {
      sum_ieee += tab_ieee[i];
    }
  clock_gettime (CLOCK_MONOTONIC_RAW, &t1);
  printf ("%20s: %lf\n", "Sum ieee", get_time (t0, t1));

  clock_gettime (CLOCK_MONOTONIC_RAW, &t0);
  for (int i = 0; i < n; i++)
    {
      sum_posit += tab_posit[i];
    }
  clock_gettime (CLOCK_MONOTONIC_RAW, &t1);
  printf ("%20s: %lf\n", "Sum posit", get_time (t0, t1));

  return 0;
}
