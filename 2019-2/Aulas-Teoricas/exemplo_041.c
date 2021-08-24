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

#define ARGUMENTO_FUNCAO_INVALIDO	-1

long long
DeterminarComprimentoString (char *);

long long
DeterminarComprimentoString (char *string)
{
  long long comprimento = 0;

  if (string == NULL) /* if (!string) */
    return ARGUMENTO_FUNCAO_INVALIDO;

  while (string [comprimento] != END_OF_STRING)
    comprimento++;

  return comprimento; 
}

int
main (int argc, char *argv []) 
{
  long long codigoRetorno;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <comprimento-sequencia>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  codigoRetorno = DeterminarComprimentoString (NULL);
  if (codigoRetorno < 0)
    printf ("Erro executando a funcao. Erro #%lli\n", codigoRetorno);
  else
    printf ("A string \"%s\" tem %llu caracteres\n",
           argv [1], (unsigned long long) codigoRetorno);

  return OK;

} /* funcao principal */

