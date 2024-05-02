void
ieee_32bits_gemm (float * a, float * b, float * c,
                  int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
        {
          const float _a_ = a[i * n + k];

          for (int j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}

void
ieee_64bits_gemm (double * a, double * b, double * c,
                  int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int k = 0; k < n; k++)
        {
          const double _a_ = a[i * n + k];

          for (int j = 0; j < n; j++)
            c[i * n + j] += _a_ * b[k * n + j];
        }
    }
}

__global__ void 
sgemm (float *A, float *B, float *C, int N)
{
  int j = blockIdx.x * blockDim.x + threadIdx.x;
  // Col
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  float sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}
__global__ void
dgemm (double *A, double *B, double *C, int N)
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


