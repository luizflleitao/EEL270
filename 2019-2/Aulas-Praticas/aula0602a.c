/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes da funcao GerarDigitoVerificadorPisPasep.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/29 23:20:54 $
 * $Log: aula0602a.c,v $
 * Revision 1.2  2019/09/29 23:20:54  luiz.leitao
 * Alteracoes adicionais no arquivo.
 *
 * Revision 1.1  2019/09/17 17:07:19  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0601.h"





/* Definicao da macro. */

#define NUMERO_DE_ARGUMENTOS				11





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  byte pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN];
  char *validacao;
  ush  indiceArgumento;
  tipoErros resultado;
  ull valor;





  /* Verificacao da quantidade de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Varredura dos argumentos passados ao programa. */

  for (indiceArgumento = 1; indiceArgumento <= PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceArgumento++)
  {

    /* Verificacao da existencia de caracteres invalidos passados ao programa. */
    /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

    if (*(*(argv + indiceArgumento) + 0) == '-')
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%hu (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '-'.\n");
      printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





    /* Conversao dos argumentos passados ao programa em inteiros sem sinal. */

    valor = strtoull(*(argv + indiceArgumento), &validacao, 10);





    /* Verificacao da existencia de caracteres invalidos passados ao programa. */
    /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%hu (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '%c'.\n", *validacao);
      printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





    /* Verificacao da existencia de digitos invalidos com dois ou mais algarismos. */
    /* Informacao da existencia de argumentos com dois ou mais digitos passados ao programa (Erro #3). */

    if (valor > 255)
    {
      printf("\n\n\nErro #%i: impossivel passar argumentos com dois ou mais digitos.\n", DIGITO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%hu (%llu).\n", indiceArgumento, valor);
      printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
      exit(DIGITO_INVALIDO);  /* Programa abortado. */
    } /* if */



    
    /* Vetor pisPasep recebe o digito passado na linha de comando convertido para inteiro. */

    pisPasep[indiceArgumento - 1] = (byte) valor;

  } /* for */





  /* Chamada da funcao GerarDigitoVerificadorPisPasep. */

  resultado = GerarDigitoVerificadorPisPasep(pisPasep); 





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento nulo passado ao programa. (Erro #6) */

  if (resultado == argumentoNulo)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
    printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
    exit(ARGUMENTO_NULO);
  } /* if */





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumentos com dois ou mais digitos passados ao programa (Erro #3). */

  if (resultado == digitoInvalido)
    for (indiceArgumento = 1; indiceArgumento <= PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceArgumento++)
    {

      valor = strtoull(*(argv + indiceArgumento), &validacao, 10);

      if (valor > 9)
      {
        printf("\n\n\nErro #%i: impossivel passar argumentos com dois ou mais digitos.\n", DIGITO_INVALIDO);
        printf("Primeira ocorrencia: argumento #%hu (%llu).\n", indiceArgumento, valor);
        printf("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <d9> <d10>\n\n\n\n", *argv);
        exit(DIGITO_INVALIDO); /* Programa abortado. */
      } /* if */

    } /* for */





  /* Exibicao do resultado na tela. */

  printf("\n\n\nDigito Verificador: %hhu\n\n\n\n", pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1]);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0602a.c,v $ */
