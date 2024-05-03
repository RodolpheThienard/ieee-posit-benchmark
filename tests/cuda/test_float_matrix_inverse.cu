extern "C"
{
  #include "../../include/utils.h"
  #include "../../include/host_kernels.h"

}
#include "../../include/driver.h"
#include "../../include/cuda.h"
#include "../../include/kernels.h"

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
  data->type = sizeof (float);
  struct bench_s bench = { data, accuracy, 100, 200, 100 };

  char buffer[1000];
  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      long _matrix_size_2 = _matrix_size * _matrix_size;

      float *a, *b, *c, *d, *d_a, *d_b;
      double *aa, *bb;
      a = (float *)malloc (sizeof (float) * _matrix_size_2);
      b = (float *)malloc (sizeof (float) * _matrix_size_2);
      aa = (double *)malloc (sizeof (double) * _matrix_size_2);
      bb = (double *)malloc (sizeof (double) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (float));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (float));
      INIT (aa, _matrix_size_2);

      for (int i = 0; i < _matrix_size_2; i++)
        {
          a[i] = aa[i];
        }
      set_identity_matrix (b, i, i);

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_b, b, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);

      for (int kk = 0; kk < i; kk++)
        {
          driver_inverse_gauss_jordan (inve_matrix_gauss_jordan_cuda, i, d_a, d_b,
                                       &bench);
        }

      cudaMemcpy (b, d_b, _matrix_size_2 * sizeof (float),
                  cudaMemcpyDeviceToHost);
      cudaMemcpy (a, d_a, _matrix_size_2 * sizeof (float),
                  cudaMemcpyDeviceToHost);

      host_inve_matrix_gauss_jordan (aa, bb, i);


      free (a);
      free (b);
      save_data (NULL, buffer);
    }

  free (data);
  return 0;
}
