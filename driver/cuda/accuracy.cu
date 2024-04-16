#include <cstdio>
extern "C" {
#include "../../include/utils.h"
}
#include "../../include/cuda.h"
#include "../../include/kernels.h"

#define DRIVER_BODY_ACCURACY_CUDA(kernel, ...)                                 \
  {                                                                            \
    dim3 threadsPerBlock(32, 32);                                              \
    dim3 numBlocks(matrix_size / threadsPerBlock.x,                            \
                   matrix_size / threadsPerBlock.y);                           \
    kernel<<<numBlocks, threadsPerBlock>>>(__VA_ARGS__);                       \
  }

#define DRIVER_BODY_COMPARE_ACCURACY_CUDA(fn, fn2, a, b, size)                 \
  {                                                                            \
    dim3 threadsPerBlock(32, 32);                                              \
    dim3 numBlocks(matrix_size / threadsPerBlock.x,                            \
                   matrix_size / threadsPerBlock.y);                           \
    fn<<<numBlocks, threadsPerBlock>>>(a, size);                               \
    fn2<<<numBlocks, threadsPerBlock>>>(b, size);                              \
  }

/* driver for inv matrix computation
   Alloc and init matrix
   compute with given kernel
   compute identity matrix from A * A⁻¹
   check error between computed identity matrix and real identity matrix */
void driver_cuda_inv_matrix_accuracy(char *title, char *buffer,
                                     void (*kernel)(double *, double *, int),
                                     struct accuracy *accuracy,
                                     int matrix_size) {
  // initialisation matrix
  double *A, *B, *C, *D, *d_A, *d_B, *d_C, *d_D;
  int _matrix_size_2 = matrix_size * matrix_size;
  A = (double *)malloc(sizeof(double) * _matrix_size_2);
  B = (double *)malloc(sizeof(double) * _matrix_size_2);
  C = (double *)malloc(sizeof(double) * _matrix_size_2);
  D = (double *)malloc(sizeof(double) * _matrix_size_2);

  INIT(A, _matrix_size_2);
  INIT(B, _matrix_size_2);

  cudaMalloc(&d_A, _matrix_size_2 * sizeof(double));
  cudaMalloc(&d_B, _matrix_size_2 * sizeof(double));
  cudaMalloc(&d_C, _matrix_size_2 * sizeof(double));
  cudaMalloc(&d_D, _matrix_size_2 * sizeof(double));

  cudaMemcpy(d_A, A, _matrix_size_2 * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, B, _matrix_size_2 * sizeof(double), cudaMemcpyHostToDevice);
  fprintf(stdout, "ICI\n");
  DRIVER_BODY_ACCURACY_CUDA(kernel, d_A, d_B, matrix_size);

  set_identity_matrix(C, matrix_size, matrix_size);

  cudaMemcpy(d_C, C, _matrix_size_2 * sizeof(double), cudaMemcpyHostToDevice);
  ieee_64bits_gemm_bloc(C, B, D, matrix_size);

  DRIVER_BODY_ACCURACY_CUDA(kernel, d_D, d_B, matrix_size);
  cudaMemcpy(A, d_A, _matrix_size_2 * sizeof(double), cudaMemcpyDeviceToHost);
  cudaMemcpy(B, d_B, _matrix_size_2 * sizeof(double), cudaMemcpyDeviceToHost);

  accuracy->accuracy = compute_err_accuracy(A, B, _matrix_size_2);
  accuracy->RMS = RMS(A, B, _matrix_size_2);
  accuracy->forward_error = forward_error(A, B, _matrix_size_2);
  print_data_accuracy(title, buffer, accuracy);

  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C);
  cudaFree(d_D);
  free(A);
  free(B);
  free(C);
  free(D);
}

/* driver to compare 2 vectors/matrix
   Alloc and init vector/matrix
   compute with given kernels
   check error between the two kernels  */
void driver_compare_accuracy(char *title, char *buffer, void (*kernel)(double *, int),
                                  void (*kernel_2)(double *, int), struct accuracy *accuracy,
                                  int matrix_size) {
  double *A, *B, *d_A, *d_B;
  int _matrix_size_2 = matrix_size * matrix_size;
  A = (double *)malloc(sizeof(double) * _matrix_size_2);
  B = (double *)malloc(sizeof(double) * _matrix_size_2);
  // INIT(A, matrix_size);

  cudaMalloc(&d_A, _matrix_size_2 * sizeof(double));
  cudaMalloc(&d_B, _matrix_size_2 * sizeof(double));
  // copying init values
  for (int i = 0; i < _matrix_size_2; i++) {
    A[i] += drand48();
    B[i] = A[i];
  }

  cudaMemcpy(d_A, A, _matrix_size_2 * sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, B, _matrix_size_2 * sizeof(double), cudaMemcpyHostToDevice);

  DRIVER_BODY_COMPARE_ACCURACY_CUDA(kernel, kernel_2, d_A, d_B, _matrix_size_2);

  cudaMemcpy(A, d_A, _matrix_size_2 * sizeof(double), cudaMemcpyDeviceToHost);
  cudaMemcpy(B, d_B, _matrix_size_2 * sizeof(double), cudaMemcpyDeviceToHost);


  accuracy->accuracy = compute_err_accuracy(A, B, _matrix_size_2);
  accuracy->RMS = RMS(A, B, _matrix_size_2);
  accuracy->forward_error = forward_error(A, B, _matrix_size_2);

  print_data_accuracy(title, buffer, accuracy);

  cudaFree(d_A);
  cudaFree(d_B);
  free(A);
  free(B);
}
