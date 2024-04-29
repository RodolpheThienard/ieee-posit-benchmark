#include "../../include/utils.h"
/* TODO Driver macro bandwidth
   macro permettant de faire la mesure du temps / débit
   paramettre variable
   Meta répétition de 31 pour stabilité avec 31 fois le meme calcul exact
   */

#define DRIVER_BANDWIDTH(fn, ...)                                             \
  {                                                                           \
    double init_time, end_time;                                               \
    long begin_register, end_register;                                        \
    for (int stability = 0; stability < 31; stability++)                      \
      {                                                                       \
        init_time = get_elapsedtime ();                                       \
        begin_register = rdtsc ();                                            \
        for (int rep = 0; rep < bench->data->repetition; rep++)               \
          {                                                                   \
            fn (__VA_ARGS__);                                                 \
          }                                                                   \
        end_register = rdtsc ();                                              \
        end_time = get_elapsedtime ();                                        \
        bench->data->RC[stability]                                            \
            = (end_register - begin_register) / bench->data->repetition;      \
        bench->data->samples[stability]                                       \
            = (end_time - init_time) / bench->data->repetition;               \
      }                                                                       \
  }

/* TODO driver macro accuracy
   macro permettant de faire la mesure de précision
   verification de la sorti du calcul de Bandwidth avec la fonction CPU
   Checker si OMP et x86 sont équivalent */
#define DRIVER_ACCURACY(host, device, size)                                   \
  bench->accuracy->accuracy = compute_err_accuracy (host, device, size);      \
  bench->accuracy->RMS = RMS (host, device, size);                            \
  bench->accuracy->forward_error = forward_error (host, device, size);

/* Foo example of API utilisation
   compare 2 function for dgemm */
void
driver_sgemm (void (*function) (float *, float *, float *, int), int size,
              float *a, float *b, float *c, struct bench_s bench[static 1])
{
  DRIVER_BANDWIDTH (function, a, b, c, size);
  formatting_data (bench->data);
}

void
driver_accuracy_32bits (int size, float *c_host, float *c_device,
                        struct bench_s bench[static 1])
{
  DRIVER_ACCURACY ((double *)c_host, (double *)c_device, size);
}
