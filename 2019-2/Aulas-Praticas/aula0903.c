/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes da funcao DecodificarBase64.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/24 04:56:15 $
 * $Log: aula0903.c,v $
 * Revision 1.1  2019/10/24 04:56:15  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao do sistema. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0901.h"





/* Definicao da macro. */

#define NUMERO_DE_ARGUMENTOS					2





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  byte saida[NUMERO_MAXIMO_DE_BYTES_DE_CODIFICACAO];
  tipoErros resultado;
  ush indiceCaractere;
  unsigned numeroBytes;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Chamada da funcao interna do sistema. */

  numeroBytes = strlen(*(argv + 1));





  /* Verificacao do comprimento do argumento passado ao programa. */
  /* Informacao do comprimento invalido do argumento passado ao programa (Erro #3). */

  if (numeroBytes > NUMERO_MAXIMO_DE_BYTES_DE_DECODIFICACAO)
  {
    printf("\n\n\nErro #%i: comprimento do argumento invalido.\n", COMPRIMENTO_INVALIDO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(COMPRIMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Chamada da funcao DecodificarBase64. */

  resultado = DecodificarBase64(*(argv + 1), saida, &numeroBytes);





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao do comprimento invalido do argumento passado ao programa (Erro #3). */

  if (resultado == comprimentoInvalido)
  {
    printf("\n\n\nErro #%i: comprimento do argumento invalido.\n", COMPRIMENTO_INVALIDO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(COMPRIMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento nulo passado ao programa (Erro #4). */

  if (resultado == argumentoNulo)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(ARGUMENTO_NULO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento vazio passado ao programa (Erro #5). */

  if (resultado == argumentoVazio)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento vazio.\n", ARGUMENTO_VAZIO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(ARGUMENTO_VAZIO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de caractere invalido passado ao programa (Erro #6). */

  if (resultado == caractereInvalido)
  {
    printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", CARACTERE_INVALIDO);
    printf("Uso: %s <string-codificada-base64>\n\n\n\n", *argv);
    exit(CARACTERE_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Exibicao do resultado na tela. */

  printf("\n\n\nSaida:\n");

  for (indiceCaractere = 0; indiceCaractere < numeroBytes; indiceCaractere++)
    printf("%X ", *(saida + indiceCaractere));

  printf("\n\n\n\n");





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0903.c,v $ */
