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
#include <string.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS             2 
#define COMPRIMENTO_MAXIMO_NOME       50

#define OK				                    0
#define NUMERO_ARGUMENTOS_INVALIDO	  1
#define ERRO_ABRINDO_ARQUIVO          2

int
main (int argc, char *argv []) 
{
  char nome [COMPRIMENTO_MAXIMO_NOME + 1];
  FILE *arquivo;
  unsigned linhas = 0;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <arquivo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  arquivo = fopen (argv [1], "w");
  if (arquivo == NULL)
  {
    printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [1]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  do
  {
    printf ("Nome: ");
    gets (nome);
    if (strcmp (nome, "FIM"))
    {
      if (linhas == 0)
        fprintf (arquivo, "%s", nome);
      else
        fprintf (arquivo, "\n%s", nome);
      linhas++;
    }
  }
  while (strcmp (nome, "FIM"));

  printf ("Arquivo criado com sucesso contendo  %u linhas\n", linhas);
  fclose (arquivo);
  return OK;

} /* funcao principal */

