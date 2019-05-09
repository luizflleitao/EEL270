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

#include <string.h>
#include "exemplo_028.h"

boolean
ValidarDre (char dre [COMPRIMENTO_DRE + 1])
{
  unsigned short soma;
  unsigned char indice;

  if (!dre)
    return falso;

  if (strlen (dre) != COMPRIMENTO_DRE)
    return falso;

  for (soma = indice = 0; 
       indice < (COMPRIMENTO_DRE - 1); 
       indice++)
  {
    if (dre [indice] < '0' || dre [indice] > '9')
      return falso;

    soma += (dre [indice] - '0') * (indice + 1);
  }

  if ((soma % 10) != (dre [indice] - '0'))
    return falso;

  return verdadeiro;
}
