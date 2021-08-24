/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 06.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/03 05:34:11 $
 * $Log: aula0608.h,v $
 * Revision 1.2  2019/10/03 05:34:11  luiz.leitao
 * Inclusao do prototipo da funcao GerarPisPasep.
 *
 * Revision 1.1  2019/10/03 04:32:00  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0608_  /* Inicio da diretiva do pre-processador. */
#define _AULA0608_  "@(#)aula0608.h $Revision: 1.2 $"





/* Definicao das macros. */

#define PESOS_PIS_PASEP						10
#define PIS_PASEP_SEM_DIGITO_VERIFICADOR			10
#define PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN		11
#define EOS							'\0'





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2
#define DIGITO_INVALIDO						3
#define COMPRIMENTO_INVALIDO					4
#define ARGUMENTO_NULO						5





/* Definicao do tipo byte a partir dos tipos basicos da linguagem. */

typedef unsigned char byte;





/* Definicao do tipo ush a partir dos tipos basicos da linguagem. */

typedef unsigned short ush;





/* Definicao do tipo ull a partir dos tipos basicos da linguagem. */

typedef unsigned long long ull;





/* Definicao do tipo enumerado tipoErros. */

typedef enum
{
  invalido,
  valido,
  ok = 0,
  digitoInvalido = 3,
  argumentoNulo = 5
} tipoErros;





/* Prototipo da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(char *);





/* Prototipo da funcao GerarPisPasep. */

tipoErros
GerarPisPasep(char *);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0608.h,v $ */