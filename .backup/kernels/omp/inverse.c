#include "../../include/kernels.h"
#include "../../include/utils.h"

void
inve_matrix_gauss_jordan (float *mat, float *inv, int n)
{
  float *temp;
  temp = malloc (n * n * sizeof (float));

  for (int i = 0; i < n * n; i++)
    {
      temp[i] = mat[i];
    }
// init identity matrix
#pragma omp for
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (i == j)
            {
              inv[i * n + j] = 1.0;
            }
          else
            {
              inv[i * n + j] = 0.0;
            }
        }
    }
#pragma omp barrier

#pragma omp single
  {
    // Gauss-Jordan elimination
    for (int i = 0; i < n; i++)
      {
        // get pivot
        float pivot = temp[i * n + i];

        // Dividing by pivot
        for (int j = 0; j < n; j++)
          {
            temp[i * n + j] /= pivot;
            inv[i * n + j] /= pivot;
          }

        // remove other elements
        for (int k = 0; k < n; k++)
          {
            if (k != i)
              {
                float coeff = temp[k * n + i];
                for (int j = 0; j < n; j++)
                  {
                    temp[k * n + j] -= coeff * temp[i * n + j];
                    inv[k * n + j] -= coeff * inv[i * n + j];
                  }
              }
          }
      }

    // free memory
    free (temp);
  }
}
