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

#define COMPRIMENTO_BUFFER		512

typedef unsigned char byte;
int
main (int argc, char *argv []) 
{
  byte buffer [COMPRIMENTO_BUFFER];
  FILE *origem, *destino;
  size_t lidos;
  size_t numeroBytes = 0;

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

  while ((lidos = fread ((void *) buffer, 1, COMPRIMENTO_BUFFER, origem)) > 0)
  {
    numeroBytes += lidos;
    fwrite ((void *) buffer, 1, lidos, destino);
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

  printf ("Arquivo criado com sucesso: %llu bytes copiados\n", (long long unsigned) numeroBytes);
  return OK;

} /* funcao principal */

