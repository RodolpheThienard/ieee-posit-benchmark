__global__ void
inve_matrix_gauss_jordan_2 (double *mat, double *inv, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      for (int i = 0; i < n; i++)
        {
          double tmp = mat[i * n + i];
          ;
          // get pivot
          double pivot = tmp;

          // Dividing by pivot
          mat[i * n + tid] /= pivot;
          inv[i * n + tid] /= pivot;

          __syncthreads ();

          // remove other elements
          if (tid != i)
            {
              double coeff = mat[tid * n + i];
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
inve_matrix_gauss_jordan (double *a, double *b, int size)
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
