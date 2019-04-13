/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/04/10 16:03:27 $
 * $Log: aula0301.h,v $
 * Revision 1.1  2019/04/10 16:03:27  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0301_  /* Inicio da diretiva do pre-processador. */
#define _AULA0301_  "@(#)aula0301.h $Revision: 1.1 $"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS					3
#define EOS							'\0'





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2





/* Definicao do tipo ull a partir dos tipos basicos da linguagem. */

typedef unsigned long long ull;





/* Prototipo da funcao CalcularMaximoDivisorComum. */

ull
CalcularMaximoDivisorComum(ull, ull);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0301.h,v $ */
