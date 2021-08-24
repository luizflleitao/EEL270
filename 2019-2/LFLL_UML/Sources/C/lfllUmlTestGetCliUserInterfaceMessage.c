/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/26 16:58:28 $
 * $Log: lfllUmlTestGetCliUserInterfaceMessage.c,v $
 * Revision 1.1  2019/11/26 16:58:28  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlUserInterface.h"





/* Inclusion of macros. */

#define LFLL_UML_EOS						'\0'
#define LFLL_UML_NUMBER_OF_ARGUMENTS				3




/* Local error codes. */

#define LFLL_UML_OK						0
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS			101
#define LFLL_UML_INVALID_CHARACTER				102
#define LFLL_UML_INVALID_LANGUAGES_NUMBER			103
#define LFLL_UML_INVALID_USER_INTERFACE_MESSAGES_NUMBER		104





/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlLanguageType lfllUmlLanguageValue;
  lfllUmlUserInterfaceMessageNumberType lfllUmlUserInterfaceMessageValue;
  char *lfllUmlValidation, *lfllUmlResult;




  /* Tests the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc != LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlLanguageType. */

  lfllUmlLanguageValue = (lfllUmlLanguageType) strtoul(*(argv + 1), &lfllUmlValidation, 10);





  /* Tests the existence of hyphen in the first byte of the first argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nLocal Error #%i: one or more arguments have invalid characters.\n", LFLL_UML_INVALID_CHARACTER);
    printf("Invalid character: '-'.\n");
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the existence of invalid characters in the first argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: one or more arguments have invalid characters.\n", LFLL_UML_INVALID_CHARACTER);
    printf("Invalid character: '%c'.\n", *lfllUmlValidation);
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered. */
  /* Warn about the correct use of the program (Local Error #103). */

  if (lfllUmlLanguageValue >= lfllUmlLanguagesNumber)
  {
    printf("\n\n\nLocal Error #%i: invalid language value.\n", LFLL_UML_INVALID_LANGUAGES_NUMBER);
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_LANGUAGES_NUMBER);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlUserInterfaceMessageNumberType. */

  lfllUmlUserInterfaceMessageValue = (lfllUmlUserInterfaceMessageNumberType) strtoul(*(argv + 2), &lfllUmlValidation, 10);





  /* Tests the existence of hyphen in the first byte of the second argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 2) + 0) == '-')
  {
    printf("\n\n\nLocal Error #%i: one or more arguments have invalid characters.\n", LFLL_UML_INVALID_CHARACTER);
    printf("Invalid character: '-'.\n");
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the existence of invalid characters in the second argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: one or more arguments have invalid characters.\n", LFLL_UML_INVALID_CHARACTER);
    printf("Invalid character: '%c'.\n", *lfllUmlValidation);
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered. */
  /* Warn about the correct use of the program (Local Error #104). */

  if (lfllUmlUserInterfaceMessageValue >= lfllUmlUserInterfaceMessagesNumber)
  {
    printf("\n\n\nLocal Error #%i: invalid user interface message value.\n", LFLL_UML_INVALID_USER_INTERFACE_MESSAGES_NUMBER);
    printf("Use: %s <language value> <user interface message value>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_USER_INTERFACE_MESSAGES_NUMBER);  /* Program aborted. */
  } /* if */





  /* Function call. */

  lfllUmlResult = LfllUmlGetCliUserInterfaceMessage((char) lfllUmlUserInterfaceMessageValue, (char) lfllUmlLanguageValue);





  /* Shows the result on screen. */

  printf("\n\n\n%s\n\n\n\n", lfllUmlResult);





  return LFLL_UML_OK;  /* Successful return. */

} /* main */





/* $RCSfile: lfllUmlTestGetCliUserInterfaceMessage.c,v $ */
