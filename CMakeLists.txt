cmake_minimum_required(VERSION 3.1)
project(microbench)

add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native 
  -gdwarf-4
)

# Global utils needed
FILE(GLOB utils utils/*.c)
FILE(GLOB host_kernels kernels/host/*.c)

# cuda compilation
if(ENABLE_CUDA_COMPILE)
  # cuda kernel,test files
  FILE(GLOB cuda_test tests/cuda/*.cu)
  FILE(GLOB cuda_kernels kernels/cuda/*.cu)
  FILE(GLOB cuda_driver driver/cuda/*.cu)

  set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; -lcublas -lcuda -lcudart -lm )

  find_package(CUDA REQUIRED)

  # cuda library compilation
  add_library(cuda_bench SHARED 
    ${utils} 
    ${cuda_driver} 
    ${cuda_kernels}
    ${host_kernels}
  )
  target_link_libraries(cuda_bench ${CUDA_NVCC_FLAGS} -lm)

  # cuda test file getter
  set(TESTS
    ${cuda_test}
  )

  # compilation of each cuda test file
  foreach(test ${TESTS})
    get_filename_component(test_name ${test} NAME_WE)
    cuda_add_executable(${test_name} 
      ${test}
      ${utils} 
      ${cuda_driver} 
      ${cuda_kernels} 
    )
    target_link_libraries(${test_name} ${CUDA_NVCC_FLAGS} cuda_bench -lm)
    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/cuda_bin")
  endforeach()
endif()


# omp compilation
if(ENABLE_OMP_COMPILE)
  # omp bin directory path
  # set(CMAKE_BINARY_DIR omp_bin)
  # set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_C_STANDARD 99)

  # omp kernel,test files
  FILE(GLOB omp_test tests/omp/*.c)
  FILE(GLOB omp_kernels kernels/omp/*.c)
  FILE(GLOB omp_driver driver/omp/*.c)

  find_package(OpenMP REQUIRED)

  # omp library compilation
  add_library(omp_bench SHARED 
    ${utils} 
    ${omp_driver} 
    ${omp_kernels}
    ${host_kernels}
  )
  # omp test file getter
  set(TESTS
    ${omp_test}
  )

  if(OpenMP_C_FOUND)
      target_link_libraries(omp_bench PUBLIC OpenMP::OpenMP_C -lm )
  endif()

  # compilation of each omp test file
  foreach(test ${TESTS})
    get_filename_component(test_name ${test} NAME_WE)
    ADD_EXECUTABLE(${test_name}
      ${test}
      )
    if(OpenMP_C_FOUND)
        target_link_libraries(${test_name} PUBLIC OpenMP::OpenMP_C omp_bench -lm )
    endif()
    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/omp_bin")
  endforeach()
endif()



# racer compilation
if(ENABLE_RACER_COMPILE)

  # racer kernel,test files
# RACER compilation
FILE(GLOB utils utils/*.c)
FILE(GLOB racer_test tests/racer/*.c)
FILE(GLOB racer_kernels kernels/racer/*.c)
FILE(GLOB racer_driver driver/racer/driver.c)

add_definitions(-DRacEr_global_X=4)
add_definitions(-DRacEr_global_Y=4)
add_definitions(-DRacEr_tiles_X=4)
add_definitions(-DRacEr_tiles_Y=3)

  # racer library compilation
  add_library(racer_bench SHARED 
    ${utils} 
    ${racer_driver} 
    ${racer_kernels}
  )
  # racer test file getter
  set(TESTS
    ${racer_test}
  )

  # compilation of each racer test file
  foreach(test ${TESTS})
    get_filename_component(test_name ${test} NAME_WE)
    ADD_EXECUTABLE(${test_name} 
      ${test}
      )
    target_link_libraries(${test_name} PUBLIC racer_bench -lm -lRacEr_manycore_runtime )
    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/racer_bin")
  endforeach()
endif()
