/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2018/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * $Author$
 * $Date$
 *
 * $Log$
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/mlcgi.h"

#define EOS					'\0'

#define AMBIENTE_EXECUCAO_INVALIDO		1

#define COMPRIMENTO_MAXIMO_IDIOMA		16
#define COMPRIMENTO_MAXIMO_USUARIO		64
#define COMPRIMENTO_MAXIMO_SENHA		127
#define COMPRIMENTO_MAXIMO_ENDERECO_IP		15

/* criar tipo tipoIdiomas */
int 
main (int argc, char *argv [])
{
  /* variavel mensagens */
  /* variavel indiceIdioma inicializa com idioma padrao */
  environmentType ambiente;
  unsigned codigoRetorno;
  char idioma [COMPRIMENTO_MAXIMO_IDIOMA + 1];
  char usuario [COMPRIMENTO_MAXIMO_USUARIO + 1];
  char senha [COMPRIMENTO_MAXIMO_SENHA + 1];
  char enderecoIp [COMPRIMENTO_MAXIMO_ENDERECO_IP + 1];

  if ((codigoRetorno = mlCgiInitialize (&ambiente)) != ML_CGI_OK)
    exit (codigoRetorno);

  if (ambiente == commandLine) 
  {
    printf ("Ambiente de execucao invalido\n");
    exit (AMBIENTE_EXECUCAO_INVALIDO);
  }
 
  /* codigo referente a execucao via web */
  mlCgiBeginHttpHeader ("text/html");

  if ((codigoRetorno = 
         mlCgiGetFormStringNoNewLines ("idioma", idioma, COMPRIMENTO_MAXIMO_IDIOMA)) != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* Criar o codigo HTML de uma pagina de erro - preferencialmente
       atraves de uma funcao */
    printf ("Erro obtendo o campo idioma !!! Erro numero: %u \n", codigoRetorno);
    mlCgiFreeResources ();
    exit (codigoRetorno);
  }

  /* atribuir a indiceIdioma o valor correto */

  if ((codigoRetorno = 
         mlCgiGetFormStringNoNewLines ("usuario", usuario, COMPRIMENTO_MAXIMO_USUARIO)) != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* Criar o codigo HTML de uma pagina de erro - preferencialmente
       atraves de uma funcao usando o idioma desejado */
    printf ("Erro obtendo o campo usuario !!! Erro numero: %u \n", codigoRetorno);
    mlCgiFreeResources ();
    exit (codigoRetorno);
  }

  if ((codigoRetorno = 
         mlCgiGetFormStringNoNewLines ("senha", senha, COMPRIMENTO_MAXIMO_SENHA)) != ML_CGI_OK)
  {
    mlCgiEndHttpHeader ();
    /* Criar o codigo HTML de uma pagina de erro - preferencialmente
       atraves de uma funcao usando o idioma desejado */
    printf ("Erro obtendo o campo senha !!! Erro numero: %u \n", codigoRetorno);
    mlCgiFreeResources ();
    exit (codigoRetorno);
  }

  /* chamar funcao de autenticacao */
  if (strcmp (usuario, "aluna") || strcmp (senha, "123456"))
  {
    mlCgiEndHttpHeader ();
    /* Criar o codigo HTML de uma pagina de erro - preferencialmente
       atraves de uma funcao usando o idioma desejado */
    printf ("Usuario inexistente ou senha incorreta\n");
    mlCgiFreeResources ();
    exit (codigoRetorno);
  }

  mlCgiGetEnvironmentVariableValue (ML_CGI_REMOTE_ADDRESS, enderecoIp);

  /* Gerar/definir/identificar os campos do cookie */
  /* nome do cookie <- identicador numerico com 20 digitos */
  /* valor do cookie <- string aleatoria com 1024 caracteres gerados a partir do BASE64 */
  /* validade <- 30 min (convertidos para segundos) */
  /* criar arquivo de cookie com os dados: validade absoluta (time_t), valor e ip */

  mlCgiSetCookie ("CONFUSAO", "aeiou", 600, NULL, NULL, NULL);
  mlCgiEndHttpHeader ();

  /* Criar menu */
  printf ("<html>\n");
  printf ("  <head>\n");
  printf ("    <title>\n");
  printf ("      Sistema de Liberdade Condicional\n");
  printf ("    </title>\n");
  printf ("  </head>\n");
  printf ("  <body bgcolor=\"white\">\n");
  printf ("    <div align=\"center\">\n");
  printf ("      %s<br><br>%s", usuario, enderecoIp);
  printf ("    </div>\n");
  /* printfs com o menu */
  printf ("  </body>\n");
  printf ("</html>\n");
  
  mlCgiFreeResources ();
  return ML_CGI_OK;

}
/* $RCSfile$ */
