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
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "exemplo_043.h"

/*
 *
 * comprimento (E)
 * senha (S)
 *
 */
tipoErros
CriarSenhaAleatoria (unsigned short comprimento, char *senha)
/* CriarSenhaAleatoria (unsigned short comprimento, char senha []) */
{
  unsigned short indice;

  if (comprimento > COMPRIMENTO_MAXIMO_SENHA)
    return comprimentoSenhaInvalido;

  if (senha == NULL)
    return argumentoSenhaInvalido;

  srand ((unsigned) time (NULL));
  for (indice = 0; indice < comprimento; indice++)
    senha [indice] = CARACTERES_VALIDOS [rand () % strlen (CARACTERES_VALIDOS)];
  senha [indice] = '\0';

  return ok;
}

/* $RCSfile$ */
