
#include "add.h"
#include "stdio.h"

int
main ()
{
  data_h a, b, c;

  a = 1.0;
  b = 2.0;

  add (a, b, c);
  if (c == 3.0)
    {
      printf ("test passed !\n");
      return 0;
    }
  return 1;
}
