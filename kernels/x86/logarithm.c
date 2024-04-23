#include "../../include/kernels.h"

void
log_libmath (double *input, double *output, int n)
{
  for (int i = 0; i < n; i++)
    output[i] = log (input[i]);
}

void
logarithm_taylor (double *input, double *output, int n)
{
  int iter = 100;
  for (int j = 0; j < n; j++)
    {
      if (input[j] <= 0)
        {
          printf ("Erreur : Le logarithme ne peut être calculé pour des "
                  "valeurs négatives ou nulles.\n");
          continue; // Passe à la valeur suivante si x[j] est négatif ou nul
        }

      double result = 0.0;
      double term = input[j] - 1.0; // Premier terme de la série de Taylor

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
