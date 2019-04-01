#include <stdio.h>

/*
 int main (int argc, char **argv) 
 */
int main (int argc, char *argv []) 
{
  unsigned int indice;

  for (indice = 0; indice < argc; ++indice)
    printf ("ARG(#%u): \"%s\"\n", indice, argv [indice]);

  return 0;
} /* funcao principal */
