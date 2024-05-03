#include "../../include/kernels.h"

void
log_libmath (float *input, float *output, int n)
{
#pragma omp for
  for (int i = 0; i < n; i++)
    input[i] = log (output[i]);
}

void
logarithm_taylor (float *input, float *output, int n)
{
  int iter = 100;
#pragma omp for
  for (int j = 0; j < n; j++)
    {
      if (input[j] <= 0)
        {
          printf ("Erreur : Le logarithme ne peut être calculé pour des "
                  "valeurs négatives ou nulles.\n");
          continue; // Passe à la valeur suivante si x[j] est négatif ou nul
        }

      float result = 0.0;
      float term = input[j] - 1.0; // Premier terme de la série de Taylor

      for (int i = 1; i <= iter; i++)
        {
          if (i % 2 == 0)
            {
              result -= term / i;
            }
          else
            {
              result += term / i;
            }
          term *= (input[j] - 1.0);
        }
      output[j] = result;
    }
}
