/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao das funcoes GerarDigitoVerificadorPisPasep, ValidarPisPasep e GerarPisPasep.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/02 23:58:54 $
 * $Log: aula0601.c,v $
 * Revision 1.4  2019/10/02 23:58:54  luiz.leitao
 * Implementacao da funcao GerarPisPasep.
 *
 * Revision 1.3  2019/09/29 23:17:42  luiz.leitao
 * Alteracoes adicionais no arquivo.
 *
 * Revision 1.2  2019/09/20 02:49:04  luiz.leitao
 * Implementacao da funcao ValidarPisPasep.
 *
 * Revision 1.1  2019/09/17 17:10:41  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdlib.h>
#include <time.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0601.h"





/* Implementacao da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(byte pisPasep[])
{

  /* Utilizacao de variaveis locais dentro da funcao GerarDigitoVerificadorPisPasep. */

  unsigned pesosPisPasep[PESOS_PIS_PASEP] = {3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
  unsigned digitoVerificador, resto;
  ush indiceDigito;
  ull soma = 0;





  /* Verificacao da existencia de argumento nulo. */

  if (!pisPasep)  /* if (pisPasep == NULL) */
    return argumentoNulo;  /* 6 */





  /* Verificacao da existencia de digitos com dois ou mais algarismos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    if (pisPasep[indiceDigito] > 9)
      return digitoInvalido;  /* 3 */ 





  /* Soma dos digitos multiplicados pelos seus respectivos pesos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++) 
    soma += (ull) pisPasep[indiceDigito] * pesosPisPasep[indiceDigito];





  /* Calculo do resto. */

  resto = (unsigned) (soma % 11); 





  /* Atribuicao do valor do digito verificador a decima primeira posicao do vetor pisPasep
     a partir do calculo do resto. */

  if ((resto == 0) || (resto == 1))
    pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1] = (byte) 0;
  else
  {
    digitoVerificador = (11 - resto);
    pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1] = (byte) digitoVerificador;
  } /* else */





  return ok;  /* 0 */

} /* GerarDigitoVerificadorPisPasep */










/* Implementacao da funcao ValidarPisPasep. */

tipoErros
ValidarPisPasep(byte pisPasep[])
{

  /* Utilizacao de variaveis locais dentro da funcao ValidarPisPasep. */

  byte validadePisPasep;
  ush indiceDigito;





  /* Verificacao da existencia de argumento nulo. */

  if (!pisPasep)  /* if (pisPasep == NULL)  */
    return argumentoNulo;  /* 6 */





  /* Verificacao da existencia de digitos com dois ou mais algarismos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceDigito++)
    if (pisPasep[indiceDigito] > 9)
      return digitoInvalido;  /* 3 */





  /* Variavel recebe o ultimo elemento do vetor pisPasep para posterior comparacao. */

  validadePisPasep = pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1];





  /* Chamada da funcao GerarDigitoVerificadorPisPasep. */

  GerarDigitoVerificadorPisPasep(pisPasep);





  /* Comparacao entre a variavel auxiliar e o digito calculado pela funcao GerarDigitoVerificadorPisPasep. */

  if (pisPasep[PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1] == validadePisPasep)
    return valido;  /* 1 */





  return invalido;  /* 0 */

} /* ValidarPisPasep */










/* Implementacao da funcao GerarPisPasep. */

tipoErros
GerarPisPasep(byte *pisPasep)
{

  /* Utilizacao de variaveis locais dentro da funcao GerarPisPasep. */

  unsigned semente;
  ush indiceDigito;
  ull auxiliar;
  const char *digitosPisPasep = "0123456789";





  /* Verificacao da existencia de argumento nulo. */

  if (!pisPasep)  /* if (pisPasep == NULL)  */
    return argumentoNulo;  /* 6 */





  /* Criacao da semente. */

  semente = (unsigned) time(NULL);





  /* Chamada de funcao interna do sistema. */

  srand(semente);





  /* Laco de repeticao para criacao do PisPasep. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
  {
    auxiliar = rand() % PIS_PASEP_SEM_DIGITO_VERIFICADOR;
    *(pisPasep + indiceDigito) = (*(digitosPisPasep + auxiliar) - '0');
  } /* for */





  /* Chamada da funcao GerarDigitoVerificadorPisPasep. */

  GerarDigitoVerificadorPisPasep(pisPasep);





  return ok;  /* 0 */

} /* GerarPisPasep */










/* $RCSfile: aula0601.c,v $ */
