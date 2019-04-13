/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/10 16:32:37 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2019/04/10 16:32:37  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0301.h"





/* Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao for. */

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{

  ull numeroAuxiliar1, numeroAuxiliar2;
  ull indice; 


  if (numero2 > numero1)
  {
    numeroAuxiliar1 = numero1;
    numero1 = numero2;
    numero2 = numeroAuxiliar1; 
  } /* if */


  if ((numero1 == 0) && (numero2 == 0))
    return 0;


  if (numero2 == 0)
    return numero1;


  for (indice = 1; ((indice <= numero1) && (indice <= numero2)); indice++)
    if ((numero1 % indice == 0) && (numero2 % indice == 0))
      numeroAuxiliar2 = indice;


  return numeroAuxiliar2; 

} /* CalcularMaximoDivisorComum */










/* $RCSfile: aula0301c.c,v $ */
