/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: <nome completo>
 * Descricao: <descricao sucinta sobre o programa>
 *
 * $Author$
 * $Date$
 * $Log$
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/mlcgi.h"

#define OK					0
#define AMBIENTE_EXECUCAO_INVALIDO		1

#define COMPRIMENTO_MAXIMO_IDIOMA		32
#define COMPRIMENTO_MAXIMO_USUARIO		32
#define COMPRIMENTO_MAXIMO_SENHA		127

#define EOS '\0'

int
main (int argc, char **argv)
{
  unsigned codigoRetorno;
  environmentType ambienteExecucao;
  char idioma [COMPRIMENTO_MAXIMO_IDIOMA + 1];
  char usuario [COMPRIMENTO_MAXIMO_USUARIO + 1];
  char senha [COMPRIMENTO_MAXIMO_SENHA + 1];

  if (mlCgiInitialize (&ambienteExecucao))
    exit (ML_CGI_OK);

  if (ambienteExecucao == commandLine)
  {
    printf ("Ambiente de execucao invalido\n");
    exit (AMBIENTE_EXECUCAO_INVALIDO);
  }

  mlCgiBeginHttpHeader ("text/html");
  /* mlCgiBeginHttpHeader (NULL); */

  codigoRetorno = 
    mlCgiGetFormStringNoNewLines ("idioma", idioma, COMPRIMENTO_MAXIMO_IDIOMA);
  if (codigoRetorno != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* chamar uma funcao que cria o codigo HTML de uma pagina de erro */
    printf ("<html>\n");
    printf ("  <head>\n");
    printf ("    <title>\n");
    printf ("      P&aacute;gina de Erro\n");
    printf ("    </title>\n");
    printf ("  </head>\n");
    printf ("  <body>\n");
    printf ("      Erro obtendo o campo \"idioma\". Erro #%u\n", codigoRetorno);
    printf ("  </body>\n");
    printf ("</html>\n");
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  codigoRetorno = 
    mlCgiGetFormStringNoNewLines ("usuario", usuario, COMPRIMENTO_MAXIMO_USUARIO);
  if (codigoRetorno != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* chamar uma funcao que cria o codigo HTML de uma pagina de erro */
    printf ("<html>\n");
    printf ("  <head>\n");
    printf ("    <title>\n");
    printf ("      P&aacute;gina de Erro\n");
    printf ("    </title>\n");
    printf ("  </head>\n");
    printf ("  <body>\n");
    printf ("      Erro obtendo o campo \"usuario\". Erro #%u\n", codigoRetorno);
    printf ("  </body>\n");
    printf ("</html>\n");
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }


  codigoRetorno = 
    mlCgiGetFormStringNoNewLines ("senha", senha, COMPRIMENTO_MAXIMO_SENHA);
  if (codigoRetorno != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* chamar uma funcao que cria o codigo HTML de uma pagina de erro */
    printf ("<html>\n");
    printf ("  <head>\n");
    printf ("    <title>\n");
    printf ("      P&aacute;gina de Erro\n");
    printf ("    </title>\n");
    printf ("  </head>\n");
    printf ("  <body>\n");
    printf ("      Erro obtendo o campo \"senha\". Erro #%u\n", codigoRetorno);
    printf ("  </body>\n");
    printf ("</html>\n");
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  /* autenticar o usuario */
  if (strcmp (usuario, "aluno") || strcmp (senha, "Larica"))
  {
    mlCgiEndHttpHeader ();
    printf ("<html>\n");
    printf ("  <head>\n");
    printf ("    <title>\n");
    printf ("      P&aacute;gina de Erro\n");
    printf ("    </title>\n");
    printf ("  </head>\n");
    printf ("  <body>\n");
    printf ("    Usu&aacute;rio inexistente ou senha inv&aacute;lida \n");
    printf ("  </body>\n");
    printf ("</html>\n");
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  /* gerar valor do cookie, armazenar no arquivo local, ... */
  mlCgiSetCookie (usuario, "zaqwsx1234567890", 300, NULL, NULL, NULL);
  mlCgiEndHttpHeader ();
  
  printf ("<html>\n");
  printf ("  <head>\n");
  printf ("    <title>\n");
  printf ("      Sistema de ...\n");
  printf ("    </title>\n");
  printf ("  </head>\n");
  printf ("  <body>\n");
  printf ("    Sistema de Avalia ...  >\n");
  printf ("  </body>\n");
  printf ("</html>\n");

  mlCgiFreeResources ();
  return ML_CGI_OK;
}
