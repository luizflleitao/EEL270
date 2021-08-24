/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 02.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/08/20 17:23:03 $
 * $Log: aula0201.h,v $
 * Revision 1.1  2019/08/20 17:23:03  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0201_  /* Inicio da diretiva do pre-processador. */
#define _AULA0201_  "@(#)aula0201.h $Revision: 1.1 $"





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










/* $RCSfile: aula0201.h,v $ */
