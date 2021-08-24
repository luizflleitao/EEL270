/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author$
 * $Date$
 * $Log$
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlErrors.h"
#include "lfllUmlConst.h"
#include "lfllUmlFunctions.h"
#include "Libraries/mlcgi.h"





/* Local error codes. */

#define LFLL_UML_OK					0
#define LFLL_UML_INVALID_EXECUTION_ENVIRONMENT		101
#define LFLL_UML_INVALID_CHARACTER			102
#define LFLL_UML_INVALID_LANGUAGES_NUMBER		104










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  /* char *lfllUmlValidation, *lfllUmlResult; */
  environmentType executionEnvironment;
  char lfllUmlLanguageField[LFLL_UML_LANGUAGE_MAXIMUM_LENGTH + 1];
  char lfllUmlConfigurationFileNameField[LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH + 1];
  unsigned lfllUmlReturnedCode;





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





  /* ???*/

  lfllUmlReturnedCode = mlCgiGetFormStringNoNewLines("lfllUmlConfigurationFileNameField",
		                                     lfllUmlConfigurationFileNameField,
                                                     LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH);





  /* ??? */

  if ((unsigned) lfllUmlReturnedCode != ML_CGI_OK)
  {
    mlCgiEndHttpHeader();
    printf("<html>\n");
    printf("<script>alert(\"Error!\")</script>\n");
    mlCgiFreeResources();
    exit(ML_CGI_OK);  /* Program aborted. */
  } /* if */



  /* ??? */

  lfllUmlReturnedCode = mlCgiGetFormStringNoNewLines("lfllUmlLanguageValue",
		                                     lfllUmlLanguageField,
						     LFLL_UML_LANGUAGE_MAXIMUM_LENGTH);

  /* ??? */

  if ((unsigned) lfllUmlReturnedCode != ML_CGI_OK)
  {
    mlCgiEndHttpHeader();
    printf("<html>\n");
    printf("<script>alert(\"Error!\")</script>\n");
    mlCgiFreeResources();
    exit(ML_CGI_OK);  /* Program aborted. */
  } /* if */


  /* */

  mlCgiEndHttpHeader();


  /* ??? */

  mlCgiFreeResources();





  return ML_CGI_OK;  /* Succesful return. */

} /* main */




/* $RCSfile$ */
