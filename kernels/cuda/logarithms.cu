
__global__ void
log_libmath (double *x, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      x[tid] = log (x[tid]);
    }
}

__global__ void
logarithm_taylor (double *x, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      int iter = 100;
      double result = 0.0;
      double term = x[tid] - 1.0;

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
          term *= (x[tid] - 1.0);
        }

      x[tid] = result;
    }
}
