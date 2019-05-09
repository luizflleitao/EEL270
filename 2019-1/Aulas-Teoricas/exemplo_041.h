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

#ifndef _EXEMPLO_041_
#define _EXEMPLO_041_	"exemplo_041.h"

#define COMPRIMENTO_IDENTIFICADOR 	17

typedef enum
{
  ok,
  argumentoEntradaNull
} 
tipoErros;


tipoErros
GerarIdentificador (char *);
/*
GerarIdentificador (char []);
*/

#endif
