/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/10 16:03:43 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2019/04/10 16:03:43  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0301.h"





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  unsigned short indiceArgumento, indiceCaractere;
  ull numero1, numero2, resultado;
  char *validacao;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-inteiro-nao negativo> <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de hifen no primeiro caractere dos argumentos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumentos passados ao programa (Erro #2). */

  for (indiceArgumento = 1; indiceArgumento < NUMERO_DE_ARGUMENTOS; indiceArgumento++)
    if (*(*(argv + indiceArgumento) + 0) == '-')
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%i (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '-'.\n");
      printf("Uso: %s <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */






  /* Conversao do primeiro argumento passado ao programa em inteiro sem sinal. */

  numero1 = strtoul(*(argv + 1), &validacao, 10);    





  /* Verificacao da existencia de demais caracteres invalidos no primeiro argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no primeiro argumento passado ao programa (Erro #2). */

  for (indiceCaractere = 0; *(*(argv + 1) + indiceCaractere) != EOS; indiceCaractere++)
    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #1 (%s).\n", *(argv + 1));
      printf("Caractere invalido: '%c'.\n", *validacao);
      printf("Uso: %s <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Conversao do segundo argumento passado ao programa em inteiro sem sinal. */

  numero2 = strtoul(*(argv + 2), &validacao, 10);    





  /* Verificacao da existencia de demais caracteres invalidos no segundo argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no segundo argumento passado ao programa (Erro #2). */

  for (indiceCaractere = 0; *(*(argv + 2) + indiceCaractere) != EOS; indiceCaractere++)
    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #2 (%s).\n", *(argv + 2));
      printf("Caractere invalido: '%c'.\n", *validacao);
      printf("Uso: %s <numero-inteiro-nao-negativo> <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Chamada da funcao CalcularMaximoDivisorComum. */

  resultado = CalcularMaximoDivisorComum(numero1, numero2);





  /* Exibicao do resultado na tela. */

  printf("\n\n\nMDC(%llu, %llu) = %llu\n\n\n\n", numero1, numero2, resultado); 





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0302.c,v $ */
