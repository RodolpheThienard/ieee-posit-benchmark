#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)

void
init (float *A, float *B, float *C, int size)
{
  int i = 0, j = 0;

  srand (2019);

  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
        {
          A[i * size + j] = (float)(rand () % 10) + 0.01 * (rand () % 5);
          B[i * size + j] = (float)(rand () % 10) + 0.01 * (rand () % 5);
          C[i * size + j] = 0.0;
        }
    }
}

__global__ void
sgemm_ijk (float *A, float *B, float *C, int N)
{
  int it_z, it_y;
  for (it_z = RacEr_z; it_z < blockDim.z; it_z += RacEr_tilegroupDim.z)
    {
      for (it_y = RacEr_y; it_y < blockDim.y; it_y += RacEr_tilegroupDim.y)
        {
          float sum = 0.;
          for (int k = 0; k < N; k++)
            {
              sum += A[it_z * N + k] * B[k * N + it_y];
            }
          C[it_z * N + it_y] = sum;
        }
    }
}

int
main (int argc, char *argv[])
{
  int N = 1 << 20;
  float *A, *B, *C, *d_A, *d_B, *d_C, t1, t0;

  N = (argc < 2) ? 1000 : atoi (argv[1]);
  // fprintf (stdout, "Matrix Multiplication\n  Size: %dx%d\n", N, N);

  // Memory allocation
  A = (float *)malloc (sizeof (float) * N * N);
  B = (float *)malloc (sizeof (float) * N * N);
  C = (float *)malloc (sizeof (float) * N * N);

  float ms = 0;

  init (A, B, C, N);

  sgemm_ijk (d_A, d_B, d_C, N);

  // Pretty print
  long long N_u64 = (long long)N;
  long long nb_op = N_u64 * N_u64 * N_u64;
  // fprintf (stdout, "Performance results: \n");
  // fprintf (stdout, "  Time: %e ms\n", ms);
  // fprintf (stdout, "  MFlops: %.2f\n", (nb_op / ms*1e3) * 1E-6);
  fprintf (stdout, "%d; %f; %.2f\n", N, ms, ((nb_op / (ms * 1e-3)) * 1e-9));

  free (A);
  free (B);
  free (C);
}
