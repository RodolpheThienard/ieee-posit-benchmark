#include <stdio.h>
#include <stdlib.h>

void
initializevector (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      // f[idx] = ((float)rand () / RAND_MAX) * i
      //          / 1e6; // warning, requires posix standard.
      f[idx] = ((float)rand () / RAND_MAX) * i
               / 1e2; // warning, requires posix standard.
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
  int n = 1000;
  float *f1 = malloc (sizeof (float) * n);
  float *f2 = malloc (sizeof (float) * n);

  double *d1 = malloc (sizeof (double) * n);
  double *d2 = malloc (sizeof (double) * n);
  for (int i = -1e6; i < 1e6; i += 1)
    {

      initializevector (f1, n, i);
      initializevector (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf;  %e \n", i, (double)f_res, d_res,
               (f_res - d_res) / d_res);
    }
  return 0;
}
