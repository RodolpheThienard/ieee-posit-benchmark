extern "C" {
  #include "../include/driver.h"
}
  #include "../include/cuda.h"

#define DRIVER_BODY_CUDA(kernel, ...)                                         \
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
    }                                                                         \

  
void
driver_cuda_fp64 (char *title, void (*kernel) (double*, double*, double*, int), struct data *data,
                  double * a, double *b, double *c,
                  int matrix_size)
{
  DRIVER_BODY_CUDA (kernel, a, b, c, matrix_size);
  formatting_data(data);
  print_data(title, data);
}
