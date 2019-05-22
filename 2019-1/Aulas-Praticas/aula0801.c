/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/21 13:22:31 $
 * $Log: aula0801.c,v $
 * Revision 1.1  2019/05/21 13:22:31  luiz.leitao
 * Initial revision
 *
 */










/* Diretiva do pre-processador utilizada somente em ambiente Linux. */

#ifdef __linux__

#define _XOPEN_SOURCE					600    /* < 700 */
#define _POSIX_X_SOURCE					10000  /* < 200809L */

#endif





/* Inclusao da biblioteca padrao da linguagem referente a diretiva anterior. */

#include <unistd.h>





/* Inclusao das demais bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0801.h"





/* Implementacao da funcao MostrarMonitor. */

tipoErros
MostrarMonitor(tipoPixel monitor[NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
               unsigned maximoLinhas, unsigned maximoColunas, useconds_t tempoAtraso)
{

  /* Utilizacao de variaveis locais dentro da funcao MostrarMonitor. */

  unsigned indiceLinha, indiceColuna;



  /* Comando para limpar o terminal antes da exibicao do conteudo. */

  system("clear");



  /* Varredura pelas linhas e colunas do monitor. */

  for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
  {
 
    /* Ajuste na exibicao dos indices do monitor. */

    if ((maximoLinhas < (EXIBICAO_DE_UM_DIGITO + 1)))
      printf("%u -  ", (indiceLinha + 1));


    /* Ajuste na exibicao dos indices do monitor. */

    if ((maximoLinhas >= (EXIBICAO_DE_UM_DIGITO + 1)) && (maximoLinhas < (EXIBICAO_DE_DOIS_DIGITOS + 1)))
    {
      if (indiceLinha < EXIBICAO_DE_UM_DIGITO)
        printf("0%u -  ", (indiceLinha + 1));
      else
        printf("%u -  ", (indiceLinha + 1));
    } /* if */


    /* Ajuste na exibicao dos indices do monitor. */

    if ((maximoLinhas >= (EXIBICAO_DE_DOIS_DIGITOS + 1)) && (maximoLinhas <= NUMERO_MAXIMO_DE_LINHAS))
    {
      if (indiceLinha < EXIBICAO_DE_UM_DIGITO)
        printf("00%u -  ", (indiceLinha + 1));
      else if ((indiceLinha >= EXIBICAO_DE_UM_DIGITO) && (indiceLinha < EXIBICAO_DE_DOIS_DIGITOS))
        printf("0%u -  ", (indiceLinha + 1));
      else
        printf("%u -  ", (indiceLinha + 1));
    } /* if */


    /* Exibicao dos pixels na tela. */
   
    for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
      printf("%c ", monitor[indiceLinha][indiceColuna] == aceso ? ACESO : APAGADO);


    /* Quebra de linha apos a exibicao do ultimo elemento. */

    printf("\n");

  } /* for */





  /* Tempo minimo de visualizacao do processo pelo usuario. */

  usleep(tempoAtraso * CONSTANTE_DE_ATRASO);



  return ok;  /* 0 */

} /* MostrarMonitor */










/* Implementacao da funcao LimparMonitor. */

tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
              unsigned maximoLinhas, unsigned maximoColunas, useconds_t tempoAtraso)
{

  /* Utilizacao de variaveis locais dentro da funcao LimparMonitor. */

  unsigned indiceLinha, indiceColuna;



  /* Verificacao do numero de linhas passadas ao programa (avalia se o
     numero de linhas esta acima das dimensoes permitidas). */

  if (maximoLinhas > NUMERO_MAXIMO_DE_LINHAS)
    return maximoLinhasInvalido;  /* 4 */



  /* Verificacao do numero de colunas passadas ao programa (avalia se o
     numero de colunas esta acima das dimensoes permitidas). */

  if (maximoColunas > NUMERO_MAXIMO_DE_COLUNAS)
    return maximoColunasInvalido;  /* 5 */



  /* Atribuicao de pixel apagado (caractere '0') para cada um dos pixels
     existentes. */

  for (indiceLinha = 0; indiceLinha < maximoLinhas; indiceLinha++)
    for (indiceColuna = 0; indiceColuna < maximoColunas; indiceColuna++)
      monitor[indiceLinha][indiceColuna] = apagado;



  /* Exibicao do monitor na tela. */

  MostrarMonitor(monitor, maximoLinhas, maximoColunas, tempoAtraso);



  return ok;  /* 0 */

} /* LimparMonitor */










