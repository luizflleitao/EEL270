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
#include <time.h>

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

#define END_OF_STRING			'\0'

int
main (int argc, char *argv []) 
{
  unsigned indice, comprimentoSequencia, semente;
  char *validacao;
  
  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <comprimento-sequencia>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (argv [1][0] == '-')
  {
    printf ("Argumento invalido. Numero negativo.\n");
    exit (ARGUMENTO_INVALIDO); 
  }

  comprimentoSequencia = (unsigned) strtoul (argv [1], &validacao, 10);
  if (*validacao != END_OF_STRING)
  {
    printf ("Argumento invalido. Primeiro caractere invalido: \'%c\'\n", *validacao);
    exit (ARGUMENTO_INVALIDO); 
  }

  semente = (unsigned) time (NULL);
  /* time ((time_t *) &semente); */
  srand (semente);

  /* srand ((unsigned) time (NULL)); */

  for (indice = 0; indice < comprimentoSequencia; indice++)
    printf ("%u\n", (unsigned) (rand () % 11));

  return OK;

} /* funcao principal */

