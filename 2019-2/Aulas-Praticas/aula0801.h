/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao do arquivo de cabecalho referente a aula 08.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/08 16:42:20 $
 * $Log: aula0801.h,v $
 * Revision 1.1  2019/10/08 16:42:20  luiz.leitao
 * Initial revision
 *
 */










#ifndef _AULA0801_  /* Inicio da diretiva do pre-processador. */
#define _AULA0801_  "@(#)aula0801.h $Revision: 1.1 $"





/* Definicao das macros referentes ao estado do pixel (aceso ou apagado). */

#define APAGADO						'0'
#define ACESO						'1'





/* Definicao das macros referentes as dimensoes maximas permitidas (250 linhas e 800 colunas). */

#define NUMERO_MAXIMO_DE_LINHAS				250
#define NUMERO_MAXIMO_DE_COLUNAS			800





/* Definicao das demais macros. */

#define PIXEL_INICIAL					1
#define LER_O_MANUAL					2
#define NUMERO_DE_ARGUMENTOS				10
#define EXIBICAO_DE_UM_DIGITO				9
#define EXIBICAO_DE_DOIS_DIGITOS			99
#define CONSTANTE_DE_ATRASO				1000
#define TEMPO_MAXIMO_DE_ATRASO				1000
#define EOS						'\0'





/* Codigos de retorno. */

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO				2
#define ARGUMENTO_NULO					3
#define MAXIMO_DE_LINHAS_INVALIDO			4
#define MAXIMO_DE_COLUNAS_INVALIDO			5
#define ABSCISSA_ESQUERDA_INVALIDA			6
#define ORDENADA_ESQUERDA_INVALIDA			7
#define ABSCISSA_DIREITA_INVALIDA_1			8
#define ORDENADA_DIREITA_INVALIDA_1			9
#define ABSCISSA_DIREITA_INVALIDA_2			10
#define ORDENADA_DIREITA_INVALIDA_2			11
#define ATRASO_INVALIDO					12
#define PONTO_INVALIDO					13
#define LADOS_PARALELOS_NAS_BORDAS_1			14
#define LADOS_PARALELOS_NAS_BORDAS_2			15
#define ABSCISSA_DO_PONTO_INVALIDA			16
#define ORDENADA_DO_PONTO_INVALIDA			17
#define MANUAL						18





/* Definicao do tipo useconds_t a partir dos tipos basicos da linguagem. */

typedef unsigned int useconds_t;





/* Definicao do tipo enumerado tipoPixel. */

typedef enum {apagado, aceso} tipoPixel;





/* Definicao do tipo enumerado tipoErros. */

typedef enum
{
  ok,
  maximoLinhasInvalido = 4,
  maximoColunasInvalido,
  abscissaEsquerdaInvalida,
  ordenadaEsquerdaInvalida,
  abscissaDireitaInvalida1,
  ordenadaDireitaInvalida1,
  abscissaDireitaInvalida2,
  ordenadaDireitaInvalida2,
  atrasoInvalido,
  abscissaPontoInvalida = 16,
  ordenadaPontoInvalida
} tipoErros;





/* Prototipo da funcao MostrarMonitor. */

tipoErros
MostrarMonitor(tipoPixel [NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
               unsigned, unsigned, useconds_t);





/* Prototipo da funcao LimparMonitor. */

tipoErros
LimparMonitor(tipoPixel [NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
              unsigned, unsigned, useconds_t);





/* Prototipo da funcao DesenharRetangulo. */

tipoErros
DesenharRetangulo(tipoPixel [NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
                  unsigned, unsigned, unsigned, 
                  unsigned, unsigned, unsigned,
                  useconds_t);





/* Prototipo da funcao PreencherPoligono. */

tipoErros
PreencherPoligono(tipoPixel [NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
                  unsigned, unsigned,
                  unsigned, unsigned,
                  useconds_t);





#endif  /* Final da diretiva do pre-processador. */










/* $RCSfile: aula0801.h,v $ */
