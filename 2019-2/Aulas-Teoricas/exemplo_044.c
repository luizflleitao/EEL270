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
#include <limits.h>

#include "exemplo_043.h"

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2

int
main (int argc, char *argv []) 
{
  tipoErros codigoRetorno;
  char senha [COMPRIMENTO_MAXIMO_SENHA + 1];
  unsigned short comprimento;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <comprimento-senha>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (argv [1][0] == '-')
  {
    printf ("Argumento invalido. Entre com um numero inteiro nao negativo.\n");
    exit (ARGUMENTO_INVALIDO);
  }
  
  comprimento = (unsigned short) strtoul (argv [1], &validacao, 10);
  if (*validacao != '\0')
  {
    printf ("Argumento invalido.\n");
    printf ("Primeiro caractere invalido encontrado no argumento: %c\n", *validacao);
    exit (ARGUMENTO_INVALIDO);
  }
  
  codigoRetorno = CriarSenhaAleatoria (comprimento, senha);
  if (codigoRetorno)
  {
    printf ("Erro executando a funcao CriarSenhaAleatoria\n");
    printf ("Erro #%i\n", codigoRetorno);
    exit (OK);
  }
  
  printf ("Senha: \"%s\"\n", senha);
  return OK;

} /* funcao principal */

