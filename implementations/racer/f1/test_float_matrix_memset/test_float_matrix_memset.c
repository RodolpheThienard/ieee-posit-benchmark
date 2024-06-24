// Copyright (c) 2020, VividSparks IT Solutions Pvt. Ltd.  All rights reserved.
//
// Redistribution and use in source and binary forms, modifications,
// are NOT permitted.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

/******************************************************************************/
/* A[N] * B[N] --> C[N] */
/* Runs the floating point matrix multiplication on a group of 2x2 tile
 * groups*/
/* Grid dimensions are defined based on total work / block_size_x/y */
/* This tests uses the software/spmd/RacEr_cuda_lite_runtime/float_matrix_mul/
 */
/* manycore binary in the RacEr Manycore repository. */
/******************************************************************************/

#include "test_float_matrix_mul.h"

#define ALLOC_NAME "default_allocator"

/*!
 * Matrix multiplication code on the host side to compare the results
 */
void
host_float_matrix_memset (float *A, float *val, int n)
{
  for (int y = 0; y < n; y++)
    {
      for (int x = 0; x < n; x++)
        {
          A[y * n + x] = val[y * n + x];
        }
    }
  return;
}

int
kernel_float_matrix_memset (int argc, char **argv)
{
  int rc;
  char *bin_path, *test_name;
  struct arguments_path args = { NULL, NULL };

  argp_parse (&argp_path, argc, argv, 0, 0, &args);
  bin_path = args.path;
  test_name = args.name;

  RacEr_pr_test_info ("Running the CUDA Floating Point Matrix memset "
                      "Kernel on a grid of 2x2 tile group.\n\n");

  srand (time (NULL));

  /**********************************************************************/
  /* Define path to binary.                                             */
  /* Initialize device, load binary and unfreeze tiles.                 */
  /**********************************************************************/
  RacEr_mc_device_t device;
  rc = RacEr_mc_device_init (&device, test_name, 0);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to initialize device.\n");
      return rc;
    }

  rc = RacEr_mc_device_program_init (&device, bin_path, ALLOC_NAME, 0);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to initialize program.\n");
      return rc;
    }

  /**********************************************************************/
  /* Allocate memory on the device for A, B and C.                      */
  /**********************************************************************/
  uint32_t n = 10;

  RacEr_mc_eva_t A_device, val_device;
  rc = RacEr_mc_device_malloc (&device, n * n * sizeof (uint32_t),
                               &A_device); /* allocate A[M][N] on the device */
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to allocate memory on device.\n");
      return rc;
    }
  rc = RacEr_mc_device_malloc (
      &device, n * n * sizeof (uint32_t),
      &val_device); /* allocate A[M][N] on the device */
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to allocate memory on device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Allocate memory on the host for A & B                              */
  /* and initialize with random values.                                 */
  /**********************************************************************/
  float A_host[n * n];
  float val[n * n];
  srand ((unsigned int)time (NULL));
  for (int i = 0; i < n * n; i++)
    {
      A_host[i] = ((float)rand () / (float)(RAND_MAX))
                  * 5.0; // RacEr_mc_generate_float_rand();
      //                 RacEr_pr_test_info("A_host %f\n ",A_host[i]);
      val[i] = 1.5;
    }

  /**********************************************************************/
  /* Copy A & B from host onto device DRAM.                             */
  /**********************************************************************/
  void *dst = (void *)((intptr_t)A_device);
  void *src = (void *)&A_host[0];
  // rc = RacEr_mc_device_memcpy (&device, dst, src, n * n * sizeof (uint32_t),
  //                              HB_MC_MEMCPY_TO_DEVICE);
  // if (rc != HB_MC_SUCCESS)
  //   {
  //     RacEr_pr_err ("failed to copy memory to device.\n");
  //     return rc;
  //   }
  dst = (void *)((intptr_t)val_device);
  src = (void *)&val[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, n * n * sizeof (uint32_t),
                               HB_MC_MEMCPY_TO_DEVICE);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to copy memory to device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Define block_size_x/y: amount of work for each tile group          */
  /* Define tg_dim_x/y: number of tiles in each tile group              */
  /* Calculate grid_dim_x/y: number of                                  */
  /* tile groups needed based on block_size_x/y                         */
  /**********************************************************************/
  uint32_t block_size_x = 4;
  uint32_t block_size_y = 4;

  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

  RacEr_mc_dimension_t grid_dim
      = { .x = n / block_size_x, .y = n / block_size_y };

  /**********************************************************************/
  /* Prepare list of input arguments for kernel.                        */
  /**********************************************************************/
  int cuda_argv[4] = { A_device, val_device, n, block_size_y, block_size_x };

  /**********************************************************************/
  /* Enquque grid of tile groups, pass in grid and tile group dimensions*/
  /* kernel name, number and list of input arguments                    */
  /**********************************************************************/
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_matrix_memset", 5, cuda_argv);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to initialize grid.\n");
      return rc;
    }

  /**********************************************************************/
  /* Launch and execute all tile groups on device and wait for finish.  */
  /**********************************************************************/
  rc = RacEr_mc_device_tile_groups_execute (&device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to execute tile groups.\n");
      return rc;
    }

  /**********************************************************************/
  /* Copy result matrix back from device DRAM into host memory.         */
  /**********************************************************************/
  float B_host[n * n];
  src = (void *)((intptr_t)A_device);
  dst = (void *)&B_host[0];
  rc = RacEr_mc_device_memcpy (&device, (void *)dst, src,
                               n * n * sizeof (uint32_t),
                               HB_MC_MEMCPY_TO_HOST);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to copy memory from device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Freeze the tiles and memory manager cleanup.                       */
  /**********************************************************************/
  rc = RacEr_mc_device_finish (&device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to de-initialize device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Calculate the expected result using host code and compare.         */
  /**********************************************************************/
  float B_expected[n * n];
  host_float_matrix_memset (B_expected, val, n);

  float max_ferror = 0;
  float ferror = 0;

  int mismatch = 0;
  for (int y = 0; y < n; y++)
    {
      for (int x = 0; x < n; x++)
        {
          ferror = RacEr_mc_calculate_float_error (B_expected[y * n + x],
                                                   B_host[y * n + x]);
          max_ferror = fmax (max_ferror, ferror);
          if (ferror > MAX_FLOAT_ERROR_TOLERANCE)
            {
              RacEr_pr_err (
                  RacEr_RED ("Mismatch: ") "C[%d][%d]: %.32f\tExpected: "
                                           "%.32f\tRelative error: %.32f\n",
                  y, x, B_host[y * n + x], B_expected[y * n + x], ferror);
              mismatch = 1;
            }
        }
    }

  RacEr_pr_test_info ("MAX relative FP error: %e\n", max_ferror);

  if (mismatch)
    {
      return HB_MC_FAIL;
    }
  return HB_MC_SUCCESS;
}

#ifdef COSIM
void
cosim_main (uint32_t *exit_code, char *args)
{
  // We aren't passed command line arguments directly so we parse them
  // from *args. args is a string from VCS - to pass a string of arguments
  // to args, pass c_args to VCS as follows: +c_args="<space separated
  // list of args>"
  int argc = get_argc (args);
  char *argv[argc];
  get_argv (args, argc, argv);

#ifdef VCS
  svScope scope;
  scope = svGetScopeFromName ("tb");
  svSetScope (scope);
#endif
  RacEr_pr_test_info (
      "test_float_matrix_mul Regression Test (COSIMULATION)\n");
  int rc = kernel_float_matrix_mul (argc, argv);
  *exit_code = rc;
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return;
}
#else
int
main (int argc, char **argv)
{
  RacEr_pr_test_info ("test_float_matrix memset Regression Test (F1)\n");
  int rc = kernel_float_matrix_memset (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
#endif
