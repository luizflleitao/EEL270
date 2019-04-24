/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 07:25:01 $
 * $Log: aula0501d.c,v $
 * Revision 1.1  2019/04/24 07:25:01  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas personalizadas para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao */
/* while e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  float resultado = 0;


  while (termos > 0)
  {
    if ((termos % 2) == 0)
      resultado = (resultado - (1.0 / CalcularExponencial(termos, termos)));
    else
      resultado = (resultado + (1.0 / CalcularExponencial(termos, termos)));

    --termos;
  } /* while */


  return resultado;

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501d.c,v $ */
