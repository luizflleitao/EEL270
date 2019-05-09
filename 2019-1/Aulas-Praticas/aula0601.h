/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/08 22:50:05 $
 * $Log: aula0601.h,v $
 * Revision 1.2  2019/05/08 22:50:05  luiz.leitao
 * Inclusao do prototipo da funcao ValidarPisPasep.
 *
 * Revision 1.1  2019/05/08 17:40:53  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0601_  /* Inicio da diretiva do pre-processador. */
#define _AULA0601_  "@(#)aula0601.h $Revision: 1.2 $"





/* Definicao das macros. */

#define PESOS_PIS_PASEP						10
#define PIS_PASEP_SEM_DIGITO_VERIFICADOR			10
#define PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN		11
#define PIS_PASEP_COM_DIGITO_VERIFICADOR_COM_HIFEN		12





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2
#define DIGITO_INVALIDO						3
#define COMPRIMENTO_INVALIDO					4
#define AUSENCIA_DO_HIFEN					5





/* Definicao do tipo byte a partir dos tipos basicos da linguagem. */

typedef unsigned char byte;





/* Definicao do tipo ush a partir dos tipos basicos da linguagem. */

typedef unsigned short ush;





/* Definicao do tipo ull a partir dos tipos basicos da linguagem. */

typedef unsigned long long ull;





/* Definicao do tipo enumerado tipoErros. */

typedef enum
{
  ok,
  invalido = 0,
  valido,
  digitoInvalido = 3
} tipoErros;





/* Prototipo da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(byte []);





/* Prototipo da funcao ValidarPisPasep. */

tipoErros
ValidarPisPasep(byte []);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0601.h,v $ */
