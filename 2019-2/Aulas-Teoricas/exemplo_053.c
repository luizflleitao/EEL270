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

#ifdef __FreeBSD__
#include <pwd.h>
#else
#define _XOPEN_SOURCE 600
#endif

#include <unistd.h>

#define NUMERO_ARGUMENTOS         1 
#define COMPRIMENTO_MAXIMO_SENHA  127

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

int
main (int argc, char *argv []) 
{
  char senha [COMPRIMENTO_MAXIMO_SENHA + 1];
  char confirmacao [COMPRIMENTO_MAXIMO_SENHA + 1];

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  strcpy (senha, getpass ("Entre com a senha:"));
  printf ("Senha: \"%s\"\n", senha);
  strcpy (confirmacao, getpass ("Entre com a confirmacao da senha:"));
  printf ("Senha: \"%s\"\n", senha);
  printf ("Confirmacao: \"%s\"\n", confirmacao);

  return OK;

} /* funcao principal */

