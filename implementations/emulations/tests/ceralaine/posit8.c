#include "softposit.h"
#include "softposit_types.h"
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("P8_ceralaine.dat", "w");

  double f;
  for (f = 1; f < 10; f *= 1.0001)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f,
               ((convertP8ToDouble (convertDoubleToP8 (f)) - f) / f), f);
    }
  fclose (file);

  return 0;
}
