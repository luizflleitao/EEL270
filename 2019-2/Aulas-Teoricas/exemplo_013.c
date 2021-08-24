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


#define NUMERO_ARGUMENTOS 		2

int
main (int argc, char *argv [ ])
{
  unsigned long long resultado = 1;
  unsigned short numero;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  
  numero = atoi (argv [1]);
  for (; numero > 1; --numero)
    resultado = resultado * numero; /* resultado *= numero */

  printf ("\n%s!: %llu\n\n", argv [1], resultado);

  return OK;
}

/* $RCSfile$ */
