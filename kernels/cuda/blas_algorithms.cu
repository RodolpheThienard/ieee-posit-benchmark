__global__ void
ieee_64bits_gemm_jik (double *A, double *B, double *C, int N)
{
  int j = blockIdx.x * blockDim.x + threadIdx.x;
  // Col
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  double sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}

__global__ void
ieee_64bits_gemm_ijk (double *A, double *B, double *C, int N)
{
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  // Col
  int j = blockIdx.y * blockDim.y + threadIdx.y;
  double sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}

__global__ void
ieee_64bits_gemm_bloc (double *A, double *B, double *C, int N)
{
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  int j = blockIdx.y * blockDim.y + threadIdx.y;

  __shared__ double a[32][32];
  __shared__ double b[32][32];

  double sum = 0;
  for (int k = 0; k < N; k += 32)
    {
      a[threadIdx.y][threadIdx.x] = A[j * N + k + threadIdx.x];
      b[threadIdx.y][threadIdx.x] = B[(k + threadIdx.y) * N + i];

      __syncthreads ();

      for (int l = 0; l < 32; l++)
        sum += a[threadIdx.y][l] * b[l][threadIdx.x];

      __syncthreads ();
    }
  C[j * N + i] = sum;
}

__global__ void
inve_matrix_gauss_jordan (double *mat, double *inv, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      for (int i = 0; i < n; i++)
        {
          // get pivot
          double pivot = mat[i * n + i];

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
