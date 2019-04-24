/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 06:56:04 $
 * $Log: aula0501b.c,v $
 * Revision 1.1  2019/04/24 06:56:04  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas personalizadas para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao */
/* do ... while e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  float resultado = 0;


  if (termos == 0)
    return 0;


  do
  {
    if ((termos % 2) == 0)
      resultado = (resultado - (1.0 / CalcularExponencial(termos, termos)));
    else
      resultado = (resultado + (1.0 / CalcularExponencial(termos, termos)));

    --termos;
  }
  while (termos > 0);


  return resultado;

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501b.c,v $ */
