/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: <nome completo>
 * Descricao: <descricao sucinta sobre o programa>
 *
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define OK 0

int
main (int argc, char *argv []) 
{
  printf ("Content-Type: text/html\n\n");

  printf ("<html>\n");
  printf ("  <head>\n");
  printf ("    <title>\n");
  printf ("      CGIs -Segundo Exemplo\n");
  printf ("    </title>\n");
  printf ("  </head>\n");
  printf ("  <body bgcolor=\"yellow\">\n");
  printf ("    CGIs -Segundo Exemplo\n");
  printf ("  </body>\n");
  printf ("</html>\n");
  return OK;
} /* funcao principal */

