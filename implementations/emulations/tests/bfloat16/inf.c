#include "bf16.h"
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("bfloat_around_0.dat", "w");

  printf ("%lf\n", (double)(BF16_to_FP32 (FP32_to_BF16 (1.24680))));

  double f;
  for (f = 1; f < 1e2; f *= 1.0001)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f,
               (((double)(BF16_to_FP32 (FP32_to_BF16 (f)))) - f) / f, f);
    }
  fclose (file);

  file = fopen ("bfloat_range.dat", "w");

  for (f = 1; f < 1e40; f *= 2)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f,
               (((double)(BF16_to_FP32 (FP32_to_BF16 (f)))) - f) / f, f);
    }
  fclose (file);
  return 0;
}
