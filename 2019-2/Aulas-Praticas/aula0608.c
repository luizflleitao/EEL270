/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: Implementacao das funcoes GerarDigitoVerificadorPisPasep e GerarPisPasep.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/03 05:34:55 $
 * $Log: aula0608.c,v $
 * Revision 1.2  2019/10/03 05:34:55  luiz.leitao
 * Implementacao da funcao GerarPisPasep.
 *
 * Revision 1.1  2019/10/03 04:32:26  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao dos arquivos de cabecalho da biblioteca padrao da linguagem. */

#include <stdlib.h>
#include <time.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0608.h"





/* Implementacao da funcao GerarDigitoVerificadorPisPasep. */

tipoErros
GerarDigitoVerificadorPisPasep(char *pisPasep)
{

  /* Utilizacao de variaveis locais dentro da funcao GerarDigitoVerificadorPisPasep. */

  const char *pesosPisPasep= "3298765432";
  unsigned resto;
  ush indiceDigito;
  ull soma = 0;





  /* Verificacao da existencia de argumento nulo. */

  if (!pisPasep)  /* if (pisPasep == NULL) */
    return argumentoNulo;  /* 5 */





  /* Verificacao da existencia de digitos com dois ou mais algarismos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    if (*(pisPasep + indiceDigito) > 9)
      return digitoInvalido;  /* 3 */ 



  /* Soma dos digitos multiplicados pelos seus respectivos pesos. */

  for (indiceDigito = 0; indiceDigito < PIS_PASEP_SEM_DIGITO_VERIFICADOR; indiceDigito++)
    soma += (ull) (*(pisPasep + indiceDigito)) * (*(pesosPisPasep + indiceDigito) - '0');





  /* Calculo do resto. */

  resto = (unsigned) (soma % 11); 





  /* Atribuicao do valor do digito verificador ao final da string. */

  if ((resto == 0) || (resto == 1))
    *(pisPasep + indiceDigito) = '0';
  else
    *(pisPasep + indiceDigito) = (11 - resto + '0');





  return ok;  /* 0 */

} /* GerarDigitoVerificadorPisPasep */










/* Implementacao da funcao GerarPisPasep. */

tipoErros
GerarPisPasep(char *pisPasep)
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










/* $RCSfile: aula0608.c,v $ */
