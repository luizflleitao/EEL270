/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/10 16:03:38 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2019/04/10 16:03:38  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0301.h"





/* Implementacao da funcao CalcularMaximoDivisorComum utilizando recursividade. */

ull
CalcularMaximoDivisorComum(ull numero1, ull numero2)
{  
 
  if ((numero1 == 0) && (numero2 == 0))
    return 0; 


  if (numero2 == 0)
    return numero1;


  return CalcularMaximoDivisorComum(numero2, numero1 % numero2);

} /* CalcularMaximoDivisorComum */










/* $RCSfile: aula0301a.c,v $ */
