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

#define OK			0

int
main (int argc, char *argv [ ])
{
  unsigned long long resultado = 1;
  unsigned short numero;

  numero = atoi (argv [1]);
  for (; numero > 1; --numero)
    resultado = resultado * numero; /* resultado *= numero */

  printf ("\n%s!: %llu\n\n", argv [1], resultado);
  
  return OK;
}

/* $RCSfile$ */
