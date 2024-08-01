
/// Tiles
#include "test_float_vec_kmeans.h"

#define ALLOC_NAME "default_allocator"
void
initialize_centroids (Point points[], Centroid centroids[], int n_points,
                      int k)
{
  for (int i = 0; i < k; i++)
    {
      centroids[i].x = points[i].x;
      centroids[i].y = points[i].y;
    }
}

int
kernel_float_vec_kmeans (int argc, char *argv[])
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

  // host matrix
  int n = 100;

  Point points[n];

  for (int i = 0; i < n; i++)
    {
      points[i].x = (float)rand () / RAND_MAX;
      points[i].y = (float)rand () / RAND_MAX;
      points[i].cluster = -1;
    }
  int k = 3;
  Centroid centroids[k];
  initialize_centroids (points, centroids, n, k);

  // device matrix
  RacEr_mc_eva_t point_device, centroid_device;

  RacEr_pr_test_info ("before send data\n");
  // device allocation
  rc = RacEr_mc_device_malloc (&device, sizeof (Point) * n, &point_device);
  rc = RacEr_mc_device_malloc (&device, 3 * sizeof (Centroid),
                               &centroid_device);

  // memcopy host to device
  rc = RacEr_mc_device_memcpy (&device, &point_device, &points[0],
                               sizeof (Point) * n, HB_MC_MEMCPY_TO_DEVICE);
  rc = RacEr_mc_device_memcpy (&device, &centroid_device, &centroids[0],
                               sizeof (Centroid) * 3, HB_MC_MEMCPY_TO_DEVICE);

  RacEr_pr_test_info ("before kernel run\n");
  // define bloc params
  uint32_t block_size_x = n;

  // Only 4 cores
  RacEr_mc_dimension_t tg_dim = { .x = 1, .y = 1 };

  RacEr_mc_dimension_t grid_dim = { .x = 1, .y = 1 };

  // init kernel args struct
  uint32_t kernel_args[4] = { point_device, centroid_device, k, block_size_x };

  // add kernel in queue on the device
  rc = RacEr_mc_kernel_enqueue (&device, grid_dim, tg_dim,
                                "kernel_float_vec_kmeans", 4, kernel_args);
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

  RacEr_pr_test_info ("before receive data\n");
  rc = RacEr_mc_device_memcpy (&device, &points[0], &point_device,
                               sizeof (Point) * n, HB_MC_MEMCPY_TO_HOST);
  rc = RacEr_mc_device_memcpy (&device, &centroids[0], &centroid_device,
                               sizeof (Centroid) * 3, HB_MC_MEMCPY_TO_HOST);

  FILE *fout = fopen ("kmeans_result.txt", "w");

  for (int i = 0; i < n; i++)
    {
      fprintf (fout, "%lf %lf %d\n", points[i].x, points[i].y,
               points[i].cluster);
    }

  // Print centroids
  for (int i = 0; i < k; i++)
    {
      fprintf (fout, "%lf %lf %d\n", centroids[i].x, centroids[i].y, k);
    }

  fclose (fout);
  printf ("K-means clustering result written to 'kmeans_result.txt'\n");
}

int
main (int argc, char *argv[])
{
  RacEr_pr_test_info ("Test kmeans Regression TEST(F1)\n");
  int rc = kernel_float_vec_kmeans (argc, argv);
  RacEr_pr_test_pass_fail (rc == HB_MC_SUCCESS);
  return rc;
}
