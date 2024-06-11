
/// Tiles
#include "test_float_matrix_inverse.h"

#define ALLOC_NAME "default_allocator"

void
host_inve_matrix_gauss_jordan (float *restrict mat, float *restrict inv, int n)
{
  double *temp = malloc (n * n * sizeof (double));
  for (int i = 0; i < n * n; i++)
    {
      temp[i] = mat[i];
    }

  // init identity matrix
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (i == j)
            {
              inv[i * n + j] = 1.0;
            }
          else
            {
              inv[i * n + j] = 0.0;
            }
        }
    }

  // Gauss-Jordan elimination
  for (int i = 0; i < n; i++)
    {
      // get pivot
      double pivot = temp[i * n + i];

      // Dividing by pivot
      for (int j = 0; j < n; j++)
        {
          temp[i * n + j] /= pivot;
          inv[i * n + j] /= pivot;
        }

      // remove other elements
      for (int k = 0; k < n; k++)
        {
          if (k != i)
            {
              double coeff = temp[k * n + i];
              for (int j = 0; j < n; j++)
                {
                  temp[k * n + j] -= coeff * temp[i * n + j];
                  inv[k * n + j] -= coeff * inv[i * n + j];
                }
            }
        }
    }
}

// test w sgemm
int
kernel_float_matrix_inverse (int argc, char *argv[])
{
  char *bin_path, *test_name;
  struct arguments_path args = { NULL, NULL };

  // fetch kernel path & test name
  argp_parse (&argp_path, argc, argv, 0, 0, &args);
  bin_path = args.path;
  test_name = args.name;

  int rc;
  // init device
  RacEr_mc_device_t device;
  rc = RacEr_mc_device_init (&device, test_name, 0);
  rc = RacEr_mc_device_program_init (&device, bin_path, ALLOC_NAME, 0);

  // host matrix
  float *a, *b, *b_host;

  // size matrix
  int n = 100;
  int size = sizeof (float) * n * n;

  // host allocation
  a = malloc (size);
  b = malloc (size);
  b_host = malloc (size);

  // init a & b matrix
  for (int i = 0; i < n * n; i++)
    {
      a[i] = drand48 ();
    }

  // device matrix
  RacEr_mc_eva_t a_device, b_device;

  // device allocation
  rc = RacEr_mc_device_malloc (&device, size, &a_device);
  rc = RacEr_mc_device_malloc (&device, size, &b_device);

  // memcopy host to device
  rc = RacEr_mc_device_memcpy (&device, &a_device, a, size,
                               HB_MC_MEMCPY_TO_DEVICE);
  // rc = RacEr_mc_device_memcpy (&device, &b_device, b, size,
  // HB_MC_MEMCPY_TO_DEVICE);

  // define bloc params
  uint32_t block_size_x = 4;
  uint32_t block_size_y = 4;

  // Only 4 cores
  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

  RacEr_mc_dimension_t grid_dim
      = { .x = n / block_size_x, .y = n / block_size_y };

  // init kernel args struct
  uint32_t kernel_args[5]
      = { a_device, b_device, n, block_size_x, block_size_y };

  // add kernel in queue on the device
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_matrix_inverse", 5, kernel_args);

  // execute enqueue kernel
  rc = RacEr_mc_device_tile_groups_execute (&device);

  // memcopy device to host
  rc = RacEr_mc_device_memcpy (&device, b, &b_device, size,
                               HB_MC_MEMCPY_TO_HOST);

  // check w host computation
  host_inve_matrix_gauss_jordan (a, b_host, n);

  float max_ferror = 0;
  float ferror = 0;

  int mismatch = 0;
  for (int i = 0; i < size; i++)
    {
      ferror = RacEr_mc_calculate_float_error (a[i], b[i]);
      max_ferror = fmax (max_ferror, ferror);
      if (ferror > MAX_FLOAT_ERROR_TOLERANCE)
        {
          RacEr_pr_err (
              RacEr_RED ("Mismatch: ") "B[%d]: %.32f\tExpected: "
                                       "%.32f\tRelative error: %.32f\n",
              i, b_host[i], b[i], ferror);
          mismatch = 1;
        }
    }

  RacEr_pr_test_info ("MAX relative FP error: %e\n", max_ferror);

  if (mismatch)
    return HB_MC_FAIL;
  return HB_MC_SUCCESS;
}

int
main (int argc, char *argv[])
{
  RacEr_pr_test_info ("Test inverse Regression TEST(F1)\n");
  int rc = kernel_float_matrix_inverse (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
