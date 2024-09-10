#include "softposit.h"
#include "softposit_types.h"
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("P16_ceralaine.dat", "w");

  double f;
  for (f = 1; f < 1e2; f *= 1.001)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f,
               ((convertP16ToDouble (convertDoubleToP16 (f)) - f) / f), f);
    }
  fclose (file);

  return 0;
}
