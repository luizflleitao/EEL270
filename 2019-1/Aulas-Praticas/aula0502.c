/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/24 06:42:30 $
 * $Log: aula0502.c,v $
 * Revision 1.1  2019/04/24 06:42:30  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>





/* Inclusao das bibliotecas personalizadas para o trabalho. */

#include "aula0401.h"
#include "aula0501.h"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS				2
#define EOS						'\0'





/* Implementacao do programa de testes.*/

int
main(int argc, char *argv[])
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  ul termos;
  char *validacao;
  float resultado;
  ush indice;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Conversao do argumento passado ao programa em inteiro sem sinal */

  termos = strtoul(*(argv + 1), &validacao, 10);





  /* Verificacao da existencia de hifen no primeiro caractere do argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumento passado ao programa (Erro #2). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Caractere invalido: '-'.\n");
    printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de demais caracteres invalidos no argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumento passado ao programa (Erro #2). */

  for (indice = 0; *(*(argv + 1) + indice) != EOS; indice++)
    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Caractere invalido: '%c'.\n", *validacao);
      printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Chamada da funcao CalcularSerieHarmonicaAlternada. */

  resultado = CalcularSerieHarmonicaAlternada(termos);





  /* Exibicao do resultado na tela. */

  printf("\n\n\nS(%lu) = %.8f\n\n\n\n", termos, resultado);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0502.c,v $ */
