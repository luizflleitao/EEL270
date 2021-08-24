/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 03.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/30 03:49:32 $
 * $Log: aula0301.h,v $
 * Revision 1.1  2019/08/30 03:49:32  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0301_  /* Inicio da diretiva do pre-processador. */
#define _AULA0301_  "@(#)aula0301.h $Revision: 1.1 $"





/* Definicao das macros. */

#define NUMERO_DE_ARGUMENTOS					2
#define EOS							'\0'





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2





/* Prototipo da funcao CalcularTermoSerieFibonacci. */

unsigned long long
CalcularTermoSerieFibonacci(unsigned short);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0301.h,v $ */
