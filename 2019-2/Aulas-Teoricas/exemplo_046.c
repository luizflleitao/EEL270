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

#include "exemplo_045.h"

#define NUMERO_ARGUMENTOS		1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

int
main (int argc, char *argv []) 
{
  tipoErros codigoRetorno;
  byte dre [COMPRIMENTO_DRE];
  byte indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  codigoRetorno = GerarDreAleatorio (dre);
  if (codigoRetorno)
  {
    printf ("Erro executando a funcao GerarDreAleatorio\n");
    printf ("Erro #%i\n", codigoRetorno);
    exit (OK);
  }
  
  printf ("DRE: ");
  for (indice = 0; indice < COMPRIMENTO_DRE; indice++)
    printf ("%u", dre [indice]);
  printf ("\n");

  return OK;

} /* funcao principal */

