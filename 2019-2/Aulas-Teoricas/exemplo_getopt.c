#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OK				0

int
main (int argc, char **argv)
{
  int opcao;
  char *stringOpcoes = "c:x:a:r:n::";

  while ((opcao = getopt (argc, argv, stringOpcoes)) != -1)
  {
    printf ("%i\n", opcao);
  }  

  return OK;
}
