#ifndef _RacEr_MANYCORE_H
#define _RacEr_MANYCORE_H

#include "RacEr_manycore_arch.h"

int RacEr_printf(const char *fmt, ...);

typedef volatile int   *RacEr_remote_int_ptr;
typedef volatile posit   *RacEr_remote_float_ptr;
typedef volatile unsigned char  *RacEr_remote_uint8_ptr;
typedef volatile unsigned short  *RacEr_remote_uint16_ptr;
typedef volatile unsigned *RacEr_remote_uint32_ptr;
typedef volatile void *RacEr_remote_void_ptr;

#define RacEr_remote_store(x,y,local_addr,val) do { *(RacEr_remote_ptr((x),(y),(local_addr))) = (int) (val); } while (0)
#define RacEr_remote_load(x,y,local_addr,val)  do { val = *(RacEr_remote_ptr((x),(y),(local_addr))) ; } while (0)

#define RacEr_global_store(x,y,local_addr,val) do { *(RacEr_global_ptr((x),(y),(local_addr))) = (int) (val); } while (0)
#define RacEr_global_load(x,y,local_addr,val)  do { val = *(RacEr_global_ptr((x),(y),(local_addr))) ; } while (0)

#define RacEr_global_float_store(x,y,local_addr,val) do { *(RacEr_global_float_ptr((x),(y),(local_addr))) = (float) (val); } while (0)
#define RacEr_global_float_load(x,y,local_addr,val)  do { val = *(RacEr_global_float_ptr((x),(y),(local_addr))) ; } while (0)

#define RacEr_dram_store(dram_addr,val) do { *(RacEr_dram_ptr((dram_addr))) = (int) (val); } while (0)
#define RacEr_dram_load(dram_addr,val)  do { val = *(RacEr_dram_ptr((dram_addr))) ; } while (0)

#define RacEr_host_dram_store(addr, val) do {*(RacEr_host_dram_ptr((addr))) = (int) (val);} while (0)
#define RacEr_host_dram_load(addr, val) do { val = *(RacEr_host_dram_ptr((addr)));} while (0)

#define RacEr_tile_group_shared_mem(type,lc_sh,size) type lc_sh[((size + ((RacEr_tiles_X * RacEr_tiles_Y) -1))/(RacEr_tiles_X * RacEr_tiles_Y))]
#define RacEr_tile_group_shared_load(type,lc_sh,index,val) (  (val) = *(RacEr_tile_group_shared_ptr(type,(lc_sh),(index)))	)
#define RacEr_tile_group_shared_load_direct(type,lc_sh,index) (*(RacEr_tile_group_shared_ptr(type,(lc_sh),(index))))
#define RacEr_tile_group_shared_store(type,lc_sh,index,val) (  *(RacEr_tile_group_shared_ptr(type,(lc_sh),(index))) = (val)	)


#define RacEr_remote_store_uint8(x,y,local_addr,val)  do { *((RacEr_remote_uint8_ptr)  (RacEr_remote_ptr((x),(y),(local_addr)))) = (unsigned char) (val); } while (0)
#define RacEr_remote_store_uint16(x,y,local_addr,val) do { *((RacEr_remote_uint16_ptr) (RacEr_remote_ptr((x),(y),(local_addr)))) = (unsigned short) (val); } while (0)

#define RacEr_remote_ptr_control(x,y, CSR_offset) RacEr_remote_ptr( (x), (y), ( (CSR_BASE_ADDR) + (CSR_offset) ) )
//#define RacEr_remote_unfreeze(x,y) RacEr_remote_control_store((x),(y),0,0)
//#define RacEr_remote_freeze(x,y)   RacEr_remote_control_store((x),(y),0,1)
//deprecated
//#define RacEr_remote_arb_config(x,y,value)   RacEr_remote_control_store((x),(y),4,value)

// remote loads
//#define RacEr_remote_load(x,y,local_addr, val) ( val = *(RacEr_remote_ptr((x),(y),(local_addr))) )

#define RacEr_remote_ptr_io(x,local_addr) RacEr_global_ptr((x), IO_Y_INDEX,(local_addr))
#define RacEr_remote_ptr_io_store(x,local_addr,val) do { *(RacEr_remote_ptr_io((x),(local_addr))) = (int) (val); } while (0)
#define RacEr_remote_ptr_io_load(x,local_addr,val) do { (val) = *(RacEr_remote_ptr_io((x),(local_addr))) ; } while (0)

// see RacEr_nonsynth_manycore_monitor for secret codes
// For 18 bits remote address, we cannot mantain the 0xDEAD0 address.
#define RacEr_finish()       do {  RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(IO_X_INDEX,0xEAD0); *ptr = ((RacEr_y << 16) + RacEr_x); while (1); } while(0)

