#include "../../include/utils.h"
#include <math.h>
#define SQUARE(a) a *a
void
image_correlation (const float *image1, const float *image2, int width,
                   int height, int x_begin, int y_begin)
{
  float *tmp;
  tmp = malloc (sizeof (float) * width * height);
  for (int y1 = 0; y1 < height - 50; y1++)
    {
      for (int x1 = 0; x1 < width - 50; x1++)
        {
          float correlation_value = 0, a = 0, b = 0;

          for (int i = 0; i < 50; i++)
            {
              for (int j = 0; j < 50; j++)
                {
                  correlation_value
                      += image1[(y1 + i) * width + (x1 + j)]
                         * image2[(y_begin + i) * width + (x_begin + j)];
                  a += image1[(y1 + i) * width + (x1 + j)];
                  b += image2[(y_begin + i) * width + (x_begin + j)];
                }
            }

          correlation_value /= sqrt (SQUARE (a) * SQUARE (b));
          tmp[y1 * width + x1] = correlation_value;
        }
    }
  float ret = 01;
  int x_out, y_out;
  for (int i = 0; i < height - 50; i++)
    {
      for (int j = 0; j < width - 50; j++)
        {
          if (ret > tmp[i * width + j])
            {
              ret = tmp[i * width + j];
              x_out = j;
              y_out = i;
            }
        }
    }
  printf ("min box is : %f at (%d,%d)\n", ret, x_out, y_out);
}
