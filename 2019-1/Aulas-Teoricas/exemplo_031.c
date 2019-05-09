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

#include "exemplo_031.h"

tipoErros
SomarMatrizes (float matrizA [LINHAS][COLUNAS],
               float matrizB [LINHAS][COLUNAS],
               float matrizSoma [LINHAS][COLUNAS])
{
  unsigned linha, coluna;

  if (!matrizA)
    return primeiroArgumentoNull;

  if (!matrizB)
    return segundoArgumentoNull;

  if (!matrizSoma)
    return terceiroArgumentoNull;

  for (linha = 0; linha < LINHAS; ++linha)
    for (coluna = 0; coluna < COLUNAS; coluna++)
      matrizSoma [linha][coluna] = 
        matrizA [linha][coluna] + matrizB [linha][coluna];

  return ok;
}  
