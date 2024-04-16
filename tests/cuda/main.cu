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
  
  uint64_t _matrix_size = atoll (argv[1]);
  uint64_t _repetition = atoll (argv[2]);

  uint64_t _matrix_size_2 = _matrix_size * _matrix_size;
  data->matrice_size = _matrix_size_2;
  data->repetition = _repetition;

  // ≃ 200 per kernel
  char *output_buffer;
  output_buffer = (char *)malloc (sizeof (char) * 200 * 11);
  print_header_benchmark (output_buffer, _matrix_size_2 * 2);
  data->type = sizeof (double);

  // driver_cuda_fp64_benchmark ("cuda gemm ijk", output_buffer, cuda_64bits_gemm_ijk, data,
  //                             _matrix_size);
  // driver_cuda_fp64_benchmark ("cuda gemm jik", output_buffer, cuda_64bits_gemm_jik, data, 
  //                _matrix_size);
  // driver_cuda_fp64_benchmark ("cuda gemm bloc", output_buffer, cuda_64bits_gemm_bloc, data, 
  //                _matrix_size);

  print_header_accuracy(output_buffer);

  // driver_cuda_inv_matrix_accuracy("Inversion Gauss Jordan", output_buffer , cuda_inve_matrix_gauss_jordan, accuracy, _matrix_size);
  driver_compare_accuracy("Log vs log Taylor", output_buffer , logarithm_taylor, log_libmath, accuracy, _matrix_size);

  save_data (NULL, output_buffer);

 }
