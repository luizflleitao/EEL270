/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: <nome completo>
 * Descricao: <descricao sucinta sobre o programa>
 *
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "exemplo_047.h"

#define NUMERO_ARGUMENTOS 1 + (2 * NUMERO_LINHAS * NUMERO_COLUNAS)

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define EOS 				'\0'

int
main (int argc, char *argv []) 
{
  float matriz1 [NUMERO_LINHAS][NUMERO_COLUNAS];
  float matriz2 [NUMERO_LINHAS][NUMERO_COLUNAS];
  float matrizSoma [NUMERO_LINHAS][NUMERO_COLUNAS];
  unsigned linha, coluna;
  char *verificacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <a11> <a12> ... <a%u%u> <b11> <b12> ... <b%u%u>\n", 
    argv [0], NUMERO_LINHAS, NUMERO_COLUNAS, NUMERO_LINHAS, NUMERO_COLUNAS);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (linha = 0; linha < NUMERO_LINHAS; linha++)
    for (coluna = 0; coluna < NUMERO_COLUNAS; coluna++)
    {
      matriz1 [linha][coluna] = 
        strtof (argv [coluna + (linha * NUMERO_COLUNAS) + 1], &verificacao);
      if (*verificacao != EOS)
      {
        printf ("Argumento invalido (#%u).\n Caractere invalido: %c\n",
                coluna + (linha * NUMERO_COLUNAS) + 1, *verificacao);
        exit (ARGUMENTO_INVALIDO);
      }

      matriz2 [linha][coluna] = 
        strtof (argv [coluna + (linha * NUMERO_COLUNAS) + (NUMERO_LINHAS * NUMERO_COLUNAS) + 1], &verificacao);

      if (*verificacao != EOS)
      {
        printf ("Argumento invalido (#%u).\n Caractere invalido: %c\n",
                coluna + (linha * NUMERO_COLUNAS) + (NUMERO_LINHAS * NUMERO_COLUNAS) + 1, *verificacao);
        exit (ARGUMENTO_INVALIDO);
      }
    } /* for */

  SomarMatrizes (matriz1, NULL, matrizSoma);

  for (linha = 0; linha < NUMERO_LINHAS; linha++)
  {
    for (coluna = 0; coluna < NUMERO_COLUNAS; coluna++)
      printf ("\t%.04f", matrizSoma [linha][coluna]);
    printf ("\n");
  }
  return OK;

} /* funcao principal */

