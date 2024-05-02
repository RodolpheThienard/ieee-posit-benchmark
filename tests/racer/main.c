/// Tiles
#include "../../include/RacEr_manycore_cuda.h"
#include "../../include/RacEr_set_tile_x_y.h"

/// Main function
#include "../../include/RacEr_manycore.h"
#include "../../include/driver.h"
#include "../../include/utils.h"
#include "stdlib.h"

#define ALLOC_NAME "default_allocator"

int run_kernel_racer ();

int
main (int argc, char *argv[])
{
  int rc = run_kernel_racer ();
  return rc;
}

// test w sgemm
int
run_kernel_racer (int argc, char *argv[])
{
  struct bench bench;
  char *bin_path, *test_name;
  struct arguments_path args = { NULL, NULL };

  // fetch kernel path & test name
  argp_parse (&argp_path, argc, argv, 0, 0, &args);
  bin_path = args.path;
  test_name = args.name;

  // init device
  RacEr_mc_device_t device;
  RacEr_mc_device_init (&device, test_name, 0);
  RacEr_mc_device_program_init (&device, bin_path, ALLOC_NAME, 0);

  // host matrix
  float *a, *b, *c;

  // size matrix
  int n = 100;
  int size = sizeof (float) * n * n;

  // host allocation
  a = malloc (size);
  b = malloc (size);
  c = malloc (size);

  // init a & b matrix
  for (int i = 0; i < n * n; i++)
    {
      a[i] = drand48 ();
      b[i] = drand48 ();
    }

  // device matrix
  RacEr_mc_eva_t a_device, b_device, c_device;

  // device allocation
  RacEr_mc_device_malloc (&device, size, &a_device);
  RacEr_mc_device_malloc (&device, size, &b_device);
  RacEr_mc_device_malloc (&device, size, &c_device);

  // memcopy host to device
  RacEr_mc_device_memcpy (&device, &a_device, a, size, HB_MC_MEMCPY_TO_DEVICE);
  RacEr_mc_device_memcpy (&device, &b_device, b, size, HB_MC_MEMCPY_TO_DEVICE);

  // define bloc params
  uint32_t block_size_x = 4;
  uint32_t block_size_y = 4;

  // Only 4 cores
  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

  RacEr_mc_dimension_t grid_dim
      = { .x = n / block_size_x, .y = n / block_size_y };

  // init kernel args struct
  // int kernel_args[6]
  // = { a_device, b_device, c_device, n, block_size_x, block_size_y };

  // add kernel in queue on the device
  // RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim, "sgemm", 6,
  // kernel_args);

  // execute enqueue kernel
  // RacEr_mc_device_tile_groups_execute (&device);
  driver_sgemm ("sgemm", size, a_device, b_device, c_device, &bench,
                block_size_x, block_size_y);

  // memcopy device to host
  RacEr_mc_device_memcpy (&device, c, &c_device, HB_MC_MEMCPY_TO_HOST);

  free (a);
  free (b);
  free (c);
  return 0;
}
