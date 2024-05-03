
__global__ void
log_libmath (float *input, float *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      output[tid] = log (input[tid]);
    }
}

__global__ void
logarithm_taylor (float *input, float *output, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      int iter = 100;
      float result = 0.0;
      float term = input[tid] - 1.0;

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
          term *= (input[tid] - 1.0);
        }

      output[tid] = result;
    }
}
