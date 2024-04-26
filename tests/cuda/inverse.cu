extern "C" {
  #include "../../include/utils.h"
}
  #include "../../include/kernels.h"
  #include "../../include/cuda.h"

#define DRIVER_BODY(fn, ...)                                                  \
  {                                                                           \
    dim3 threadsPerBlock (32, 32);                                            \
    dim3 numBlocks (i / threadsPerBlock.x,                          \
                    i / threadsPerBlock.y);                         \
    cudaEvent_t start_event, end_event;                                       \
    float elapsed;                                                            \
    for (int stability = 0; stability < 33; stability++)                      \
      {                                                                       \
        cudaEventCreate (&start_event);                                       \
        cudaEventCreate (&end_event);                                         \
        cudaEventRecord (start_event, 0);                                     \
        for (int rep = 0; rep < bench.data->repetition; rep++)                      \
          {                                                                   \
            fn<<<numBlocks, threadsPerBlock>>> (__VA_ARGS__);                 \
          }                                                                   \
        cudaEventRecord (end_event, 0);                                       \
        cudaEventSynchronize (end_event);                                     \
        cudaEventElapsedTime (&elapsed, start_event, end_event);              \
        elapsed *= 1e-3;                                                      \
        bench.data->samples[stability]                                       \
            = (double)elapsed / bench.data->repetition;                      \
      }                                                                       \
  }
  
__global__ void
inve_matrix_gauss_jordan2 (double *mat, double *inv, int n)
{
  int tid = threadIdx.x + blockIdx.x * blockDim.x;
  if (tid < n)
    {
      for (int i = 0; i < n; i++)
        {
          double tmp = mat[i * n + i];
          ;
          // get pivot
          double pivot = tmp;

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
  data->type = sizeof (double);
  struct bench bench = { data, accuracy, 100, 3000, 100 };

  char buffer[1000];
  print_header_diff (buffer);
  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;

      double *a, *b, *c, *d, *d_a, *d_b, *d_c, *d_d;
      a = (double *)malloc (sizeof (double) * _matrix_size_2);
      b = (double *)malloc (sizeof (double) * _matrix_size_2);
      c = (double *)malloc (sizeof (double) * _matrix_size_2);
      d = (double *)malloc (sizeof (double) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_c, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_d, _matrix_size_2 * sizeof (double));
      INIT (a, _matrix_size_2);
      INIT (b, _matrix_size_2);

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);

      DRIVER_BODY (inve_matrix_gauss_jordan2, d_a, d_b, i);

      set_identity_matrix (c, i, i);
      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_c, c, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      ieee_64bits_gemm_jik (d_c, d_b, d_d, i);

      DRIVER_BODY (inve_matrix_gauss_jordan2, d_d, d_b, i);

      cudaMemcpy (b, d_b, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      cudaMemcpy (a, d_a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      formatting_data (bench.data);
      print_data_benchmark ("inversion gauss jordan", bench.data, buffer);

      bench.accuracy->accuracy = compute_err_accuracy (a, b, i);
      bench.accuracy->RMS = RMS (a, b, i);
      bench.accuracy->forward_error = forward_error (a, b, i);

      print_diff_accuracy ("Comparaison", buffer, &bench, bench.data);
      free (a);
      free (b);
      free (c);
      free (d);
      save_data (NULL, buffer);
    }

  free (data);
  return 0;
}
