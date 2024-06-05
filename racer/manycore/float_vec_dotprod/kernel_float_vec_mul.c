// This kernel multiplies 2 vectors and stores the result in the thrid

#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
#include "RacEr_tile_group_barrier.h"
INIT_TILE_GROUP_BARRIER (r_barrier, c_barrier, 0, RacEr_tiles_X - 1, 0,
                         RacEr_tiles_Y - 1);

posit posit_mul (posit Aa, posit Bb);
int __attribute__ ((noinline))
kernel_float_vec_mul (posit *A, posit *B, posit *C, int N, int block_size_x)
{
  int start_x = block_size_x
                * (__RacEr_tile_group_id_y * __RacEr_grid_dim_x
                   + __RacEr_tile_group_id_x);
  posit A_a, B_b;

  for (int iter_x = __RacEr_id; iter_x < block_size_x;
       iter_x += RacEr_tiles_X * RacEr_tiles_Y)
    {
      A_a = A[start_x + iter_x];
      B_b = B[start_x + iter_x];

      C[start_x + iter_x] = posit_mul (A_a, B_b); // B[start_x + iter_x];
    }

  RacEr_tile_group_barrier (&r_barrier, &c_barrier);

  return 0;
}
