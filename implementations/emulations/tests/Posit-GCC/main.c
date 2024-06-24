#include <stdio.h>
#include <stdlib.h>

void
initializevector_0 (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx] = ((float)rand () / (float)RAND_MAX) * i
               / 1e5; // warning, requires posix standard.
    }
}
void
initializevector (float *f, int n, int i)
{
  for (int idx = 0; idx < n; ++idx)
    {
      f[idx] = ((float)rand () / (float)RAND_MAX) * i
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
#ifdef POSIT

  char name[] = "posit_gcc_posit_around_0.dat";
  char name2[] = "posit_gcc_posit_range.dat";
  char name3[] = "posit_gcc_posit_nan.dat";
#else
  char name[] = "posit_gcc_ieee_around_0.dat";
  char name2[] = "posit_gcc_ieee_range.dat";
  char name3[] = "posit_gcc_ieee_nan.dat";
#endif

  FILE *file;
  file = fopen (name, "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  int n = 1000;
  float *f1 = malloc (sizeof (float) * n);
  float *f2 = malloc (sizeof (float) * n);

  double *d1 = malloc (sizeof (double) * n);
  double *d2 = malloc (sizeof (double) * n);

  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector_0 (f1, n, i);
      initializevector_0 (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %e \n", i, d_res, (double)f_res,
               (f_res - d_res) / d_res);
    }
  fclose (file);

  file = fopen (name2, "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  for (double i = -1e6; i < 1e6; i += 1e1)
    {

      initializevector (f1, n, i);
      initializevector (f2, n, i);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%lf; %lf; %f; %e \n", i, (double)f_res, d_res,
               ((double)f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen (name3, "w");
  for (double f = 1; f < 1e50; f *= 2)
    {

      fprintf (file, "%f; %le\n", ((float)f), f);
    }
  free (f1);
  free (f2);
  free (d1);
  free (d2);
  fclose (file);
  return 0;
}
