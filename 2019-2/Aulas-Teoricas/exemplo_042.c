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

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define END_OF_STRING			'\0'

typedef enum {ok, argumento1Invalido, argumento2Invalido} tipoErros;

tipoErros
DeterminarComprimentoString (char *, unsigned long long *);

tipoErros
DeterminarComprimentoString (char *string, unsigned long long *comprimento)
{
  if (string == NULL) /* if (!string) */
    return argumento1Invalido;

  if (comprimento == NULL)
    return argumento2Invalido;

  *comprimento = 0;
  while (string [*comprimento] != END_OF_STRING)
    (*comprimento)++;

  return ok; 
}

int
main (int argc, char *argv []) 
{
  unsigned long long comprimento;
  tipoErros codigoRetorno;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <comprimento-sequencia>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  codigoRetorno = DeterminarComprimentoString (NULL, NULL);
  if (codigoRetorno != 0)
    printf ("Erro executando a funcao. Erro #%i\n", codigoRetorno);
  else
    printf ("A string \"%s\" tem %llu caracteres\n",
           argv [1], comprimento);

  return OK;

} /* funcao principal */

