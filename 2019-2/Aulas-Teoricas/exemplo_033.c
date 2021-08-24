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

#define NUMERO_ARGUMENTOS		COMPRIMENTO_DRE + 1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define END_OF_STRING			'\0'

int
main (int argc, char *argv []) 
{

  byte dre [COMPRIMENTO_DRE];
  byte indice;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <DV>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 1; indice < argc; indice++)
  {
    if (argv [indice][0] == '-')
    {
      printf ("Argumento (#%u) invalido: \"%s\"\n", indice, argv [indice]);
      exit (ARGUMENTO_INVALIDO);
    }

    dre [indice - 1] = (byte) strtoul (argv [indice], &validacao, 10);
    if (*validacao != END_OF_STRING)
    {
      printf ("Argumento (#%u) invalido: \"%s\"\n", indice, argv [indice]);
      exit (ARGUMENTO_INVALIDO);
    }
  }

  /* if (ValidarDigitoVerificadorDre (&(dre [0]))) */
  if (ValidarDigitoVerificadorDre (dre)) 
    printf ("Digito verificador valido\n");
  else
    printf ("Digito verificador invalido\n");

  return OK;

} /* funcao principal */

