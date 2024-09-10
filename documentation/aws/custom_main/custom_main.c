
/// Tiles
#include "custom_main.h"

#define ALLOC_NAME "default_allocator"

int
custom_main (int argc, char *argv[])
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
      RacEr_pr_err ("failed to initialize device.\n");
      return rc;
    }

  rc = RacEr_mc_device_program_init (&device, bin_path, ALLOC_NAME, 0);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to execute tile groups.\n");
      return rc;
    }

  // size matrix
  int n = 25;
  int size = sizeof (float) * n * n;
  // host matrix
  float a[n * n], b[n * n];

  // init a & b matrix
  for (int i = 0; i < n * n; i++)
    {
      a[i] = i;
    }

  // device matrix
  RacEr_mc_eva_t a_device, b_device;

  // device allocation
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

  void *dst = (void *)((intptr_t)a_device);
  void *src = (void *)&a[0];
  // memcopy host to device
  rc = RacEr_mc_device_memcpy (&device, dst, src, size,
                               HB_MC_MEMCPY_TO_DEVICE);
  if (rc != HB_MC_SUCCESS)
    {
      return rc;
    }

  // define bloc params
  uint32_t block_size_x = n * n;

  // Only 4 cores
  RacEr_mc_dimension_t tg_dim = { .x = 2, .y = 2 };

  RacEr_mc_dimension_t grid_dim = { .x = 1, .y = 1 };

  // init kernel args struct
  uint32_t kernel_args[3] = { a_device, b_device, block_size_x };

  // add kernel in queue on the device
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim, "custom_kernel", 3,
                                kernel_args);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to initialize grid.\n");
      return rc;
    }

  // execute enqueue kernel
  rc = RacEr_mc_device_tile_groups_execute (&device);
  if (rc != HB_MC_SUCCESS)
    {
      RacEr_pr_err ("failed to execute tile groups.\n");
      return rc;
    }

  // memcopy device to host
  src = (void *)((intptr_t)b_device);
  dst = (void *)&b[0];
  rc = RacEr_mc_device_memcpy (&device, dst, src, size, HB_MC_MEMCPY_TO_HOST);
}

int
main (int argc, char *argv[])
{
  RacEr_pr_test_info ("test du custom main\n");
  int rc = custom_main (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
