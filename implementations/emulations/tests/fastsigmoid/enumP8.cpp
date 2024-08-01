#include "../../fastsigmoids/c-src/include/P16e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P16e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P32e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e0.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e1.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/P8e2.h" // <== 32 bit posit, exponent 2
#include "../../fastsigmoids/c-src/include/posit.h"
#include <iostream>
#include <type_traits>

int
main (int argc, char *argv[])
{
  // FILE *file;
  // file = fopen ("p8_around_0.dat", "w");

  // double f;
  // for (f = 1; f < 10; f += 0.001)
  //   {

  //     fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
  //              (((double)((P8e0)f)) - f) / f, (((double)((P8e1)f)) - f) / f,
  //              (((double)((P8e2)f)) - f) / f, f);
  //   }
  // fclose (file);

  // file = fopen ("p8_range.dat", "w");

  // for (f = 1e-7; f < 1e4; f *= 1.001)
  //   {

  //     fprintf (file, "%20.15f;  %20.15f; %20.15f; %20.15f\n", (float)f,
  //              ((double)((P8e0)f)), ((double)((P8e1)f)),
  //              ((double)((P8e2)f)));
  //     // fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
  //     //          (((double)((P8e0)f)) - f) / f, (((double)((P8e1)f)) - f) /
  //     f,
  //     //          (((double)((P8e2)f)) - f) / f, f);
  //   }
  // fclose (file);
  // file = fopen ("p8_range2.dat", "w");

  // for (f = 1; f < 1e3; f += 0.1)
  //   {

  //     fprintf (file, "%20.15f;  %20.15f; %20.15f; %20.15f\n", (float)f,
  //              ((double)((P8e0)f)), ((double)((P8e1)f)),
  //              ((double)((P8e2)f)));
  //     // fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
  //     //          (((double)((P8e0)f)) - f) / f, (((double)((P8e1)f)) - f) /
  //     f,
  //     //          (((double)((P8e2)f)) - f) / f, f);
  //   }
  // fclose (file);
  // float n = 163.103614;
  // printf ("NUMBER : %f, Posit : %f;%f;\n", n, (float)((P16e1)n),
  //         (float)((P16e2)n));

  // P8e2 val2 = 0.;
  // P8e1 val1 = 0.;
  // P8e0 val0 = 0.;
  // FILE *file2 = fopen ("p8e2_enum.dat", "w");
  // FILE *file1 = fopen ("p8e1_enum.dat", "w");
  // FILE *file0 = fopen ("p8e0_enum.dat", "w");
  // for (f = 0; f < 1e5; f += 0.00001)
  //   {
  //     if (!((P8e2)f == val2))
  //       {
  //         val2 = (P8e2)f;
  //         fprintf (file2, "%20.15f;\n", ((float)val2));
  //       }
  //     if (!((P8e1)f == val1))
  //       {
  //         val1 = (P8e1)f;
  //         fprintf (file1, "%20.15f;\n", ((float)val1));
  //       }
  //     if (!((P8e0)f == val0))
  //       {
  //         val0 = (P8e0)f;
  //         fprintf (file0, "%20.15f;\n", ((float)val0));
  //       }
  //   }
  // fclose (file1);
  // fclose (file2);
  // fclose (file0);

  float int8_posit8[9] = { .2, 1.4, 2, 1, 0.5, -3.1, -0.5, -2, 1.2 };
  for (int i = 0; i < 9; i++)
    {
      printf ("%f\n", ((float)(P8e2)int8_posit8[i]));
    }

  return 0;
}
