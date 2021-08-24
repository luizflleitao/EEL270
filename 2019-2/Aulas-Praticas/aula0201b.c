/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de MDC utilzando o laco de repeticao do ... while.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/20 17:42:13 $
 * $Log: aula0201b.c,v $
 * Revision 1.1  2019/08/20 17:42:13  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0201.h"





/* Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao do ... while. */

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{

  ull numeroAuxiliar;


  if ((numero1 == 0) && (numero2 == 0))
    return 0;  


  if (numero2 == 0)
    return numero1;


  do
  {
    numeroAuxiliar = numero1 % numero2;
    numero1 = numero2;
    numero2 = numeroAuxiliar;
  }
  while (numeroAuxiliar != 0); 


  return numero1; 

} /* CalcularMaximoDivisorComum */










/* $RCSfile: aula0201b.c,v $ */
