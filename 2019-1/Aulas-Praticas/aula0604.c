/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/09 20:30:39 $
 * $Log: aula0604.c,v $
 * Revision 1.2  2019/05/09 20:30:39  luiz.leitao
 * Implementacao da funcao ValidarPisPasep.
 *
 * Revision 1.1  2019/05/09 17:56:15  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0604.h"





/* Implementacao da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(char *pisPasep, char *digitoVerificador)
{

  /* Utilizacao de variaveis locais dentro da funcao GerarDigitoVerificadorPisPasep. */

  const char *pesosPisPasep = "3298765432";
  unsigned resto;
  ush indiceDigito;
  ull soma = 0;





  /* Verificacao da existencia de digitos com dois ou mais algarismos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    if (*(pisPasep + indiceDigito) > 9)
      return digitoInvalido;  /* 3 */ 





  /* Soma dos digitos multiplicados pelos seus respectivos pesos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    soma += (ull) (*(pisPasep + indiceDigito)) * (*(pesosPisPasep + indiceDigito) - '0');





  /* Calculo do resto. */

  resto = (unsigned) (soma % 11); 





  /* Atribuicao do valor do digito verificador ao parametro de saida. */

  if ((resto == 0) || (resto == 1))
    *digitoVerificador = '0';
  else
    *digitoVerificador = (11 - resto + '0');





  return ok;  /* 0 */

} /* GerarDigitoVerificadorPisPasep */










/* Implementacao da funcao ValidarPisPasep. */

tipoErros
ValidarPisPasep(char *pisPasep)
{

  /* Utilizacao de variaveis locais dentro da funcao ValidarPisPasep. */

  char validadePisPasep;
  char digitoVerificador[DIGITO_VERIFICADOR + 1];
  ush indiceDigito;





  /* Verificacao da existencia de digitos com dois ou mais algarismos. */
  /* Informacao da existencia de argumentos com dois ou mais digitos passados ao programa (Erro #3). */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceDigito++)
    if (*(pisPasep + indiceDigito) > 9)
      return digitoInvalido;  /* 3 */





  /* Variavel recebe o ultimo elemento do vetor pisPasep para posterior comparacao. */

  validadePisPasep = (*(pisPasep + (PIS_PASEP_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1))  + '0');





  /* Chamada da funcao GerarDigitoVerificadorPisPasep. */

  GerarDigitoVerificadorPisPasep(pisPasep, digitoVerificador);





  /* Comparacao entre a variavel auxiliar e o digito calculado pela funcao GerarDigitoVerificadorPisPasep. */

  if (digitoVerificador[DIGITO_VERIFICADOR - 1] == validadePisPasep)
    return valido;  /* 1 */





  return invalido;  /* 0 */

} /* ValidarPisPasep */










/* $RCSfile: aula0604.c,v $ */
