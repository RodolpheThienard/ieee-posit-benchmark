#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
typedef struct
{
  posit x;
  posit y;
  int cluster;
} Point;

typedef struct
{
  posit x;
  posit y;
} Centroid;

int __attribute__ ((noinline))
kernel_float_vec_kmeans (Point *points, Centroid *centroids, int k, int n)
{
  RacEr_print_float (points[0].x);
  for (int iter = 0; iter < 100; iter++)
    {
      RacEr_printf ("Loop : %d\n", iter);
      for (int i = 0; i < n; i++)
        {
          posit min_dist = ((points[i].x - centroids[0].x)
                                * (points[i].x - centroids[0].x)
                            + (points[i].y - centroids[0].y)
                                  * (points[i].y - centroids[0].y));
          int cluster = 0;
          for (int j = 1; j < k; j++)
            {
              posit dist = ((points[i].x - centroids[j].x)
                                * (points[i].x - centroids[j].x)
                            + (points[i].y - centroids[j].y)
                                  * (points[i].y - centroids[j].y));
              if (dist < min_dist)
                {
                  min_dist = dist;
                  cluster = j;
                }
            }
          points[i].cluster = cluster;
        }
      int count[k];
      for (int i = 0; i < k; i++)
        {
          centroids[i].x = 0;
          centroids[i].y = 0;
          count[i] = 0;
        }

      for (int i = 0; i < n; i++)
        {
          int cluster = points[i].cluster;
          centroids[cluster].x += points[i].x;
          centroids[cluster].y += points[i].y;
          count[cluster]++;
        }

      for (int i = 0; i < k; i++)
        {
          if (count[i] != 0)
            {
              centroids[i].x /= count[i];
              centroids[i].y /= count[i];
            }
        }
    }

  return 0;
}
