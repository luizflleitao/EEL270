/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/29 13:56:32 $
 * $Log: lfllUmlTestCheckEmail.c,v $
 * Revision 1.1  2019/11/29 13:56:32  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlFunctions.h"
#include "lfllUmlErrors.h"
#include "lfllUmlConst.h"





/* Inclusion of macro. */

#define LFLL_UML_NUMBER_OF_ARGUMENTS				2





/* Local error codes. */

#define LFLL_UML_OK						0
#define LFLL_UML_EMAIL_NULL					21
#define LFLL_UML_EMAIL_EMPTY					22
#define LFLL_UML_EMAIL_VALID_CHARACTERS_SET_NULL		23
#define LFLL_UML_EMAIL_VALID_CHARACTERS_SET_EMPTY		24
#define LFLL_UML_EMAIL_INVALID_LENGTH				25
#define LFLL_UML_EMAIL_INVALID_CHARACTER			26
#define LFLL_UML_EMAIL_INVALID_FORMAT				27
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS			101










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variable inside main function. */

  lfllUmlErrorType lfllUmlResult;





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc > LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* External function call. */ 

  lfllUmlResult = LfllUmlCheckEmail(*(argv + 1),
                                    LFLL_UML_EMAIL_VALID_CHARACTERS_SET,
                                    LFLL_UML_EMAIL_MINIMUM_LENGTH,
                                    LFLL_UML_EMAIL_MAXIMUM_LENGTH);





  /* Checks if the e-mail argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #21). */

  if (lfllUmlResult == lfllUmlEmailNull)
  {
    printf("\n\n\nLocal Error #%i: the e-mail argument is a null pointer.\n", LFLL_UML_EMAIL_NULL);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail argument is empty. */
  /* Warn about the correct use of the program (Local Error #22). */

  if (lfllUmlResult == lfllUmlEmailEmpty)
  {
    printf("\n\n\nLocal Error #%i: the e-mail argument is empty.\n", LFLL_UML_EMAIL_EMPTY);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail's set of valid characters argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #23). */

  if (lfllUmlResult == lfllUmlEmailValidCharactersSetNull)
  {
    printf("\n\n\nLocal Error #%i: the e-mail's set of valid characters is a null pointer.\n",
           LFLL_UML_EMAIL_VALID_CHARACTERS_SET_NULL);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_VALID_CHARACTERS_SET_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail's set of valid characters argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #24). */

  if (lfllUmlResult == lfllUmlEmailValidCharactersSetEmpty)
  {
    printf("\n\n\nLocal Error #%i: the e-mail's set of valid characters is an empty string.\n",
           LFLL_UML_EMAIL_VALID_CHARACTERS_SET_EMPTY);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_VALID_CHARACTERS_SET_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #25). */

  if (lfllUmlResult == lfllUmlEmailInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the e-mail argument has an invalid length.\n", LFLL_UML_EMAIL_INVALID_LENGTH);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail argument contains a invalid character. */
  /* Warn about the correct use of the program (Local Error #26). */

  if (lfllUmlResult == lfllUmlEmailInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the e-mail argument contains one or more characters which don't belong to the set of valid characters.\n", LFLL_UML_EMAIL_INVALID_CHARACTER);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the e-mail argument has an invalid format. */
  /* Warn about the correct use of the program (Local Error #27). */

  if (lfllUmlResult == lfllUmlEmailInvalidFormat)
  {
    printf("\n\n\nLocal Error #%i: the e-mail argument has an invalid format.\n", LFLL_UML_EMAIL_INVALID_FORMAT);
    printf("Use: %s <user-name>@<domain-name>\n\n\n\n", *argv);
    exit(LFLL_UML_EMAIL_INVALID_FORMAT);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\nSuccess.\n\n\n\n");





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCheckEmail.c,v $ */