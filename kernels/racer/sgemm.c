#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (double)t.tv_nsec)
#define get_total_time(t) ((double)t.tv_sec + get_sub_seconde (t))

void
init (float *A, float *B, float *C, int size)
{
  int i = 0, j = 0;

  for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
        {
          A[i * size + j] = (float)(drand48 ());
          B[i * size + j] = (float)(drand48 ());
          C[i * size + j] = 0.0;
        }
    }
}

__global__ void
sgemm_ijk (float *A, float *B, float *C, int N)
{
  int it_x, it_y;
  for (it_x = RacEr_x; it_x < blockDim.x; it_x += RacEr_tilegroupDim.x)
    {
      for (it_y = RacEr_y; it_y < blockDim.y; it_y += RacEr_tilegroupDim.y)
        {
          float sum = 0.;
          for (int k = 0; k < N; k++)
            {
              sum += A[it_x * N + k] * B[k * N + it_y];
            }
          C[it_x * N + it_y] = sum;
        }
    }
}
__global__ void
sgemm_jik (float *A, float *B, float *C, int N)
{
  int it_x, it_y;
  for (it_x = RacEr_x; it_x < blockDim.x; it_x += RacEr_tilegroupDim.x)
    {
      for (it_y = RacEr_y; it_y < blockDim.y; it_y += RacEr_tilegroupDim.y)
        {
          float sum = 0.;
          for (int k = 0; k < N; k++)
            {
              sum += A[it_y * N + k] * B[k * N + it_x];
            }
          C[it_y * N + it_x] = sum;
        }
    }
}

__global__ void
sgemm_bloc (float *A, float *B, float *C, int N)
{
  int it_x, it_y;
  for (it_x = RacEr_x; it_x < blockDim.x; it_x += RacEr_tilegroupDim.x)
    {
      for (it_y = RacEr_y; it_y < blockDim.y; it_y += RacEr_tilegroupDim.y)
        {

          // __shared__ float a[32][32];
          // __shared__ float b[32][32];
          float a[32][32];
          float b[32][32];

          float sum = 0;
          for (int k = 0; k < N; k += 32)
            {
              a[it_y][it_x] = A(it_y * N + k + it_x];
              b[it_y][it_x] = B[(k + it_y) * N + it_x];

              __syncthreads ();

              for (int l = 0; l < 32; l++)
                sum += a[it_y][l] * b[l][it_x];

              __syncthreads ();
            }
          C[it_y * N + it_x] = sum;
        }
    }
}

int
main (int argc, char *argv[])
{
  int N = 1 << 20;
  float *A, *B, *C, *d_A, *d_B, *d_C;

  N = (argc < 2) ? 1000 : atoi (argv[1]);

  // Memory allocation
  A = (float *)malloc (sizeof (float) * N * N);
  B = (float *)malloc (sizeof (float) * N * N);
  C = (float *)malloc (sizeof (float) * N * N);

  init (A, B, C, N);

  struct timespec t0, t1;
  gettime (&t0);

  sgemm_ijk (d_A, d_B, d_C, N);

  gettime (&t1);

  double s = get_total_time (t1) - get_total_time (t0);
  // Pretty print
  long long N_u64 = (long long)N;
  long long nb_op = N_u64 * N_u64 * N_u64;
  // fprintf (stdout, "Performance results: \n");
  // fprintf (stdout, "  Time: %e ms\n", ms);
  // fprintf (stdout, "  MFlops: %.2f\n", (nb_op / ms*1e3) * 1E-6);
  fprintf (stdout, "%d; %f; %.2f\n", N, s, ((nb_op / s) * 1e-9));

  free (A);
  free (B);
  free (C);
}
