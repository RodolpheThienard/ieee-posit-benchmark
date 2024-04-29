extern "C"
{
#include "../../include/utils.h"
}
#include "../../include/kernels.h"
#include "../../include/cuda.h"
#include "../../include/driver.h"

float
compute_err_accuracy_float (float *a, float *b, int n)
{
  int i = 0;
  float err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i])*(a[i] - b[i]);
    }
   err /= n;
  return sqrt (err);
}

float
RMS_float (float *a, float *b, int n)
{
  int i = 0;
  float err = 0.0;
  for (i = 0; i < n; i++)
    {
      err += (a[i] - b[i]) * (a[i] - b[i]);
    }
  err /= n;
  return sqrt (err);
}
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
  struct bench_s bench = { data, accuracy, 100, 1000, 100 };

  for (int i = bench.start_size; i < bench.end_size; i += bench.step_size)
    {
      _matrix_size = i;
      bench.data->matrice_size = _matrix_size;
      int _matrix_size_2 = _matrix_size * _matrix_size;

      float *a, *b, *c, *c_host, *d_a, *d_b, *d_c;
      a = (float *)malloc (sizeof (float) * _matrix_size_2);
      b = (float *)malloc (sizeof (float) * _matrix_size_2);
      c = (float *)malloc (sizeof (float) * _matrix_size_2);
      c_host = (float *)malloc (sizeof (float) * _matrix_size_2);
      cudaMalloc (&d_a, _matrix_size_2 * sizeof (float));
      cudaMalloc (&d_b, _matrix_size_2 * sizeof (float));
      cudaMalloc (&d_c, _matrix_size_2 * sizeof (float));

      INIT (a, _matrix_size_2);
      INIT (b, _matrix_size_2);

      cudaMemcpy (d_a, a, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);
      cudaMemcpy (d_b, b, _matrix_size_2 * sizeof (float),
                  cudaMemcpyHostToDevice);

      driver_sgemm(sgemm, _matrix_size, d_a,d_b,d_c,&bench);

      cudaMemcpy (c, d_c, _matrix_size_2 * sizeof (float),
                  cudaMemcpyDeviceToHost);

      ieee_32bits_gemm(a, b, c_host, i);

      // driver_accuracy_32bits(_matrix_size_2, c_host, d_c, &bench);

      float err = compute_err_accuracy_float(c, c_host, i);
      float rms = RMS_float(c, c_host, i);

      fprintf(stdout, "float matrix mul err : %le; rms : %le\n", err, rms);
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
