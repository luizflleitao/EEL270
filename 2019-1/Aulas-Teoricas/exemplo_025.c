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
#include "exemplo_025.h"

boolean
ValidarDre (byte dre [COMPRIMENTO_DRE])
{
  unsigned short soma;
  byte indice;

  if (dre == NULL)
    return falso;

  for (soma = indice = 0; 
       indice < (COMPRIMENTO_DRE - 1); 
       indice++)
  {
    if (dre [indice] > 9)
      return falso;

    soma += dre [indice] * (indice + 1);
  }

  if ((soma % 10) != dre [indice])
    return falso;

  return verdadeiro;
}