#define RacEr_finish_x(x)       do {  RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(x,0xEAD0); *ptr = ((RacEr_y << 16) + RacEr_x); while (1); } while(0)
#define RacEr_fail()       do {  RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(IO_X_INDEX,0xEAD8); *ptr = ((RacEr_y << 16) + RacEr_x); while (1); } while(0)
#define RacEr_fail_x(x)       do {  RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(x,0xEAD8); *ptr = ((RacEr_y << 16) + RacEr_x); while (1); } while(0)
#define RacEr_print_time()   do {  RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(IO_X_INDEX,0xEAD4); *ptr = ((RacEr_y << 16) + RacEr_x); } while(0)

#define RacEr_putchar( c )       do {  RacEr_remote_uint8_ptr ptr = (RacEr_remote_uint8_ptr) RacEr_remote_ptr_io(IO_X_INDEX,0xEADC); *ptr = c; } while(0)
#define RacEr_putchar_err( c )       do {  RacEr_remote_uint8_ptr ptr = (RacEr_remote_uint8_ptr) RacEr_remote_ptr_io(IO_X_INDEX,0xEEE0); *ptr = c; } while(0)

static inline void RacEr_print_int(int i)
{
        RacEr_remote_int_ptr ptr = (RacEr_remote_int_ptr)RacEr_remote_ptr_io(IO_X_INDEX,0xEAE0);
        *ptr = i;
}

static inline void RacEr_print_unsigned(unsigned u)
{
        RacEr_remote_uint32_ptr ptr = (RacEr_remote_uint32_ptr)RacEr_remote_ptr_io(IO_X_INDEX,0xEAE4);
        *ptr = u;
}

static inline void RacEr_print_hexadecimal(unsigned u)
{
        RacEr_remote_uint32_ptr ptr = (RacEr_remote_uint32_ptr)RacEr_remote_ptr_io(IO_X_INDEX,0xEAE8);
        *ptr = u;
}

static inline void RacEr_print_float(posit f)
{
        RacEr_remote_float_ptr ptr = (RacEr_remote_float_ptr)RacEr_remote_ptr_io(IO_X_INDEX,0xEAEC);
        *ptr = f;
}
static inline void RacEr_print_float_scientific(posit f)
{
        RacEr_remote_float_ptr ptr = (RacEr_remote_float_ptr)RacEr_remote_ptr_io(IO_X_INDEX,0xEAF0);
        *ptr = f;
}

#define RacEr_id_to_x(id)    ((id) % RacEr_tiles_X)
#define RacEr_id_to_y(id)    ((id) / RacEr_tiles_X)
#define RacEr_x_y_to_id(x,y) (RacEr_tiles_X*(y) + (x))
#define RacEr_num_tiles (RacEr_tiles_X*RacEr_tiles_Y)

// later, we can add some mechanisms to save power
#define RacEr_wait_while(cond) do {} while ((cond))

// load reserved; and load reserved acquire
#ifdef __clang__
inline int RacEr_lr(int *p)    { int tmp; __asm__ __volatile__("lr.w    %0,%1\n" : "=r" (tmp) : "m" (*p)); return tmp; }
inline int RacEr_lr_aq(int *p) { int tmp; __asm__ __volatile__("lr.w.aq %0,%1\n" : "=r" (tmp) : "m" (*p)); return tmp; }
#elif defined(__GNUC__) || defined(__GNUG__)
inline int RacEr_lr(int *p)    { int tmp; __asm__ __volatile__("lr.w    %0,%1\n" : "=r" (tmp) : "A" (*p)); return tmp; }
inline int RacEr_lr_aq(int *p) { int tmp; __asm__ __volatile__("lr.w.aq %0,%1\n" : "=r" (tmp) : "A" (*p)); return tmp; }
#else
#error Unsupported Compiler!
#endif

inline void RacEr_fence()      { __asm__ __volatile__("fence" :::); }

#define RacEr_volatile_access(var)        (*((RacEr_remote_int_ptr) (&(var))))
#define RacEr_volatile_access_uint16(var) (*((RacEr_remote_uint16_ptr) (&(var))))
#define RacEr_volatile_access_uint8(var)  (*((RacEr_remote_uint8_ptr) (&(var))))

// prevents compiler from reordering memory operations across
// this line in the code
// see http://preshing.com/20120625/memory-ordering-at-compile-time/
// see also atomic_signal_fence(std::memory_order_seq_cst) for C11
//
// this is a very heavy weight operation, and generally not advised
// at least for GCC.
//

#define RacEr_compiler_memory_barrier() asm volatile("" ::: "memory")

#define RacEr_commit_stores() do { RacEr_fence(); /* fixme: add commit stores instr */  } while (0)

// This micros are used to print the definiations in manycore program at compile time.
// Useful for other program to the get the manycore configurations, like the number of tiles, buffer size etc.
#define RacEr_VALUE_TO_STRING(x) #x
#define RacEr_VALUE(x) RacEr_VALUE_TO_STRING(x)
#define RacEr_VAR_NAME_VALUE(var) "MANYCORE_EXPORT #define " #var " "  RacEr_VALUE(var)


