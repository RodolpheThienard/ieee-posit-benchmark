#ifndef TEST_FLOAT_MATRIX_MEMCPY_H
#define TEST_FLOAT_MATRIX_MEMCPY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>

#include "cuda_tests.h"

typedef struct
{
  float x;
  float y;
  int cluster;
} Point;

typedef struct
{
  float x;
  float y;
} Centroid;

#endif
