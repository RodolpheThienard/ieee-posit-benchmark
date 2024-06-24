#include "../../fastsigmoids/c-src/include/P16e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P32e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/posit.h"
#include <iostream>
#include <type_traits>

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("p16_around_0.dat", "w");

  double f;
  for (f = 1; f < 1e3; f *= 1.001)
    {

      fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
               (((double)((P16e0)f)) - f) / f, (((double)((P16e1)f)) - f) / f,
               (((double)((P16e2)f)) - f) / f, f);
    }
  fclose (file);

  file = fopen ("p16_range.dat", "w");

  for (f = 1; f < 1e40; f *= 2)
    {

      fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
               (((double)((P16e0)f)) - f) / f, (((double)((P16e1)f)) - f) / f,
               (((double)((P16e2)f)) - f) / f, f);
    }
  fclose (file);
  return 0;
}
