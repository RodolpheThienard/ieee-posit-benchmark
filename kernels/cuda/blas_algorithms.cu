__global__ void 
sgemm (float *A, float *B, float *C, int N)
{
  int j= blockIdx.x * blockDim.x + threadIdx.x;
  int i = blockIdx.y * blockDim.y + threadIdx.y;
  float sum = 0.;
  for (int k = 0; k < N; k++)
    {
      sum += A[i * N + k] * B[k * N + j];
    }
  C[i * N + j] = sum;
}
