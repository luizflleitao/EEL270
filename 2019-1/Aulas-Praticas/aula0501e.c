/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 07:41:51 $
 * $Log: aula0501e.c,v $
 * Revision 1.1  2019/04/24 07:41:51  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca padrao da linguagem. */

#include <math.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando recursividade */
/* e a funcao pow. */

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
