#include "softposit.h"
#include "softposit_types.h"
#include <stdlib.h>

void
initializevector (float *f, int n, double i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx] = ((float)rand () / (float)RAND_MAX) * i;
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
  // for (int i = 0; i < n; i++)
  //   res += pv1[i];
  int length = n;
  while (length > 1)
    {
      int new_length = length / 2;

      // Pour chaque paire d'éléments, on effectue la somme
      for (int i = 0; i < new_length; i++)
        {
          pv1[i] = pv1[2 * i] + pv1[2 * i + 1];
        }

      // Si la longueur est impaire, on doit ajouter l'élément restant
      if (length % 2 != 0)
        {
          pv1[new_length] = pv1[length - 1];
          new_length++;
        }

      // On réduit la taille pour la prochaine itération
      length = new_length;
    }
  res = pv1[0];

  return res;
}

posit32_t
positdotproduct (posit32_t *pv1, posit32_t *pv2, int n)
{
  posit32_t res = convertFloatToP32 (0.0);
  int length = n;
  while (length > 1)
    {
      int new_length = length / 2;

      // Pour chaque paire d'éléments, on effectue la somme
      for (int i = 0; i < new_length; i++)
        {
          pv1[i] = p32_add (pv1[2 * i], pv1[2 * i + 1]);
        }

      // Si la longueur est impaire, on doit ajouter l'élément restant
      if (length % 2 != 0)
        {
          pv1[new_length] = pv1[length - 1];
          new_length++;
        }

      // On réduit la taille pour la prochaine itération
      length = new_length;
    }
  res = pv1[0];

  return res;
}
posit32_t
positdotproduct_naive (posit32_t *pv1, posit32_t *pv2, int n)
{
  posit32_t res = convertFloatToP32 (0.0);
  for (int i = 0; i < n; i++)
    pv1[0] = p32_add (pv1[i], pv1[0]);
  res = pv1[0];
  return res;
}
float
floatdotproduct_naive (float *f1, float *f2, int n)
{
  float res = 0.0;
  for (int i = 0; i < n; i++)
    res += f1[i];
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
  int n = 1000;
  float *f1 = malloc (sizeof (float) * n);
  float *f2 = malloc (sizeof (float) * n);

  posit32_t *p1 = malloc (sizeof (posit32_t) * n);
  posit32_t *p2 = malloc (sizeof (posit32_t) * n);

  double *d1 = malloc (sizeof (double) * n);
  double *d2 = malloc (sizeof (double) * n);

  file = fopen ("ceralaine_around_0.dat", "w");
  fprintf (file, "n;float; posit32; double; posit_naive; P32-Double; "
                 "double-float; double-Pnaive; double-float_naive\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 1e5);
      initializevector (f2, n, i / 1e5);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f1, n);

      float f_res_naive = floatdotproduct_naive (f1, f2, n);
      float f_res = floatdotproduct (f1, f2, n);
      double p32e2_res = convertP32ToDouble (positdotproduct (p1, p2, n));
      double p32e2_res_naive
          = convertP32ToDouble (positdotproduct (p2, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file,
               "%d; %24.23lf; %24.23lf; %24.23lf; %24.23lf; %e; %e; %e; %e \n",
               i, (double)f_res, (double)p32e2_res, d_res, p32e2_res_naive,
               ((double)p32e2_res - d_res) / d_res, (f_res - d_res) / d_res,
               ((double)p32e2_res_naive - d_res) / d_res,
               (f_res_naive - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("ceralaine_mid.dat", "w");
  fprintf (file, "n;float; posit32; double; posit_naive; P32-Double; "
                 "double-float; double-Pnaive; double-float_naive\n");
  for (int i = -1e6; i < 1e6; i += 1e1)
    {
      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f1, n);

      float f_res_naive = floatdotproduct_naive (f1, f2, n);
      float f_res = floatdotproduct (f1, f2, n);
      double p32e2_res = convertP32ToDouble (positdotproduct (p1, p2, n));
      double p32e2_res_naive
          = convertP32ToDouble (positdotproduct (p2, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file,
               "%d; %24.23lf; %24.23lf; %24.23lf; %24.23lf; %e; %e; %e; %e \n",
               i, (double)f_res, (double)p32e2_res, d_res, p32e2_res_naive,
               ((double)p32e2_res - d_res) / d_res, (f_res - d_res) / d_res,
               ((double)p32e2_res_naive - d_res) / d_res,
               (f_res_naive - d_res) / d_res);
    }
  fclose (file);

  file = fopen ("ceralaine_range_racer.dat", "w");
  fprintf (file, "n;float; posit32; double; posit_naive; P32-Double; "
                 "double-float; double-Pnaive; double-float_naive\n");
  for (int i = -1e5; i < 1e5; i += 1e1)
    {
      int n = 1000;
      initializevector (f1, n, i * 1e2);
      initializevector (f2, n, i * 1e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f1, n);

      float f_res_naive = floatdotproduct_naive (f1, f2, n);
      float f_res = floatdotproduct (f1, f2, n);
      double p32e2_res = convertP32ToDouble (positdotproduct (p1, p2, n));
      double p32e2_res_naive
          = convertP32ToDouble (positdotproduct (p2, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file,
               "%d; %24.23lf; %24.23lf; %24.23lf; %24.23lf; %e; %e; %e; %e \n",
               i, (double)f_res, (double)p32e2_res, d_res, p32e2_res_naive,
               ((double)p32e2_res - d_res) / d_res, (f_res - d_res) / d_res,
               ((double)p32e2_res_naive - d_res) / d_res,
               (f_res_naive - d_res) / d_res);
    }
  fclose (file);

  file = fopen ("ceralaine_mid.dat", "w");
  fprintf (file, "n;float; posit32; double; posit_naive; P32-Double; "
                 "double-float; double-Pnaive; double-float_naive\n");
  for (int i = -1e6; i < 1e6; i += 1e1)
    {
      int n = 1000;
      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f1, n);

      float f_res_naive = floatdotproduct_naive (f1, f2, n);
      float f_res = floatdotproduct (f1, f2, n);
      double p32e2_res = convertP32ToDouble (positdotproduct (p1, p2, n));
      double p32e2_res_naive
          = convertP32ToDouble (positdotproduct (p2, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file,
               "%d; %24.23lf; %24.23lf; %24.23lf; %24.23lf; %e; %e; %e; %e \n",
               i, (double)f_res, (double)p32e2_res, d_res, p32e2_res_naive,
               ((double)p32e2_res - d_res) / d_res, (f_res - d_res) / d_res,
               ((double)p32e2_res_naive - d_res) / d_res,
               (f_res_naive - d_res) / d_res);
    }
  fclose (file);
  return 0;
}
