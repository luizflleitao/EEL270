/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes da funcao CodificarBase64.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/16 20:26:28 $
 * $Log: aula0902.c,v $
 * Revision 1.1  2019/10/16 20:26:28  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0901.h"





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  byte entrada[NUMERO_MAXIMO_DE_BYTES_DE_CODIFICACAO];
  char saida[NUMERO_MAXIMO_DE_BYTES_DE_DECODIFICACAO + 1];
  tipoErros resultado;
  ush indiceArgumento;
  char *validacao;
  unsigned numeroBytes;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if ((argc < NUMERO_MINIMO_DE_ARGUMENTOS) || (argc > NUMERO_MAXIMO_DE_ARGUMENTOS))
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
    printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
    printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de hifen no argumentos decimal passado ao programa. */
  /* Informacao da existencia de hifen no argumento decimal passado ao programa (Erro #2). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Primeira ocorrencia: argumento #1 (%s).\n", *(argv + 1));
    printf("Caractere invalido: '-'.\n");
    printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
    printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
    printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Conversao do argumento decimal passado ao programa em inteiros sem sinal. */

  numeroBytes = strtoul(*(argv + 1), &validacao, 10);





  /* Verificacao da existencia de demais caracteres invalidos no argumento decimal passado ao programa. */
  /* Informacao da existencia de caracteres invalidos no argumento decimal passado ao programa (Erro #2). */

  if (*validacao != EOS)
  {
    printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Primeira ocorrencia: argumento #1 (%s).\n", *(argv + 1));
    printf("Caractere invalido: '%c'.\n", *validacao);
    printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
    printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
    printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (numeroBytes != (argc - 2))
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
    printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
    printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */







  /* Varredura dos argumentos hexadecimais passados ao programa. */

  for (indiceArgumento = 2; indiceArgumento < argc; indiceArgumento++)
  {

    /* Verificacao da existencia de hifen nos argumentos hexadecimais passados ao programa. */
    /* Informacao da existencia de hifen nos argumentos hexadecimais passados ao programa (Erro #2). */

    if (*(*(argv + indiceArgumento) + 0) == '-')
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%u (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '-'.\n");
      printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
      printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
      printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */



    /* Conversao dos argumentos hexadecimais passados ao programa em inteiros sem sinal. */

    *(entrada + (indiceArgumento - 2)) = strtoul(*(argv + indiceArgumento), &validacao, 16);



    /* Verificacao da existencia de demais caracteres invalidos nos argumentos hexadecimais passados ao programa. */
    /* Informacao da existencia de caracteres invalidos nos argumentos hexadecimais passados ao programa (Erro #2). */

    if (*validacao != EOS)
    {
      printf("\n\n\nErro #%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%u (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '%c'.\n", *validacao);
      printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
      printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
      printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */

  } /* for */





  /* Chamada da funcao CodificarBase64. */

  resultado = CodificarBase64(entrada, numeroBytes, saida);





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento nulo passado ao programa (Erro #4). */

  if (resultado == argumentoNulo)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
    printf("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", *argv);
    printf("Aviso: o argumento referente ao numero de bytes deve estar no formato decimal; os argumentos\n");
    printf("referentes aos bytes codificados devem estar no formato hexadecimal.\n\n\n\n");
    exit(ARGUMENTO_NULO);  /* Programa abortado. */
  } /* if */





  /* Exibicao do resultado na tela. */

  printf("\n\n\nSaida:\n");
  printf("%s\n\n\n\n", saida);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0902.c,v $ */
