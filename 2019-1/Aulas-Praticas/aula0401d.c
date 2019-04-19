/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/19 02:40:32 $
 * $Log: aula0401d.c,v $
 * Revision 1.1  2019/04/19 02:40:32  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0401.h"





/* Implementacao da funcao CalcularExponencial utilizando o laco de repeticao while. */

ld
CalcularExponencial(double base, int expoente)
{

  ld resultado = 1;


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
