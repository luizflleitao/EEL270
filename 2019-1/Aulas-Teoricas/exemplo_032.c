/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
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
#include "exemplo_031.h"

#define NUMERO_ARGUMENTOS 1 + 2 * LINHAS * COLUNAS

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2	
#define ARGUMENTO_FUNCAO_INVALIDO	3

#define EOS				'\0'

int
main (int argc, char *argv []) 
{

  float matriz1 [LINHAS][COLUNAS];
  float matriz2 [LINHAS][COLUNAS];
  float matrizSoma [LINHAS][COLUNAS];
  unsigned linha, coluna;
  char *verificacao;
  tipoErros codigoRetorno;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <a11> <a12> ... <a%i%i> <b11> <b12> ... <b%i%i>\n", 
            argv [0], LINHAS, COLUNAS, LINHAS, COLUNAS);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  for (linha = 0; linha < LINHAS; linha++)
    for (coluna = 0; coluna < COLUNAS; coluna++)
    {
      matriz1 [linha][coluna] = 
        strtof (argv [1 + (linha * COLUNAS) + coluna], &verificacao);

      if (*verificacao != '\0')
      {
        printf ("Argumento contem caractere invalido\n");
        exit (ARGUMENTO_INVALIDO);
      }

      matriz2 [linha][coluna] = 
        strtof (argv [1 + (linha * COLUNAS) + coluna + (LINHAS * COLUNAS)], &verificacao);

      if (*verificacao != '\0')
      {
        printf ("Argumento contem caractere invalido\n");
        exit (ARGUMENTO_INVALIDO);
      }
    }

  codigoRetorno = SomarMatrizes (NULL, matriz2, matrizSoma);
  switch (codigoRetorno)
  {
    case ok:
    break;

    case primeiroArgumentoNull:
      printf ("Primeiro argumento eh NULL\n");
    break;
    
    case segundoArgumentoNull:
      printf ("Segundo argumento eh NULL\n");
    break;
    
    case terceiroArgumentoNull:
      printf ("Terceiro argumento eh NULL\n");
    break;
    
    default:
      printf ("Comportamento incorreto. Chame uma mae de santo.\n");
  }
/*
  if ((codigoRetorno = SomarMatrizes (NULL, matriz2, matrizSoma)))
  if ((codigoRetorno = SomarMatrizes (NULL, matriz2, matrizSoma)) != ok)
*/

  printf ("---------------------------------------------\n");

  codigoRetorno = SomarMatrizes (matriz1, matriz2, matrizSoma);
  switch (codigoRetorno)
  {
    case ok:
      for (linha = 0; linha < LINHAS; linha++)
      {
        for (coluna = 0; coluna < COLUNAS; coluna++)
          printf ("\t%.03f", matrizSoma [linha][coluna]);
        printf ("\n");
      }
    break;

    case primeiroArgumentoNull:
      printf ("Primeiro argumento eh NULL\n");
      exit (ARGUMENTO_FUNCAO_INVALIDO);
    break;
    
    case segundoArgumentoNull:
      printf ("Segundo argumento eh NULL\n");
      exit (ARGUMENTO_FUNCAO_INVALIDO);
    break;
    
    case terceiroArgumentoNull:
      printf ("Terceiro argumento eh NULL\n");
      exit (ARGUMENTO_FUNCAO_INVALIDO);
    break;
    
    default:
      printf ("Comportamento incorreto. Chame uma mae de santo.\n");
      exit (ARGUMENTO_FUNCAO_INVALIDO);
  }

  return OK;

} /* funcao principal */

