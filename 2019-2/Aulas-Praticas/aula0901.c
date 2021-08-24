/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Luiz Fernando Loureiro Leitao
 * Descricao: implementacao das funcoes CodificarBase64, DecodificarBase64 e EncontrarPosicaoPonteiroCaractere.
 *
 * $Author: luiz.leitao $
 * $Date: 2019/10/24 04:58:15 $
 * $Log: aula0901.c,v $
 * Revision 1.2  2019/10/24 04:58:15  luiz.leitao
 * Implementacao da funcao DecodificarBase64.
 * Implementacao da funcao EncontrarPosicaoPonteiroCaractere.
 *
 * Revision 1.1  2019/10/16 20:26:07  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao do arquivo de cabecalho da biblioteca padrao da linguagem. */

#include <string.h>





/* Inclusao do arquivo de cabecalho personalizado para o trabalho. */

#include "aula0901.h"





/* Implementacao da funcao CodificarBase64. */

tipoErros
CodificarBase64(byte *entrada, unsigned numeroBytes, char *saida)
{

  /* Utilizacao de variaveis locais dentro da funcao CodificarBase64. */

  ush indiceEntrada, indiceSaida, resto;





  /* Verificacao da existencia de argumento nulo. */

  if (!entrada)
    return argumentoNulo;  /* 4 */





  /* Verificacao da existencia de argumento nulo. */

  if (!saida)
    return argumentoNulo;  /* 4 */




  /* Inicializacao das variaveis indice. */

  indiceEntrada = 0;
  indiceSaida = 0;


  

  
  /* Varredura do argumento passado como parametro de entrada. */

  while ((indiceEntrada % TAMANHO_DO_BLOCO_DE_CODIFICACAO == 0) &&
         (indiceEntrada + TAMANHO_DO_BLOCO_DE_CODIFICACAO <= numeroBytes))
  {

    /* Transformacao dos 3 bytes de entrada em 4 bytes de saida. */

    *(saida + indiceSaida) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada) >> 2) & 0x03F)];

    *(saida + (indiceSaida + 1)) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada) << 4) & 0x30) |
                                                    ((*(entrada + (indiceEntrada + 1)) >> 4) & 0x0F)];

    *(saida + (indiceSaida + 2)) = CONJUNTO_BASE_64[((*(entrada + (indiceEntrada + 1)) << 2) & 0x3C) |
                                                    ((*(entrada + (indiceEntrada + 2)) >> 6) & 0x03)];

    *(saida + (indiceSaida + 3)) = CONJUNTO_BASE_64[(*(entrada + (indiceEntrada + 2)) & 0x3F)];



    /* Saltos para os grupos seguintes de 3 bytes de entrada e 4 bytes de saida. */

    indiceEntrada += 3;
    indiceSaida += 4;



    /* Verificacao de final de linha. */

    if (indiceSaida % TAMANHO_MAXIMO_DA_LINHA_DE_DECODIFICACAO == 0)
    {
      *(saida + indiceSaida) = RLN;
      *(saida + (indiceSaida + 1)) = NWL;

      indiceSaida += 2;
    } /* if */

  } /* while */





  /* Calculo do resto. */

  resto = (numeroBytes - indiceEntrada);





  /* Verificacao do caso em que restam 2 bytes no final (padding simples). */

  if (resto == 2)
  { 

    /* Transformacao dos 2 bytes de entrada em 4 bytes de saida. */

    *(saida + indiceSaida) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada)  >> 2) & 0x3F)];

    *(saida + (indiceSaida + 1)) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada) << 4) & 0x30) |
                                                    ((*(entrada + (indiceEntrada + 1)) >> 4) & 0x0F)];

    *(saida + (indiceSaida + 2)) = CONJUNTO_BASE_64[((*(entrada + (indiceEntrada + 1)) << 2) & 0x3C)];

    *(saida + (indiceSaida + 3)) = PADDING;



    /* Saltos para os finais do vetor e da string. */

    indiceEntrada += 2;
    indiceSaida += 4;



    /* Insercao dos caracteres de controle. */

    *(saida + indiceSaida) = RLN;
    *(saida + (indiceSaida + 1)) = NWL;



    /* Salto para o final da string. */

    indiceSaida += 2;

  } /* if */





  /* Verificacao do caso em que resta 1 byte no final (padding duplo). */

  if (resto == 1)
  {	

    /* Transformacao do byte de entrada em 4 bytes de saida. */

    *(saida + indiceSaida) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada) >> 2) & 0x3F)];

    *(saida + (indiceSaida + 1)) = CONJUNTO_BASE_64[((*(entrada + indiceEntrada) << 4) & 0x30)];

    *(saida + (indiceSaida + 2)) = PADDING;

    *(saida + (indiceSaida + 3)) = PADDING;



    /* Saltos para os finais do vetor e da string. */

    indiceEntrada += 1;
    indiceSaida += 4;



    /* Insercao dos caracteres de controle. */

    *(saida + indiceSaida) = RLN;
    *(saida + (indiceSaida + 1)) = NWL;



    /* Salto para o final da string. */

    indiceSaida += 2;

  } /* if */





  /* Insercao do caractere de controle. */

  *(saida + indiceSaida) = EOS;





  return ok;  /* 0 */

} /* CodificarBase64 */










