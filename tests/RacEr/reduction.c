#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)

__global__ void
reduction (int *output, int *input, int n)
{
  extern __shared__ int sdata[];

  unsigned int tid = it_x;
  unsigned int i = blockIdx_x * blockDim_x + it_x;

  if (i < n)
    {
      sdata[tid] = input[i];
    }
  else
    {
      sdata[tid] = 0;
    }
  __syncthreads ();

  for (unsigned int s = blockDim_x / 2; s > 0; s >>= 1)
    {
      if (tid < s)
        {
          sdata[tid] += sdata[tid + s];
        }
      __syncthreads ();
    }

  if (tid == 0)
    {
      output[blockIdx_x] = sdata[0];
    }
}

int
main (int argc, char *argv[])
{
  int N = 1 < 10;
  int *input, *output;
  input = malloc (N * sizeof (int));
  output = malloc (N * sizeof (int));

  reduction (output, input, N);

  printf ("Data gathered : %d; %d\n", input[0], output[0]);

  free (input);
  free (output);
  return 0;
}
