/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/05 01:58:15 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2019/04/05 01:58:15  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0201.h"





/* Implementacao da funcao CalcularTermoSerieFibonacci utilizando recursividade. */

unsigned long long
CalcularTermoSerieFibonacci(unsigned short termo)
{

  if (termo == 0)
    return 0;


  if (termo == 1)
    return 1;


  return (CalcularTermoSerieFibonacci(termo - 1) +
          CalcularTermoSerieFibonacci(termo - 2));

} /* CalcularTermoSerieFibonacci */










/* $RCSfile: aula0201a.c,v $ */
