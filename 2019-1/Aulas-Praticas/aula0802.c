/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/05/21 13:22:37 $
 * $Log: aula0802.c,v $
 * Revision 1.1  2019/05/21 13:22:37  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusao da biblioteca personalizada para o trabalho. */

#include "aula0801.h"





/* Implementacao do programa de testes.*/

int
main(int argc, char **argv)
{

  /* Utilizacao de variaveis locais dentro da funcao principal. */

  unsigned numeroLinhas, numeroColunas;
  unsigned ordenadaEsquerda, abscissaEsquerda;
  unsigned ordenadaDireita, abscissaDireita;
  unsigned abscissaPonto, ordenadaPonto;
  unsigned argumentos[NUMERO_DE_ARGUMENTOS - 1];
  unsigned indiceArgumento, indiceCaractere;
  unsigned resultado;
  char *validacao;
  tipoPixel monitor[NUMERO_MAXIMO_DE_LINHAS][NUMERO_MAXIMO_DE_COLUNAS];
  useconds_t tempoAtraso;




















  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao do numero de argumentos invalidos passados ao programa (Erro #01). */

  if ((argc != NUMERO_DE_ARGUMENTOS) && (argc != LER_O_MANUAL))
  {
    system("clear");
    printf("Erro #0%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  }  /* if */ 





  /* Verificacao da chamada para o manual do programa. */
  /* Informacao do numero de argumentos invalidos passados ao programa (Erro #01). */

  if ((*(*(argv + 1) + 0) != 'm') && (argc == LER_O_MANUAL))
  {
    system("clear");
    printf("\n\n\nErro #0%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <m>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */




















  /* Exibicao do manual na tela. */

  if (*(*(argv + 1) + 0) == 'm')
  {
    system("clear");

    printf("MANUAL DO USUARIO\n\n\n");

    printf("1. Objetivos\n\n");
    printf("\t- Exibe um monitor na tela.\n\n");
    printf("\t- Desenha um retangulo a partir de dois vertices escolhidos\n");
    printf("\t- (um a esquerda e outro a direita).\n\n");
    printf("\t- Preenche o retângulo (ou sua area externa) a partir de um ponto informado.\n\n\n");

    printf("2. Uso\n\n");
    printf("\t%s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n\n", argv[0]);
    printf("\t\t<A>  - Altura (Numero de Linhas do Monitor)\n");
    printf("\t\t<L>  - Largura (Numero de Colunas do Monitor)\n");
    printf("\t\t<X1> - Abscissa Esquerda do Retangulo\n");
    printf("\t\t<Y1> - Ordenada Esquerda do Retangulo\n");
    printf("\t\t<X2> - Abscissa Direita do Retangulo\n");   
    printf("\t\t<Y2> - Ordenada Direita do Retangulo\n");
    printf("\t\t<XP> - Abscissa do Ponto Informado\n");
    printf("\t\t<YP> - Ordenada do Ponto Informado\n");
    printf("\t\t<T>  - Tempo de Atraso (delay) em ms\n\n");
    printf("\t- Todos os argumentos devem ser numeros inteiros positivos.\n\n");
    printf("\t- A coordenada da abscissa direita deve ser superior a da\n");
    printf("\t  abscissa esquerda: (X2 > X1).\n\n");
    printf("\t- As coordenadas do ponto informado nao podem estar no perimetro\n");
    printf("\t  do retangulo: (((XP != X1) || ((XP == X1) && ((YP < Y1) || (YP > Y2))))\n");
    printf("\t  && ((XP != X2) || ((XP == X2) && ((YP < Y1) || (YP > Y2))))\n");
    printf("\t  && ((YP != Y1) || ((YP == Y1) && ((XP < X1) || (XP > X2))))\n");
    printf("\t  && ((YP != Y2) || ((YP == Y2) && ((XP < X1) || (XP > X2))))).\n\n");
    printf("\t- Se dois lados paralelos do retangulo (esquerdo/direito ou superior/inferior)\n");
    printf("\t  estiverem nas extremidades do monitor enquanto os outros dois nao, o ponto\n");
    printf("\t  informado devera estar dentro do retangulo.\n\n\n");

    printf("3. Definicoes\n\n");
    printf("\t- Dimensoes maximas do monitor: (%i x %i).\n\n", NUMERO_MAXIMO_DE_LINHAS, NUMERO_MAXIMO_DE_COLUNAS);
    printf("\t- Coordenadas do primeiro pixel: (%i, %i).\n\n", PIXEL_INICIAL, PIXEL_INICIAL);
    printf("\t- Tempo de atraso (delay) maximo: %i ms.\n\n\n", TEMPO_MAXIMO_DE_ATRASO);

    printf("4. Codigos de Erro\n\n");
    printf("\t#0%i  - Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("\t#0%i  - Argumento invalido.\n", ARGUMENTO_INVALIDO);
    printf("\t#0%i  - Argumento nulo.\n", ARGUMENTO_NULO);
    printf("\t#0%i  - Numero de linhas acima do permitido.\n", MAXIMO_DE_LINHAS_INVALIDO);
    printf("\t#0%i  - Numero de colunas acima do permitido.\n", MAXIMO_DE_COLUNAS_INVALIDO);
    printf("\t#0%i  - Abscissa esquerda fora dos limites estabelecidos.\n", ABSCISSA_ESQUERDA_INVALIDA);
    printf("\t#0%i  - Ordenada esquerda fora dos limites estabelecidos.\n", ORDENADA_ESQUERDA_INVALIDA);
    printf("\t#0%i  - Abscissa direita fora dos limites estabelecidos.\n", ABSCISSA_DIREITA_INVALIDA_1);
    printf("\t#0%i  - Ordenada direita fora dos limites estabelecidos.\n", ORDENADA_DIREITA_INVALIDA_1);
    printf("\t#%i  - Abscissa direita igual ou inferior a abscissa esquerda.\n", ABSCISSA_DIREITA_INVALIDA_2);
    printf("\t#%i  - Ordenada direita igual a ordenada esquerda.\n", ORDENADA_DIREITA_INVALIDA_2);
    printf("\t#%i  - Tempo de atraso (delay) invalido.\n", ATRASO_INVALIDO);
    printf("\t#%i  - Ponto informado no perimetro do retangulo.\n", PONTO_INVALIDO);
    printf("\t#%i  - Lados esquerdo e direito do retangulo nas extremidades do monitor e\n", LADOS_PARALELOS_NAS_BORDAS_1);
    printf("\t       ponto informado fora do retangulo.\n");
    printf("\t#%i  - Lados superior e inferior do retangulo nas extremidades do monitor e\n", LADOS_PARALELOS_NAS_BORDAS_2);
    printf("\t       ponto informado fora do retangulo.\n");
    printf("\t#%i  - Abscissa do ponto informado fora dos limites estabelecidos.\n", ABSCISSA_DO_PONTO_INVALIDA);
    printf("\t#%i  - Ordenada do ponto informado fora dos limites estabelecidos.\n\n\n\n", ORDENADA_DO_PONTO_INVALIDA);

    exit(MANUAL);
  } /* if */




















  /* Varredura dos argumentos passados ao programa. */

  for (indiceArgumento = 1; indiceArgumento < argc; indiceArgumento++)
  {

    /* Conversao dos argumentos passados ao programa em inteiros sem sinal. */
    /* Vetor armazena os valores dos argumentos passados ao programa. */

    argumentos[indiceArgumento - 1] = strtoul(*(argv + indiceArgumento), &validacao, 10);



    /* Verificacao da existencia de argumentos com caracteres invalidos. */
    /* Informacao da existencia de argumentos com caracteres invalidos (Erro #2). */

    if (*(*(argv + indiceArgumento) + 0) == '-')    
    {
      system("clear");
      printf("Erro #0%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
      printf("Primeira ocorrencia: argumento #%i (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Caractere invalido: '-'.\n");
      printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
      printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
      exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
    } /* if */



    /* Verificacao da existencia de argumentos com caracteres invalidos. */
    /* Informacao da existencia de argumentos com caracteres invalidos (Erro #02). */

    for (indiceCaractere = 0; *(*(argv + indiceArgumento) + indiceCaractere) != EOS; indiceCaractere++)
      if (*validacao != EOS)
      {
        system("clear");
        printf("Erro #0%i: os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
        printf("Primeira ocorrencia: argumento #%i (%s).\n", indiceArgumento, *(argv + indiceArgumento));
        printf("Caractere invalido: '%c'.\n", *validacao);
        printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
        printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
        exit(ARGUMENTO_INVALIDO);  /* Programa abortado. */
      } /* if */



    /* Verificacao da existencia de argumentos nulos. */
    /* Informacao da existencia de argumentos nulos (Erro #03). */

    if (argumentos[indiceArgumento - 1] == 0)
    {
      system("clear");
      printf("Erro #0%i: impossivel passar argumentos nulos.\n", ARGUMENTO_NULO);
      printf("Primeira ocorrencia: argumento #%i (%s).\n", indiceArgumento, *(argv + indiceArgumento));
      printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
      printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
      exit(ARGUMENTO_NULO);  /* Programa abortado. */
    } /* if */ 

  } /* for */




















  /* Variaveis locais recebem os valores dos argumentos passados ao programa. */

  numeroLinhas     = argumentos[0];
  numeroColunas    = argumentos[1];
  abscissaEsquerda = argumentos[2];
  ordenadaEsquerda = argumentos[3];
  abscissaDireita  = argumentos[4];
  ordenadaDireita  = argumentos[5];
  abscissaPonto    = argumentos[6];
  ordenadaPonto    = argumentos[7];
  tempoAtraso      = argumentos[8];




















  /* Chamada da funcao LimparMonitor. */

  resultado = LimparMonitor(monitor, numeroLinhas, numeroColunas, tempoAtraso);





  /* Verificaco da correspondencia do numero de linhas as dimensoes suportadas. */
  /* Informacao da nao correspondencia do numero de linhas as dimensoes suportadas (Erro #04). */

  if (resultado == maximoLinhasInvalido)
  {
    system("clear");
    printf("Erro #0%i: o numero de linhas (%s) excede as dimensoes do monitor (%i x %i).\n",
           MAXIMO_DE_LINHAS_INVALIDO, *(argv + 1), NUMERO_MAXIMO_DE_LINHAS, NUMERO_MAXIMO_DE_COLUNAS);
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(MAXIMO_DE_LINHAS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificaco da correspondencia do numero de colunas as dimensoes suportadas. */
  /* Informacao da nao correspondencia do numero de colunas as dimensoes suportadas (Erro #05). */

  if (resultado == maximoColunasInvalido)
  {
    system("clear");
    printf("Erro #0%i: o numero de colunas (%s) excede as dimensoes do monitor (%i x %i).\n",
           MAXIMO_DE_COLUNAS_INVALIDO, *(argv + 2), NUMERO_MAXIMO_DE_LINHAS, NUMERO_MAXIMO_DE_COLUNAS);
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(MAXIMO_DE_COLUNAS_INVALIDO);  /* Programa abortado. */
  } /* if */




















  /* Chamada da funcao DesenharRetangulo. */

  resultado = DesenharRetangulo(monitor, numeroLinhas, numeroColunas,
                                ordenadaEsquerda, abscissaEsquerda,
                                ordenadaDireita, abscissaDireita,
                                tempoAtraso);





  /* Verificacao da correspondencia do valor da abscissa esquerda as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da abscissa esquerda as dimensoes suportadas (Erro #06). */

  if (resultado == abscissaEsquerdaInvalida)
  {
    system("clear");
    printf("Erro #0%i: abscissa esquerda do retangulo (%s) superior as dimensoes especificadas (%s x %s).\n",
           ABSCISSA_ESQUERDA_INVALIDA, *(argv + 3), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ABSCISSA_ESQUERDA_INVALIDA);  /* Programa abortado. */
  } /* if */





  /* Verificacao da correspondencia do valor da ordenada esquerda as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da ordenada esquerda as dimensoes suportadas (Erro #07). */

  if (resultado == ordenadaEsquerdaInvalida)
  {
    system("clear");
    printf("Erro #0%i: ordenada esquerda do retangulo (%s) superior as dimensoes especificadas (%s x %s).\n",
           ORDENADA_ESQUERDA_INVALIDA, *(argv + 4), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ORDENADA_ESQUERDA_INVALIDA);  /* Programa abortado. */
  } /* if */





  /* Verificacao da correspondencia do valor da abscissa direita as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da abscissa direita as dimensoes suportadas (Erro #8). */

  if (resultado == abscissaDireitaInvalida1)
  {
    system("clear");
    printf("Erro #0%i: abscissa direita do retangulo (%s) superior as dimensoes especificadas (%s x %s).\n",
           ABSCISSA_DIREITA_INVALIDA_1, *(argv + 5), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ABSCISSA_DIREITA_INVALIDA_1);  /* Programa abortado. */
  } /* if */





  /* Verificacao da correspondencia do valor da ordenada direita as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da ordenada direita as dimensoes suportadas (Erro #09). */

  if (resultado == ordenadaDireitaInvalida1)
  {
    system("clear");
    printf("Erro #0%i: ordenada direita do retangulo (%s) superior as dimensoes especificadas (%s x %s).\n",
           ORDENADA_DIREITA_INVALIDA_1, *(argv + 6), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ORDENADA_DIREITA_INVALIDA_1);  /* Programa abortado. */
  } /* if */





  /* Verificacao da inferioridade numerica da abscissa esquerda em relacao a direita. */
  /* Informacao da nao inferioridade numerica da abscissa esquerda em relacao a direita (Erro #10). */

  if (resultado == abscissaDireitaInvalida2)
  {
    system("clear");
    printf("Erro #%i: abscissa direita do retangulo (%s) igual ou inferior a abscissa esquerda (%s).\n",
           ABSCISSA_DIREITA_INVALIDA_2, *(argv + 5), *(argv + 3));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ABSCISSA_DIREITA_INVALIDA_2);  /* Programa abortado. */
  } /* if */





  /* Verificacao da desigualdade numerica da ordenada direita em relacao a esquerda. */
  /* Informacao da nao desigualdade numerica da ordenada direita em relacao a esquerda (Erro #11). */

  if (resultado == ordenadaDireitaInvalida2)
  {
    system("clear");
    printf("Erro #%i: ordenada direita do retangulo (%s) igual a ordenada esquerda (%s).\n",
           ORDENADA_DIREITA_INVALIDA_2, *(argv + 6), *(argv + 4));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ORDENADA_DIREITA_INVALIDA_2);  /* Programa abortado. */
  } /* if */





  /* Verificacao do tempo de atraso (delay) informado. */
  /* Informacao da invalidez do tempo de atraso (delay) informado (Erro #12). */

  if (resultado == atrasoInvalido)
  {
    system("clear");
    printf("Erro #%i: tempo de atraso (%s ms) invalido.\n", ATRASO_INVALIDO, *(argv + 9));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Tempo de atraso (delay) maximo: 1000 ms.\n");
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ATRASO_INVALIDO);  /* Programa abortado. */
  } /* if */




















  /* Verificacao da localizacao do ponto informado. */
  /* Informacao da localizacao do ponto informado no perimetro do retangulo (Erro #13). */

  if ((abscissaPonto >= abscissaEsquerda) && (abscissaPonto <= abscissaDireita) &&
      ((ordenadaPonto == ordenadaEsquerda) || (ordenadaPonto == ordenadaDireita)))
  {
    system("clear");
    printf("Erro #%i: o ponto especificado (%s, %s) esta no perimetro do retangulo.\n",
           PONTO_INVALIDO, *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(PONTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da localizacao do ponto informado. */
  /* Informacao da localizacao ponto informado no perimetro do retangulo (Erro #13). */

  if ((ordenadaPonto >= ordenadaEsquerda) && (ordenadaPonto <= ordenadaDireita) &&
      ((abscissaPonto == abscissaEsquerda) || (abscissaPonto == abscissaDireita)))
  {
    system("clear");
    printf("Erro #%i: o ponto especificado (%s, %s) esta no perimetro do retangulo.\n",
           PONTO_INVALIDO, *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(PONTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da localizacao do ponto informado. */
  /* Informacao da localizacao ponto informado no perimetro do retangulo (Erro #13). */

  if ((ordenadaPonto <= ordenadaEsquerda) && (ordenadaPonto >= ordenadaDireita) &&
      ((abscissaPonto == abscissaEsquerda) || (abscissaPonto == abscissaDireita)))
  {
    system("clear");
    printf("Erro #%i: o ponto especificado (%s, %s) esta no perimetro do retangulo.\n",
            PONTO_INVALIDO, *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(PONTO_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de lados paralelos do retangulo nas extremidades esquerda e direita do monitor. */
  /* Informacao da existencia de lados paralelos do retangulo nas extremidades esquerda e direita do monitor (Erro #14). */

  if (((abscissaEsquerda == PIXEL_INICIAL) && (abscissaDireita == numeroColunas)) &&
      (!((ordenadaEsquerda == PIXEL_INICIAL) && (ordenadaDireita == numeroLinhas))) &&
      ((ordenadaPonto < ordenadaEsquerda) || (ordenadaPonto > ordenadaDireita)) &&
      (ordenadaEsquerda < ordenadaDireita))
  {
    system("clear");
    printf("Erro #%i: lados esquerdo [(%s, %s), (%s, %s)] e direito [(%s, %s), (%s, %s)] do retangulo\n",
           LADOS_PARALELOS_NAS_BORDAS_1, *(argv + 3), *(argv + 4), *(argv + 3), *(argv + 6), *(argv + 5),
           *(argv + 4), *(argv + 5), *(argv + 6));
    printf("nas extremidades do monitor e ponto informado (%s, %s) fora do retangulo.\n",
           *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(LADOS_PARALELOS_NAS_BORDAS_1);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de lados paralelos do retangulo nas extremidades esquerda e direita do monitor. */
  /* Informacao da existencia de lados paralelos do retangulo nas extremidades esquerda e direita do monitor (Erro #14). */

  if (((abscissaEsquerda == PIXEL_INICIAL) && (abscissaDireita == numeroColunas)) &&
      (!((ordenadaEsquerda == numeroLinhas) && (ordenadaDireita == PIXEL_INICIAL))) &&
      ((ordenadaPonto > ordenadaEsquerda) || (ordenadaPonto < ordenadaDireita)) &&
      (ordenadaEsquerda > ordenadaDireita))
  {
    system("clear");
    printf("Erro #%i: lados esquerdo [(%s, %s), (%s, %s)] e direito [(%s, %s), (%s, %s)] do retangulo\n",
           LADOS_PARALELOS_NAS_BORDAS_1, *(argv + 3), *(argv + 6), *(argv + 3), *(argv + 4), *(argv + 5),
           *(argv + 6), *(argv + 5), *(argv + 4));
    printf("nas extremidades do monitor e ponto informado (%s, %s) fora do retangulo.\n",
           *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(LADOS_PARALELOS_NAS_BORDAS_1);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de lados paralelos do retangulo nas extremidades superior e inferior do monitor. */
  /* Informacao da existencia de lados paralelos do retangulo nas extremidades superior e inferior do monitor (Erro #15). */

  if (((ordenadaEsquerda == PIXEL_INICIAL) && (ordenadaDireita == numeroLinhas)) &&
      (!((abscissaEsquerda == PIXEL_INICIAL) && (abscissaDireita == numeroColunas))) &&
      ((abscissaPonto < abscissaEsquerda) || (abscissaPonto > abscissaDireita)))
  {
    system("clear");
    printf("Erro #%i: lados superior [(%s, %s), (%s, %s)] e inferior [(%s, %s), (%s, %s)] do retangulo\n",
           LADOS_PARALELOS_NAS_BORDAS_2, *(argv + 3), *(argv + 4), *(argv + 5), *(argv + 4), *(argv + 3),
           *(argv + 6), *(argv + 5), *(argv + 6));
    printf("nas extremidades do monitor e ponto informado (%s, %s) fora do retangulo.\n",
           *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(LADOS_PARALELOS_NAS_BORDAS_2);  /* Programa abortado. */
  } /* if */





  /* Verificacao da existencia de lados paralelos do retangulo nas extremidades superior e inferior do monitor. */
  /* Informacao da existencia de lados paralelos do retangulo nas extremidades superior e inferior do monitor (Erro #15). */

  if (((ordenadaEsquerda == numeroLinhas) && (ordenadaDireita == PIXEL_INICIAL)) &&
      (!((abscissaEsquerda == PIXEL_INICIAL) && (abscissaDireita == numeroColunas))) &&
      ((abscissaPonto < abscissaEsquerda) || (abscissaPonto > abscissaDireita)))
  {
    system("clear");
    printf("Erro #%i: lados superior [(%s, %s), (%s, %s)] e inferior [(%s, %s), (%s, %s)] do retangulo\n",
           LADOS_PARALELOS_NAS_BORDAS_2, *(argv + 3), *(argv + 6), *(argv + 5), *(argv + 6), *(argv + 3),
           *(argv + 4), *(argv + 5), *(argv + 4));
    printf("nas extremidades do monitor e ponto informado (%s, %s) fora do retangulo.\n",
           *(argv + 7), *(argv + 8));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(LADOS_PARALELOS_NAS_BORDAS_2);  /* Programa abortado. */
  } /* if */




















  /* Chamada da funcao PreencherPoligono. */

  resultado = PreencherPoligono(monitor, numeroLinhas, numeroColunas,
                                (ordenadaPonto - 1), (abscissaPonto - 1), tempoAtraso);





  /* Verificacao da correspondencia do valor da abscissa do ponto as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da abscissa do ponto as dimensoes suportadas (Erro #16). */

  if (resultado == abscissaPontoInvalida)
  {
    system("clear");
    printf("Erro #%i: abscissa do ponto especificado (%s) superior as dimensoes especificadas (%s x %s).\n",
           ABSCISSA_DO_PONTO_INVALIDA, *(argv + 7), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ABSCISSA_DO_PONTO_INVALIDA);  /* Programa abortado. */
  } /* if */





  /* Verificacao da correspondencia do valor da ordenada do ponto as dimensoes suportadas. */
  /* Informacao da nao correspondencia do valor da ordenada do ponto as dimensoes suportadas (Erro #17). */

  if (resultado == ordenadaPontoInvalida)
  {
    system("clear");
    printf("Erro #%i: ordenada do ponto especificado (%s) superior as dimensoes especificadas (%s x %s).\n",
           ORDENADA_DO_PONTO_INVALIDA, *(argv + 8), *(argv + 1), *(argv + 2));
    printf("Uso: %s <A> <L> <X1> <Y1> <X2> <Y2> <XP> <YP> <T>\n", *argv);
    printf("Para acessar o manual do usuario digite <%s m>.\n\n\n\n", *argv);
    exit(ORDENADA_DO_PONTO_INVALIDA);  /* Programa abortado. */
  } /* if */




















  /* Quebra tripla de linha ao final da execucao do programa. */

  printf("\n\n\n");





  return OK;  /* Codigo retornado com sucesso. */

} /* main */











/* $RCSfile: aula0802.c,v $ */
