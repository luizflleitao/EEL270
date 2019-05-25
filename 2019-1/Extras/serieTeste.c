/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author$
 * $Date$
 * $Log$
 */










#include <stdio.h>
#include <stdlib.h>

#include "serie.h"





#define NUMERO_DE_ARGUMENTOS				2
#define EOS						'\0'

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO				2






int main(int argc, char **argv)
{

  char *validacao;
  unsigned short termo, indiceCaractere, indiceTermo;
  long double resultado;



  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nNumero de argumentos invalido.\n");
    printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);
  }



  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nArgumento invalido.\n");
    printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
    exit(ARGUMENTO_INVALIDO);
  }



  termo = (unsigned short) strtoul(*(argv + 1), &validacao, 10);



  for (indiceCaractere = 0; *(*(argv + 1) + indiceCaractere) != EOS; indiceCaractere++)
    if (*validacao != EOS)
    {
      printf("\n\n\nArgumento invalido.\n");
      printf("Uso: %s <numero-inteiro-nao-negativo>\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);
    }



  printf("\n\n\n");

  for (indiceTermo = 0; indiceTermo <= termo; indiceTermo++)
  {
    resultado = CalcularSerieAlternada(indiceTermo);
    printf("S(%hu) = %.2Lf\n", indiceTermo, resultado);
  }

  printf("\n\n\n");



  return OK;

}










/* $RCSfile$ */
