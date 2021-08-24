/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo da Serie de Fibonacci utilizando recursividade.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/30 03:49:46 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2019/08/30 03:49:46  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0301.h"





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










/* $RCSfile: aula0301a.c,v $ */
