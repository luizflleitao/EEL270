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

#include "exemplo_051.h"

tipoErros
CopiarStrings (char *destino, char *origem)
{
  unsigned indice = 0;

  if (!destino)
    return primeiroArgumentoInvalido;

  if (!origem)
    return segundoArgumentoInvalido;

  while (origem [indice] != '\0')
  {
    destino [indice] = origem [indice];
    indice++;
  }
  destino [indice] = '\0';
 
  return ok;
}

/* $RCSfile$ */
