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

#define NUMERO_ARGUMENTOS		1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

int
main (int argc, char *argv []) 
{

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  #ifdef __FreeBSD__
  printf ("FreeBSD\n");
  #endif

  #ifdef __linux__
  printf ("Linux\n");
  #endif

  #ifdef __ANDROID__
  printf ("Android\n");
  #endif

  #ifdef __CYGWIN__
  printf ("CYGWIN\n");
  #endif

  #ifdef __WINDOWS__
  printf ("Windows\n");
  #endif

  return OK;

} /* funcao principal */

