cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -gdwarf-4
)

# RACER compilation
FILE(GLOB utils utils/*.c)
FILE(GLOB racer_test tests/racer/*.c)
FILE(GLOB racer_kernels kernels/racer/*.c)
FILE(GLOB racer_driver driver/racer/driver.c)

add_definitions(-DRacEr_global_X=4)
add_definitions(-DRacEr_global_Y=4)
add_definitions(-DRacEr_tiles_X=4)
add_definitions(-DRacEr_tiles_Y=3)

set(CMAKE_C_STANDARD 99)

add_library(racer_bench SHARED 
  ${utils} 
  ${racer_driver} 
  ${racer_kernels}
)
target_link_libraries(racer_bench PUBLIC -lm )

ADD_EXECUTABLE(racer_main 
  ${racer_test}
)
target_link_libraries(racer_main PUBLIC racer_bench -lm -lRacEr_manycore_runtime )
