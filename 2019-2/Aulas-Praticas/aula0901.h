/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 09.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/24 04:57:14 $
 * $Log: aula0901.h,v $
 * Revision 1.2  2019/10/24 04:57:14  luiz.leitao
 * Inclusao do prototipo da funcao DecodificarBase64.
 * Inclusao do prototipo da funcao EncontrarPosicaoPonteiroCaractere.
 *
 * Revision 1.1  2019/10/16 20:25:22  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0901_  /* Inicio da diretiva do pre-processador. */
#define _AULA0901_  "@(#)aula0901.h $Revision: 1.2 $"





/* Definicao do conjunto Base64.*/

#define CONJUNTO_BASE_64				"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"





/* Definicao das macros. */

#define NUMERO_MAXIMO_DE_PADDINGS			2
#define NUMERO_MINIMO_DE_ARGUMENTOS			3
#define TAMANHO_DO_BLOCO_DE_CODIFICACAO			3
#define TAMANHO_DO_BLOCO_DE_DECODIFICACAO		4
#define TAMANHO_MAXIMO_DA_LINHA_DE_CODIFICACAO		57
#define TAMANHO_MAXIMO_DA_LINHA_DE_DECODIFICACAO	76
#define NUMERO_MAXIMO_DE_BYTES_DE_CODIFICACAO		1024
#define NUMERO_MAXIMO_DE_ARGUMENTOS			1026
#define NUMERO_MAXIMO_DE_BYTES_DE_DECODIFICACAO		1368
#define PADDING						'='
#define RLN						'\r'
#define NWL						'\n'
#define EOS						'\0'





/* Codigos de retorno. */

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO				2
#define COMPRIMENTO_INVALIDO				3
#define ARGUMENTO_NULO					4
#define ARGUMENTO_VAZIO					5
#define CARACTERE_INVALIDO				6





/* Definicao do tipo byte a partir dos tipos basicos da linguagem. */

typedef unsigned char byte;





/* Definicao do tipo ush a partir dos tipos basicos da linguagem. */

typedef unsigned short ush;





/* Definicao do tipo enumerado tipoErros. */

typedef enum
{
  ok,
  comprimentoInvalido = 3,
  argumentoNulo,
  argumentoVazio,
  caractereInvalido
} tipoErros;





/* Prototipo da funcao CodificarBase64. */

tipoErros
CodificarBase64(byte *, unsigned, char *);





/* Prototipo da funcao DecodificarBase64. */

tipoErros
DecodificarBase64(char *, byte *, unsigned *);





/* Prototipo da funcao EncontrarPosicaoPonteiroCaractere. */

byte
EncontrarPosicaoPonteiroCaractere(char *, char);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0901.h,v $ */
