#include "source/include/softposit.h"
#include "source/include/softposit_types.h"
#include <stdlib.h>

void
initializevector (float *f)
{
  for (int idx = 0; idx < 100; ++idx)
    {
      f[idx] = drand48 () / 100;
    }
}

double
doubledotproduct (double *pv1, double *pv2)
{
  double res = 0.0;
  for (int i = 0; i < 100; i++)
    res += pv1[i];

  return res;
}
float
floatdotproduct (float *pv1, float *pv2)
{

  float res = 0.0;
  for (int i = 0; i < 100; i++)
    res += pv1[i];

  return res;
}

posit32_t
positdotproduct (posit32_t *pv1, posit32_t *pv2)
{
  posit32_t res = convertFloatToP32 (0.0);
  for (int i = 0; i < 100; i++)
    {
      res = p32_add (res, pv1[i]);
    }

  return res;
}
void
transfertoposit32 (posit32_t *pv, float *fv)
{
  for (int idx = 0; idx < 100; ++idx)
    {
      pv[idx] = convertFloatToP32 (fv[idx]);
    }
}

void
transfertodouble (double *pv, float *fv)
{
  for (int idx = 0; idx < 100; ++idx)
    {
      pv[idx] = (double)fv[idx];
    }
}
int
main (int argc, char *argv[])
{

  float *f1 = malloc (sizeof (float) * 100);
  float *f2 = malloc (sizeof (float) * 100);

  posit32_t *p1 = malloc (sizeof (posit32_t) * 100);
  posit32_t *p2 = malloc (sizeof (posit32_t) * 100);

  double *d1 = malloc (sizeof (double) * 100);
  double *d2 = malloc (sizeof (double) * 100);

  initializevector (f1);
  initializevector (f2);

  transfertodouble (d1, f1);
  transfertodouble (d2, f2);

  transfertoposit32 (p1, f1);
  transfertoposit32 (p2, f2);

  float f_res = floatdotproduct (f1, f2);
  posit32_t p32e2_res = positdotproduct (p1, p2);
  double d_res = doubledotproduct (d1, d2);

  printf ("Float  : %24.23lf\n", (double)f_res);
  printf ("Posit  : %24.23lf\n", convertP32ToDouble (p32e2_res));
  printf ("Double : %24.23lf\n", d_res);

  return 0;
}
