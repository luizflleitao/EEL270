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
 */
#ifdef _MY_DEBUG_
#include <stdio.h>
#endif

#include "exemplo_015.h"

unsigned long long
CalcularFatorial (unsigned numero)
{

  #ifdef _MY_DEBUG_
  printf ("Implementacao utilizando recursividade \n");
  #endif

  if (numero <= 1)
    return 1;

  return numero * CalcularFatorial (numero - 1);
}

