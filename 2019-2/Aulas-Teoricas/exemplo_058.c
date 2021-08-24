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
#define COMPRIMENTO_BUFFER            512

#define OK				                    0
#define NUMERO_ARGUMENTOS_INVALIDO	  1
#define ERRO_ABRINDO_ARQUIVO          2
#define ERRO_LENDO_ARQUIVO            3
#define ARQUIVO_CORROMPIDO            4

typedef unsigned char byte;

int
main (int argc, char *argv []) 
{
  byte buffer [COMPRIMENTO_BUFFER];
  FILE *leitura, *escrita;
  size_t lidos, escritos;
  unsigned passada = 1;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <arquivo-entrada> <arquivo-saida>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

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

  while ((lidos = fread (buffer, COMPRIMENTO_BUFFER, 1, leitura)))
  {
    escritos = fwrite (buffer, COMPRIMENTO_BUFFER, lidos, escrita);
    /*
    if (escritos != lidos)
    */
   printf ("Passada: %u\n", passada++);

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

  printf ("Arquivo copiado com sucesso\n");

  fclose (leitura);
  fclose (escrita);
  return OK;

} /* funcao principal */

