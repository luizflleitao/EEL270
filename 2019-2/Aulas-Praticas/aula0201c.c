/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de MDC utilizando o laco de repeticao for.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/20 17:51:17 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2019/08/20 17:51:17  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0201.h"





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










/* $RCSfile: aula0201c.c,v $ */
