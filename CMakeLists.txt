cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -gdwarf-4
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
FILE(GLOB driver_cuda driver/benchmark_cuda.cu)
FILE(GLOB cuda kernels/Cuda/gemm.cu)
FILE(GLOB cuda_test tests/cuda/main.cu)

# set(CMAKE_CUDA_HOST_COMPILER nvcc)
# set(CMAKE_CUDA_COMPILER nvcc)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -lcublas -lcuda -lcudart -lm )

find_package(CUDA REQUIRED)
cuda_add_executable(cuda_main
  ${cuda_test}
  ${utils}
  ${driver_cuda}
  ${cuda}
)
target_link_libraries(cuda_main ${CUDA_NVCC_FLAGS})

# RACER compilation

FILE(GLOB racer kernels/racer/*.c)


