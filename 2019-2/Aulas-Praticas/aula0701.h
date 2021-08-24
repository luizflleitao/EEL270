/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 07.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/03 20:56:25 $
 * $Log: aula0701.h,v $
 * Revision 1.1  2019/10/03 20:56:25  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0701_  /* Inicio da diretiva do pre-processador. */
#define _AULA0701_  "@(#)aula0701.h $Revision: 1.1 $"





/* Definicao das macros referentes as quantidades de linhas e colunas de cada matriz
   (5 x 3) e (3 x 4). */

#define LINHAS_1					5
#define COLUNAS_1					3
#define LINHAS_2					3
#define COLUNAS_2					4





/* Definicao das demais macros. */

#define NUMERO_DE_ARGUMENTOS				1 + LINHAS_1 * COLUNAS_1 + LINHAS_2 * COLUNAS_2
#define EOS						'\0'	





/* Codigos de retorno. */

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO				2
#define ARGUMENTO_NULO					3





/* Definicao do tipo ush a partir dos tipos basicos da linguagem. */

typedef unsigned short ush;





/* Definicao do tipo enumerado tipoErros. */

typedef enum
{
  ok,
  argumentoNulo = 3
} tipoErros;





/* Prototipo da funcao MultiplicarMatrizes. */

tipoErros
MultiplicarMatrizes (float [LINHAS_1][COLUNAS_1], 
                     float [LINHAS_2][COLUNAS_2], 
                     float [LINHAS_1][COLUNAS_2]);





/* Prototipo da funcao MostrarMatriz1. */

void
MostrarMatriz1(float [LINHAS_1][COLUNAS_1]);





/* Prototipo da funcao MostrarMatriz2. */

void
MostrarMatriz2(float [LINHAS_2][COLUNAS_2]);





/* Prototipo da funcao MostrarMatrizResultado. */

void
MostrarMatrizResultado(float [LINHAS_1][COLUNAS_2]);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0701.h,v $ */