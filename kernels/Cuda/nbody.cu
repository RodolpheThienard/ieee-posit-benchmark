#include <cstddef>
#include <cstdlib>
#include <cublas_v2.h>
#include <cuda_runtime.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define gettime(t) clock_gettime (CLOCK_MONOTONIC_RAW, t)
#define get_sub_seconde(t) (1e-9 * (float)t.tv_nsec)

/* Masses : Same for all particles
   Acceleration : differ
   Velocity : differ */
struct system {
  double *x, *y;
  double *acceleration, *velocity, masses;
};

/* Kernel of nbody function */
__global__ void
nbody_update (struct system system,  int N)
{

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      {
        system.x[i * N + j] += 1;
        system.y[i * N + j] += 1;
      }
  return;
}

// Initialisation with linear congruential algorithm and 48-bit integer arithmetic
void
init (struct system system, int N)
{
  for (int i = 0; i < N; i++)
    {
      system.x[i] = drand48 ();
      system.y[i] = drand48 ();
    }
}


int
ma (int argc, char *argv[])
{
  int N = 42;
  double *d_x, *d_y, *d_acceleration, *d_velocity;
  double *h_x, *h_y, *h_acceleration, *h_velocity;

  double masses = 5.0;

  struct system h_system;

  // Allocation
  h_x = (double *)malloc (sizeof (double) * N);
  h_y = (double *)malloc (sizeof (double) * N);

  // Cuda Allocation
  cudaMalloc (&d_x, sizeof (double) * N);
  cudaMalloc (&d_y, sizeof (double) * N);
  cudaMalloc (&d_acceleration, sizeof (double) * N);
  cudaMalloc (&d_velocity, sizeof (double) * N);

  // Initialisation value between 0.0 & 1.0
  init(h_system, N);
  
  // Copy host to device
  cudaMemcpy (d_x, h_x, sizeof (double) * N, cudaMemcpyHostToDevice);
  cudaMemcpy (d_y, h_y, sizeof (double) * N, cudaMemcpyHostToDevice);
  cudaMemcpy (d_acceleration, h_acceleration, sizeof (double) * N, cudaMemcpyHostToDevice);
  cudaMemcpy (d_velocity, h_velocity, sizeof (double) * N, cudaMemcpyHostToDevice);

  // device system initialisation
  struct system d_system = {d_x, d_y, d_acceleration, d_velocity, masses};

  // Kernel
  nbody_update<<<64, 64>>> (d_system, N);

  // Copy device to host
  cudaMemcpy (h_x, d_x, sizeof (double) * N, cudaMemcpyDeviceToHost);
  cudaMemcpy (h_y, d_y, sizeof (double) * N, cudaMemcpyDeviceToHost);
  cudaMemcpy (h_acceleration, d_acceleration, sizeof (double) * N, cudaMemcpyDeviceToHost);
  cudaMemcpy (h_velocity, d_velocity, sizeof (double) * N, cudaMemcpyDeviceToHost);

  // Free device & host
  cudaFree (d_x);
  cudaFree (d_y);
  cudaFree (d_acceleration);
  cudaFree (d_velocity);

  free (h_x);
  free (h_y);
  free (h_acceleration);
  free (h_velocity);

  return 0;
}
