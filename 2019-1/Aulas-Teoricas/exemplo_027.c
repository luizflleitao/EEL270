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
#include "exemplo_025.h"

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define COMPRIMENTO_DRE_INVALIDO	2
#define ARGUMENTO_INVALIDO		3	

#define EOS				'\0'

int
main (int argc, char *argv []) 
{

  byte dre [COMPRIMENTO_DRE];
  byte indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <dre>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  if (strlen (argv [1]) != COMPRIMENTO_DRE)
  {
    printf ("O DRE deve ter %i digitos\n", COMPRIMENTO_DRE);
    exit (COMPRIMENTO_DRE_INVALIDO);
  }

  for (indice = 0; indice < COMPRIMENTO_DRE; indice++)
  {
    if (argv [1][indice] < '0' || argv [1][indice] > '9')
    {
      printf ("Argumento negativo. Entre com numeros entre 0 e 9\n");
      exit (ARGUMENTO_INVALIDO);
    } 

    dre [indice] = (byte) (argv [1][indice] - '0');
  }

  if (ValidarDre (dre) == falso)
    printf ("DRE invalido\n");
  else
    printf ("DRE valido\n");

  return OK;

} /* funcao principal */

