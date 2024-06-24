#include <stdio.h>
int
main ()
{
#ifdef POSIT
  float A = 1.3230001111234;
  float B = -0.7920123421234;
  float C = A + B;
  printf ("Posit  = %25.20f\n", C); // Answer = 0.531
  double Ad = 1.3230001111234;
  double Bd = -0.7920123421234;
  double Cd = Ad + Bd;
  printf ("Double = %25.20lf\n", Cd); // Answer = 0.531

#else

  float A = 1.3230001111234;
  float B = -0.7920123421234;
  float C = A + B;
  printf ("Float  = %25.20f\n", C); // Answer = 0.531

  double Ad = 1.3230001111234;
  double Bd = -0.7920123421234;
  double Cd = Ad + Bd;
  printf ("Double = %25.20lf\n", Cd); // Answer = 0.531

#endif
}
