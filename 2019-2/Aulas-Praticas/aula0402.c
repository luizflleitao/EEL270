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
 * $Date: 2019/09/04 10:40:46 $
 * $Log: aula0402.c,v $
 * Revision 1.1  2019/09/04 10:40:46  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0401.h"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS					3
#define EOS							'\0'





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Variaveis locais utilizadas na funcao principal. */

  double base;
  int expoente;
  long double resultado;
  char *validacao;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-real> <numero-inteiro>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Conversao do primeiro argumento passado ao programa em real. */

  base = strtod(*(argv + 1), &validacao);





  /* Verificacao da existencia de caracteres invalidos no primeiro argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no primeiro argumento passado ao programa (Erro #2). */

  if (*validacao != EOS)
  {
    printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Primeira ocorrencia: argumento #1 (%s).\n", *(argv + 1));
    printf("Caractere invalido: '%c'.\n", *validacao);
    printf("Uso: %s <numero-real> <numero-inteiro>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Conversao do segundo argumento passado ao programa em real. */

  expoente = strtol(*(argv + 2), &validacao, 10);





  /* Verificacao da existencia de caracteres invalidos no segundo argumento passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no segundo argumento passado ao programa (Erro #2). */

  if (*validacao != EOS)
  {
    printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Primeira ocorrencia: argumento #2 (%s).\n", *(argv + 2));
    printf("Caractere invalido: '%c'.\n", *validacao);
    printf("Uso: %s <numero-real> <numero-inteiro>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Chamada da funcao CalcularExponencial. */

  resultado = CalcularExponencial(base, expoente);





  /* Exibicao do resultado na tela. */

  printf("\n\n(%.4f) ^ (%i) = %.4LF\n\n\n", base, expoente, resultado);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0402.c,v $ */
