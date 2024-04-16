extern "C" {
  #include "../../include/utils.h"
  // #include "../../include/driver.h"
}
  #include "../../include/cuda.h"
  #include "../../include/kernels.h"

#define DRIVER_BODY_BENCHMARK_CUDA(kernel, ...)                                         \
  dim3 threadsPerBlock (32, 32);                                              \
  dim3 numBlocks (matrix_size / threadsPerBlock.x,                            \
                  matrix_size / threadsPerBlock.y);                           \
  cudaEvent_t start_event, end_event;                                         \
  float elapsed;                                                              \
  for (uint32_t stability = 0; stability < 33; stability++)                   \
    {                                                                         \
      cudaEventCreate (&start_event);                                         \
      cudaEventCreate (&end_event);                                           \
      cudaEventRecord (start_event, 0);                                       \
      for (uint32_t rep = 0; rep < data->repetition; rep++)                   \
        {                                                                     \
          kernel<<<numBlocks, threadsPerBlock>>> (__VA_ARGS__);               \
        }                                                                     \
      cudaEventRecord (end_event, 0);                                         \
      cudaEventSynchronize (end_event);                                       \
      cudaEventElapsedTime (&elapsed, start_event, end_event);                \
      elapsed *= 1e-3;                                                        \
      data->samples[stability] = (double)elapsed / data->repetition;          \
    }                                                                         

void
driver_cuda_fp64_benchmark (char *title, char *buffer,
                            void (*kernel) (double *, double *, double *, int),
                            struct data *data, int matrix_size)
{
  double *A, *B, *C, *d_A, *d_B, *d_C;
  long _matrix_size_2 = matrix_size * matrix_size;
  A = (double *)malloc (sizeof (double) * _matrix_size_2);
  B = (double *)malloc (sizeof (double) * _matrix_size_2);
  C = (double *)malloc (sizeof (double) * _matrix_size_2);

  INIT (A, _matrix_size_2);
  INIT (B, _matrix_size_2);
  INIT (C, _matrix_size_2);

  cublasHandle_t handle;
  cublasCreate (&handle);
  cudaMalloc (&d_A, _matrix_size_2 * sizeof (double));
  cudaMalloc (&d_B, _matrix_size_2 * sizeof (double));
  cudaMalloc (&d_C, _matrix_size_2 * sizeof (double));

  cudaMemcpy (d_A, A, _matrix_size_2 * sizeof (double),
              cudaMemcpyHostToDevice);
  cudaMemcpy (d_B, B, _matrix_size_2 * sizeof (double),
              cudaMemcpyHostToDevice);

  DRIVER_BODY_BENCHMARK_CUDA (kernel, d_A, d_B, d_C, matrix_size);
  formatting_data (data);
  print_data_benchmark (title, data, buffer);

  cudaFree (d_A);
  cudaFree (d_B);
  cudaFree (d_C);
  free (A);
  free (B);
  free (C);
}
int
main (int argc, char *argv[])
{

  struct data *data;
  data = (struct data*)malloc(sizeof(struct data));
  
  uint64_t _matrix_size = atoll (argv[1]);
  uint64_t _repetition = atoll (argv[2]);

  uint64_t _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char *output_buffer;
  output_buffer = (char *)malloc (sizeof (char) * 200 * 11);
  print_header_benchmark (output_buffer, _matrix_size_2 * 2);
  data->type = sizeof (double);
  char test[] = "cuda gemm ijk";

  driver_cuda_fp64_benchmark (test, output_buffer, cuda_64bits_gemm_ijk, data,
                              _matrix_size);
  // driver_cuda_fp64_benchmark ("cuda gemm jik", output_buffer, cuda_64bits_gemm_jik, data, 
  //                // N);
  // driver_cuda_fp64_benchmark ("cuda gemm bloc", output_buffer, cuda_64bits_gemm_bloc, data, 
  //                // N);

  save_data (NULL, output_buffer);

 }
