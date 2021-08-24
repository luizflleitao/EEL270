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
 * $Date: 2019/09/30 02:20:08 $
 * $Log: aula0604.h,v $
 * Revision 1.3  2019/09/30 02:20:08  luiz.leitao
 * Alteracoes adicionais no arquivo.
 *
 * Revision 1.2  2019/09/20 04:12:54  luiz.leitao
 * Inclusao do prototipo da funcao ValidarPisPasep.
 *
 * Revision 1.1  2019/09/20 03:41:19  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0604_  /* Inicio da diretiva do pre-processador. */
#define _AULA0604_  "@(#)aula0604.h $Revision: 1.3 $"





/* Definicao das macros. */

#define DIGITO_VERIFICADOR					1
#define PIS_PASEP_SEM_DIGITO_VERIFICADOR			10
#define PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN		11
#define PIS_PASEP_COM_DIGITO_VERIFICADOR_COM_HIFEN		12
#define EOS							'\0'





/* Codigos de retorno. */

#define OK							0
#define NUMERO_DE_ARGUMENTOS_INVALIDO				1
#define ARGUMENTO_INVALIDO					2
#define DIGITO_INVALIDO						3
#define COMPRIMENTO_INVALIDO					4
#define AUSENCIA_DO_HIFEN					5
#define ARGUMENTO_NULO						6





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
  argumentoNulo = 6
} tipoErros;





/* Prototipo da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(char * /* entrada */, char * /* saida */);





/* Prototipo da funcao ValidarPisPasep. */

tipoErros
ValidarPisPasep(char *);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0604.h,v $ */
