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

#include "exemplo_016.h"

ULL
CalcularFatorial (US numero)
{
  ULL resultado = 1;

  if (numero <= 1)
    return 1;

  do
  {
    resultado *= numero;
    numero--;
  }
  while (numero > 1);

  return resultado;
}

/* $RCSfile$ */
