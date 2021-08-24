/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/30 03:50:30 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2019/08/30 03:50:30  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0301.h"





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










/* $RCSfile: aula0302.c,v $ */
