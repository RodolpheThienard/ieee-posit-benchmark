cmake_minimum_required(VERSION 3.1)
project(microbench)

FILE(GLOB MyCSources *.c)
add_compile_options(
  -O3 -Wall -Wextra -Wpedantic -march=native -funroll-loops -ftree-vectorize
  -g
)

ADD_EXECUTABLE(main ${MyCSources})

target_link_libraries(main m)
