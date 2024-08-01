
/// Tiles
#include "test_float_vec_dotprod.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define ALLOC_NAME "default_allocator"

void
host_float_vec_dotprod (float *A, float *B, int N)
{
  float sum = 0.0;
  for (int i = 0; i < N; i++)
    {
      sum += A[i];
    }
  B[0] = sum;
  return;
}
void
host_double_vec_dotprod (double *A, double *B, int N)
{
  double sum = 0.0;
  for (int i = 0; i < N; i++)
    {
      sum += A[i];
    }
  B[0] = sum;
  return;
}

int
kernel_float_vec_dotprod (int argc, char *argv[])
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
  if (rc != HB_MC_SUCCESS)
    {
      return rc;
    }

  rc = RacEr_mc_device_program_init (&device, bin_path, ALLOC_NAME, 0);
  if (rc != HB_MC_SUCCESS)
    {
      return rc;
    }

  int mismatch = 0;
  FILE *file;
  file = fopen ("result.dat", "w");
  fprintf (file, "n;float; posit32; double; P32-Double; double-float\n");
  int n = 1000;
  // size matrix
  int size = sizeof (double) * n;

  // host allocation
  double a[n];
  double b[n];

  // device allocation
  RacEr_mc_eva_t a_device, b_device;
  rc = RacEr_mc_device_malloc (&device, size, &a_device);
  if (rc != HB_MC_SUCCESS)
    {
      return rc;
    }

  rc = RacEr_mc_device_malloc (&device, size, &b_device);
  if (rc != HB_MC_SUCCESS)
    {
      return rc;
    }

  for (int ii = -1e5; ii < 1e5; ii++)
    {
      // init a & b matrix
      for (int i = 0; i < n; i++)
        {
          a[i] = (double)rand () / (double)RAND_MAX * ii / 1e1; // around 0
          // a[i] = drand48 () * ii / 1e1; // Large
        }

      // memcopy host to device
      void *dst = (void *)((intptr_t)a_device);
      void *src = (void *)&a[0];

      rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                                   HB_MC_MEMCPY_TO_DEVICE);
      if (rc != HB_MC_SUCCESS)
        {
          return rc;
        }

      // init kernel args struct

      uint32_t block_size_x = n;

      // Only 4 cores
      RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

      RacEr_mc_dimension_t grid_dim = { .x = 1, .y = 1 };
      // define bloc params
      int cuda_argv[3] = { a_device, b_device, block_size_x };
      // add kernel in queue on the device
      rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                    "kernel_float_vec_dotprod", 3, cuda_argv);
      if (rc != HB_MC_SUCCESS)
        {
          return rc;
        }

      // execute enqueue kernel
      rc = RacEr_mc_device_tile_groups_execute (&device);
      if (rc != HB_MC_SUCCESS)
        {
          return rc;
        }

      // memcopy device to host
      src = (void *)((intptr_t)b_device);
      dst = (void *)&b[0];
      rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                                   HB_MC_MEMCPY_TO_HOST);

      float b_excepted[1] = { 0.0 };
      host_float_vec_dotprod (a, b_excepted, n);

      double a_double[n], b_double_excepted[1] = { 0.0 };
      for (int ij = 0; ij < n; ij++)
        a_double[ij] = (double)a[ij];
      host_double_vec_dotprod (a_double, b_double_excepted, n);

      // RacEr_pr_test_info (
      //     "\nPosit  : %24.23f\nFloat  : %24.23f\nDouble : %24.23lf", b[0],
      //     b_excepted[0], b_double_excepted[0]);
      fprintf (file, "%d; %24.23lf; %24.23lf; %24.23lf; %e; %e \n", ii,
               (double)b_excepted[0], (double)b[0], b_double_excepted[0],
               ((double)b[0] - b_double_excepted[0]) / b_double_excepted[0],
               ((double)b_excepted[0] - b_double_excepted[0])
                   / b_double_excepted[0]);
      // RacEr_pr_test_info ("MAX relative FP error: %e\n", max_ferror);
    }
  if (mismatch)
    return HB_MC_FAIL;
  return HB_MC_SUCCESS;
}

int
main (int argc, char *argv[])
{
  RacEr_pr_test_info ("Test DOTPROD (F1)\n");
  int rc = kernel_float_vec_dotprod (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
