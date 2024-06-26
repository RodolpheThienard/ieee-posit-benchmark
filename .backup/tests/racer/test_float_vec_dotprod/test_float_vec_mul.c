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
/* Runs the floating point vector multiplication on one 2x2 tile group */
/* Grid dimensions are prefixed at 1x1. --> block_size_x is set to N. */
/* This tests uses the software/spmd/RacEr_cuda_lite_runtime/float_vec_mul/ */
/* manycore binary in the RacEr Manycore repository. */
/******************************************************************************/

#include "test_float_vec_mul.h"

#define ALLOC_NAME "default_allocator"

void
host_float_vec_mul (float *A, float *B, float *C, int N)
{
  // float B_const = 45.5969595;
  for (int i = 0; i < N; i++)
    {
      C[i] = A[i] * B[i];
    }
  return;
}

int
kernel_float_vec_mul (int argc, char **argv)
{
  int rc;
  char *bin_path, *test_name;
  struct arguments_path args = { NULL, NULL };

  argp_parse (&argp_path, argc, argv, 0, 0, &args);
  bin_path = args.path;
  test_name = args.name;

  RacEr_pr_test_info ("Running the CUDA Floating Point Vector Multiplciation "
                      "Kernel on a 1x1 grid of 2x2 tile group.\n\n");

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
  uint32_t N = 1024;

  RacEr_mc_eva_t A_device, B_device, C_device;
  rc = RacEr_mc_device_malloc (&device, N * sizeof (uint32_t), &A_device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to allocate memory on device.\n");
      return rc;
    }

  rc = RacEr_mc_device_malloc (&device, N * sizeof (uint32_t), &B_device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to allocate memory on device.\n");
      return rc;
    }

  rc = RacEr_mc_device_malloc (&device, N * sizeof (uint32_t), &C_device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to allocate memory on device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Allocate memory on the host for A & B                              */
  /* and initialize with random values.                                 */
  /**********************************************************************/
  float A_host[N];
  float B_host[N];
  for (int i = 0; i < N; i++)
    {
      A_host[i] = ((float)rand () / (float)(RAND_MAX))
                  * 1.23343433; // RacEr_mc_generate_float_rand();
      B_host[i] = ((float)rand () / (float)(RAND_MAX))
                  * -2.233848483; // RacEr_mc_generate_float_rand();
    }

  /**********************************************************************/
  /* Copy A & B from host onto device DRAM.                             */
  /**********************************************************************/
  void *dst = (void *)((intptr_t)A_device);
  void *src = (void *)&A_host[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, N * sizeof (uint32_t),
                               HB_MC_MEMCPY_TO_DEVICE);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to copy memory to device.\n");
      return rc;
    }

  dst = (void *)((intptr_t)B_device);
  src = (void *)&B_host[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, N * sizeof (uint32_t),
                               HB_MC_MEMCPY_TO_DEVICE);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to copy memory to device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Initialize values in C_device to 0.                                */
  /**********************************************************************/
  rc = RacEr_mc_device_memset (&device, &C_device, 0, N * sizeof (uint32_t));
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to set memory on device.\n");
      return rc;
    }

  /**********************************************************************/
  /* Define block_size_x/y: amount of work for each tile group          */
  /* Define tg_dim_x/y: number of tiles in each tile group              */
  /* Calculate grid_dim_x/y: number of                                  */
  /* tile groups needed based on block_size_x/y                         */
  /**********************************************************************/
  uint32_t block_size_x = N;

  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

  RacEr_mc_dimension_t grid_dim = { .x = 1, .y = 1 };

  /**********************************************************************/
  /* Prepare list of input arguments for kernel.                        */
  /**********************************************************************/
  int cuda_argv[5] = { A_device, B_device, C_device, N, block_size_x };

  /**********************************************************************/
  /* Enquque grid of tile groups, pass in grid and tile group dimensions*/
  /* kernel name, number and list of input arguments                    */
  /**********************************************************************/
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_vec_mul", 5, cuda_argv);
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
  float C_host[N];
  src = (void *)((intptr_t)C_device);
  dst = (void *)&C_host[0];
  rc = RacEr_mc_device_memcpy (&device, (void *)dst, src,
                               N * sizeof (uint32_t), HB_MC_MEMCPY_TO_HOST);
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
  float C_expected[N];
  host_float_vec_mul (A_host, B_host, C_expected, N);

  float max_ferror = 0;
  float ferror = 0;

  int mismatch = 0;
  for (int i = 0; i < N; i++)
    {
      ferror = RacEr_mc_calculate_float_error (C_expected[i], C_host[i]);
      max_ferror = fmax (max_ferror, ferror);
      if (ferror > MAX_FLOAT_ERROR_TOLERANCE)
        {
          RacEr_pr_err (
              RacEr_RED ("Mismatch: ") "C[%d]: %.40f\tExpected: "
                                       "%.40f\tRelative Err: %.32f\n",
              i, C_host[i], C_expected[i], ferror);
          mismatch = 1;
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
  RacEr_pr_test_info ("test_float_vec_mul Regression Test (COSIMULATION)\n");
  int rc = kernel_float_vec_mul (argc, argv);
  *exit_code = rc;
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return;
}
#else
int
main (int argc, char **argv)
{
  RacEr_pr_test_info ("test_float_vec_mul Regression Test (F1)\n");
  int rc = kernel_float_vec_mul (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
#endif
