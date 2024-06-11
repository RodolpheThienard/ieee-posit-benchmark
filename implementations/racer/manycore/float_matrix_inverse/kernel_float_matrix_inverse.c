#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
#include "RacEr_tile_group_barrier.h"
INIT_TILE_GROUP_BARRIER (r_barrier, c_barrier, 0, RacEr_tiles_X - 1, 0,
                         RacEr_tiles_Y - 1);

int __attribute__ ((noinline))
kernel_float_matrix_inverse (posit *mat, posit *inv, int n, int block_size_y,
                             int block_size_x)
{

  int start_y = __RacEr_tile_group_id_y * block_size_y;
  int start_x = __RacEr_tile_group_id_x * block_size_x;
  int end_y = start_y + block_size_y;
  int end_x = start_x + block_size_x;

  float temp[n * n];
  for (int i = 0; i < n * n; i++)
    {
      temp[i] = mat[i];
    }

  // init identity matrix
  for (int iter_y = start_y + __RacEr_y; iter_y < end_y;
       iter_y += RacEr_tiles_Y)
    {
      for (int iter_x = start_x + __RacEr_x; iter_x < end_x;
           iter_x += RacEr_tiles_X)
        {
          if (iter_y == iter_x)
            {
              inv[iter_y * n + iter_x] = 1.0;
            }
          else
            {
              inv[iter_y * n + iter_x] = 0.0;
            }
        }
    }

  // Gauss-Jordan elimination
  for (int iter_y = start_y + __RacEr_y; iter_y < end_y;
       iter_y += RacEr_tiles_Y)
    {
      // get pivot
      double pivot = temp[iter_y * n + iter_y];

      // Dividing by pivot
      for (int iter_x = start_x + __RacEr_x; iter_x < end_x;
           iter_x += RacEr_tiles_X)
        {
          temp[iter_y * n + iter_x] /= pivot;
          inv[iter_y * n + iter_x] /= pivot;
        }

      // remove other elements
      for (int iter_x = start_x + __RacEr_x; iter_x < end_x;
           iter_x += RacEr_tiles_X)
        {
          if (iter_x != iter_y)
            {
              double coeff = temp[iter_x * n + iter_y];
              for (int j = 0; j < n; j++)
                {
                  temp[iter_x * n + j] -= coeff * temp[iter_y * n + j];
                  inv[iter_x * n + j] -= coeff * inv[iter_y * n + j];
                }
            }
        }
    }

  RacEr_tile_group_barrier (&r_barrier, &c_barrier);

  return 0;
}
