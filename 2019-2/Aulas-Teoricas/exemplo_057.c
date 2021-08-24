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

#define NUMERO_ARGUMENTOS             3 
#define COMPRIMENTO_MAXIMO_LINHA      50

#define OK				                    0
#define NUMERO_ARGUMENTOS_INVALIDO	  1
#define ERRO_ABRINDO_ARQUIVO          2
#define ERRO_LENDO_ARQUIVO            3
#define ARQUIVO_CORROMPIDO            4

typedef enum {falso, verdadeiro} boolean;

int
main (int argc, char *argv []) 
{
  char linha [COMPRIMENTO_MAXIMO_LINHA + 1 + 1]; /* \n \0 */
  FILE *leitura, *escrita;
  boolean ultimaLinha = falso;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <arquivo-entrada> <arquivo-saida>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

/*
  leitura = fopen (argv [1], "r");
  if (leitura == NULL)

  if ((leitura = fopen (argv [1], "r")) == NULL)
*/
  if (!(leitura = fopen (argv [1], "r")))
  {
    printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [1]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  if (!(escrita = fopen (argv [2], "w")))
  {
    printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [2]);
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    fclose (leitura);
    exit (ERRO_ABRINDO_ARQUIVO);
  }

/*
  while ((fgets (linha, COMPRIMENTO_MAXIMO_LINHA + 2, leitura)) != NULL)
*/
  while ((fgets (linha, COMPRIMENTO_MAXIMO_LINHA + 2, leitura)))
  {
    #ifdef _DEPURANDO_
    printf ("\"%s\"\n", linha);
    #endif

    if (ultimaLinha)
    {
      printf ("Arquivo corrompido !!!\n");
      printf ("Comprimento maximo da linha foi excedido !!!\n");
      fclose (leitura);
      fclose (escrita);
      remove (argv [2]);
      exit (ARQUIVO_CORROMPIDO);
    }

    if (linha [strlen (linha) - 1] != '\n')
      ultimaLinha = verdadeiro;

    fprintf (escrita, "%s", linha);
  } /* while */

  if (ferror (leitura))
  {
    printf ("Erro lendo arquivo\n");
    printf ("Erro (#%i): %s\n", errno, strerror (errno));
    fclose (leitura);
    fclose (escrita);
    remove (argv [2]);
    exit (ERRO_LENDO_ARQUIVO); 
  }

  if (!ultimaLinha)
  {
    printf ("Arquivo corrompido !!!\n");
    printf ("Ultima linha contem \\n !!!\n");
    fclose (leitura);
    fclose (escrita);
    remove (argv [2]);
    exit (ARQUIVO_CORROMPIDO);
  }

  printf ("Arquivo copiado com sucesso\n");

  fclose (leitura);
  fclose (escrita);
  return OK;

} /* funcao principal */

