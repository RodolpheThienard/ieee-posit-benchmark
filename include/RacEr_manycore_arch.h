#ifndef _RacEr_MANYCORE_ARCH_H
#define _RacEr_MANYCORE_ARCH_H

//------------------------------------------------------
// 0. basic SoC definitaion
//------------------------------------------------------
#define IO_X_INDEX (0)
#define IO_Y_INDEX (0)
// in words.
#define EPA_ADDR_BITS 18

// The CSR Addr configurations
// RacEr_manycore/v/parameters.vh  for definition in RTL
#define CSR_BASE_ADDR (1 << (EPA_ADDR_BITS - 1))
#define CSR_FREEZE 0x0
#define CSR_TGO_X 0x4
#define CSR_TGO_Y 0x8
//------------------------------------------------------
// 1. X/Y dimention setting/Checking.
//------------------------------------------------------
#ifndef RacEr_global_X
#error RacEr_global_X must be defined
#endif

#ifndef RacEr_global_Y
#error RacEr_global_Y must be defined
#endif

#ifndef RacEr_tiles_X
#error RacEr_tiles_X must be defined
#endif

#ifndef RacEr_tiles_Y
#error RacEr_tiles_Y must be defined
#endif

#if (RacEr_tiles_Y + 1) > (RacEr_global_Y)
#error RacEr_tiles_Y must 1 less than RacEr_global_Y
#endif

//------------------------------------------------------
// 2.Tile Address Mapping Configuation
//------------------------------------------------------
#define MAX_X_CORD_BITS 6
#define MAX_Y_CORD_BITS 6

#define X_CORD_SHIFTS (EPA_ADDR_BITS)
#define Y_CORD_SHIFTS (X_CORD_SHIFTS + MAX_X_CORD_BITS)

#define REMOTE_EPA_PREFIX 0x1
#define GLOBAL_EPA_PREFIX 0x1
#define REMOTE_EPA_MASK_BITS                                                  \
  (32 - EPA_ADDR_BITS - MAX_X_CORD_BITS - MAX_Y_CORD_BITS)
#define REMOTE_EPA_MASK ((1 << REMOTE_EPA_MASK_BITS) - 1)
// TODO -- MAX_Y_CORD_BITS is reduced 1 bits.
#define REMOTE_EPA_MASK_SHIFTS (Y_CORD_SHIFTS + MAX_Y_CORD_BITS - 1)
#define GLOBAL_EPA_MASK_SHIFTS (Y_CORD_SHIFTS + MAX_Y_CORD_BITS)

//------------------------------------------------------
// 3. Basic Remote Pointers Definition
//------------------------------------------------------
// Global EPA = {01, y_cord, x_cord, addr }
// Remote EPA = {001,y_cord, x_cord, addr }
// DRAM Addr  = {1 addr                   }
//------------------------------------------------------

#define RacEr_remote_addr_bits EPA_ADDR_BITS
// Used for in tile group access
#define RacEr_remote_ptr(x, y, local_addr)                                    \
  ((RacEr_remote_int_ptr)((REMOTE_EPA_PREFIX << REMOTE_EPA_MASK_SHIFTS)       \
                          | ((y) << Y_CORD_SHIFTS) | ((x) << X_CORD_SHIFTS)   \
                          | ((int)(local_addr))))

#define CREATE_POINTER_BY_TYPE(type) RacEr_remote_##type##_ptr

#define RacEr_tile_group_remote_ptr(type, x, y, local_addr)                   \
  ((CREATE_POINTER_BY_TYPE (type)) (                                          \
      (REMOTE_EPA_PREFIX << REMOTE_EPA_MASK_SHIFTS) | ((y) << Y_CORD_SHIFTS)  \
      | ((x) << X_CORD_SHIFTS) | ((int)(local_addr))))

// Used for global network access
#define RacEr_global_ptr(x, y, local_addr)                                    \
  ((RacEr_remote_int_ptr)((GLOBAL_EPA_PREFIX << GLOBAL_EPA_MASK_SHIFTS)       \
                          | ((y) << Y_CORD_SHIFTS) | ((x) << X_CORD_SHIFTS)   \
                          | ((int)(local_addr))))
#define RacEr_global_float_ptr(x, y, local_addr)                              \
  ((RacEr_remote_float_ptr)((GLOBAL_EPA_PREFIX << GLOBAL_EPA_MASK_SHIFTS)     \
                            | ((y) << Y_CORD_SHIFTS) | ((x) << X_CORD_SHIFTS) \
                            | ((int)(local_addr))))
#define RacEr_dram_ptr(local_addr)                                            \
  ((RacEr_remote_int_ptr)((1 << 31) | ((int)(local_addr))))

#define RacEr_host_dram_ptr(addr)                                             \
  ((RacEr_remote_int_ptr)((3 << 30) | ((int)(addr))))

#define RacEr_local_ptr(remote_addr)                                          \
  ((int)(remote_addr) & ((1 << RacEr_remote_addr_bits) - 1))

#define RacEr_tile_group_shared_ptr(type, lc_sh, index)                       \
  (RacEr_tile_group_remote_ptr (                                              \
      type, ((index) % RacEr_tiles_X),                                        \
      (((index) / RacEr_tiles_X) % RacEr_tiles_Y),                            \
      (&((lc_sh)[((index) / (RacEr_tiles_X * RacEr_tiles_Y))]))))

#define RacEr_io_mutex_ptr(local_addr)                                        \
  RacEr_global_ptr (IO_X_INDEX, IO_Y_INDEX, (local_addr))
#endif
