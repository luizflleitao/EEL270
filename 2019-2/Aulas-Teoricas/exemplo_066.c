#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/mlcgi.h"

#define NUMERO_ARGUMENTOS             2
#define AMBIENTE_EXECUCAO_INVALIDO    1
#define COMPRIMENTO_MAXIMO_STRING     2


int
main (int argc, char **argv)
{
  unsigned codigoRetorno;
  environmentType ambienteExecucao;
  char numeroString [COMPRIMENTO_MAXIMO_STRING + 1];
  unsigned short numero;
  char *validacao;
  double resultado;

  if ((codigoRetorno = mlCgiInitialize (&ambienteExecucao)) != ML_CGI_OK)
    exit (ML_CGI_OK);

  if (ambienteExecucao ==  commandLine)
  {
    printf ("Ambiente de execucao invalido\n");
    exit (AMBIENTE_EXECUCAO_INVALIDO);
  }

  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

/*
  if ((codigoRetorno = 
    mlCgiGetFormStringNoNewLines ("numero", numeroString, COMPRIMENTO_MAXIMO_STRING)))
*/

  codigoRetorno = 
    mlCgiGetFormStringNoNewLines ("numero", numeroString, COMPRIMENTO_MAXIMO_STRING);
  if (codigoRetorno != ML_CGI_OK)
  {
    /* exibir uma pagina HTML de erro */
    printf ("<html>\nErro #%u\n...</html>\n", codigoRetorno);
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  numero = (unsigned short) strtoul (numeroString, &validacao, 10);
  if (*validacao != '\0')
  {
    /* exibir uma pagina HTML de erro */
    printf ("<html>\nN&uacute;mero inv&aacute;lido\n...</html>\n");
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  resultado = 1;
  while (numero > 1)
  {
    resultado *= numero;
    numero--;
  }
  
  printf ("<html>\n");
  printf ("  <head>\n");
  printf ("    <title>\n");
  printf ("      C&aacute;lculo de Fatorial\n");
  printf ("    </title>\n");
  printf ("  </head>\n");
  printf ("  <body bgcolor=\"cyan\">\n");
  printf ("      C&aacute;lculo de Fatorial<br><br><\n");
  printf ("      %s!: %f\n", numeroString, resultado);
  printf ("  </body>\n");
  printf ("</html>\n");

  mlCgiFreeResources ();
  return ML_CGI_OK;
}

