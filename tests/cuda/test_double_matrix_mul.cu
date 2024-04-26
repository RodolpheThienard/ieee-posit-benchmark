#include <cstring>
extern "C"
{
#include "../../include/utils.h"
}
#include "../../include/kernels.h"
#include "../../include/cuda.h"

extern __global__ void dgemm (double *matrix1, double *matrix2, double *matrix3, int size);

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
  struct bench bench = { data, accuracy, 100, 1000, 100 };

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      int _matrix_size_2 = _matrix_size * _matrix_size;

      double *a, *b, *c, *c_host, *d_a, *d_b, *d_c;
      a = (double *)malloc (sizeof (double) * _matrix_size_2);
      b = (double *)malloc (sizeof (double) * _matrix_size_2);
      c = (double *)malloc (sizeof (double) * _matrix_size_2);
      c_host = (double *)malloc (sizeof (double) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (double));
      cudaMalloc (&d_c, _matrix_size_2 * sizeof (double));

      INIT (a, _matrix_size_2);
      INIT (b, _matrix_size_2);

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_b, b, _matrix_size_2 * sizeof (double),
                  cudaMemcpyHostToDevice);

      dgemm<<<32,32>>>(d_a, d_b, d_c, i);

      cudaMemcpy (c, d_c, _matrix_size_2 * sizeof (double),
                  cudaMemcpyDeviceToHost);

      ieee_64bits_gemm(a, b, c_host, i);

      double err = RMS(c, c_host, i);

      fprintf(stdout, "double matrix mul err : %le\n", err);
      fprintf(stdout, "c device : %20.13lf\n", c[0]);
      fprintf(stdout, "c_host   : %20.13lf\n", c_host[0]);
      free (a);
      free (b);
      free (c);
      free (c_host);
      cudaFree(d_a);
      cudaFree(d_b);
      cudaFree(d_c);
    }

  free (data);
  return 0;
}
