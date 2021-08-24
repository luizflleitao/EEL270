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

#ifndef _EXEMPLO_045_
#define _EXEMPLO_045_ 		"exemplo_045.h"

#define COMPRIMENTO_DRE		9

typedef unsigned char byte;

typedef enum
{
  ok,
  argumentoInvalido
}
tipoErros;

tipoErros
GerarDreAleatorio (byte [COMPRIMENTO_DRE]);

#endif

/* $RCSfile$ */