//------------------------------------------------------
// Print stat parameters and operations
//------------------------------------------------------
#define RacEr_CUDA_PRINT_STAT_ID_STAT         0
#define RacEr_CUDA_PRINT_STAT_ID_START        1
#define RacEr_CUDA_PRINT_STAT_ID_END          2

#define RacEr_CUDA_PRINT_STAT_TAG_WIDTH       4
#define RacEr_CUDA_PRINT_STAT_TG_ID_WIDTH     14
#define RacEr_CUDA_PRINT_STAT_X_WIDTH         6
#define RacEr_CUDA_PRINT_STAT_Y_WIDTH         6
#define RacEr_CUDA_PRINT_STAT_TYPE_WIDTH      2

#define RacEr_CUDA_PRINT_STAT_TAG_TOTAL       0x0

#define RacEr_CUDA_PRINT_STAT_TAG_SHIFT       (0)                                                                 // 0
#define RacEr_CUDA_PRINT_STAT_TG_ID_SHIFT     (RacEr_CUDA_PRINT_STAT_TAG_SHIFT   + RacEr_CUDA_PRINT_STAT_TAG_WIDTH)   // 4
#define RacEr_CUDA_PRINT_STAT_X_SHIFT         (RacEr_CUDA_PRINT_STAT_TG_ID_SHIFT + RacEr_CUDA_PRINT_STAT_TG_ID_WIDTH) // 18
#define RacEr_CUDA_PRINT_STAT_Y_SHIFT         (RacEr_CUDA_PRINT_STAT_X_SHIFT     + RacEr_CUDA_PRINT_STAT_X_WIDTH)     // 24
#define RacEr_CUDA_PRINT_STAT_TYPE_SHIFT      (RacEr_CUDA_PRINT_STAT_Y_SHIFT     + RacEr_CUDA_PRINT_STAT_Y_WIDTH)     // 30

#define RacEr_CUDA_PRINT_STAT_TAG_MASK        ((1 << RacEr_CUDA_PRINT_STAT_TAG_WIDTH) - 1)    // 0xF
#define RacEr_CUDA_PRINT_STAT_TG_ID_MASK      ((1 << RacEr_CUDA_PRINT_STAT_TG_ID_WIDTH) - 1)  // 0x3FFF
#define RacEr_CUDA_PRINT_STAT_X_MASK          ((1 << RacEr_CUDA_PRINT_STAT_X_WIDTH) - 1)      // 0x3F
#define RacEr_CUDA_PRINT_STAT_Y_MASK          ((1 << RacEr_CUDA_PRINT_STAT_Y_WIDTH) - 1)      // 0x3F


#define RacEr_print_stat(tag) do { RacEr_remote_int_ptr ptr = RacEr_remote_ptr_io(IO_X_INDEX,0xd0c); *ptr = tag; } while (0)


#define RacEr_cuda_print_stat_type(tag,stat_type) do {                                                              \
    int val = ( (stat_type << RacEr_CUDA_PRINT_STAT_TYPE_SHIFT)                                                |    \
                (((__RacEr_grp_org_y + __RacEr_y) & RacEr_CUDA_PRINT_STAT_Y_MASK) << RacEr_CUDA_PRINT_STAT_Y_SHIFT)  |    \
                (((__RacEr_grp_org_x + __RacEr_x) & RacEr_CUDA_PRINT_STAT_X_MASK) << RacEr_CUDA_PRINT_STAT_X_SHIFT)  |    \
                ((__RacEr_tile_group_id & RacEr_CUDA_PRINT_STAT_TG_ID_MASK) << RacEr_CUDA_PRINT_STAT_TG_ID_SHIFT)  |    \
                ((tag & RacEr_CUDA_PRINT_STAT_TAG_MASK) << RacEr_CUDA_PRINT_STAT_TAG_SHIFT) );                        \
    RacEr_print_stat(val);                                                                                          \
} while (0)

#define RacEr_cuda_print_stat(tag)          RacEr_cuda_print_stat_type(tag,RacEr_CUDA_PRINT_STAT_ID_STAT)
#define RacEr_cuda_print_stat_start(tag)    RacEr_cuda_print_stat_type(tag,RacEr_CUDA_PRINT_STAT_ID_START)
#define RacEr_cuda_print_stat_end(tag)      RacEr_cuda_print_stat_type(tag,RacEr_CUDA_PRINT_STAT_ID_END)
#define RacEr_cuda_print_stat_kernel_start() RacEr_cuda_print_stat_type(RacEr_CUDA_PRINT_STAT_TAG_TOTAL,RacEr_CUDA_PRINT_STAT_ID_START)
#define RacEr_cuda_print_stat_kernel_end()   RacEr_cuda_print_stat_type(RacEr_CUDA_PRINT_STAT_TAG_TOTAL,RacEr_CUDA_PRINT_STAT_ID_END)


#endif
