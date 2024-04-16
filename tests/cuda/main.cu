extern "C" {
  #include "../../include/utils.h"
}
  #include "../../include/driver.h"
  #include "../../include/cuda.h"
  #include "../../include/kernels.h"

int
main (int argc, char *argv[])
{
  struct data *data;
  data = (struct data*)malloc(sizeof(struct data));
  struct accuracy *accuracy;
  accuracy = (struct accuracy*)malloc(sizeof(struct accuracy));
  
  long _matrix_size = atoll (argv[1]);
  long _repetition = atoll (argv[2]);

  long _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char *output_buffer;
  output_buffer = (char *)malloc (sizeof (char) * 200 * 11);
  print_header_benchmark (output_buffer, _matrix_size_2 * 2);
  data->type = sizeof (double);

  driver_fp64_benchmark ("ieee gemm ijk", output_buffer, ieee_64bits_gemm_ijk, data,
                              _matrix_size);
  driver_fp64_benchmark ("ieee gemm jik", output_buffer, ieee_64bits_gemm_jik, data, 
                 _matrix_size);
  driver_fp64_benchmark ("ieee gemm bloc", output_buffer, ieee_64bits_gemm_bloc, data, 
                 _matrix_size);

  print_header_accuracy(output_buffer);

  driver_inv_matrix_accuracy("Inversion Gauss Jordan", output_buffer , inve_matrix_gauss_jordan, accuracy, _matrix_size);
  driver_compare_accuracy("Log vs log Taylor", output_buffer , logarithm_taylor, log_libmath, accuracy, _matrix_size);

  save_data (NULL, output_buffer);

 }