/* Implementacao da funcao DecodificarBase64. */

tipoErros
DecodificarBase64(char *entrada, byte *saida, unsigned *numeroBytes)
{

  /* Utilizacao de variaveis locais dentro da funcao DecodificarBase64. */ 

  ush indiceEntrada, indiceSaida, indiceLinhas, comprimentoEntrada;





  /* Verificacao da existencia de argumento nulo. */

  if (!entrada)
    return argumentoNulo;  /* 4 */





  /* Verificacao da existencia de argumento nulo. */

  if (!saida)
    return argumentoNulo;  /* 4 */





  /* Verificacao da existencia de argumento vazio. */

  if (*entrada == EOS)
    return argumentoVazio;  /* 5 */





  /* Chamada da funcao interna do sistema. */

  comprimentoEntrada = strlen(entrada);





  /* */

  for (indiceEntrada = 0, indiceLinhas = 1; indiceEntrada < comprimentoEntrada; indiceEntrada++, indiceLinhas++)
  {
    if (*(entrada + (TAMANHO_DO_BLOCO_DE_DECODIFICACAO)))

  }


  /* Verificacao da existencia de comprimento invalido. */

  /* if (comprimentoEntrada % TAMANHO_DO_BLOCO_DE_DECODIFICACAO != 0)
       return comprimentoInvalido; */ /* 3 */




  /* Verificacao da existencia de caracteres invalidos. */

  for (indiceEntrada = 0; indiceEntrada < comprimentoEntrada; indiceEntrada++)
    if ((!strchr(CONJUNTO_BASE_64, *(entrada + indiceEntrada))) &&
        (*(entrada + indiceEntrada) != PADDING) &&
        (*(entrada + indiceEntrada) != RLN) &&
         (*(entrada + indiceEntrada) != NWL))
      return caractereInvalido;  /* 6 */





  /* Verificacao da existencia de caractere invalido. */

  for (indiceEntrada = 0; indiceEntrada < comprimentoEntrada; indiceEntrada++)
    if ((*(entrada + indiceEntrada) == PADDING) &&
        ((indiceEntrada != (comprimentoEntrada - 2)) &&
         (indiceEntrada != (comprimentoEntrada - 1))))
      return caractereInvalido;  /* 6 */





  /* Inicializacao das variaveis indice. */  

  indiceEntrada = 0;
  indiceSaida = 0;





  /* Varredura pelo parametro de entrada. */

  while ((indiceEntrada + 4) <= comprimentoEntrada)
  {

    /* Verificacao de final de linha (estilo Windows) */

    if ((*(entrada + indiceEntrada) == RLN) && (*(entrada + (indiceEntrada + 1)) == NWL))     
      indiceEntrada += 2;





    /* Verificacao do caso em que ha padding duplo. */

    if ((*(entrada + (indiceEntrada + 2)) == PADDING) && (*(entrada + (indiceEntrada + 3)) == PADDING))
    {
      *(saida + indiceSaida) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + indiceEntrada)) << 2)) |
                               ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 1))) >> 4));

      indiceSaida -= 2;
    } /* if */



    /* Verificacao do caso em que ha padding simples. */

    else if ((*(entrada + (indiceEntrada + 2)) != PADDING) && (*(entrada + (indiceEntrada + 3)) == PADDING))
    {
      *(saida + indiceSaida) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + indiceEntrada)) << 2)) |
                               ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 1))) >> 4));

      *(saida + (indiceSaida + 1)) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 1))) << 4)) |
                                     ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 2))) >> 2));

      indiceSaida -= 1;
    } /* else if */



    /* Verificacao do caso em que nao ha padding. */

    else
    {
      *(saida + indiceSaida) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + indiceEntrada)) << 2)) |
                               ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 1))) >> 4));

      *(saida + (indiceSaida + 1)) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 1))) << 4)) |
                                     ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 2))) >> 2));

      *(saida + (indiceSaida + 2)) = ((EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 2))) << 6)) |
                                      (EncontrarPosicaoPonteiroCaractere(CONJUNTO_BASE_64, *(entrada + (indiceEntrada + 3))));
    } /* else */

    

    /* Incremento nas variaveis indice. */  

    indiceEntrada += 4;
    indiceSaida += 3;

  } /* while */





  /* Atribuicao de valor ao parametro de saida. */

  *numeroBytes = indiceSaida;





  return ok;  /* 0 */

} /* DecodificarBase64 */










/* Implementacao da funcao EncontrarPosicaoPonteiroCaractere. */

byte
EncontrarPosicaoPonteiroCaractere(char *conjuntoCaracteres, char caractere)
{

  /* Utilizacao de variaveis locais dentro da funcao EncontrarPosicaoPonteiroCaractere. */

  char *ponteiroCaractere;
  byte posicaoPonteiroCaractere;





  /* Chamada de funcao interna do sistema. */

  ponteiroCaractere = strchr(conjuntoCaracteres, caractere);





  /* Determinacao da posicao do caractere. */

  posicaoPonteiroCaractere = (byte) (ponteiroCaractere - conjuntoCaracteres);





  /* Retorno da funcao. */

  return posicaoPonteiroCaractere;

} /* EncontrarPosicaoPonteiroCaractere */










/* $RCSfile: aula0901.c,v $ */
