/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de potenciacao utilizando o laco de repeticao while.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/04 12:16:16 $
 * $Log: aula0401d.c,v $
 * Revision 1.1  2019/09/04 12:16:16  luiz.leitao
 * Initial revision
 *
 */










/* Implementacao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0401.h"





/* Implementacao da funcao CalcularExponencial utilizando o laco de repeticao while. */

long double
CalcularExponencial(double base, int expoente)
{

  long double resultado = 1;


  if (expoente < 0)
  {
    base = (1 / base);
    expoente = (expoente * (-1));
  } /* if */


  while (expoente > 0)
  {
    resultado *= base;
    --expoente;
  } /* while */


  return resultado;

} /* CalcularExponencial */










/* $RCSfile: aula0401d.c,v $ */
