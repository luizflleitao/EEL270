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
  unsigned char indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  for (indice = 0; indice < 20; indice++)
    printf ("%i \n", rand ());

  return OK;

} /* funcao principal */
