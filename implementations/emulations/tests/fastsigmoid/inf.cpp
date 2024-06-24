#include "../../fastsigmoids/c-src/include/P16e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P32e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/posit.h"
#include <iostream>
#include <type_traits>
using namespace std;
struct tf32
{
  unsigned int data;

public:
  tf32 () { data = 0; }

  tf32 (float t_floatVal)
  {
    data = (*reinterpret_cast<unsigned int *> (&t_floatVal)) >> 13;
  }
  tf32 (double t_doubleVal)
  {
    float floatVal = (float)t_doubleVal;
    data = (*reinterpret_cast<unsigned int *> (&floatVal)) >> 13;
  }
  // cast to float
  operator float ()
  {
    unsigned int extendedData = data << 13;
    return *reinterpret_cast<float *> (&extendedData);
  }
  // cast to tf32
  tf32 &
  operator= (float t_floatVal)
  {
    data = (*reinterpret_cast<unsigned int *> (&t_floatVal)) >> 13;
    return *this;
  }
};

int
main (int argc, char *argv[])
{
  FILE *file;
  file = fopen ("tf32_vs_p16_3.dat", "w");

  double f;
  for (f = 1; f < 1e3; f *= 1.001)
    {

      fprintf (file, "%f; %f; %f; %f; %f; %lf\n", (float)f,
               (((double)((P16e0)f)) - f) / f, (((double)((tf32)f)) - f) / f,
               (((double)((P16e1)f)) - f) / f, (((double)((P16e2)f)) - f) / f,
               f);
    }
  fclose (file);

  file = fopen ("tf32_vs_p16.dat", "w");

  for (f = 1; f < 1e40; f *= 2)
    {

      fprintf (file, "%f; %f; %f; %f; %f; %lf\n", (float)f,
               (((double)((P16e0)f)) - f) / f, (((double)((tf32)f)) - f) / f,
               (((double)((P16e1)f)) - f) / f, (((double)((P16e2)f)) - f) / f,
               f);
    }
  fclose (file);
  return 0;
}
