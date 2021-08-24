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

#include "exemplo_032.h"

boolean
ValidarDigitoVerificadorDre (byte dre [COMPRIMENTO_DRE])
{
  unsigned short soma = 0;
  byte indice;

  for (indice = 0; indice < (COMPRIMENTO_DRE - 1); indice++) 
    soma += dre [indice] * (indice + 1);

  if ((soma % 10) != dre [indice])
    return falso;

  return verdadeiro;

}

/* $RCSfile$ */
