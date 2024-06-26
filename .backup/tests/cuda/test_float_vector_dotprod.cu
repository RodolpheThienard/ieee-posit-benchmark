
#include <cublas_v2.h>
#include <cuda_runtime.h>
__global__ void
vector_dotprod (float *A, float *B, float *C, int N)
{
  extern __shared__ float S[];
  int tid = threadIdx.x ;
  int i = blockDim.x * blockIdx.x + threadIdx.x;
  if (i < N) {
    S[tid] = A[i];
    __syncthreads();
    // Reduce in shared memory
    for (int t = blockDim.x/2; t > 0; t>>=1) {
      if (tid < t) {
        S[tid] += S[tid + t];
      }
      __syncthreads();
    }
    if (tid == 0) C[blockIdx.x] = S[0];
  }
}
int
main (int argc, char *argv[])
{
  struct data *data;
  data = (struct data *)malloc (sizeof (struct data));
  struct accuracy *accuracy;
  accuracy = (struct accuracy *)malloc (sizeof (struct accuracy));

  int _matrix_size = atoll (argv[1]);
  long _repetition = atoll (argv[2]);

  long _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char buffer[1000];
  data->type = sizeof (double);
  struct bench_s bench = { data, accuracy, 1024, 2048, 128 };

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      _matrix_size = i;
      int _matrix_size_2 = i;
      bench.data->matrice_size = _matrix_size_2;

      float *a, *b, *c, *c_host, *d_a, *d_b, *d_c;
      a = (float *)malloc (sizeof (float) * _matrix_size_2);
      b = (float *)malloc (sizeof (float) * _matrix_size_2);
      c = (float *)malloc (sizeof (float) * _matrix_size_2);
      c_host = (float *)malloc (sizeof (float) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (float));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (float));
      cudaMalloc (&d_c, _matrix_size_2 * sizeof (float));

      // INIT (a, _matrix_size_2);
      // INIT (b, _matrix_size_2);

      double *aa,*bb,*cc, *c_device;
      aa = (double *)malloc (sizeof (double) * _matrix_size_2);
      bb = (double *)malloc (sizeof (double) * _matrix_size_2);
      cc = (double *)malloc (sizeof (double) * _matrix_size_2);
      c_device = (double *)malloc (sizeof (double) * _matrix_size_2);
      INIT (aa, _matrix_size_2);
      for (int ll = 0; ll < _matrix_size_2; ll++)
      {
        a[ll] = aa[ll];
        b[ll] = bb[ll];
      }

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_b, b, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);

      driver_vector_dotprod (vector_add, _matrix_size_2, d_a, d_b, &bench);

      cudaMemcpy (c, d_c, _matrix_size_2 * sizeof (float),
                  cudaMemcpyDeviceToHost);

      host_vector_dotprod (aa, bb, _matrix_size);


      conversion_into_double(c, c_device, _matrix_size_2);

      driver_accuracy (_matrix_size_2, cc, c_device, &bench);
      print_data_accuracy (buffer, bench.accuracy);

      free (a);
      free (b);
      free (c);
      free (c_host);
      cudaFree (d_a);
      cudaFree (d_b);
      cudaFree (d_c);
    }

  save_data (NULL, buffer);
  free (data);
  free (accuracy);
  return error_accuracy(&bench);
}

