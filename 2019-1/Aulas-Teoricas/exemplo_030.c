/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
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
#include <string.h>
#include "exemplo_028.h"

#define NUMERO_ARGUMENTOS		COMPRIMENTO_DRE + 1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define COMPRIMENTO_ARGUMENTO_INVALIDO	2	

#define EOS				'\0'

int
main (int argc, char *argv []) 
{

  char dre [COMPRIMENTO_DRE + 1];
  unsigned char indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <dv>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  for (indice = 0; indice < COMPRIMENTO_DRE; indice++)
  {
    if (strlen (argv [indice + 1]) != 1)
    {
      printf ("Comprimento do argumento eh invalido\n");
      exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
    } 

    dre [indice] = argv [indice + 1][0];
  }
  dre [indice] = '\0'; /* EOS */

  if (ValidarDre (dre) == falso)
    printf ("DRE invalido\n");
  else
    printf ("DRE valido\n");

  return OK;

} /* funcao principal */

