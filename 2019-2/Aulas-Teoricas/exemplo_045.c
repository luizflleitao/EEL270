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
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "exemplo_045.h"

/*
 *
 * senha (S)
 *
 */
tipoErros
GerarDreAleatorio (byte dre [COMPRIMENTO_DRE])
{
  unsigned short indice, soma;

  if (dre == NULL)
    return argumentoInvalido;

  srand ((unsigned) time (NULL));
  for (indice = soma = 0; indice < COMPRIMENTO_DRE - 1; indice++)
  {
    dre [indice] = rand () % 10;
    soma += dre [indice] * (indice + 1);
  }
  dre [indice] = soma % 10;

  return ok;
}

/* $RCSfile$ */
