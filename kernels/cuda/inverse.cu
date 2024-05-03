__global__ void
inve_matrix_gauss_jordan_2 (float *mat, float *inv, int n)
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
inve_matrix_gauss_jordan_cuda(float *a, float *b, int size, int i)
{
  int x = blockIdx.x * blockDim.x + threadIdx.x;
  int y = blockIdx.y * blockDim.y + threadIdx.y;

  if (x < size && y < size)
    {
      float pivot = a[i * size + i];
      if (x == i && x != y)
        {
          b[x * size + y] /= pivot;
          a[x * size + y] /= pivot;
        }

      if (x == y && x == i)
        {
          b[x * size + y] /= pivot;
          a[x * size + y] /= pivot;
        }

      if (x != i)
        {
          float multiplier = a[x * size + i];
          b[x * size + y] -= b[i * size + y] * multiplier;
          if (y != i)
            {
              a[x * size + y] -= a[i * size + y] * multiplier;
            }
        }

      if (x != i && y == i)
        {
          a[x * size + y] = 0;
        }
    }
}
