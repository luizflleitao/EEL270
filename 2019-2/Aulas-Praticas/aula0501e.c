/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo da Serie Harmonica Alternada utilizando recursividade e a funcao pow.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/12 13:05:27 $
 * $Log: aula0501e.c,v $
 * Revision 1.1  2019/09/12 13:05:27  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho da biblioteca padrao da linguagem. */

#include <math.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando recursividade
   e a funcao pow. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  if (termos == 0)
    return 0;


  if ((termos % 2) == 0)
    return ((float) (((-1.0) / pow(termos, termos)) +
	     CalcularSerieHarmonicaAlternada(termos - 1)));


  return ((float) ((1.0 / pow(termos, termos)) +
	   CalcularSerieHarmonicaAlternada(termos - 1)));

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501e.c,v $ */
