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

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

int
main (int argc, char *argv []) 
{
  const char *opcoesCurtas = "a:e:r:m:s";
  int opcao;
  
  opterr = 0;

  if (argc < NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  while ((opcao = getopt (argc, argv, opcoesCurtas)) != -1)
  {
    switch (opcao)
    {
      case 'a':
        printf ("Adicionar Usuario\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
      break;

      case 'e':
        printf ("Editar Dados Usuario\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
      break;

      case 'r':
        printf ("Remover Usuario\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
      break;

      case 'm':
        printf ("Mudar Senha Usuario\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
      break;

      case 's':
        printf ("Mostrar Ajuda\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
      break;
 
      default:
        printf ("Opcao invalida\n");
        printf ("Argumento: %s - Proximo argumento: %i\n", optarg, optind);
    }
  }
  return OK;

} /* funcao principal */

