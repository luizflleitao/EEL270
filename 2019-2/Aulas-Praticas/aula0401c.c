/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo de potenciacao utilizando o laco de repeticao for.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/04 12:06:43 $
 * $Log: aula0401c.c,v $
 * Revision 1.1  2019/09/04 12:06:43  luiz.leitao
 * Initial revision
 *
 */










/* Implementacao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0401.h"





/* Implementacao da funcao CalcularExponencial utilizando o laco de repeticao for. */

long double
CalcularExponencial(double base, int expoente)
{

  unsigned short indice;
  long double resultado = 1;


  if (expoente == 0)
    return 1;


  if (expoente < 0)
  {
    base = (1 / base);
    expoente = (expoente * (-1));
  } /* if */


  for (indice = 0; indice < expoente; indice++)
    resultado *= base;


  return resultado;

} /* CalcularExponencial */










/* $RCSfile: aula0401c.c,v $ */