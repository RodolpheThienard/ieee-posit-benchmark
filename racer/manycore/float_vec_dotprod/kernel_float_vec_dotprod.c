#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
#include "RacEr_tile_group_barrier.h"
INIT_TILE_GROUP_BARRIER (r_barrier, c_barrier, 0, RacEr_tiles_X - 1, 0,
                         RacEr_tiles_Y - 1);

posit posit_add (posit Aa, posit Bb);
int __attribute__ ((noinline))
kernel_float_vec_dotprod (posit *A, posit *B, int block_size_x)
{
  int start_x = block_size_x
                * (__RacEr_tile_group_id_y * __RacEr_grid_dim_x
                   + __RacEr_tile_group_id_x);
  posit A_a = 0.0, B_b = 0.0;
  for (int iter_x = __RacEr_id; iter_x < block_size_x;
       iter_x += RacEr_tiles_X * RacEr_tiles_Y)
    {
      // A_a = A[iter_x];
      // B_b = posit_add (A_a, B_b);
      B_b = A[iter_x] + B_b;
    }
  B[__RacEr_id] = B_b;

  RacEr_tile_group_barrier (&r_barrier, &c_barrier);
  for (int i = 0; i < RacEr_tiles_X * RacEr_tiles_Y; i++)
    {
      A_a = A_a + B[i];
    }
  RacEr_tile_group_barrier (&r_barrier, &c_barrier);
  B[__RacEr_id] = A_a;

  return 0;
}
