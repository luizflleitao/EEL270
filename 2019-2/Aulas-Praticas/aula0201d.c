/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de MDC utilizando o laco de repeticao while.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/20 17:58:24 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2019/08/20 17:58:24  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0201.h"





/* Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao while. */

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{

  ull numeroAuxiliar = 0;


  if ((numero1 == 0) && (numero2 == 0))
    return 0;


  if (numero2 == 0)
    return numero1;


  while (numeroAuxiliar != 0) 
  {
    numeroAuxiliar = numero1 % numero2;
    numero1 = numero2;
    numero2 = numeroAuxiliar;
  } /* while */


  return numero1; 

} /* CalcularMaximoDivisorComum */










/* $RCSfile: aula0201d.c,v $ */
