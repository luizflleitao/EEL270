e*
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

unsigned long long
CalcularFatorial (unsigned);

unsigned long long
CalcularFatorial (unsigned numero)
{
  unsigned long long resultado = 1;

  if (numero <= 1)
    return resultado;

  do
  {
    resultado *= numero;
    numero--; 
  }
  while (numero > 0); 

  return resultado;
}

int
main (int argc, char *argv []) 
{
  unsigned numero;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }	  
  
  numero = atoi (argv [1]);

  printf ("\n%s!: %llu\n\n", argv [1], CalcularFatorial (numero));
  return OK;

} /* funcao principal */

