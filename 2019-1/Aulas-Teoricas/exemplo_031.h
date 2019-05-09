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

#ifndef _EXEMPLO_031_
#define _EXEMPLO_031_	"exemplo_031.h"

#define LINHAS		3
#define COLUNAS		2

typedef enum 
{
  ok, 
  primeiroArgumentoNull, 
  segundoArgumentoNull, 
  terceiroArgumentoNull
} tipoErros;

tipoErros
SomarMatrizes (float [LINHAS][COLUNAS], 
               float [LINHAS][COLUNAS], 
               float [LINHAS][COLUNAS]);

#endif
