void
inve_matrix_gauss_jordan_double (double * mat, double * inv, int n)
{
  double *temp = (double*)malloc (n * n * sizeof (double));
  for (int i = 0; i < n * n; i++)
    {
      temp[i] = mat[i];
    }

  // init identity matrix
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

  // Gauss-Jordan elimination
  for (int i = 0; i < n; i++)
    {
      // get pivot
      double pivot = temp[i * n + i];

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
              double coeff = temp[k * n + i];
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

__global__ void
inve_matrix_gauss_jordan (float *mat, float *inv, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      for (int i = 0; i < n; i++)
        {
          float tmp = mat[i * n + i];
          ;
          // get pivot
          float pivot = tmp;

          // Dividing by pivot
          mat[i * n + tid] /= pivot;
          inv[i * n + tid] /= pivot;

          __syncthreads ();

          // remove other elements
          if (tid != i)
            {
              float coeff = mat[tid * n + i];
              for (int j = 0; j < n; j++)
                {
                  mat[tid * n + j] -= coeff * mat[i * n + j];
                  inv[tid * n + j] -= coeff * inv[i * n + j];
                }
            }

          __syncthreads ();
        }
    }
}

__global__ void
inve_matrix_gauss_jordan_2 (float *a, float *b, int size)
{
#define element(_x, _y) (*(sdata + ((_y) * (size + 1) + (_x))))
  unsigned int xx, yy, rr;

  // With a limit of 512 threads per block, and only one block, this results
  // in a maximum of a matrix size 22, which requires (22 + 1) x 22 values
  __shared__ float sdata[(22 + 1) * 22];

  xx = threadIdx.x;
  rr = threadIdx.y;

  int tid = rr * (size + 1) + xx;

  // The matrix will be modified in place, so first make a copy of matrix a
  sdata[tid] = a[tid];

  for (yy = 0; yy < size; yy++)
    {

      __syncthreads ();

      // Make the pivot be 1
      element (xx, yy) /= element (yy, yy);

      __syncthreads ();

      // Make all other values in the pivot column be zero
      if (rr != yy)
        element (xx, rr) -= element (yy, rr) * element (xx, yy);
    }

  b[tid] = sdata[tid];
#undef element
}
