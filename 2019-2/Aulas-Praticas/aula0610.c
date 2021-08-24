/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do programa de testes da funcao GerarPisPasep.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/03 05:33:51 $
 * $Log: aula0610.c,v $
 * Revision 1.1  2019/10/03 05:33:51  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0608.h"





/* Definicao da macro. */

#define NUMERO_DE_ARGUMENTOS				1





/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  char pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN + 1];
  unsigned indiceDigito;
  tipoErros resultado;





  /* Verificacao da quantidade de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s \n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Chamada da funcao GerarPisPasep. */

  resultado = GerarPisPasep(pisPasep);





  /* Verificacao da existencia de erro no retorno da funcao. */
  /* Informacao da existencia de argumento nulo passado ao programa. (Erro #6) */

  if (resultado == argumentoNulo)
  {
    printf("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
    printf("Uso: %s\n\n\n\n", *argv);
    exit(ARGUMENTO_NULO);
  } /* if */





  /* Exibicao do resultado na tela. */


  printf("\n\n\nPisPasep: ");

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    printf("%u", pisPasep[indiceDigito]);

  printf("-%c\n\n\n\n", pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1]);





  return OK;  /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0610.c,v $ */