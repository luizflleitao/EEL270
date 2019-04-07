/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/05 01:58:21 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2019/04/05 01:58:21  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0201.h"





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  unsigned short indice, termo;
  unsigned long long resultado;
  char *validacao;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-inteiro-nao negativo>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Conversao do argumento passado ao programa em inteiro sem sinal. */

  termo = (unsigned short) strtoul(*(argv + 1), &validacao, 10);





  /* Verificacao da existencia de hifen no primeiro caractere do argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumento passado ao programa (Erro #2). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Caractere invalido: '-' .\n");
    printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de demais caracteres invalidos no argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumento passado ao programa (Erro #2). */

  for (indice = 0; *(*(argv + 1) + indice) != EOS; indice++)
    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Caractere invalido: '%c' .\n", *validacao);
      printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Chamada da funcao CalcularTermoSerieFibonacci. */
  /* Exibicao do resultado na tela. */

  printf("\n\n\n");

  for (indice = 0; indice <= termo; indice++)
  {
    resultado = CalcularTermoSerieFibonacci(indice);
    printf("F(%hu) = %llu\n", indice, resultado);
  }

  printf("\n\n\n");





  return OK;  /* Codigo retornado com sucesso. */

} /* main */



/* $RCSfile: aula0202.c,v $ */
