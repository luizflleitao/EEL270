#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS             2
#define COMPRIMENTO_MAXIMO_NOME       50

#define OK                            0
#define NUMERO_ARGUMENTOS_INVALIDO    1
#define ERRO_ABRINDO_ARQUIVO          2 
#define ERRO_LENDO_ARQUIVO            3 
#define MEMORIA_INSUFICIENTE          4
#define NOME_REPETIDO                 5

typedef enum {falso, verdadeiro} boolean;

typedef struct estruturaDadosAluno
{
  char nome [COMPRIMENTO_MAXIMO_NOME + 1];
  struct estruturaDadosAluno *proximo;
} tipoDadosAluno;

void
LiberarMemoria (tipoDadosAluno *);

void
LiberarMemoria (tipoDadosAluno *primeiro)
{
  tipoDadosAluno *auxiliar;

  while (primeiro != NULL)
  {
    auxiliar = primeiro;
    primeiro = primeiro->proximo;
    free (auxiliar);
  }
}

int
main (int argc, char **argv)
{
  FILE *arquivo;
  boolean achou;
  char nome [COMPRIMENTO_MAXIMO_NOME + 2];
  tipoDadosAluno *primeiro, *anterior, *atual, *novo;
  int comparacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <nome-arquivo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if ((arquivo = fopen (argv [1], "r")) == NULL)
  {
    printf ("Erro abrindo o arquivo \"%s\"\n", argv [1]);
    printf ("Erro (#%i) - %s\n", errno, strerror (errno));
    exit (ERRO_ABRINDO_ARQUIVO);
  }

  primeiro = NULL;
  while ((fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, arquivo)) != NULL)
  {
    if (nome [strlen (nome) - 1] == '\n')
      nome [strlen (nome) - 1] = '\0';

    novo = (tipoDadosAluno *) malloc (sizeof (tipoDadosAluno));
    if (novo == NULL)
    {
      printf ("Nao foi possivel alocar memoria.\n");
      LiberarMemoria (primeiro);
      fclose (arquivo);
      exit (MEMORIA_INSUFICIENTE);
    } 

    memset (novo, 0x00, sizeof (tipoDadosAluno));
    strcpy (novo->nome, nome);
    novo->proximo = NULL;

    if (primeiro == NULL)
      primeiro = novo;
    else
    {
      achou = falso;
      atual = primeiro;
      while (!achou && atual != NULL)
      {
        comparacao = strcmp (novo->nome, atual->nome);
        if (comparacao == 0)
        {
          printf ("Nome repetido\n");
          LiberarMemoria (primeiro);
          fclose (arquivo);
          exit (NOME_REPETIDO);
        } 

        if (comparacao > 0)
        {
          anterior = atual;
          atual = atual->proximo;
        }
        else
        {
          achou = verdadeiro;
          if (atual == primeiro)
          {
            novo->proximo = primeiro;
            primeiro = novo;
          }
          else
          {
            anterior->proximo = novo;
            novo->proximo = atual;
          }
        }
      } /* while !achou ... */

      if (!achou)
        anterior->proximo = novo;
    }
  } /* while !fgets ... */

  /* if (ferror (arquivo)) */

  atual = primeiro;
  while (atual != NULL)
  {
    printf ("%s\n", atual->nome);
    atual = atual->proximo;
  }

  LiberarMemoria (primeiro);
  fclose (arquivo);
  return OK;
}

