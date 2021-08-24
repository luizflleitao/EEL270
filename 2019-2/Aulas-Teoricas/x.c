#include <stdio.h>

int
main (int argc, char *argv[])
{
  signed char x;
  unsigned char y;
  
  x = -1;
  y = x;

  printf ("%02X %i %u\n", x, x, x);
  printf ("%02X %u %i\n", y, y, y);

  return 0;
}

