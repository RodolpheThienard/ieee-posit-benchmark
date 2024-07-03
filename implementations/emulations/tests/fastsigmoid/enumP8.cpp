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
  FILE *file;
  file = fopen ("p8_around_0.dat", "w");

  double f;
  for (f = 1; f < 10; f *= 1.0001)
    {

      fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
               (((double)((P8e0)f)) - f) / f, (((double)((P8e1)f)) - f) / f,
               (((double)((P8e2)f)) - f) / f, f);
    }
  fclose (file);

  file = fopen ("p8_range.dat", "w");

  for (f = 1e-7; f < 1e4; f *= 1.1)
    {

      fprintf (file, "%20.15f;  %20.15f; %20.15f; %20.15f\n", (float)f,
               ((double)((P8e0)f)), ((double)((P8e1)f)), ((double)((P8e2)f)));
      // fprintf (file, "%f; %f; %f; %f; %lf\n", (float)f,
      //          (((double)((P8e0)f)) - f) / f, (((double)((P8e1)f)) - f) / f,
      //          (((double)((P8e2)f)) - f) / f, f);
    }
  fclose (file);
  float n = 163.103614;
  printf ("NUMBER : %f, Posit : %f;%f;\n", n, (float)((P16e1)n),
          (float)((P16e2)n));
  return 0;
}
/* #include <math.h>
#include <stdint.h>
#include <stdio.h>

double
decodePosit8e0 (uint8_t posit)
{
  if (posit == 0x00)
    return 0;
  if (posit == 0x80)
    return -INFINITY;

  int sign = (posit & 0x80) ? -1 : 1;
  if (sign == -1)
    posit = ~posit + 1;

  int regime = 0;
  uint8_t temp = posit << 1;

  if (temp & 0x80)
    {
      while (temp & 0x80)
        {
          regime++;
          temp <<= 1;
        }
      regime -= 1;
    }
  else
    {
      while (!(temp & 0x80))
        {
          regime--;
          temp <<= 1;
        }
    }

  double fraction = 1.0;
  int fractionBits = 6 - abs (regime);
  double fractionValue = 0.5;
  temp <<= 1;

  for (int i = 0; i < fractionBits; i++)
    {
      if (temp & 0x80)
        {
          fraction += fractionValue;
        }
      fractionValue /= 2;
      temp <<= 1;
    }

  double value = sign * pow (2, regime) * fraction;
  return value;
}

double
decodePosit8e1 (uint8_t posit)
{
  if (posit == 0x00)
    return 0; // Zéro
  if (posit == 0x80)
    return -INFINITY; // -Infini (valeur spéciale)

  int sign = (posit & 0x80) ? -1 : 1; // Extraction du bit de signe
  if (sign == -1)
    posit = ~posit + 1; // Si négatif, prendre le complément à 2

  int regime = 0;
  uint8_t temp
      = posit << 1; // Ignorer le bit de signe pour l'analyse du régime

  // Déterminer le régime en comptant les bits successifs avant la première
  // transition
  if (temp & 0x80)
    { // Régime positif, suite de 1
      while (temp & 0x80)
        {
          regime++;
          temp <<= 1;
        }
      regime -= 1; // Le régime positif commence à 0
    }
  else
    { // Régime négatif, suite de 0
      while (!(temp & 0x80))
        {
          regime--;
          temp <<= 1;
        }
    }

  // Extraction de l'exposant (1 bit pour es = 1)
  int exponent = (temp & 0x40) ? 1 : 0; // Bit d'exposant pour es = 1
  temp <<= 1;                           // Décalage après l'exposant

  // Calculer la fraction
  double fraction = 1.0;
  int fractionBits = 5 - abs (regime); // 5 bits restants pour la fraction (6 -
                                       // 1 pour l'exposant - abs(régime))
  double fractionValue = 0.5;

  for (int i = 0; i < fractionBits; i++)
    {
      if (temp & 0x80)
        {
          fraction += fractionValue;
        }
      fractionValue /= 2;
      temp <<= 1;
    }

  // Calculer la valeur finale
  double value = sign * pow (2, regime) * pow (2, exponent) * fraction;
  return value;
}

int
main ()
{
  uint8_t posit = 0x01;
  double p8e0, p8e1;
  for (int i = 0; i < 256; i++)
    {
      p8e0 = decodePosit8e0 (i);
      p8e1 = decodePosit8e1 (i);
      printf ("%d; %g\n", i, p8e0);
    }
  return 0;
} */
