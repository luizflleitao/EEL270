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

#include "exemplo_032.h"

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define END_OF_STRING			'\0'

int
main (int argc, char *argv []) 
{

  byte dre [COMPRIMENTO_DRE];
  byte indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <DRE>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 0; indice < COMPRIMENTO_DRE; indice++)
  {
    printf ("%c\t", argv [1][indice]);
    printf ("%u\t", argv [1][indice]);
    printf ("%u\n", (byte) (argv [1][indice] - '0'));
    dre [indice] = (byte) (argv [1][indice] - '0');
  }
  /* if (ValidarDigitoVerificadorDre (&(dre [0]))) */
  if (ValidarDigitoVerificadorDre (dre)) 
    printf ("Digito verificador valido\n");
  else
    printf ("Digito verificador invalido\n");

  return OK;

} /* funcao principal */

