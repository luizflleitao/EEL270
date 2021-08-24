/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/27 09:19:36 $
 * $Log: lfllUmlTestGetWebErrorMessage.c,v $
 * Revision 1.1  2019/11/27 09:19:36  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlErrors.h"
#include "lfllUmlConst.h"
#include "Libraries/mlcgi.h"





/* Local error codes. */

#define LFLL_UML_OK					0
#define LFLL_UML_INVALID_EXECUTION_ENVIRONMENT		101
#define LFLL_UML_INVALID_CHARACTER			102
#define LFLL_UML_INVALID_LANGUAGES_NUMBER		103
#define LFLL_UML_INVALID_ERROR_CODES_NUMBER		104










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlLanguageType lfllUmlLanguageValue;
  lfllUmlErrorType lfllUmlErrorCodeValue;
  char *lfllUmlValidation, *lfllUmlResult;
  environmentType executionEnvironment;
  char lfllUmlLanguageField[LFLL_UML_LANGUAGE_MAXIMUM_LENGTH + 1];
  char lfllUmlErrorCodeField[LFLL_UML_ERROR_CODE_MAXIMUM_LENGTH + 1];





  /* ??? */

  if (mlCgiInitialize(&executionEnvironment))
    exit(ML_CGI_OK);  /* Program aborted. */





  /* ??? */

  if (executionEnvironment == commandLine)
  {
    printf("\n\n\nLocal Error #%i: this program can only be executed on web environment.\n\n\n\n", LFLL_UML_INVALID_EXECUTION_ENVIRONMENT);
    exit(LFLL_UML_INVALID_EXECUTION_ENVIRONMENT);  /* Program aborted. */
  } /* if */





  /* ??? */

  mlCgiBeginHttpHeader("text/html");
  mlCgiEndHttpHeader();





  /* ??? */

  lfllUmlLanguageValue = mlCgiGetFormStringNoNewLines("lfllUmlLanguageValue", lfllUmlLanguageField, LFLL_UML_LANGUAGE_MAXIMUM_LENGTH);





  /* ??? */

  if ((unsigned) lfllUmlLanguageValue != ML_CGI_OK)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Web Error #%u: error obtaining \"lfllUmlLanguageValue\" field.</p>\n", lfllUmlLanguageValue);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(ML_CGI_OK);  /* Program aborted. */
  } /* if */





  /* ??? */

  lfllUmlErrorCodeValue = mlCgiGetFormStringNoNewLines("lfllUmlErrorCodeValue", lfllUmlErrorCodeField, LFLL_UML_ERROR_CODE_MAXIMUM_LENGTH);





  /* ??? */

  if ((unsigned) lfllUmlErrorCodeValue != ML_CGI_OK)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Web Error #%u: error obtaining \"lfllUmlErrorCodeValue\" field.</p>\n", lfllUmlErrorCodeValue);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(ML_CGI_OK);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlLanguageType. */

  lfllUmlLanguageValue = (lfllUmlLanguageType) strtoul(lfllUmlLanguageField, &lfllUmlValidation, 10);





  /* Tests the existence of invalid character in "lfllUmlLanguageValue" argument. */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Local Error #%i: argument \"lfllUmlLanguageValue\" contains a invalid character.</p>\n", LFLL_UML_INVALID_CHARACTER);
    printf("      <p>Invalid character: '%c'.</p>\n", *lfllUmlValidation);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(LFLL_UML_OK);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlErrorType. */

  lfllUmlErrorCodeValue = (lfllUmlErrorType) strtoul(lfllUmlErrorCodeField, &lfllUmlValidation, 10);





  /* Tests the existence of invalid character in "lfllUmlErrorCodeValue" argument. */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Local Error #%i: argument \"lfllUmlErrorCodeValue\" contains a invalid character.</p>\n", LFLL_UML_INVALID_CHARACTER);
    printf("      <p>Invalid character: '%c'.</p>\n", *lfllUmlValidation);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(LFLL_UML_OK);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered in "lfllUmlLanguageValue" argument. */
 
  if (lfllUmlLanguageValue >= lfllUmlLanguagesNumber)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Local Error #%i: argument \"lfllUmlLanguageValue\" contains a invalid value.</p>\n", LFLL_UML_INVALID_LANGUAGES_NUMBER);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(LFLL_UML_OK);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered in "lfllUmlLanguageValue" argument. */
 
  if (lfllUmlErrorCodeValue >= lfllUmlErrorCodesNumber)
  {
    printf("<html>\n");
    printf("  <head>\n");
    printf("    <title>\n");
    printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
    printf("    </title>\n");
    printf("  </head>\n");
    printf("  <body>\n");
    printf("      <p>Local Error #%i: argument \"lfllUmlErrorCodeValue\" contains a invalid value.</p>\n", LFLL_UML_INVALID_ERROR_CODES_NUMBER);
    printf("  </body>\n");
    printf("</html>\n");
    mlCgiFreeResources();
    exit(LFLL_UML_OK);  /* Program aborted. */
  } /* if */





  /* Function call. */

  lfllUmlResult = LfllUmlGetWebErrorMessage((char) lfllUmlErrorCodeValue, (char) lfllUmlLanguageValue);





  /* Shows the result on web page. */

  printf("<html>\n");
  printf("  <head>\n");
  printf("    <title>\n");
  printf("      Error Message Page (P&aacute;gina de Mensagem de Erro)\n");
  printf("    </title>\n");
  printf("  </head>\n");
  printf("  <body>\n");
  printf("      <p>%s</p>\n", lfllUmlResult);
  printf("  </body>\n");
  printf("</html>\n");





  /* ??? */

  mlCgiFreeResources();





  return ML_CGI_OK;  /* Succesful return. */

} /* main */










/* $RCSfile: lfllUmlTestGetWebErrorMessage.c,v $ */
