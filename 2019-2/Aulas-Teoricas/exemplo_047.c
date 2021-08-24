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

#include "exemplo_047.h"

/*
 * 1o argumento - matriz entrada
 * 2o argumento - matriz entrada
 * 3o argumento - matriz saida
 *
 */

void
SomarMatrizes (float matrizA [NUMERO_LINHAS] [NUMERO_COLUNAS],
               float matrizB [NUMERO_LINHAS] [NUMERO_COLUNAS],
               float matrizSoma [NUMERO_LINHAS] [NUMERO_COLUNAS])
{
  unsigned indiceLinha, indiceColuna;

  for (indiceLinha = 0; indiceLinha < NUMERO_LINHAS; indiceLinha++)
    for (indiceColuna = 0; indiceColuna < NUMERO_COLUNAS; indiceColuna++)
      matrizSoma [indiceLinha][indiceColuna] =
        matrizA [indiceLinha][indiceColuna] + 
        matrizB [indiceLinha][indiceColuna];
}

/* $RCSfile$ */
