/*!
 * This kernel performs matrix multiplication
 * For now the matrices are assumed to have the same X/Y dimension n.
 */

#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
#include "RacEr_tile_group_barrier.h"
INIT_TILE_GROUP_BARRIER (r_barrier, c_barrier, 0, RacEr_tiles_X - 1, 0,
                         RacEr_tiles_Y - 1);

int __attribute__ ((noinline))
kernel_float_matrix_mul (posit *A, posit *val, int n, int block_size_y,
                         int block_size_x)
{

  double A_const, B_const;

  int start_y = __RacEr_tile_group_id_y * block_size_y;
  int start_x = __RacEr_tile_group_id_x * block_size_x;
  int end_y = start_y + block_size_y;
  int end_x = start_x + block_size_x;
  // int end_y = M < (start_y + block_size_y) ? M : (start_y + block_size_y);
  // int end_x = P < (start_x + block_size_x) ? P : (start_x + block_size_x);

  for (int iter_y = start_y + __RacEr_y; iter_y < end_y;
       iter_y += RacEr_tiles_Y)
    {
      for (int iter_x = start_x + __RacEr_x; iter_x < end_x;
           iter_x += RacEr_tiles_X)
        {
          A[iter_y * n + iter_x] = val[iter_y * n + iter_x];
        }
    }

  RacEr_tile_group_barrier (&r_barrier, &c_barrier);

  return 0;
}
