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

#define EOS				'\0'

int
main (int argc, char *argv [ ])
{
  unsigned long long resultado = 1;
  unsigned short numero;
  unsigned indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  
  for (indice = 0; argv [1][indice] != EOS; indice++)
    if (argv [1][indice] < '0' || argv [1][indice] > '9')
    {
      printf ("Argumento invalido.\n");
      printf ("Primeiro caractere invalido: \"%c\"\n", argv [1][indice]);
      exit (ARGUMENTO_INVALIDO);
    }

  numero = atoi (argv [1]);
  for (; numero > 1; --numero)
    resultado = resultado * numero; /* resultado *= numero */

  printf ("\n%s!: %llu\n\n", argv [1], resultado);

  return OK;
}

/* $RCSfile$ */
