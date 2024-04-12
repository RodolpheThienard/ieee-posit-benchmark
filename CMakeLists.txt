cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -g
)

# Global utils needed
FILE(GLOB utils utils/*.c)
FILE(GLOB driver driver/*.c)

# IEEE compilation
FILE(GLOB ieee_test tests/ieee/main.c)
FILE(GLOB ieee kernels/ieee/*.c)

ADD_EXECUTABLE(ieee_main 
  ${ieee_test}
  ${utils} 
  ${driver} 
  ${ieee}
)

target_link_libraries(ieee_main -lm)

# CUDA compilation 
FILE(GLOB cuda kernels/cuda/*.cu)
FILE(GLOB cuda_test tests/cuda/main.cu)

set(CMAKE_CUDA_HOST_COMPILER nvcc)
set(CMAKE_CUDA_COMPILER nvcc)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -lcublas -lm -gencode arch=compute_52,code=sm_52 )

find_package(CUDA QUIET REQUIRED)
cuda_add_executable(cuda_main
  ${cuda_test}
  ${utils}
  ${driver}
  ${cuda}
  
)


# RACER compilation

FILE(GLOB racer kernels/racer/*.c)


