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

#ifndef _EXEMPLO_043_
#define _EXEMPLO_043_ 		"exemplo_043.h"

#define CARACTERES_VALIDOS 	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_+=*/"

#define COMPRIMENTO_MAXIMO_SENHA	127

typedef enum
{
  ok,
  comprimentoSenhaInvalido,
  argumentoSenhaInvalido
}
tipoErros;

tipoErros
CriarSenhaAleatoria (unsigned short, char *);

#endif

/* $RCSfile$ */
