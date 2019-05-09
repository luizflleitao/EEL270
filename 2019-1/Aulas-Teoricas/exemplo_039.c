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
#include <time.h>

#include "exemplo_039.h"

tipoErros
GerarIdentificador (byte *identificador)
{
  unsigned indice;
  unsigned soma;
  
  if (identificador == NULL) /* if (!identificador) */
    return argumentoEntradaNull;

  srand ((unsigned) time (NULL));
  for (soma = indice = 0; indice < (COMPRIMENTO_IDENTIFICADOR - 1); indice++)
  {
    identificador [indice] = rand () % (COMPRIMENTO_IDENTIFICADOR - 1);
    soma += identificador [indice] * (COMPRIMENTO_IDENTIFICADOR - 1 - indice);
  }
  
  identificador [indice] = soma % (COMPRIMENTO_IDENTIFICADOR - 1);
  return ok;
}
