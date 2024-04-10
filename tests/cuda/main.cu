extern "C" {
  #include "../../include/utils.h"
  #include "../../include/driver.h"
}
  #include "../../include/cuda.h"
  #include "../../include/kernels.h"

int
main (int argc, char *argv[])
{
  int N = 1 << 20;
  double *A, *B, *C, *d_A, *d_B, *d_C;

  N = (argc < 2) ? 1000 : atoi (argv[1]);

  // Memory allocation
  A = (double *)malloc (sizeof (double) * N * N);
  B = (double *)malloc (sizeof (double) * N * N);
  C = (double *)malloc (sizeof (double) * N * N);


  INIT (A, N);
  INIT (B, N);
  INIT (C, N);

  cublasHandle_t handle;
  cublasCreate (&handle);
  cudaMalloc (&d_A, N * N * sizeof (double));
  cudaMalloc (&d_B, N * N * sizeof (double));
  cudaMalloc (&d_C, N * N * sizeof (double));

  cudaMemcpy (d_A, A, N * N * sizeof (double), cudaMemcpyHostToDevice);
  cudaMemcpy (d_B, B, N * N * sizeof (double), cudaMemcpyHostToDevice);


  struct data *data;
  data = (struct data*)malloc(sizeof(struct data));
  
  uint64_t _matrix_size = atoll (argv[1]);
  uint64_t _repetition = atoll (argv[2]);

  uint64_t _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  print_header(_matrix_size_2);

  data->type = 8;
  driver_cuda_fp64 ("cuda gemm ijk", cuda_64bits_gemm_ijk, data, d_A, d_B, d_C,
                    N);
  driver_cuda_fp64 ("cuda gemm jik", cuda_64bits_gemm_jik, data, d_A, d_B, d_C,
                    N);
  driver_cuda_fp64 ("cuda gemm bloc", cuda_64bits_gemm_bloc, data, d_A, d_B, d_C,
                    N);

  cudaFree (d_A);
  cudaFree (d_B);
  cudaFree (d_C);
  free (A);
  free (B);
  free (C);
}
