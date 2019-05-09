/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/09 18:19:27 $
 * $Log: aula0605b.c,v $
 * Revision 1.1  2019/05/09 18:19:27  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0604.h"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS				2
#define EOS						'\0'





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  char pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN + 1];
  char digitoVerificador[DIGITO_VERIFICADOR + 1];
  ush indiceDigito;





  /* Verificacao da quantidade de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de caracteres invalidos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
    printf("Caractere invalido: '-'.\n");
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Informacao do comprimento invalido do argumento passado ao programa (Erro #4). */

  if (strlen(*(argv + 1)) != PIS_PASEP_SEM_DIGITO_VERIFICADOR)
  {
    printf("\n\n\nErro #%i: comprimento do argumento invalido.\n", COMPRIMENTO_INVALIDO);
    printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10>\n\n\n\n", *argv);
    exit(COMPRIMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de caracteres invalidos passados ao programa. */
  /* Informacao da existencia de caracteres invalidos passados ao programa (Erro #2). */

  for (indiceDigito = 0; *(*(argv + 1) + indiceDigito) != EOS; indiceDigito++)
    if (((*(*(argv + 1) + indiceDigito) < '0') || (*(*(argv + 1) + indiceDigito) > '9')))
    {
      printf("\n\n\nErro #%i: o argumento contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Caractere invalido: '%c'.\n", *(*(argv + 1) + indiceDigito));
      printf("Uso: %s <d1d2d3d4d5d6d7d8d9d10>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */ 





  /* Conversao digito a digito do argumento passado ao programa em inteiros sem sinal. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
   pisPasep[indiceDigito] = (char) (*(*(argv + 1) + indiceDigito) - '0');





  /* Chamada da funcao GerarDigitoVerificadorPisPasep. */

  GerarDigitoVerificadorPisPasep(pisPasep, digitoVerificador);





  /* Exibicao do resultado na tela. */

  printf("\n\n\nDigito verificador: %c\n\n\n\n", digitoVerificador[DIGITO_VERIFICADOR - 1]);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0605b.c,v $ */