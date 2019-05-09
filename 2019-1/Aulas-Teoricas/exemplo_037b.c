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

#include "exemplo_037.h"

unsigned long long
RetornarComprimentoString (char *string)
{
  char *inicio;

  if (!string)
    return 0;
 
  for (inicio = string; *string != '\0'; string++);
  return (string - inicio);

}
