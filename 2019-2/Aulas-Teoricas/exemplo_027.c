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

#define NUMERO_ARGUMENTOS		3

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2	

#define EOS				'\0'

void
TrocarValores (int *, int *);

void
TrocarValores (int *valorA, int *valorB)
{
  #define FUNCIONA

  int auxiliar;

  #ifdef _MY_DEBUG_
  printf ("Dentro da Função - Antes da Troca\n");
  printf ("&auxiliar: %p\n", &auxiliar);
  printf ("auxiliar: %i\n", auxiliar);
  printf ("ValorA: %p\n", valorA);
  printf ("&ValorA: %p\n", &valorA);
  printf ("*ValorA: %i\n", *valorA);
  printf ("ValorB: %p\n", valorB);
  printf ("&ValorB: %p\n", &valorB);
  printf ("*ValorB: %i\n", *valorB);
  #endif

  auxiliar = *valorA;
  *valorA = *valorB;
  *valorB = auxiliar;

  #ifdef _MY_DEBUG_
  printf ("Dentro da Função - Depois da Troca\n");
  printf ("&auxiliar: %p\n", &auxiliar);
  printf ("auxiliar: %i\n", auxiliar);
  printf ("ValorA: %p\n", valorA);
  printf ("&ValorA: %p\n", &valorA);
  printf ("*ValorA: %i\n", *valorA);
  printf ("ValorB: %p\n", valorB);
  printf ("&ValorB: %p\n", &valorB);
  printf ("*ValorB: %i\n", *valorB);
  #endif

}

int
main (int argc, char *argv []) 
{

  int valorA, valorB;
  char *validacao;

  #ifdef _MY_DEBUG_
  printf ("ValorA: %i\n", valorA);
  printf ("ValorB: %i\n", valorB);
  #endif

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro> <inteiro>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  valorA = (int) strtol (argv [1], &validacao, 10);
  if (*validacao != EOS)
  {
    printf ("Argumento inválido. Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }
  
  valorB = (int) strtol (argv [2], &validacao, 10);
  if (*validacao != EOS)
  {
    printf ("Argumento inválido. Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }
  
  printf ("Antes da Função\n");
  printf ("ValorA: %i\n", valorA);
  #ifdef _MY_DEBUG_
  printf ("&ValorA: %p\n", &valorA);
  #endif
  printf ("ValorB: %i\n", valorB);
  #ifdef _MY_DEBUG_
  printf ("&ValorB: %p\n", &valorB);
  #endif

  TrocarValores (&valorA, &valorB);

  printf ("Depois da Função\n");
  printf ("ValorA: %i\n", valorA);
  #ifdef _MY_DEBUG_
  printf ("&ValorA: %p\n", &valorA);
  #endif
  printf ("ValorB: %i\n", valorB);
  #ifdef _MY_DEBUG_
  printf ("&ValorB: %p\n", &valorB);
  #endif
  return OK;

} /* funcao principal */