/* Implementacao da funcao DesenharRetangulo. */

tipoErros
DesenharRetangulo(tipoPixel monitor[NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
                  unsigned maximoLinhas,     unsigned maximoColunas,
                  unsigned ordenadaEsquerda, unsigned abscissaEsquerda,
                  unsigned ordenadaDireita,  unsigned abscissaDireita,
                  useconds_t tempoAtraso)
{

  /* Utilizacao de variaveis locais dentro da funcao DesenharRetangulo. */

  unsigned indiceLinha, indiceColuna;



  /* Verificacao da correspondencia do valor da abscissa esquerda as dimensoes
     do monitor (abscissaEsquerda < maximoColunas). */

  if (abscissaEsquerda > maximoColunas)
    return abscissaEsquerdaInvalida;  /* 6 */



  /* Verificacao da correspondencia do valor da ordenada esquerda as dimensoes
     do monitor (ordenadaEsquerda < maximoLinhas). */

  if (ordenadaEsquerda > maximoLinhas)
    return ordenadaEsquerdaInvalida;  /* 7 */



  /* Verificacao da correspondencia do valor da abscissa direita as dimensoes
     do monitor (abscissaDireita < maximoColunas). */

  if (abscissaDireita > maximoColunas)
    return abscissaDireitaInvalida1;  /* 8 */



  /* Verificacao da correspondencia do valor da ordenada direita as dimensoes
     do monitor (ordenadaDireita < maximoLinhas). */

  if (ordenadaDireita > maximoLinhas)
    return ordenadaDireitaInvalida1;  /* 9 */



  /* Verificacao da superioridade numerica da abscissa direita em relacao 
     a abscissa esquerda (X2 > X1). */

  if (abscissaDireita <= abscissaEsquerda)
    return abscissaDireitaInvalida2;  /* 10 */



  /* Verificacao da igualdade numerica da ordenada direita em relacao a ordenada
     esquerda (Y2 == Y1). */

  if (ordenadaDireita == ordenadaEsquerda)
    return ordenadaDireitaInvalida2;  /* 11 */



  /* Verificacao do tempo de atraso (delay) informado. */

  if (tempoAtraso > TEMPO_MAXIMO_DE_ATRASO)
    return atrasoInvalido;  /* 12 */





  /* Verificacao da condicao em que sao informados o canto superior esquerdo e o
     canto inferior direito do retangulo. */

  if ((abscissaEsquerda < abscissaDireita) && (ordenadaEsquerda < ordenadaDireita))
  {

   /* Acendimento dos pixels do lado esquerdo do retangulo. */

    for (indiceLinha = (ordenadaEsquerda - 1); indiceLinha < ordenadaDireita; indiceLinha++)
    monitor[indiceLinha][abscissaEsquerda - 1] = aceso;


    /* Acendimento dos pixels do lado inferior do retangulo. */

    for (indiceColuna = (abscissaEsquerda - 1); indiceColuna < abscissaDireita; indiceColuna++)
    monitor[ordenadaDireita - 1][indiceColuna] = aceso;


    /* Acendimento dos pixels do lado direito do retangulo. */

    for (indiceLinha = (ordenadaDireita - 1); indiceLinha > (ordenadaEsquerda - 1); indiceLinha--)
    monitor[indiceLinha][abscissaDireita - 1] = aceso;


    /* Acendimento dos pixels do lado superior do retangulo. */

    for (indiceColuna = (abscissaDireita - 1); indiceColuna > (abscissaEsquerda - 1); indiceColuna--)
    monitor[ordenadaEsquerda - 1][indiceColuna] = aceso;


    /* Exibicao do monitor na tela. */

    MostrarMonitor(monitor, maximoLinhas, maximoColunas, tempoAtraso);

  } /* if */





  /* Verificacao da condicao em que sao informados o canto inferior esquerdo e o
     canto superior direito do retangulo. */

  if ((abscissaEsquerda < abscissaDireita) && (ordenadaEsquerda > ordenadaDireita))
  {

    /* Acendimento dos pixels do lado esquerdo do retangulo. */

    for (indiceLinha = (ordenadaEsquerda - 1); indiceLinha > (ordenadaDireita - 1); indiceLinha--)
    monitor[indiceLinha][abscissaEsquerda - 1] = aceso;


    /* Acendimento dos pixels do lado superior do retangulo. */

    for (indiceColuna = (abscissaEsquerda - 1); indiceColuna < abscissaDireita; indiceColuna++)
    monitor[ordenadaDireita - 1][indiceColuna] = aceso;


    /* Acendimento dos pixels do lado direito do retangulo. */

    for (indiceLinha = (ordenadaDireita - 1); indiceLinha < ordenadaEsquerda; indiceLinha++)
    monitor[indiceLinha][abscissaDireita - 1] = aceso;


    /* Acendimento dos pixels do lado inferior do retangulo. */

    for (indiceColuna = (abscissaDireita - 1); indiceColuna > (abscissaEsquerda - 1); indiceColuna--)
    monitor[ordenadaEsquerda - 1][indiceColuna] = aceso;


    /* Exibicao do monitor na tela. */

    MostrarMonitor(monitor, maximoLinhas, maximoColunas, tempoAtraso);

  } /* if */

 



  return ok;  /* 0 */

} /* DesenharRetangulo */










/* Implementacao da funcao PreencherPoligono utilizando recursividade. */

tipoErros
PreencherPoligono(tipoPixel monitor[NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS],
                  unsigned maximoLinhas, unsigned maximoColunas,
                  unsigned linha,        unsigned coluna,
                  useconds_t tempoAtraso)
{

  /* Verificacao da correspondencia do valor da abscissa do ponto as dimensoes
     do monitor (abscissaPonto < maximoColunas). */

  if ((coluna + 1) > maximoColunas)
    return abscissaPontoInvalida;  /* 16 */



  /* Verificacao da correspondencia do valor da ordenada do ponto as dimesnoes
     do monitor (abscissaPonto < maximoLinhas). */

  if ((linha + 1) > maximoLinhas)
    return ordenadaPontoInvalida;  /* 17 */





  /* Verificacao do estado do pixel desejado. */
  /* Preenchimento do monitor por solucao recursiva. */

  if (monitor[linha][coluna] == apagado)
  {

    /* Acendimento do pixel desejado. */

    monitor[linha][coluna] = aceso;



    /* Exibicao do monitor na tela. */

    MostrarMonitor(monitor, maximoLinhas, maximoColunas, tempoAtraso);



    /* Preenchimento do pixel abaixo do pixel anterior. */

    if (linha != maximoLinhas)
      PreencherPoligono(monitor, maximoLinhas, maximoColunas, (linha + 1), coluna, tempoAtraso);



    /* Preenchimento do pixel acima do pixel anterior. */

    if (linha != 0)
      PreencherPoligono(monitor, maximoLinhas, maximoColunas, (linha - 1), coluna, tempoAtraso);



    /* Preenchimento do pixel a direita do pixel anterior. */

    if (coluna != maximoColunas)
      PreencherPoligono(monitor, maximoLinhas, maximoColunas, linha, (coluna + 1), tempoAtraso);



    /* Preenchimento do pixel a esquerda do pixel anterior. */

    if (coluna != 0)
      PreencherPoligono(monitor, maximoLinhas, maximoColunas, linha, (coluna - 1), tempoAtraso);

  } /* if */



  return ok;  /* 0 */

} /* PreencherPoligono */










/* $RCSfile: aula0801.c,v $ */
