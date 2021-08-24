/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo da Serie Harmonica Alternada utilizando o laco de repeticao for e a funcao CalcularExponencial.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/10 17:48:43 $
 * $Log: aula0501c.c,v $
 * Revision 1.1  2019/09/10 17:48:43  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho personalizados para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao
   for e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  float resultado = 0;


  if (termos == 0)
    return 0;


  for (; termos > 0; termos--)
  {
    if ((termos % 2) == 0)
      resultado -= 1.0 / CalcularExponencial(termos, termos);
    else
      resultado += 1.0 / CalcularExponencial(termos, termos);
  } /* for */


  return resultado; 

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501c.c,v $ */
