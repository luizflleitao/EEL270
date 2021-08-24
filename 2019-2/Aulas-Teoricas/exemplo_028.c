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
TrocarValores (int *valorA_TrocarValores, int *valorB_TrocarValores)
{
  #define FUNCIONA

  int auxiliar;

  #ifdef _MY_DEBUG_
  printf ("Dentro da Função - Antes da Troca\n");
  printf ("&auxiliar: %p\n", &auxiliar);
  printf ("auxiliar: %i\n", auxiliar);
  printf ("ValorA_TrocarValores: %p\n", valorA_TrocarValores);
  printf ("&ValorA_TrocarValores: %p\n", &valorA_TrocarValores);
  printf ("*ValorA_TrocarValores: %i\n", *valorA_TrocarValores);
  printf ("ValorB_TrocarValores: %p\n", valorB_TrocarValores);
  printf ("&ValorB_TrocarValores: %p\n", &valorB_TrocarValores);
  printf ("*ValorB_TrocarValores: %i\n", *valorB_TrocarValores);
  #endif

  auxiliar = *valorA_TrocarValores;
  *valorA_TrocarValores = *valorB_TrocarValores;
  *valorB_TrocarValores = auxiliar;

  #ifdef _MY_DEBUG_
  printf ("Dentro da Função - Depois da Troca\n");
  printf ("&auxiliar: %p\n", &auxiliar);
  printf ("auxiliar: %i\n", auxiliar);
  printf ("ValorA_TrocarValores: %p\n", valorA_TrocarValores);
  printf ("&ValorA_TrocarValores: %p\n", &valorA_TrocarValores);
  printf ("*ValorA_TrocarValores: %i\n", *valorA_TrocarValores);
  printf ("ValorB_TrocarValores: %p\n", valorB_TrocarValores);
  printf ("&ValorB_TrocarValores: %p\n", &valorB_TrocarValores);
  printf ("*ValorB_TrocarValores: %i\n", *valorB_TrocarValores);
  #endif

}

int
main (int argc, char *argv []) 
{

  int valorA_main, valorB_main;
  char *validacao;

  #ifdef _MY_DEBUG_
  printf ("ValorA_main: %i\n", valorA_main);
  printf ("ValorB_main: %i\n", valorB_main);
  #endif

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro> <inteiro>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  valorA_main = (int) strtol (argv [1], &validacao, 10);
  if (*validacao != EOS)
  {
    printf ("Argumento inválido. Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }
  
  valorB_main = (int) strtol (argv [2], &validacao, 10);
  if (*validacao != EOS)
  {
    printf ("Argumento inválido. Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }
  
  printf ("Antes da Função\n");
  printf ("ValorA_main: %i\n", valorA_main);
  #ifdef _MY_DEBUG_
  printf ("&ValorA_main: %p\n", &valorA_main);
  #endif
  printf ("ValorB_main: %i\n", valorB_main);
  #ifdef _MY_DEBUG_
  printf ("&Va�lorB_main: %p\n", &valorB_main);
  #endif

  TrocarValores (&valorA_main, &valorB_main);

  printf ("Depois da Função\n");
  printf ("ValorA_main: %i\n", valorA_main);
  #ifdef _MY_DEBUG_
  printf ("&ValorA_main: %p\n", &valorA_main);
  #endif
  printf ("ValorB_main: %i\n", valorB_main);
  #ifdef _MY_DEBUG_
  printf ("&ValorB_main: %p\n", &valorB_main);
  #endif
  return OK;

} /* funcao principal */

