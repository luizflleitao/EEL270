/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 06:42:25 $
 * $Log: aula0501a.c,v $
 * Revision 1.1  2019/04/24 06:42:25  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas personalizadas para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando recursividade */
/* e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  if (termos == 0)
    return 0;


  if ((termos % 2) == 0)
    return ((float) (((-1.0) / CalcularExponencial(termos, termos)) +
             CalcularSerieHarmonicaAlternada(termos - 1)));


  return ((float) ((1.0 / CalcularExponencial(termos, termos)) +
             CalcularSerieHarmonicaAlternada(termos - 1)));

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501a.c,v $ */
