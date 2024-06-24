#include "softposit.h"
#include "softposit_types.h"
#include <stdlib.h>

void
transfertoposit32 (posit32_t *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = convertFloatToP32 (fv[idx]);
    }
}

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("nan.dat", "w");
  int n = 1000;
  double f1 = 1.0;
  double f2 = 1e-45;
  posit32_t p1 = convertFloatToP32 (f1);
  for (f2 = 1; f2 > 1e-50; f2 /= 10)
    {
      posit32_t p2 = convertFloatToP32 (f2);

      double posit = convertP32ToDouble (p32_div (p1, p2));
      fprintf (file, "%e; %e; %e\n", posit, (float)f1 / (float)f2, f1 / f2);
    }

  return 0;
}
