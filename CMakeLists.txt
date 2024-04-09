cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -g
)

FILE(GLOB utils utils/*.c)
FILE(GLOB ieee kernels/ieee/*.c)
FILE(GLOB driver driver/*.c)
FILE(GLOB ieee_test tests/ieee/main.c)

ADD_EXECUTABLE(ieee_main 
  ${ieee_test}
  ${utils} 
  ${driver} 
  ${ieee}
)

FILE(GLOB racer kernels/racer/*.c)
FILE(GLOB cuda kernels/cuda/*.cu)

target_link_libraries(ieee_main m)
