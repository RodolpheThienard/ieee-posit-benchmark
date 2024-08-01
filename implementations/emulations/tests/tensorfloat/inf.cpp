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
  file = fopen ("tf32_around_0.dat", "w");

  double f;
  for (f = 1; f < 1e2; f *= 1.0001)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f, (((double)((tf32)f)) - f) / f,
               f);
    }
  fclose (file);

  file = fopen ("tf32_range.dat", "w");

  for (f = 1; f < 1e40; f *= 2)
    {

      fprintf (file, "%f; %f; %lf\n", (float)f, (((double)((tf32)f)) - f) / f,
               f);
    }
  fclose (file);
  return 0;
}
