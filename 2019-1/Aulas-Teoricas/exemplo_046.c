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
#include <string.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS		3

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ERRO_ABRINDO_ARQUIVO		2
#define ERRO_FECHANDO_ARQUIVO		3
#define ARQUIVO_CORROMPIDO		4
#define ERRO_LENDO_ARQUIVO		5

#define COMPRIMENTO_MAXIMO_NOME		10

typedef enum {falso, verdadeiro} boolean;
int
main (int argc, char *argv []) 
{
  char nome [COMPRIMENTO_MAXIMO_NOME + 2];
  FILE *origem, *destino;
  unsigned linhas = 0;
  boolean teste = falso;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %si <origem> <destino>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  origem = fopen (argv [1], "r");
  if (origem == NULL) 
  {
    printf ("Não foi possivel abrir o arquivo \"%s\"\n", argv [1]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  destino = fopen (argv [2], "w");
  if (destino == NULL)
  {
    printf ("Não foi possivel abrir o arquivo \"%s\"\n", argv [2]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    fclose (origem);
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  while ((fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, origem)) != NULL)
  {
    if (teste == verdadeiro) /* if (teste) */
    {
      printf ("Arquivo corrompido. Linha muito longa\n");
      fclose (origem);
      fclose (destino);
      remove (argv [2]);
      exit (ARQUIVO_CORROMPIDO);
    }

    if (nome [strlen (nome) - 1] != '\n')
      teste = verdadeiro;
    fprintf (destino, "%s", nome);
    linhas++;
  }

  if (ferror (origem))
  {
    printf ("Erro lendo o arquivo\n");
    fclose (origem);
    fclose (destino);
    remove (argv [2]);
    exit (ERRO_LENDO_ARQUIVO);
  }

  if (fclose (origem) != 0)
  {
    printf ("Nao foi possivel fechar o arquivo: \"%s\".\n", argv [1]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_FECHANDO_ARQUIVO);
  }

  if (fclose (destino) != 0)
  {
    printf ("Nao foi possivel fechar o arquivo: \"%s\"\n", argv [2]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_FECHANDO_ARQUIVO);
  }

  printf ("Arquivo criado com sucesso, contendo %u linhas\n", linhas);
  return OK;

} /* funcao principal */

