#include <stdio.h>

int
main (int argc, char **argv)
{
  signed char x = -1;
  unsigned char y;

  y = x;

  printf ("x: %02X - %i\ny: %02X %u\n", x, x, y, y);
  return 0;
}
