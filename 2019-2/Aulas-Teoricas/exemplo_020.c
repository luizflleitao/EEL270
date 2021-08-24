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
 */

#include <stdio.h>
#include <stdlib.h>

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define NUMERO_ARGUMENTOS 		1

/* #define BYTE unsigned char */

typedef unsigned char byte;


int
main (int argc, char *argv [ ])
{
  byte indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  
  for (indice = 0; indice < 255; indice++)
    printf ("%03d\t%02X\t%c\n", indice, indice, indice);
  printf ("%03d\t%02X\t%c\n", indice, indice, indice);

  return OK;
}

/* $RCSfile$ */
