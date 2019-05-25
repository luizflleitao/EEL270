/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author$
 * $Date$
 * $Log$
 */






#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUMERO_DE_ARGUMENTOS				2
#define COMPRIMENTO_DO_ARGUMENTO			3
#define EOS						'\0'

#define BASE64						"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define COMPRIMENTO_DO_ARGUMENTO_INVALIDO		2






int
main(int argc, char **argv)
{

  unsigned numeroBinario, resto, indiceCaractere;
  unsigned auxiliarBinario, numeroDecimal;
  char *cadeiaEntrada, *entradaPrograma;
  char *cadeiaAuxiliar1, *cadeiaAuxiliar2, *cadeiaAuxiliar3,*cadeiaAuxiliar4;
  char *entrada1, *entrada2, *entrada3, *saida1, *saida2, *saida3, *saida4;
  char *auxiliarIntermediario1, *auxiliarIntermediario2, *auxiliarIntermediario3;
  char *auxiliarIntermediario4, *auxiliarIntermediario5, *auxiliarIntermediario6;
  unsigned char *cadeiaIntermediaria, *saidaPrograma;
  const char *hexa3F = "00111111";
  const char *hexa30 = "00110000";
  const char *hexa0F = "00001111";
  const char *hexa3C = "00111100";
  const char *hexa03 = "00000011";

  









  cadeiaEntrada = (char *) malloc(sizeof(char *));

  cadeiaAuxiliar1 = (char *) malloc(sizeof(char *));
  cadeiaAuxiliar2 = (char *) malloc(sizeof(char *));
  cadeiaAuxiliar3 = (char *) malloc(sizeof(char *));
  cadeiaAuxiliar4 = (char *) malloc(sizeof(char *));

  entrada1 = (char *) malloc(sizeof(char *)); 
  entrada2 = (char *) malloc(sizeof(char *));
  entrada3 = (char *) malloc(sizeof(char *));

  saida1 = (char *) malloc(sizeof(char *)); 
  saida2 = (char *) malloc(sizeof(char *));
  saida3 = (char *) malloc(sizeof(char *));
  saida4 = (char *) malloc(sizeof(char *));

  auxiliarIntermediario1 = (char *) malloc(sizeof(char *));
  auxiliarIntermediario2 = (char *) malloc(sizeof(char *));
  auxiliarIntermediario3 = (char *) malloc(sizeof(char *));
  auxiliarIntermediario4 = (char *) malloc(sizeof(char *));
  auxiliarIntermediario5 = (char *) malloc(sizeof(char *)); 
  auxiliarIntermediario6 = (char *) malloc(sizeof(char *));

  cadeiaIntermediaria = (unsigned char *) malloc(sizeof(unsigned char *));
  saidaPrograma = (unsigned char *) malloc(sizeof(unsigned char *));














  entradaPrograma = *(argv + 1);
 
  numeroDecimal = 0;
  auxiliarBinario = 1;

 














  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de numeroBinarios invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s <string-tres-caracteres>\n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */




  if (strlen(*(argv + 1)) != COMPRIMENTO_DO_ARGUMENTO)
  {
    printf("\n\n\nErro #%i: comprimento do numeroBinario invalido.\n", COMPRIMENTO_DO_ARGUMENTO_INVALIDO);
    printf("Uso: %s <string-tres-caracteres>\n\n\n\n", *argv);
    exit(COMPRIMENTO_DO_ARGUMENTO_INVALIDO);  /* Programa abortado. */
  } /* if */










  printf("\n\n\nEntrada:\n");
  printf("%s\n\n\n", *(argv + 1));












  for (indiceCaractere = 0; *(*(argv + 1) + indiceCaractere) != EOS; indiceCaractere++)
  {
    
    numeroBinario = *(*(argv + 1) + indiceCaractere);

    while (numeroBinario > 0)
    {
      resto = numeroBinario % 2;
      numeroDecimal = numeroDecimal + (auxiliarBinario * resto);
      numeroBinario = numeroBinario / 2;
      auxiliarBinario = auxiliarBinario * 10;
    } /* while */

    sprintf(cadeiaEntrada + strlen(cadeiaEntrada), "%08u", numeroDecimal);

    numeroDecimal = 0;
    auxiliarBinario = 1; 
  } /* for */
 


  printf("Cadeia de bits (juncao dos valores em binario dos codigos ASCII dos caracteres):\n");
  printf("%s\n\n\n", cadeiaEntrada);


  strncpy(entrada1, cadeiaEntrada, 8);
  *(entrada1 + 8) = EOS;

  strncpy(entrada2, (cadeiaEntrada + 8), 8);
  *(entrada2 + 8) = EOS;

  strncpy(entrada3, (cadeiaEntrada + 16), 8);
  *(entrada3 + 8) = EOS;


  printf("1o trecho de entrada:\n");
  printf("%s\n\n\n", entrada1);


  printf("2o trecho de entrada:\n");
  printf("%s\n\n\n", entrada2);


  printf("3o trecho de entrada:\n");
  printf("%s\n\n\n", entrada3);























  *(auxiliarIntermediario1 + 0) = '0';
  *(auxiliarIntermediario1 + 1) = '0';
  strncpy((auxiliarIntermediario1 + 2), entrada1, 6);

  printf("1o trecho intermediario (6 bits mais significativos do 1o trecho de entrada ocupam o espaco dos 6 bits\n");
  printf("menos significativos e adicao de zeros nos dois bits mais significativos):\n");
  printf("%s\n\n\n", auxiliarIntermediario1); 

  
  printf("ANDing do 1o trecho intermediario com o hexadecimal 3F (binario 00111111):\n");
  printf("%s\n", auxiliarIntermediario1);
  printf("%s\n", hexa3F);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa3F + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario1 + indiceCaractere) == '1') && (*(hexa3F + indiceCaractere) == '1'))
      *(saida1 + indiceCaractere) = '1';
    else
      *(saida1 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", saida1);


  printf("1o trecho de saida:\n");
  printf("%s\n\n\n", saida1);


  sscanf(saida1, "%u", &numeroBinario);

  while (numeroBinario > 0)
  {
    resto = numeroBinario % 10;
    numeroDecimal = numeroDecimal + resto * auxiliarBinario;
    numeroBinario = numeroBinario / 10;
    auxiliarBinario = auxiliarBinario * 2;
  } /* while */

  

  *(cadeiaIntermediaria + 0) = ((*(entradaPrograma + 0) >> 2) & 0x3F);
  *(saidaPrograma + 0) = BASE64[*(cadeiaIntermediaria + 0)];

  printf("%s (base 2) = %u (base 10) = %c (base 64)\n\n\n", saida1, numeroDecimal, *(saidaPrograma + 0));

  

  numeroDecimal = 0;
  auxiliarBinario = 1;
 
















  *(auxiliarIntermediario2 + 0) = '0';
  *(auxiliarIntermediario2 + 1) = '0';
  strncpy((auxiliarIntermediario2 + 2), (entrada1 + 6), 2);
  *(auxiliarIntermediario2 + 4) = '0';
  *(auxiliarIntermediario2 + 5) = '0';
  *(auxiliarIntermediario2 + 6) = '0';
  *(auxiliarIntermediario2 + 7) = '0';
  

  printf("2o trecho intermediario - parte 1 (2 bits menos significativos do 1o trecho de entrada ocupam o terceiro\n");
  printf("e quarto bits e adicao de zeros nos demais bits):\n");
  printf("%s\n\n\n", auxiliarIntermediario2);


  printf("ANDing do 2o trecho intermediario - parte 1 com o hexadecimal 30 (binario 00110000):\n");
  printf("%s\n", auxiliarIntermediario2);
  printf("%s\n", hexa30);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa30 + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario2 + indiceCaractere) == '1') && (*(hexa30 + indiceCaractere) == '1'))
      *(cadeiaAuxiliar1 + indiceCaractere) = '1';
    else
      *(cadeiaAuxiliar1 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", cadeiaAuxiliar1);


  *(auxiliarIntermediario3 + 0) = '0';
  *(auxiliarIntermediario3 + 1) = '0';
  *(auxiliarIntermediario3 + 2) = '0';
  *(auxiliarIntermediario3 + 3) = '0'; 
  strncpy((auxiliarIntermediario3 + 4), entrada2, 4);
  

  printf("2o trecho intermediario - parte 2 (4 bits mais significativos do 2o trecho de entrada ocupam os 4 bits\n");
  printf("menos significativos e adicao de zeros nos demais bits):\n");
  printf("%s\n\n\n", auxiliarIntermediario3);


  printf("ANDing do 2o trecho intermediario - parte 2 com o hexadecimal 0F (binario 00001111):\n");
  printf("%s\n", auxiliarIntermediario3);
  printf("%s\n", hexa0F);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa0F + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario3 + indiceCaractere) == '1') && (*(hexa0F + indiceCaractere) == '1'))
      *(cadeiaAuxiliar2 + indiceCaractere) = '1';
    else
      *(cadeiaAuxiliar2 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", cadeiaAuxiliar2);


  printf("ORing dos resultados dos dois ANDings anteriores:\n");
  printf("%s\n", cadeiaAuxiliar1);
  printf("%s\n", cadeiaAuxiliar2);
  printf("-------- |\n");

  for (indiceCaractere = 0; *(cadeiaAuxiliar1 + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(cadeiaAuxiliar1 + indiceCaractere) == '1') || (*(cadeiaAuxiliar2 + indiceCaractere) == '1'))
      *(saida2 + indiceCaractere) = '1';
    else
      *(saida2 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", saida2);


  printf("2o trecho de saida:\n");
  printf("%s\n\n\n", saida2);


  sscanf(saida2, "%u", &numeroBinario);

  while (numeroBinario > 0)
  {
    resto = numeroBinario % 10;
    numeroDecimal = numeroDecimal + resto * auxiliarBinario;
    numeroBinario = numeroBinario / 10;
    auxiliarBinario = auxiliarBinario * 2;
  } /* while */

  
  *(cadeiaIntermediaria + 1) = (((*(entradaPrograma + 0) << 4) & 0x30) | ((*(entradaPrograma + 1) >> 4) & 0x0F));
  *(saidaPrograma + 1) = BASE64[*(cadeiaIntermediaria + 1)];

  printf("%s (base 2) = %u (base 10) = %c (base 64)\n\n\n", saida2, numeroDecimal, *(saidaPrograma + 1));


  numeroDecimal = 0;
  auxiliarBinario = 1;

















  *(auxiliarIntermediario4 + 0) = '0';
  *(auxiliarIntermediario4 + 1) = '0';
  strncpy((auxiliarIntermediario4 + 2), (entrada2 + 4), 4);
  *(auxiliarIntermediario4 + 6) = '0';
  *(auxiliarIntermediario4 + 7) = '0';


  printf("3o trecho intermediario - parte 1 (4 bits menos significativos do 2o trecho de entrada ocupam o terceiro,\n");
  printf("quarto, quinto e sexto bits e adicao de zeros nos demais bits):\n");
  printf("%s\n\n\n", auxiliarIntermediario4);


  printf("ANDing do 3o trecho intermediario - parte 1 com o hexadecimal 3C (binario 00111100):\n");
  printf("%s\n", auxiliarIntermediario4);
  printf("%s\n", hexa3C);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa3C + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario4 + indiceCaractere) == '1') && (*(hexa3C + indiceCaractere) == '1'))
      *(cadeiaAuxiliar3 + indiceCaractere) = '1';
    else
      *(cadeiaAuxiliar3 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", cadeiaAuxiliar3);


  *(auxiliarIntermediario5 + 0) = '0';
  *(auxiliarIntermediario5 + 1) = '0';
  *(auxiliarIntermediario5 + 2) = '0';
  *(auxiliarIntermediario5 + 3) = '0';
  *(auxiliarIntermediario5 + 4) = '0';
  *(auxiliarIntermediario5 + 5) = '0'; 
  strncpy((auxiliarIntermediario5 + 6), entrada3, 2);


  printf("3o trecho intermediario - parte 2 (2 bits mais significativos do 3o trecho de entrada ocupam os 2 bits\n");
  printf("menos significativos e adicao de zeros nos demais bits):\n");
  printf("%s\n\n\n", auxiliarIntermediario5);


  printf("ANDing do 3o trecho intermediario - parte 2 com o hexadecimal 03 (binario 00000011):\n");
  printf("%s\n", auxiliarIntermediario5);
  printf("%s\n", hexa03);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa03 + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario5 + indiceCaractere) == '1') && (*(hexa03 + indiceCaractere) == '1'))
      *(cadeiaAuxiliar4 + indiceCaractere) = '1';
    else
      *(cadeiaAuxiliar4 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", cadeiaAuxiliar4);


  printf("ORing dos resultados dos dois ANDings anteriores:\n");
  printf("%s\n", cadeiaAuxiliar3);
  printf("%s\n", cadeiaAuxiliar4);
  printf("-------- |\n");

  for (indiceCaractere = 0; *(cadeiaAuxiliar3 + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(cadeiaAuxiliar3 + indiceCaractere) == '1') || (*(cadeiaAuxiliar4 + indiceCaractere) == '1'))
      *(saida3 + indiceCaractere) = '1';
    else
      *(saida3 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", saida3);


  printf("3o trecho de saida:\n");
  printf("%s\n\n\n", saida3);


  sscanf(saida3, "%u", &numeroBinario);

  while (numeroBinario > 0)
  {
    resto = numeroBinario % 10;
    numeroDecimal = numeroDecimal + resto * auxiliarBinario;
    numeroBinario = numeroBinario / 10;
    auxiliarBinario = auxiliarBinario * 2;
  } /* while */

  
  *(cadeiaIntermediaria + 2) = (((*(entradaPrograma + 1) << 2) & 0x3C) | ((*(entradaPrograma + 2) >> 6) & 0x03));
  *(saidaPrograma + 2) = BASE64[*(cadeiaIntermediaria + 2)];

  printf("%s (base 2) = %u (base 10) = %c (base 64)\n\n\n", saida3, numeroDecimal, *(saidaPrograma + 2));


  numeroDecimal = 0;
  auxiliarBinario = 1;













  *(auxiliarIntermediario6 + 0) = '0';
  *(auxiliarIntermediario6 + 1) = '0';
  strncpy((auxiliarIntermediario6 + 2), (entrada3 + 2), 6);

  printf("4o trecho intermediario (6 bits menos significativos do 3o trecho de entrada ocupam o espaco dos 6 bits\n");
  printf("menos significativos e adicao de zeros nos dois bits mais significativos):\n");
  printf("%s\n\n\n", auxiliarIntermediario6); 

  
  printf("ANDing do 4o trecho intermediario com o hexadecimal 3F (binario 00111111):\n");
  printf("%s\n", auxiliarIntermediario6);
  printf("%s\n", hexa3F);
  printf("-------- &\n");

  for (indiceCaractere = 0; *(hexa3F + indiceCaractere) != EOS; indiceCaractere++)
  {
    if ((*(auxiliarIntermediario6 + indiceCaractere) == '1') && (*(hexa3F + indiceCaractere) == '1'))
      *(saida4 + indiceCaractere) = '1';
    else
      *(saida4 + indiceCaractere) = '0';
  } /* for */

  printf("%s\n\n\n", saida4);


  printf("4o trecho de saida:\n");
  printf("%s\n\n\n", saida4);


  sscanf(saida4, "%u", &numeroBinario);

  while (numeroBinario > 0)
  {
    resto = numeroBinario % 10;
    numeroDecimal = numeroDecimal + resto * auxiliarBinario;
    numeroBinario = numeroBinario / 10;
    auxiliarBinario = auxiliarBinario * 2;
  } /* while */


  *(cadeiaIntermediaria + 3) = (*(entradaPrograma + 2) & 0x3F);
  *(saidaPrograma + 3) = BASE64[*(cadeiaIntermediaria + 3)];

  printf("%s (base 2) = %u (base 10) = %c (base 64)\n\n\n", saida4, numeroDecimal, *(saidaPrograma + 3));








  printf("Saida:\n");
  printf("%s\n\n\n\n", saidaPrograma);



  return OK;

}











/* $RCSfile$ */
