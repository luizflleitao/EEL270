/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/16 14:21:38 $
 * $Log: aula0401.h,v $
 * Revision 1.1  2019/04/16 14:21:38  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0401_  /* Inicio da diretiva do pre-processador. */
#define _AULA0401_  "@(#)aula0401.h $Revision: 1.1 $"





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2





/* Definicao do tipo ush a partir dos tipos basicos da linguagem. */

typedef unsigned short ush;





/* Definicao do tipo ld a partir dos tipos basicos da linguagem. */

typedef long double ld;





/* Prototipo da funcao CalcularExponencial. */

ld
CalcularExponencial(double, int);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0401.h,v $ */
