
/// Tiles
#include "test_float_matrix_inverse.h"
#include <stdlib.h>

#define ALLOC_NAME "default_allocator"

void
print_matrix (float *a, int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
        printf ("%lf ", a[i * n + j]);
      printf ("\n");
    }
}

void
host_inve_matrix_gauss_jordan (float *mat, float *inv, int n)
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

void
set_identity (float *inv, int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (i == j)
            {
              inv[i * n + j] = 1.0f;
            }
          else
            {
              inv[i * n + j] = 0.0f;
            }
        }
    }
}

// test w sgemm
int
kernel_float_matrix_inverse (int argc, char *argv[])
{
  RacEr_pr_test_info ("Debutt\n");
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

  // size matrix
  int n = 30;
  int size = sizeof (float) * n * n;

  // host matrix
  float a[n * n], b[n * n], b_host[n * n], id[n * n];

  // host allocation

  // init a & b matrix
  for (int i = 0; i < n * n; i++)
    {
      a[i] = (float)rand () / (float)RAND_MAX * 10;
    }
  set_identity (id, n);

  // device matrix
  RacEr_mc_eva_t a_device, b_device, c_device;

  // device allocation
  rc = RacEr_mc_device_malloc (&device, size, &a_device);
  if (rc != HB_MC_SUCCESS)
    {
      printf ("ERROR data 1\n");
      return rc;
    }
  rc = RacEr_mc_device_malloc (&device, size, &b_device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_test_info ("ERROR data 2\n");
      return rc;
    }
  rc = RacEr_mc_device_malloc (&device, size, &c_device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_test_info ("ERROR data 3\n");
      return rc;
    }
  printf ("avant envois mem\n");
  void *dst = (void *)((intptr_t)a_device);
  void *src = (void *)&a[0];
  // memcopy host to device
  rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                               HB_MC_MEMCPY_TO_DEVICE);
  dst = (void *)((intptr_t)b_device);
  src = (void *)&id[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                               HB_MC_MEMCPY_TO_DEVICE);
  dst = (void *)((intptr_t)c_device);
  src = (void *)&id[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                               HB_MC_MEMCPY_TO_DEVICE);

  // define bloc params
  uint32_t block_size_x = n * n;

  // Only 4 cores
  RacEr_mc_dimension_t tg_dim = { .x = 1, .y = 1 };

  RacEr_mc_dimension_t grid_dim = { .x = 1, .y = 1 };

  // init kernel args struct
  uint32_t kernel_args[4] = { a_device, b_device, n, block_size_x };

  RacEr_pr_test_info ("avant premier kernel\n");
  // add kernel in queue on the device
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_matrix_inverse", 4, kernel_args);

  // execute enqueue kernel
  rc = RacEr_mc_device_tile_groups_execute (&device);

  uint32_t kernel_args2[4] = { b_device, c_device, n, block_size_x };

  RacEr_pr_test_info ("avant deuxieme kernel\n");
  // add kernel in queue on the device
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_matrix_inverse", 4,
                                kernel_args2);
  if (rc != HB_MC_SUCCESS)
    {
      printf ("ERROR kernel 2\n");
      return rc;
    }

  // execute enqueue kernel
  rc = RacEr_mc_device_tile_groups_execute (&device);
  // memcopy device to host
  src = (void *)((intptr_t)c_device);
  dst = (void *)&b[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, size, HB_MC_MEMCPY_TO_HOST);
  if (rc != HB_MC_SUCCESS)
    {
      printf ("ERROR mem transfer 2\n");
      return rc;
    }

  host_inve_matrix_gauss_jordan (a, b_host, n);
  host_inve_matrix_gauss_jordan (b_host, b_host, n);
  print_matrix (a, 2, 2);
  puts ("\n");
  print_matrix (b_host, 2, 2);
  puts ("\n");
  print_matrix (b, 2, 2);
  // check w host computation
  // host_inve_matrix_gauss_jordan (a, b_host, n);

  // float max_ferror = 0;
  // float ferror = 0;

  // int mismatch = 0;
  // for (int i = 0; i < size; i++)
  //   {
  //     ferror = RacEr_mc_calculate_float_error (a[i], b[i]);
  //     max_ferror = fmax (max_ferror, ferror);
  //     if (ferror > MAX_FLOAT_ERROR_TOLERANCE)
  //       {
  //         RacEr_pr_err (
  //             RacEr_RED ("Mismatch: ") "B[%d]: %.32f\tExpected: "
  //                                      "%.32f\tRelative error: %.32f\n",
  //             i, b_host[i], b[i], ferror);
  //         mismatch = 1;
  //       }
  //   }

  // RacEr_pr_test_info ("MAX relative FP error: %e\n", max_ferror);

  // if (mismatch)
  //   return HB_MC_FAIL;
  // return HB_MC_SUCCESS;
}

int
main (int argc, char *argv[])
{
  RacEr_pr_test_info ("Test inverse Regression TEST(\n");
  int rc = kernel_float_matrix_inverse (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
