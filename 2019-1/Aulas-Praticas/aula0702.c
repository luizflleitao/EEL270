/*
 * Universidade Federal do Rio de Janeiro 
 * Escola Politecnica 
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/12 01:27:36 $
 * $Log: aula0702.c,v $
 * Revision 1.1  2019/05/12 01:27:36  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0701.h"





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  ush linhas, colunas, indice = 1;
  float matriz1[LINHAS_1][COLUNAS_1];
  float matriz2[LINHAS_2][COLUNAS_2];
  float matrizResultado[LINHAS_1][COLUNAS_2];
  char *validacao;





  /* Verificacao do numero de argumentos passados pelo usuario ao programa. */
  /* Informacao do erro relativo ao numero de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);

    printf("Uso: %s <a11> <a12> ... <a%i%i> <a%i%i> <b11> <b12> ... <b%i%i> <b%i%i>\n\n\n\n",
           *argv, LINHAS_1, (COLUNAS_1 - 1), LINHAS_1, COLUNAS_1, LINHAS_2,
           (COLUNAS_2 - 1), LINHAS_2, COLUNAS_2);

    exit(NUMERO_DE_ARGUMENTOS_INVALIDO); /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de argumento(s) com caractere(s) invalido(s) nos argumentos referentes */
  /* aos elementos da primeira matriz (Erro #2). */

  for (linhas = 0; linhas < LINHAS_1; linhas++)  
    for (colunas = 0; colunas < COLUNAS_1; colunas++)
    {

      matriz1[linhas][colunas] = strtof(argv[indice++], &validacao);

      if (*validacao != EOS)
      {
        printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
        printf("Primeira ocorrencia: <a%u%u> = %s\n", (linhas + 1), (colunas + 1), argv[indice - 1]);
        printf("Caractere invalido: '%c'\n", *validacao);

        printf("Uso: %s <a11> <a12> ... <a%i%i> <a%i%i> <b11> <b12> ... <b%i%i> <b%i%i>\n\n\n\n",
               *argv, LINHAS_1, (COLUNAS_1 - 1), LINHAS_1, COLUNAS_1, LINHAS_2,
               (COLUNAS_2 - 1), LINHAS_2, COLUNAS_2);

        exit(ARGUMENTO_INVALIDO); /* Programa abortado. */
      } /* if */ 

    } /* for */





  /* Verificacao da existencia de argumento(s) com caractere(s) invalido(s) nos argumentos referentes */
  /* aos elementos da segunda matriz (Erro #2). */

  for (linhas = 0; linhas < LINHAS_2; linhas++)  
    for (colunas = 0; colunas < COLUNAS_2; colunas++)
    {

      matriz2[linhas][colunas] = strtof(argv[indice++], &validacao);

      if (*validacao != EOS)
      {
        printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
        printf("Primeira ocorrencia: <b%u%u> = %s\n", (linhas + 1), (colunas + 1), argv[indice - 1]);
        printf("Caractere invalido: '%c'\n", *validacao);

        printf("Uso: %s <a11> <a12> ... <a%i%i> <a%i%i> <b11> <b12> ... <b%i%i> <b%i%i>\n\n\n\n",
               *argv, LINHAS_1, (COLUNAS_1 - 1), LINHAS_1, COLUNAS_1, LINHAS_2,
               (COLUNAS_2 - 1), LINHAS_2, COLUNAS_2);

        exit(ARGUMENTO_INVALIDO); /* Programa abortado. */
      } /* if */

    } /* for */





  /* Chamada da funcao MostrarMatriz1. */

  MostrarMatriz1(matriz1);





  /* Chamada da funcao MostrarMatriz2. */

  MostrarMatriz2(matriz2);  





  /* Chamada da funcao MultiplicarMatrizes. */

  MultiplicarMatrizes(matriz1, matriz2, matrizResultado);





  /* Chamada da funcao MostrarMatrizResultado. */

  MostrarMatrizResultado(matrizResultado); 





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0702.c,v $ */
