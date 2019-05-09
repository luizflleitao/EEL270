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

#ifndef _EXEMPLO_039_
#define _EXEMPLO_039_	"exemplo_039.h"

#define COMPRIMENTO_IDENTIFICADOR 	17

typedef enum
{
  ok,
  argumentoEntradaNull
} 
tipoErros;

typedef unsigned char byte;

tipoErros
GerarIdentificador (byte *);
/*
GerarIdentificador (byte []);
*/

#endif
