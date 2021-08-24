/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de MDC utilizando recursividade.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/20 17:25:22 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2019/08/20 17:25:22  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0201.h"





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










/* $RCSfile: aula0201a.c,v $ */