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

#include "exemplo_039.h"

#define NUMERO_ARGUMENTOS		1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ERRO_FUNCAO_GERAR_IDENTIFICADOR 2

int
main (int argc, char *argv []) 
{
  tipoErros codigoRetorno;
  byte identificador [COMPRIMENTO_IDENTIFICADOR];
  unsigned indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  codigoRetorno = GerarIdentificador (identificador);
  if (codigoRetorno != ok)
  {
    printf ("Erro na funcao GerarIdentificador: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_GERAR_IDENTIFICADOR);
  }

  for (indice = 0; indice < COMPRIMENTO_IDENTIFICADOR; indice++)
    printf ("%x", identificador [indice]);
  printf ("\n");

  return OK;

} /* funcao principal */

