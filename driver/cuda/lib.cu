extern "C" {
  #include "../../include/utils.h"
}
  #include "../../include/kernels.h"
  #include "../../include/cuda.h"

#define DRIVER_BODY(fn, ...)                                                  \
  {                                                                           \
    dim3 threadsPerBlock (32, 32);                                            \
    dim3 numBlocks (matrix_size / threadsPerBlock.x,                          \
                    matrix_size / threadsPerBlock.y);                         \
    cudaEvent_t start_event, end_event;                                       \
    float elapsed;                                                            \
    for (int stability = 0; stability < 33; stability++)                      \
      {                                                                       \
        cudaEventCreate (&start_event);                                       \
        cudaEventCreate (&end_event);                                         \
        cudaEventRecord (start_event, 0);                                     \
        for (int rep = 0; rep < bench->data->repetition; rep++)                      \
          {                                                                   \
            fn<<<numBlocks, threadsPerBlock>>> (__VA_ARGS__);                 \
          }                                                                   \
        cudaEventRecord (end_event, 0);                                       \
        cudaEventSynchronize (end_event);                                     \
        cudaEventElapsedTime (&elapsed, start_event, end_event);              \
        elapsed *= 1e-3;                                                      \
        bench->data->samples[stability]                                       \
            = (double)elapsed / bench->data->repetition;                      \
      }                                                                       \
  }
  

void
kernel2 (char *name_kernel, char *name_kernel_2,
         void (*kernel) (double *, double *, int),
         void (*kernel_2) (double *, double *, int), char *filename,
         struct bench *bench, int matrix_size)
{
  char buffer[1000];
  print_header_diff (buffer);
  for (int i = bench->start_size; i < bench->end_size; i += bench->step_size)
    {
      int _matrix_size = i;
      bench->data->matrice_size = _matrix_size;
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

      // copying init values
      for (int j = 0; j < _matrix_size; j++)
        {
          a[j] += drand48 ();
          c[j] = a[j];
        }

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_c, c, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      DRIVER_BODY (kernel, d_a, d_b, _matrix_size);
      cudaMemcpy (b, d_b, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      formatting_data (bench->data);

      print_data_benchmark (name_kernel, bench->data, buffer);
      DRIVER_BODY (kernel_2, d_c, d_d, _matrix_size);
      cudaMemcpy (d, d_c, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);

      struct data data_2 = *bench->data;
      formatting_data (bench->data);
      print_data_benchmark (name_kernel_2, bench->data, buffer);

      bench->accuracy->accuracy = compute_err_accuracy (d, b, _matrix_size);
      bench->accuracy->RMS = RMS (d, b, _matrix_size);
      bench->accuracy->forward_error = forward_error (d, b, _matrix_size);

      print_diff_accuracy ("Comparaison", buffer, bench, &data_2);

      free (a);
      free (b);
      free (c);
      free (d);
      save_data (filename, buffer);
    }
}

void
kernel1 (char *name_kernel, void (*kernel) (double *, double *, int),
         char *filename, struct bench *bench, int matrix_size)
{
  char buffer[1000];
  print_header_benchmark (buffer);
  for (int i = bench->start_size; i < bench->end_size; i += bench->step_size)
    {
      int _matrix_size = i;
      bench->data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;
      double *a, *b, *d_a, *d_b;
      a = (double *)malloc (sizeof (double) * _matrix_size_2);
      b = (double *)malloc (sizeof (double) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (double));

      // copying init values
      for (int i = 0; i < _matrix_size; i++)
        {
          a[i] += drand48 ();
          b[i] = a[i];
        }
      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      DRIVER_BODY (kernel, d_a, d_b, _matrix_size);
      cudaMemcpy (b, d_b, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      formatting_data (bench->data);
      print_data_benchmark (name_kernel, bench->data, buffer);
      save_data (filename, buffer);
    }
}

void
inversion (char *name_kernel, void (*kernel) (double *, double *, int),
           char *filename, struct bench *bench, int matrix_size)
{
  char buffer[1000];
  print_header_diff (buffer);
  for (int i = bench->start_size; i < bench->end_size; i += bench->step_size)
    {
      int _matrix_size = i;
      bench->data->matrice_size = _matrix_size;
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
      DRIVER_BODY (kernel, d_a, d_b, i);
      set_identity_matrix (c, i, i);
      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_c, c, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      ieee_64bits_gemm_jik (d_c, d_b, d_d, i);
      DRIVER_BODY (kernel, d_d, d_b, i);
      cudaMemcpy (b, d_b, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      cudaMemcpy (a, d_a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);
      formatting_data (bench->data);
      print_data_benchmark (name_kernel, bench->data, buffer);

      bench->accuracy->accuracy = compute_err_accuracy (a, b, i);
      bench->accuracy->RMS = RMS (a, b, i);
      bench->accuracy->forward_error = forward_error (a, b, i);

      print_diff_accuracy ("Comparaison", buffer, bench, bench->data);
      free (a);
      free (b);
      free (c);
      free (d);
      save_data (filename, buffer);
    }
}
/* API to run benchmark
   need to choose the accuracy driver */
void
benchmark (char *name_kernel, char *name_kernel_2, char *filename,
           void (*kernel) (double *, double *, int),
           void (*kernel_2) (double *, double *, int), struct bench *bench,
           enum benchmark_type type, int matrix_size)
{
  switch (type)
    {
    case INVERSION:
      inversion (name_kernel, kernel, filename, bench, matrix_size);
      break;
    case KERNEL1:
      kernel1 (name_kernel, kernel, filename, bench, matrix_size);
      break;
    case KERNEL2:
      kernel2 (name_kernel, name_kernel_2, kernel, kernel_2, filename, bench,
               matrix_size);
      break;
    }
}
