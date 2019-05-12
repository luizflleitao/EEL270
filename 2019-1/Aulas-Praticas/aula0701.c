/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/12 01:27:31 $
 * $Log: aula0701.c,v $
 * Revision 1.1  2019/05/12 01:27:31  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca padrao da linguagem. */

#include <stdio.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0701.h"





/* Implementacao da funcao MultiplicarMatrizes. */

tipoErros
MultiplicarMatrizes(float matriz1[LINHAS_1][COLUNAS_1], 
                    float matriz2[LINHAS_2][COLUNAS_2], 
                    float matrizResultado[LINHAS_1][COLUNAS_2])
{

  ush contadorLinhas1, contadorColunas2, contadorAuxiliar;  


  for (contadorLinhas1 = 0; contadorLinhas1 < LINHAS_1; contadorLinhas1++)
    for (contadorColunas2 = 0; contadorColunas2 < COLUNAS_2; contadorColunas2++)
    {

      matrizResultado[contadorLinhas1][contadorColunas2] = 0;

      for (contadorAuxiliar = 0; contadorAuxiliar < COLUNAS_1; contadorAuxiliar++)
        matrizResultado[contadorLinhas1][contadorColunas2] = 
        matrizResultado[contadorLinhas1][contadorColunas2] + 
        matriz1[contadorLinhas1][contadorAuxiliar] *
        matriz2[contadorAuxiliar][contadorColunas2];
 
    } /* for */


    return ok;  /* 0 */
} /* MultiplicarMatrizes */










/* Implementacao da funcao MostrarMatriz1. */

void
MostrarMatriz1(float matriz1[LINHAS_1][COLUNAS_1])
{

  ush linhas, colunas;


  printf("\n\n\n"); 


  for (linhas = 0; linhas < LINHAS_1; linhas++)
  {
    for (colunas = 0; colunas < COLUNAS_1; colunas++)
      printf("%0.3f ", matriz1[linhas][colunas]);

    printf("\n");
  } /* for */

} /* MostrarMatriz1 */










/* Implementacao da funcao MostrarMatriz2. */

void
MostrarMatriz2(float matriz2[LINHAS_2][COLUNAS_2])
{

  ush linhas, colunas;


  printf("\n");
  

  for (linhas = 0; linhas < LINHAS_2; linhas++)
  {
    for (colunas = 0; colunas < COLUNAS_2; colunas++)
      printf("%0.3f ", matriz2[linhas][colunas]);

    printf("\n");
  } /* for */

} /* MostrarMatriz2 */










/* Implementacao da funcao MostrarMatrizResultado. */

void
MostrarMatrizResultado(float matrizResultado[LINHAS_1][COLUNAS_2])
{

  ush linhas, colunas;


  printf("\n");


  for (linhas = 0; linhas < LINHAS_1; linhas++)
  {
    for (colunas = 0; colunas < COLUNAS_2; colunas++)
      printf("%0.3f ", matrizResultado[linhas][colunas]);

    printf("\n");
  } /* for */


  printf("\n\n\n");

} /* MostrarMatrizResultado */










/* $RCSfile: aula0701.c,v $ */
