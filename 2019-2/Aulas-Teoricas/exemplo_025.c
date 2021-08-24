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

#define NUMERO_ARGUMENTOS 		2

/* #define BYTE unsigned char */

typedef unsigned char byte;


int
main (int argc, char *argv [ ])
{
  byte indice;
  byte limiteSuperior;
  float valor = 0;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <limite-superior (inteiro positivo)>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  
  if (argv [1][0] == '-')
  {
    printf ("Argumento contem caractere invalido.\n");
    printf ("Primeiro caractere invalido: \'-\'\n");
    exit (ARGUMENTO_INVALIDO);
  }

  limiteSuperior = (byte) strtoul (argv [1], &validacao, 10);
  if (*validacao != '\0')
  {
    printf ("Argumento contem caractere invalido.\n");
    printf ("Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }

  for (indice = 1; indice <= limiteSuperior; indice++)
  {
    if ((indice % 2) == 0) /* if (!(indice % 2)) */
      valor -= 1 / (float) indice;
    else
      valor += 1 / (float) indice;
    printf ("S(%u): %f\n", indice, valor);
  }

  return OK;
}

/* $RCSfile$ */
