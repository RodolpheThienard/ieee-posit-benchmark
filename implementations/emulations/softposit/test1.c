#include "source/include/softposit.h"
#include "source/include/softposit_types.h"
#include <stdlib.h>

void
initializevector (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx] = (float)drand48 () * i / 1e5; // large range
      // f[idx] = (float)drand48 () * i / 1e5; // around 0
    }
}

double
doubledotproduct (double *pv1, double *pv2, int n)
{
  double res = 0.0;
  for (int i = 0; i < n; i++)
    res += pv1[i];

  return res;
}
float
floatdotproduct (float *pv1, float *pv2, int n)
{

  float res = 0.0;
  for (int i = 0; i < n; i++)
    res += pv1[i];

  return res;
}

posit32_t
positdotproduct (posit32_t *pv1, posit32_t *pv2, int n)
{
  posit32_t res = convertFloatToP32 (0.0);
  for (int i = 0; i < n; i++)
    {
      res = p32_add (res, pv1[i]);
    }

  return res;
}
void
transfertoposit32 (posit32_t *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = convertFloatToP32 (fv[idx]);
    }
}

void
transfertodouble (double *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = (double)fv[idx];
    }
}
int
main (int argc, char *argv[])
{

  FILE *file;
  file = fopen ("result.dat", "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      int n = 1000;
      float *f1 = malloc (sizeof (float) * n);
      float *f2 = malloc (sizeof (float) * n);

      posit32_t *p1 = malloc (sizeof (posit32_t) * n);
      posit32_t *p2 = malloc (sizeof (posit32_t) * n);

      double *d1 = malloc (sizeof (double) * n);
      double *d2 = malloc (sizeof (double) * n);

      initializevector (f1, n, i);
      initializevector (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double p32e2_res = convertP32ToDouble (positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)p32e2_res, d_res,
               ((double)p32e2_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  return 0;
}
