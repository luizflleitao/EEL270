/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes da funcao ValidarPisPasep.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/09/29 23:27:41 $
 * $Log: aula0603b.c,v $
 * Revision 1.2  2019/09/29 23:27:41  luiz.leitao
 * Alteracoes adicionais no arquivo.
 *
 * Revision 1.1  2019/09/20 03:06:11  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0601.h"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS				2





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  byte pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN];
  ush indiceDigito;
  tipoErros resultado;





  /* Verificacao da quantidade de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de caracteres invalidos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Caractere invalido: '-'.\n");
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao do comprimento do argumento passado ao programa. */
  /* Informacao do comprimento invalido do argumento passado ao programa (Erro #4). */

  if (strlen(*(argv + 1)) != PIS_PASEP_COM_DIGITO_VERIFICADOR_COM_HIFEN)
  {
    printf("\n\n\nErro #%i: comprimento do argumento invalido.\n", COMPRIMENTO_INVALIDO);
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
    exit(COMPRIMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de caracteres invalidos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    if (((*(*(argv + 1) + indiceDigito) < '0') || (*(*(argv + 1) + indiceDigito) > '9')))
    {
      printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Caractere invalido: '%c'.\n", *(*(argv + 1) + indiceDigito));
      printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Verificacao da existencia de caracteres invalidos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

  for (indiceDigito = 11; *(*(argv + 1) + indiceDigito) != EOS; indiceDigito++)
    if ((*(*(argv + 1) + indiceDigito) < '0') || (*(*(argv + 1) + indiceDigito) > '9'))
    {
      printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Caractere invalido: '%c'.\n", *(*(argv + 1) + indiceDigito));
      printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */





  /* Verificacao da existencia do hifen antes do digito verificador. */
  /* Informacao da ausencia do hifen antes do digito verificador (Erro #5). */

  if (*(*(argv + 1) + 10) != '-')
  {
    printf("\n\n\nErro #%i: ausencia do hifen antes do digito verificador.\n", AUSENCIA_DO_HIFEN);
    printf("Caractere invalido: '%c'.\n", *(*(argv + 1) + 10));
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
    exit(AUSENCIA_DO_HIFEN);  /* Programa abortado. */
  } /* if */





  /* Conversao digito a digito do argumento (ate antes do hifen) passado ao programa
     em inteiro sem sinal. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    pisPasep[indiceDigito] = (byte) (*(*(argv + 1) + indiceDigito) - '0');





  /* Conversao do digito verificador em inteiro sem sinal. */

  pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1] =
  (byte) (*(*(argv + 1) + (PIS_PASEP_COM_DIGITO_VERIFICADOR_COM_HIFEN - 1)) - '0');





  /* Chamada da funcao ValidarPisPasep. */

  resultado = ValidarPisPasep(pisPasep);





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento nulo passado ao programa. (Erro #6) */

  if (resultado == argumentoNulo)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10-dv>\n\n\n\n", *argv);
    exit(ARGUMENTO_NULO);
  } /* if */





  /* Exibicao do resultado na tela. */

  if (resultado == valido)
    printf("\n\n\nPisPasep Valido\n\n\n\n");
  else
    printf("\n\n\nPisPasep Invalido\n\n\n\n");





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0603b.c,v $ */
