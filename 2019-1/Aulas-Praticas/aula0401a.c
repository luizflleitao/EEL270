/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/16 14:22:09 $
 * $Log: aula0401a.c,v $
 * Revision 1.1  2019/04/16 14:22:09  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0401.h"





/* Implementacao da funcao CalcularExponencial utilizando recursividade. */

ld
CalcularExponencial(double base, int expoente)
{

  if (expoente == 0)
    return 1;


  if (expoente < 0)
    return ((1 / base) * CalcularExponencial((1 / base), (expoente * (-1) - 1)));


  return (base * CalcularExponencial(base, (expoente - 1))); 

} /* CalcularExponencial */










/* $RCSfile: aula0401a.c,v $ */
