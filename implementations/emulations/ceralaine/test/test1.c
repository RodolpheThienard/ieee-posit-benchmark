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

  // file = fopen ("tf32_vs_p16.dat", "w");

  // for (f = 1; f < 1e40; f *= 2)
  //   {

  //     fprintf (file, "%f; %f; %f; %f; %f; %lf\n", (float)f,
  //              (((double)((P16e0)f)) - f) / f, (((double)((tf32)f)) - f) /
  //              f,
  //              (((double)((P16e1)f)) - f) / f, (((double)((P16e2)f)) - f) /
  //              f, f);
  //   }
  // fclose (file);

  // file = fopen ("fastsigmoid_nan.dat", "w");

  // for (f = 1; f < 1e50; f *= 2)
  //   {

  //     fprintf (file, "%e; %e; %e\n", (double)((P32e2)f), ((float)f), f);
  //   }
  // fclose (file);
  return 0;
}
