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
 * $Author: marcelo.lanza $
 * $Date: 2019/03/19 14:47:19 $
 * $Log: exemplo_009.c,v $
 * Revision 1.2  2019/03/19 14:47:19  marcelo.lanza
 * Alteracao do cabecalho da funcao main.
 *
 * Revision 1.1  2019/03/19 14:37:40  marcelo.lanza
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "exemplo_025.h"

#define NUMERO_ARGUMENTOS		COMPRIMENTO_DRE + 1

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2	

#define EOS				'\0'

int
main (int argc, char *argv []) 
{

  byte dre [COMPRIMENTO_DRE];
  byte indice;
  unsigned long long auxiliar;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <dv>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  

  for (indice = 0; indice < COMPRIMENTO_DRE; indice++)
  {
    if (argv [indice + 1][0] == '-')
    {
      printf ("Argumento negativo. Entre com numeros entre 0 e 9\n");
      exit (ARGUMENTO_INVALIDO);
    } 

    auxiliar = strtoull (argv [indice + 1], &validacao, 10);

    if (*validacao != EOS)
    {
      printf ("Argumento contem caractere invalido: \'%c\'\n", *validacao);
      printf ("Argumentos devem ser numeros entre 0 e 9\n");
      exit (ARGUMENTO_INVALIDO);
    }
/*
    if (auxiliar > 255)
    {
      printf ("Argumentos devem ser numeros entre 0 e 9\n");
      exit (ARGUMENTO_INVALIDO);
    }
  */  
    dre [indice] = (byte) auxiliar;
  }

  if (ValidarDre (dre) == falso)
    printf ("DRE invalido\n");
  else
    printf ("DRE valido\n");

  return OK;

} /* funcao principal */

