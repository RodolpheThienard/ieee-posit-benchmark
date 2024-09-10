#include "../../fastsigmoids/c-src/include/P16e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P32e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/posit.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <vector>

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

P16e1
positdotproduct (P16e1 *pv1, P16e1 *pv2, int n)
{
  P16e1 res = 0.0;
  // for (int i = 0; i < n; i++)
  //   {
  //     res = p32_add (res, pv1[i]);
  //   }
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
P32e2
positdotproduct_2 (P32e2 *pv1, P32e2 *pv2, int n)
{
  P32e2 res = 0.0;
  // for (int i = 0; i < n; i++)
  //   {
  //     res = p32_add (res, pv1[i]);
  //   }
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
void
transfertoposit32 (P16e1 *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = (P16e1)fv[idx];
    }
}
void
transfertoposit32_2 (P32e2 *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = (P32e2)fv[idx];
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
  file = fopen ("posit16_around_0.dat", "w");
  fprintf (file, "n;float; P16e1; double; P32-Double; double-float\n");
  int n = 1000;
  float f1[n];
  float f2[n];
  float a = 1.24680;
  printf ("%f\n", (float)(P16e0)a);

  P16e1 p1[n];
  P16e1 p2[n];
  P32e2 p3[n];
  P32e2 p4[n];

  double d1[n];
  double d2[n];

  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 1e5);
      initializevector (f2, n, i / 1e5);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double P16e1_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)P16e1_res, d_res,
               ((double)P16e1_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("posit16_0_1e4.dat", "w");
  fprintf (file, "n;float; P16e1; double; P32-Double; double-float\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double P16e1_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)P16e1_res, d_res,
               ((double)P16e1_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  fclose (file);

  file = fopen ("posit16_range.dat", "w");
  fprintf (file, "n;float; P16e1; double; P32-Double; double-float\n");
  for (int i = -1e5; i < 1e5; i += 1e1)
    {

      initializevector (f1, n, i * 1e2);
      initializevector (f2, n, i * 1e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double P16e1_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %le; %le; %le; %e; %e \n", i, (double)f_res,
               P16e1_res, d_res, (P16e1_res - d_res) / d_res,
               ((double)f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("posit16_mid.dat", "w");
  fprintf (file, "n;float; P16e1; double; P32-Double; double-float\n");
  for (double i = -1e6; i < 1e6; i += 1e1)
    {

      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32 (p1, f1, n);
      transfertoposit32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double P16e1_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%le; %le; %le; %le; %e; %e \n", i, (double)f_res,
               P16e1_res, d_res, (P16e1_res - d_res) / d_res,
               ((double)f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("posit16_nan.dat", "w");
  for (double f = 1; f < 1e50; f *= 2)
    {

      fprintf (file, "%f; %f; %le\n", (float)f, ((double)((P16e1)f)), f);
    }
  fclose (file);
  file = fopen ("P32_0-1.dat", "w");
  fprintf (file, "n;float; P16e1; double; P32-Double; double-float\n");
  for (int i = 1; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 1e11);
      initializevector (f2, n, i / 1e11);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertoposit32_2 (p3, f1, n);
      transfertoposit32_2 (p4, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double P32e2_res = (double)(positdotproduct_2 (p3, p4, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, (double)P32e2_res, d_res,
               ((double)P32e2_res - d_res) / d_res, (f_res - d_res) / d_res);
    }
  fclose (file);

  return 0;
}