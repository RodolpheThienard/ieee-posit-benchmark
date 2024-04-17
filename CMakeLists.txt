cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -gdwarf-4
)

# Global utils needed
FILE(GLOB utils utils/*.c)

# IEEE compilation
FILE(GLOB x86_test tests/x86/*.c)
FILE(GLOB x86_kernels kernels/x86/*.c)
FILE(GLOB x86_driver driver/x86/*.c)

ADD_EXECUTABLE(x86_main 
  ${x86_test}
  ${utils} 
  ${x86_driver} 
  ${x86_kernels}
)

target_link_libraries(x86_main -lm)

# CUDA compilation 
FILE(GLOB cuda_driver driver/cuda/*.cu)
FILE(GLOB cuda_kernels kernels/cuda/*.cu)
FILE(GLOB cuda_test tests/cuda/*.cu)

# set(CMAKE_CUDA_HOST_COMPILER nvcc)
# set(CMAKE_CUDA_COMPILER nvcc)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -lcublas -lcuda -lcudart -lm )

find_package(CUDA REQUIRED)
cuda_add_executable(cuda_main
  ${cuda_test}
  ${utils}
  ${cuda_driver}
  ${cuda_kernels}
)
target_link_libraries(cuda_main ${CUDA_NVCC_FLAGS})


# OMP compilation
FILE(GLOB omp_test tests/omp/*.c)
FILE(GLOB omp_kernels kernels/omp/*.c)
FILE(GLOB omp_driver driver/omp/*.c)

find_package(OpenMP REQUIRED)
ADD_EXECUTABLE(omp_main 
  ${omp_test}
  ${utils} 
  ${omp_driver} 
  ${omp_kernels}
)

if(OpenMP_C_FOUND)
    target_link_libraries(omp_main PUBLIC OpenMP::OpenMP_C -lm)
endif()


# RACER compilation

FILE(GLOB racer kernels/racer/*.c)


