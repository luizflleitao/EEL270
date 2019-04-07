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

#define NUMERO_ARGUMENTOS		2

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO		2	

#define EOS				'\0'

int
main (int argc, char *argv []) 
{
  unsigned numero, indice;
  float resultado;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  
  
  for (indice = 0; argv [1][indice] != EOS; indice++)
    if (argv [1][indice] < '0' || argv [1][indice] > '9')
    {
      printf ("Argumento contem caractere invalido: \"%c\"\n", argv [1][indice]);
      exit (ARGUMENTO_INVALIDO);
    }

  numero = atoi (argv [1]);

  resultado = 0;
  while (numero > 0)
  {
    resultado += 1.0/numero;
    numero--;
  }

  printf ("\nS(%s): %f\n\n", argv [1], resultado);
  return OK;

} /* funcao principal */

