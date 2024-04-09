#include <cublas_v2.h>
#include <cuda_runtime.h>

#define DRIVER_BODY_CUDA(kernel, ...)                                         \
  cudaEvent_t start_event[33], end_event[33];                                 \
  for (uint32_t stability = 0; stability < 33; stability++)                   \
    {                                                                         \
      cudaEventCreate (&start_event[stability]);                              \
      cudaEventCreate (&end_event[stability]);                                \
      cudaEventRecord (start_event[stability], 0);                            \
      for (uint32_t rep = 0; rep < data->repetition; rep++)                   \
        {                                                                     \
          kernel (__VA_ARGS__);                                               \
        }                                                                     \
      cudaEventRecord (end_event[stability], 0);                              \
      cudaEventSynchronize (end_event[stability]);                            \
      data->samples[stability] = end_event - start_event;                     \
    }                                                                         \
  sort_double (data->samples);                                                \
  data->mean = mean (data->samples);                                          \
  data->stddev = stddev (data->samples, data->mean);                          \
  print_data (title, data);

