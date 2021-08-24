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
#include <unistd.h>

#define NUMERO_MINIMO_ARGUMENTOS             2 

#define OK				                    0
#define NUMERO_ARGUMENTOS_INVALIDO	  1


int
main (int argc, char *argv []) 
{
  const char *options = "a:A:hHp:P:r:R:";
  int selectedOption;
  unsigned index;
  opterr = 0;

  if (argc < NUMERO_MINIMO_ARGUMENTOS)
  {
    printf ("Uso: %s\n", argv [0]);
    printf ("\t\t-a <nickname> <username> [<group>] [<language>]\n");
    printf ("\t\t\tAdd User\n");
    printf ("\t\t\tAdicionar Usuario\n");
    printf ("\t\t-r <nickname> [<language>]\n");
    printf ("\t\t\tRemove User\n");
    printf ("\t\t\tRemover Usuario\n");
    printf ("\t\t-p <nickname> [<language>]\n");
    printf ("\t\t\tChange Password\n");
    printf ("\t\t\tTrocar Senha\n");
    printf ("\t\t-h [<language>]\n");
    printf ("\t\t\tHelp\n");
    printf ("\t\t\tAjuda\n");
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (index = 0; index < argc; index++)
    printf ("ARG (#%u): \"%s\"\n", index, argv [index]);

  while ((selectedOption = getopt (argc, argv, options)) != -1)
  {
    switch (selectedOption)
    {
      case 'a':
      case 'A':
        printf ("Add User\n");
        printf ("Arg: %s\n", optarg);
        printf ("Index: %i\n", optind);
        printf ("Index: %i\n", optopt);
      break;

      case 'h':
      case 'H':
        printf ("Help\n");
        printf ("Arg: %s\n", optarg);
        printf ("Index: %i\n", optind);
        printf ("Index: %i\n", optopt);
      break;

      case 'p':
      case 'P':
        printf ("Change Password\n");
        printf ("Arg: %s\n", optarg);
        printf ("Index: %i\n", optind);
        printf ("Index: %i\n", optopt);
      break;

      case 'r':
      case 'R':
        printf ("Remove User\n");
        printf ("Arg: %s\n", optarg);
        printf ("Index: %i\n", optind);
        printf ("Index: %i\n", optopt);
      break;

      default:
        printf ("Invalid option\n");

    }
  }
  return OK;

} /* funcao principal */

