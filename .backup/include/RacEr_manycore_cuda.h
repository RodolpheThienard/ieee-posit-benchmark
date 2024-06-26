// Copyright (c) 2020, VividSparks IT Solutions Pvt. Ltd.  All rights reserved.
//
// Redistribution and use in source and binary forms, modifications,
// are NOT permitted.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef RacEr_MANYCORE_CUDA_H
#define RacEr_MANYCORE_CUDA_H
#include "RacEr_manycore_features.h"
#include "RacEr_manycore_eva.h"

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


        // Kernel is not loaded into tile if kernel poitner equals this value.
#define HB_MC_CUDA_KERNEL_NOT_LOADED_VAL        0x0001
        // The value that is written on to finish_signal_addr to show that tile group execution is done.
#define HB_MC_CUDA_FINISH_SIGNAL_VAL            0x0001  
        // The begining of section in host memory intended for tile groups to write finish signals into.
#define HB_MC_CUDA_HOST_FINISH_SIGNAL_BASE_ADDR 0xF000  



        typedef uint8_t tile_group_id_t;
        typedef uint8_t grid_id_t;
        typedef int RacEr_mc_allocator_id_t;


        typedef enum {
                HB_MC_TILE_GROUP_STATUS_INITIALIZED=0,
                HB_MC_TILE_GROUP_STATUS_ALLOCATED=1,
                HB_MC_TILE_GROUP_STATUS_LAUNCHED=2,
                HB_MC_TILE_GROUP_STATUS_FINISHED=3,
        } RacEr_mc_tile_group_status_t ;


        typedef enum {
                HB_MC_TILE_STATUS_FREE=0,
                HB_MC_TILE_STATUS_BUSY=1,
        } RacEr_mc_tile_status_t;


        typedef struct {
                RacEr_mc_coordinate_t coord;
                RacEr_mc_coordinate_t origin;      
                RacEr_mc_coordinate_t tile_group_id;
                RacEr_mc_tile_status_t status;
        } RacEr_mc_tile_t;

        typedef struct {
                const char *name;
                uint32_t argc;
                const uint32_t *argv;
                RacEr_mc_epa_t finish_signal_addr;
        } RacEr_mc_kernel_t;

        typedef struct {
                RacEr_mc_coordinate_t id;
                grid_id_t grid_id;
                RacEr_mc_dimension_t grid_dim;
                RacEr_mc_tile_group_status_t status;
                RacEr_mc_coordinate_t origin;
                RacEr_mc_dimension_t dim;
                RacEr_mc_eva_map_t *map;
                RacEr_mc_kernel_t *kernel;
        } RacEr_mc_tile_group_t;


        typedef struct {
                RacEr_mc_dimension_t dim;
                RacEr_mc_coordinate_t origin;
                RacEr_mc_tile_t* tiles;
        } RacEr_mc_mesh_t;


        typedef struct {
                RacEr_mc_allocator_id_t id;
                const char *name; 
                void *memory_manager;
        } RacEr_mc_allocator_t;


        typedef struct {
                const char* bin_name;
                const unsigned char* bin;
                size_t bin_size;
                RacEr_mc_allocator_t *allocator;
        } RacEr_mc_program_t;


        typedef struct {
                RacEr_mc_manycore_t *mc;
                RacEr_mc_program_t *program;
                RacEr_mc_mesh_t *mesh;
                RacEr_mc_tile_group_t *tile_groups;
                uint32_t num_tile_groups;
                uint32_t tile_group_capacity;
                uint8_t num_grids;
        } RacEr_mc_device_t; 


        enum RacEr_mc_memcpy_kind {
                HB_MC_MEMCPY_TO_DEVICE = 0,
                HB_MC_MEMCPY_TO_HOST = 1,
        };




        /**
         * Initializes the manycor struct, and a mesh structure with default (maximum)
         * diemsnions inside device struct with list of all tiles and their cooridnates 
         * @param[in]  device        Pointer to device
         * @param[in]  name          Device name
         * @param[in]  id            Device id
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_init (RacEr_mc_device_t *device,
                               const char *name,
                               RacEr_mc_manycore_id_t id);





        /**
         * Initializes the manycor struct, and a mesh structure with custom
         * diemsnions inside device struct with list of all tiles and their cooridnates 
         * @param[in]  device        Pointer to device
         * @param[in]  name          Device name
         * @param[in]  id            Device id
         * @param[in]  dim           Tile pool (mesh) dimensions
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_init_custom_dimensions (RacEr_mc_device_t *device,
                                                 const char *name,
                                                 RacEr_mc_manycore_id_t id,
                                                 RacEr_mc_dimension_t dim);




        /**
         * Takes in a buffer containing the binary and its size,
         * freezes tiles, loads program binary into all tiles and into dram,
         * and sets the symbols and registers for each tile.
         * @param[in]  device        Pointer to device
         * @parma[in]  bin_name      Name of binary elf file
         * @param[in]  bin_data      Buffer containing binary 
         * @param[in]  bin_size      Size of the binary to be loaded onto device
         * @param[in]  id            Id of program's memory allocator
         * @param[in]  alloc_name    Unique name of program's memory allocator
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_program_init_binary (RacEr_mc_device_t *device,
                                              const char *bin_name,
                                              const unsigned char *bin_data,
                                              size_t bin_size,
                                              const char *alloc_name,
                                              RacEr_mc_allocator_id_t id);





        /**
         * Takes in a binary name, loads the binary from file onto a buffer,
         * freezes tiles, loads program binary into all tiles and into dram,
         * and sets the symbols and registers for each tile.
         * @param[in]  device        Pointer to device
         * @parma[in]  bin_name      Name of binary elf file
         * @param[in]  id            Id of program's memory allocator
         * @param[in]  alloc_name    Unique name of program's memory allocator
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_program_init (RacEr_mc_device_t *device,
                                       const char *bin_name,
                                       const char *alloc_name,
                                       RacEr_mc_allocator_id_t id);



        /**
         * Allocates memory on device DRAM
         * RacEr_mc_device_program_init() or RacEr_mc_device_program_init_binary() should
         * have been called before calling this function to set up a memory allocator.
         * @param[in]  device        Pointer to device
         * @parma[in]  size          Size of requested memory
         * @param[out] eva           Eva address of the allocated memory
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_malloc (RacEr_mc_device_t *device, uint32_t size, RacEr_mc_eva_t *eva);





        /**
         * Copies a buffer from src on the host/device DRAM to dst on device DRAM/host.
         * @param[in]  device        Pointer to device
         * @parma[in]  src           EVA address of source to be copied from
         * @parma[in]  dst           EVA address of destination to be copied into
         * @param[in]  name          EVA address of dst
         * @param[in]  count         Size of buffer (number of words) to be copied
         * @param[in]  RacEr_mc_memcpy_kind         Direction of copy (HB_MC_MEMCPY_TO_DEVICE / HB_MC_MEMCPY_TO_HOST)
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_memcpy (RacEr_mc_device_t *device,
                                 void *dst,
                                 const void *src,
                                 uint32_t count,
                                 enum RacEr_mc_memcpy_kind kind);





        /**
         * Sets memory to a give value starting from an address in device's DRAM.
         * @param[in]  device        Pointer to device
         * @parma[in]  eva           EVA address of destination 
         * @param[in]  val           Value to be written out
         * @param[in]  sz            The number of bytes to write into device DRAM
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        int RacEr_mc_device_memset (RacEr_mc_device_t *device,
                                 const RacEr_mc_eva_t *eva,
                                 uint8_t data,
                                 size_t sz); 





        /**
         * Frees memory on device DRAM
         * RacEr_mc_device_program_init() or RacEr_mc_device_program_init_binary() should
         * have been called before calling this function to set up a memory allocator.
         * @param[in]  device        Pointer to device
         * @param[out] eva           Eva address of the memory to be freed
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result)) 
        int RacEr_mc_device_free (RacEr_mc_device_t *device, RacEr_mc_eva_t eva);





        /**
         * Enqueues and schedules a kernel to be run on device
         * Takes the grid size, tile group dimensions, kernel name, argc,
         * argv* and the finish signal address, calls RacEr_mc_tile_group_enqueue
         * to initialize all tile groups for grid.
         * @param[in]  device        Pointer to device
         * @param[in]  grid_dim      X/Y dimensions of the grid to be initialized
         * @param[in]  tg_dim        X/Y dimensions of tile groups in grid
         * @param[in]  name          Kernel name to be executed on tile groups in grid
         * @param[in]  argc          Number of input arguments to kernel
         * @param[in]  argv          List of input arguments to kernel
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_kernel_enqueue (RacEr_mc_device_t *device,
                                       RacEr_mc_dimension_t grid_dim,
                                       RacEr_mc_dimension_t tg_dim,
                                       const char *name,
                                       const uint32_t argc,
                                       const uint32_t *argv);




        /**
         * Iterates over all tile groups inside device,
         * allocates those that fit in mesh and launches them. 
         * API remains in this function until all tile groups
         * have successfully finished execution.
         * @param[in]  device        Pointer to device
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_tile_groups_execute (RacEr_mc_device_t *device);





        /**
         * Deletes memory manager, device and manycore struct, and freezes all tiles in device.
         * @param[in]  device        Pointer to device
         * @return HB_MC_SUCCESS if succesful. Otherwise an error code is returned.
         */
        __attribute__((warn_unused_result))
        int RacEr_mc_device_finish (RacEr_mc_device_t *device);





#ifdef __cplusplus
}
#endif

#endif
