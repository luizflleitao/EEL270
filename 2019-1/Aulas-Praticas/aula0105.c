/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author: luiz.leitao $
 * $Date: 2019/03/29 06:10:53 $
 * $Log: aula0105.c,v $
 * Revision 1.1  2019/03/29 06:10:53  luiz.leitao
 * Initial revision
 *
 */










/* Inclusao das bibliotecas padrao da linguagem. */

#include <stdio.h>
#include <stdlib.h>





/* Codigos de retorno. */

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1





/* Definicao da macros. */

#define NUMERO_DE_ARGUMENTOS				1
#define NUMERO_DE_HIFENS				80










/* Implementacao do programa de testes. */

int
main(int argc, char **argv)
{

  /* Utilizacao de variavel local dentro da funcao principal. */

  unsigned indice = 0;





  /* Verificacao do numero de argumentos passados ao programa. */
  /* Informacao da quantidade invalida de argumentos passados ao programa (Erro #1). */

  if (argc != NUMERO_DE_ARGUMENTOS)
  {
    printf("\n\n\nErro #%i: numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
    printf("Uso: %s \n\n\n\n", *argv);
    exit(NUMERO_DE_ARGUMENTOS_INVALIDO);  /* Programa abortado. */
  } /* if */





  /* Determinacao do tamanho dos tipos basicos da linguagem C. */
  /* Utilizacao do operador ternario dentro da funcao printf. */

  printf("\n\n\n\t\"- Tipos Basicos -\"\n\n");

  printf("char:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(char), sizeof(char) > 1 ? "s\n\n" : "\n\n");

  printf("int:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(int), sizeof(int) > 1 ? "s\n\n" : "\n\n");
  
  printf("float:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(float), sizeof(float) > 1 ? "s\n\n" : "\n\n");

  printf("double:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(double), sizeof(double) > 1 ? "s\n\n" : "\n\n");

  printf("void:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(void), sizeof(void) > 1 ? "s\n\n" : "\n\n");





  /* Preenchimento da linha de separacao utilizando hifens. */

  while (indice < NUMERO_DE_HIFENS)
  {
    printf("-");
    indice++;
  } /* while */





  /* Reinicializacao da variavel indice. */

  indice = 0;





  /* Determinacao do tamanho dos modificadores de sinal da linguagem C. */
  /* Utilizacao do operador ternario dentro da funcao printf. */

  printf("\n\n\t\"- Modificadores de Sinal -\"\n\n");

  printf("signed:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed), sizeof(signed) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned), sizeof(unsigned) > 1 ? "s\n\n" : "\n\n");





  /* Preenchimento da linha de separacao utilizando hifens. */

  while (indice < NUMERO_DE_HIFENS)
  {
    printf("-");
    indice++;
  } /* while */





  /* Reinicializacao da variavel indice. */

  indice = 0;





  /* Determinacao do tamanho dos modificadores de largura da linguagem C. */
  /* Utilizacao do operador ternario dentro da funcao printf. */

  printf("\n\n\t\"- Modificadores de Largura -\"\n\n");

  printf("short:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(short), sizeof(short) > 1 ? "s\n\n" : "\n\n");

  printf("long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(long), sizeof(long) > 1 ? "s\n\n" : "\n\n");

  printf("long long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(long long), sizeof(long long) > 1 ? "s\n\n" : "\n\n");





  /* Preenchimento da linha de separacao utilizando hifens. */

  while (indice < NUMERO_DE_HIFENS)
  {
    printf("-");
    indice++;
  } /* while */





  /* Reinicializacao da variavel indice. */

  indice = 0;





  /* Determinacao do tamanho dos modificadores de sinal combinados com os modificadores de largura da linguagem C. */
  /* Utilizacao do operador ternario dentro da funcao printf. */

  printf("\n\n\t\"- Modificadores de Sinal combinados com Modificadores de Largura -\"\n\n");

  printf("signed short:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed short), sizeof(signed short) > 1 ? "s\n\n" : "\n\n");

  printf("signed long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed long), sizeof(signed long) > 1 ? "s\n\n" : "\n\n");

  printf("signed long long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed long long), sizeof(signed long) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned short:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned short), sizeof(unsigned short) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned long), sizeof(unsigned long) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned long long:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned long long), sizeof(unsigned long long) > 1 ? "s\n\n" : "\n\n");





  /* Preenchimento da linha de separacao utilizando hifens. */

  while (indice < NUMERO_DE_HIFENS)
  {
    printf("-");
    indice++;
  } /* while */





  /* Determinacao do tamanho dos tipos basicos combinados com os modificadores de sinal da linguagem C. */
  /* Utilizacao do operador ternario dentro da funcao printf. */
  /* Exibicao dos tipos inexistentes na linguagem C. */

  printf("\n\n\t\"- Tipos Basicos combinados com Modificadores de Sinal -\"\n\n");

  printf("signed char:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed char), sizeof(signed char) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned char:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned char), sizeof(unsigned char) > 1 ? "s\n\n" : "\n\n");

  printf("signed int:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(signed int), sizeof(signed int) > 1 ? "s\n\n" : "\n\n");

  printf("unsigned int:\n\t\t\t\t\t\t\t%lu byte%s", (long unsigned) sizeof(unsigned int), sizeof(signed int) > 1 ? "s\n\n" : "\n\n");

  printf("\t\"- Combinacoes Invalidas -\"\n\n");
  
  printf("signed float\n");

  printf("unsigned float\n");

  printf("signed double\n");

  printf("unsigned double\n");

  printf("signed void\n");

  printf("unsigned void\n\n\n\n");





  return OK; /* Codigo retornado com sucesso. */

} /* main */










/* $RCSfile: aula0105.c,v $ */
