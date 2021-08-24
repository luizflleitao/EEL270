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

#define OK			0

int
main (int argc, char *argv [ ])
{
  unsigned indice;

  for (indice = 0; indice < argc; indice++) /* indice++ ou ++indice */
    printf ("ARG (#%u): \"%s\"\n", indice, argv [indice]);   

  return OK;
}

/* $RCSfile$ */
