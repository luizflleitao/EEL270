/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo da Serie de Fibonacci utilizando o laco de repeticao while.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/30 04:56:21 $
 * $Log: aula0301d.c,v $
 * Revision 1.1  2019/08/30 04:56:21  luiz.leitao
 * Initial revision
 *
 */










/* Implementacao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0301.h"





/* Implementacao da funcao CalcularTermoSerieFibonacci utilizando o laco de repeticao while. */

unsigned long long
CalcularTermoSerieFibonacci(unsigned short termo)
{

  unsigned long long numeroAuxiliar1, numeroAuxiliar2;
  unsigned short resultado;


  numeroAuxiliar2 = 1;
  resultado = 0;


  if (termo == 0)
    return 0;


  if (termo == 1)
    return 1;


  while (termo > 0)
  {
    numeroAuxiliar1 = resultado + numeroAuxiliar2;
    resultado = numeroAuxiliar2;
    numeroAuxiliar2 = numeroAuxiliar1;
    termo--;
  } /* while */


  return resultado;

} /* CalcularTermoSerieFibonacci */










/* $RCSfile: aula0301d.c,v $ */
