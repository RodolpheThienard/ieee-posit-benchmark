extern "C"
{
#include "../../include/utils.h"
}

/* TODO Driver macro bandwidth
   macro permettant de faire la mesure du temps / débit
   paramettre variable
   Meta répétition de 31 pour stabilité avec 31 fois le meme calcul exact
   */
#define DRIVER_BANDWIDTH(fn, ...)                              \
  {                                                                           \
    dim3 threadsPerBlock (64, 64);                                            \
    dim3 numBlocks (size / threadsPerBlock.x,                          \
                    size / threadsPerBlock.y);                         \
    cudaEvent_t start_event, end_event;                                       \
    float elapsed;                                                            \
    for (int stability = 0; stability < 33; stability++)                      \
      {                                                                       \
        cudaEventCreate (&start_event);                                       \
        cudaEventCreate (&end_event);                                         \
        cudaEventRecord (start_event, 0);                                     \
        for (int rep = 0; rep < bench->data->repetition; rep++)               \
          {                                                                   \
            fn<<<threadsPerBlock, numBlocks>>> (__VA_ARGS__);                 \
          }                                                                   \
        cudaEventRecord (end_event, 0);                                       \
        cudaEventSynchronize (end_event);                                     \
        cudaEventElapsedTime (&elapsed, start_event, end_event);              \
        elapsed *= 1e-3;                                                      \
        bench->data->samples[stability]                                       \
            = (double)elapsed / bench->data->repetition;                      \
      }                                                                       \
  }

#define DRIVER_ACCURACY(fn, ...)                                              \
  {                                                                           \
    dim3 threadsPerBlock (64, 64);                                            \
    dim3 numBlocks (size / threadsPerBlock.x,                          \
                    size / threadsPerBlock.y);                         \
    fn<<<threadsPerBlock, numBlocks>>> (__VA_ARGS__);                         \
  }
  
/* TODO driver macro accuracy
   macro permettant de faire la mesure de précision
   verification de la sorti du calcul de Bandwidth avec la fonction CPU
   Checker si OMP et x86 sont équivalent */

#define DRIVER_ACCURACY_COMPARE(size, host, device, bench)                         \
  bench->accuracy->accuracy = compute_err_accuracy (host, device, size);      \
  bench->accuracy->RMS = RMS (host, device, size);                            \
  bench->accuracy->forward_error = forward_error (host, device, size);


void
driver_accuracy (int size, double *c_host, double *c_device,
                        struct bench_s bench[])
{
  DRIVER_ACCURACY_COMPARE ( size, c_host, c_device, bench);
}

/* Foo example of API utilisation
   compare 2 function for dgemm */
void
driver_sgemm (void (*function) (float *, float *, float *, int), int size,
              float *a, float *b, float *c, struct bench_s bench[])
{
  DRIVER_BANDWIDTH (function, a, b, c, size);
  cudaMemset(c,0,size*size*sizeof(float));
  DRIVER_ACCURACY(function, a,b,c,size);
  formatting_data (bench->data);
}

void
driver_inverse_gauss_jordan (void (*function) (float *, float *, int, int), int size,
              float *a, float *b, int i, struct bench_s bench[])
{
  DRIVER_BANDWIDTH(function, a,b,size, i);
  cudaMemset(b,0,size*size*sizeof(float));
  DRIVER_ACCURACY(function, a,b,size, i);
  formatting_data (bench->data);
}
