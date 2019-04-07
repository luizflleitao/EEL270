/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/05 02:32:28 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2019/04/05 02:32:28  luiz.leitao
 * Initial revision
 *
 */










/* Implementacao da biblioteca personalizada para o trabalho. */

#include "aula0201.h"





/* Implementacao da funcao CalcularTermoSerieFibonacci utilizando o laco de repeticao for. */

unsigned long long
CalcularTermoSerieFibonacci(unsigned short termo)
{

  unsigned long long numeroAuxiliar1, numeroAuxiliar2;
  unsigned long long resultado;


  numeroAuxiliar2 = 1;
  resultado = 0;


  if (termo == 0)
    return 0;


  if (termo == 1)
    return 1;


  for (; termo > 0; termo--)
  {
    numeroAuxiliar1 = resultado + numeroAuxiliar2;
    resultado = numeroAuxiliar2;
    numeroAuxiliar2 = numeroAuxiliar1;
  } /* for */


  return resultado;

} /* CalcularTermoSerieFibonacci */










/* $RCSfile: aula0201c.c,v $ */
