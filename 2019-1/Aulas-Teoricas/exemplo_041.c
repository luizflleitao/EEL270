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

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "exemplo_041.h"

tipoErros
GerarIdentificador (char *identificador)
{
  unsigned indice;
  unsigned soma;
  unsigned auxiliar;
  char *digitosHexadecimais = "0123456789ABCDEF";
  
  if (identificador == NULL) /* if (!identificador) */
    return argumentoEntradaNull;

  srand ((unsigned) time (NULL));
  for (soma = indice = 0; indice < (COMPRIMENTO_IDENTIFICADOR - 1); indice++)
  {
    auxiliar = rand () % strlen (digitosHexadecimais);
    soma += auxiliar * (COMPRIMENTO_IDENTIFICADOR - 1 - indice);
    identificador [indice] = digitosHexadecimais [auxiliar];
  }
  
  identificador [indice] = 
    digitosHexadecimais [soma % (COMPRIMENTO_IDENTIFICADOR - 1)];
  indice++;
  identificador [indice] = '\0';
  return ok;
}
