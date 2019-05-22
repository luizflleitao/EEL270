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

#define NUMERO_ARGUMENTOS		1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ERRO_ABRINDO_ARQUIVO		2
#define ERRO_FECHANDO_ARQUIVO		3

#define COMPRIMENTO_MAXIMO_NOME		10
#define NOME_ARQUIVO			"alunos.lista"

int
main (int argc, char *argv []) 
{
  char nome [COMPRIMENTO_MAXIMO_NOME + 1];
  FILE *arquivo;
  unsigned linhas = 0;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  arquivo = fopen (NOME_ARQUIVO, "w");
  if (arquivo == NULL) /* if (!arquivo) */
  {
    printf ("Não foi possivel abrir o arquivo \"%s\"\n", NOME_ARQUIVO);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  do
  {
    printf ("Nome: ");
    gets (nome);
    if (strcmp (nome, "FIM"))
    {
      if (linhas > 0)
        fprintf (arquivo, "\n%s", nome);
      else
        fprintf (arquivo, "%s", nome);
      linhas++;
    }
  }
  while (strcmp (nome, "FIM") != 0);

  if (fclose (arquivo) != 0)
  {
    printf ("Nao foi possivel fechar o arquivo.\n");
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_FECHANDO_ARQUIVO);
  }

  printf ("Arquivo criado com sucesso, contendo %u linhas\n", linhas);
  return OK;

} /* funcao principal */

