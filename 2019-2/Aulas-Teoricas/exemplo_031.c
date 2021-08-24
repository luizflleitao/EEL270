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

#include "exemplo_030.h"

#define NUMERO_ARGUMENTOS		1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

int
main (int argc, char *argv []) 
{

  byte digito1 = 1;
  byte digito2 = 1;
  byte digito3 = 6;
  byte digito4 = 0;
  byte digito5 = 1;
  byte digito6 = 9;
  byte digito7 = 5;
  byte digito8 = 8;
  byte digitoVerificador = 9;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (ValidarDigitoVerificadorDre (digito1, 
                                   digito2, 
                                   digito3, 
                                   digito4, 
                                   digito5, 
                                   digito6, 
                                   digito7, 
                                   digito8, 
                                   digitoVerificador)) 
    printf ("Digito verificador valido\n");
  else
    printf ("Digito verificador invalido\n");

  return OK;

} /* funcao principal */

