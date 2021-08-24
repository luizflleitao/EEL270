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

#define ULL unsigned long long
#define US unsigned short int

ULL
CalcularFatorial (US);

ULL
CalcularFatorial (US numero)
{
  if (numero <= 1)
    return 1;
  return numero * CalcularFatorial (numero - 1);
}

int
main (int argc, char *argv [ ])
{
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

  printf ("\n%s!: %llu\n\n", argv [1], 
          CalcularFatorial ((US) atoi (argv [1])));

  return OK;
}

/* $RCSfile$ */
