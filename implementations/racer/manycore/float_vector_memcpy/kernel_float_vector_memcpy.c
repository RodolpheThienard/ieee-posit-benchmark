#include "RacEr_manycore.h"
#include "RacEr_set_tile_x_y.h"

#define RacEr_TILE_GROUP_X_DIM RacEr_tiles_X
#define RacEr_TILE_GROUP_Y_DIM RacEr_tiles_Y
#include "RacEr_tile_group_barrier.h"
INIT_TILE_GROUP_BARRIER (r_barrier, c_barrier, 0, RacEr_tiles_X - 1, 0,
                         RacEr_tiles_Y - 1);

posit posit_add (posit Aa, posit Bb);
int __attribute__ ((noinline))
kernel_float_vector_memcpy (posit *src, posit *dst, int block_size_x)
{
  posit A = src[0];
  for (int iter_x = __RacEr_id; iter_x < block_size_x;
       iter_x += RacEr_tiles_X * RacEr_tiles_Y)
    {
      A = 2 * A;
      dst[iter_x] = A;
    }
  RacEr_tile_group_barrier (&r_barrier, &c_barrier);
  return 0;
}
