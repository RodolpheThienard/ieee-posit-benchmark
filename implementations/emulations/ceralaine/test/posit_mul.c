#include "softposit.h"

posit posit_mul (posit Aa , posit Bb){

    posit32_t pA, pB, pZ;
    double A, B;
    posit C;

    A = (double) Aa;
    B = (double) Bb;

    pA = convertDoubleToP32(A);
    pB = convertDoubleToP32(B);

    pZ = p32_mul(pA, pB);

    double dZ = convertP32ToDouble(pZ);

    C = (posit) dz;
   
  return C;
   }                                                                        
