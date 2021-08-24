/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do algoritmo da Serie Harmonica Alternada utilizando o laco de repeticao while e a funcao CalcularExponencial.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/12 12:49:56 $
 * $Log: aula0501d.c,v $
 * Revision 1.1  2019/09/12 12:49:56  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho personalizados para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao
   while e a funcao CalcularExponencial. */

float
CalcularSerieHarmonicaAlternada(ul termos)
{

  float resultado = 0;


  while (termos > 0)
  {
    if ((termos % 2) == 0)
      resultado -= 1.0 / CalcularExponencial(termos, termos);
    else
      resultado += 1.0 / CalcularExponencial(termos, termos);

    --termos;
  } /* while */


  return resultado;

} /* CalcularSerieHarmonicaAlternada */










/* $RCSfile: aula0501d.c,v $ */
