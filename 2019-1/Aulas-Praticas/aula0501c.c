/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 07:10:08 $
 * $Log: aula0501c.c,v $
 * Revision 1.1  2019/04/24 07:10:08  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas personalizadas para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao */
/* for e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  float resultado = 0;


  if (termos == 0)
    return 0;


  for (; termos > 0; termos--)
  {
    if ((termos % 2) == 0)
      resultado = (resultado - (1.0 / CalcularExponencial(termos, termos)));
    else
      resultado = (resultado + (1.0 / CalcularExponencial(termos, termos)));
  } /* for */


  return resultado; 

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501c.c,v $ */
