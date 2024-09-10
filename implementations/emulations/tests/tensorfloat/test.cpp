#include <iostream>
#include <type_traits>
using namespace std;
struct tf32
{
  unsigned int data;

public:
  tf32 () { data = 0; }

  tf32 (float t_floatVal)
  {
    data = (*reinterpret_cast<unsigned int *> (&t_floatVal)) >> 13;
  }
  tf32 (double t_doubleVal)
  {
    float floatVal = (float)t_doubleVal;
    data = (*reinterpret_cast<unsigned int *> (&floatVal)) >> 13;
  }
  // cast to float
  operator float ()
  {
    unsigned int extendedData = data << 13;
    return *reinterpret_cast<float *> (&extendedData);
  }
  // cast to tf32
  tf32 &
  operator= (float t_floatVal)
  {
    data = (*reinterpret_cast<unsigned int *> (&t_floatVal)) >> 13;
    return *this;
  }
};

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

void
transfertotf32 (tf32 *pv, float *fv, int n)
{
  for (int idx = 0; idx < n; ++idx)
    {
      pv[idx] = tf32 (fv[idx]);
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
  file = fopen ("tf32_around_0_2.dat", "w");
  fprintf (file, "n;float; P32e2; double; P32-Double; double-float\n");
  int n = 1000;
  float f1[n];
  float f2[n];

  tf32 p1[n];
  tf32 p2[n];

  double d1[n];
  double d2[n];

  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 1e5);
      initializevector (f2, n, i / 1e5);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertotf32 (p1, f1, n);
      transfertotf32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      // double p32e2_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, ((double)(tf32 (f_res))), d_res,
               ((double)(tf32 (f_res)) - d_res) / d_res,
               (f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("tf32_0_1e4.dat", "w");
  fprintf (file, "n;float; P32e2; double; P32-Double; double-float\n");
  for (int i = -100000; i < 100000; i += 1)
    {
      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertotf32 (p1, f1, n);
      transfertotf32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      // double p32e2_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, ((double)(tf32 (f_res))), d_res,
               ((double)(tf32 (f_res)) - d_res) / d_res,
               (f_res - d_res) / d_res);
    }
  fclose (file);

  file = fopen ("tf32_range_2.dat", "w");
  fprintf (file, "n;float; P32e2; double; P32-Double; double-float\n");
  for (int i = -1e5; i < 1e5; i += 1e1)
    {

      initializevector (f1, n, i * 1e2);
      initializevector (f2, n, i * 1e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertotf32 (p1, f1, n);
      transfertotf32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      // double p32e2_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", i,
               (double)f_res, ((double)(tf32 (f_res))), d_res,
               ((double)(tf32 (f_res)) - d_res) / d_res,
               (f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("tf32_mid.dat", "w");
  fprintf (file, "n;float; P32e2; double; P32-Double; double-float\n");
  for (double i = -1e6; i < 1e6; i += 1e1)
    {

      initializevector (f1, n, i / 5e2);
      initializevector (f2, n, i / 5e2);

      transfertodouble (d1, f1, n);
      transfertodouble (d2, f2, n);

      transfertotf32 (p1, f1, n);
      transfertotf32 (p2, f2, n);

      float f_res = floatdotproduct (f1, f2, n);
      // double p32e2_res = (double)(positdotproduct (p1, p2, n));
      double d_res = doubledotproduct (d1, d2, n);

      fprintf (file, "%le; %le; %le; %le; %e; %e \n", i, (double)f_res,
               (double)(tf32 (f_res)), d_res,
               ((double)(tf32 (f_res)) - d_res) / d_res,
               ((double)f_res - d_res) / d_res);
    }
  fclose (file);
  file = fopen ("tf32_nan.dat", "w");
  for (double f = 1; f < 1e50; f *= 2)
    {

      fprintf (file, "%f; %f; %le\n", (float)f, ((double)(tf32 (f))), f);
    }
  fclose (file);
  return 0;
}
