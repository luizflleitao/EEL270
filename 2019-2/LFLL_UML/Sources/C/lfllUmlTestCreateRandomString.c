/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/30 08:14:01 $
 * $Log: lfllUmlTestCreateRandomString.c,v $
 * Revision 1.1  2019/11/30 08:14:01  luiz.leitao
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

#define LFLL_UML_NUMBER_OF_ARGUMENTS					3





/* Local error codes. */

#define LFLL_UML_OK							0
#define LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_NULL		28
#define LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_EMPTY		29
#define LFLL_UML_RANDOM_STRING_INVALID_LENGTH				30
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS				101
#define LFLL_UML_INVALID_ARGUMENT					102










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  size_t lfllUmlRandomStringLength;
  char lfllUmlRandomString[LFLL_UML_RANDOM_STRING_MAXIMUM_LENGTH + 1];
  char *lfllUmlValidation;





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if ((argc > LFLL_UML_NUMBER_OF_ARGUMENTS) || (argc == (LFLL_UML_NUMBER_OF_ARGUMENTS - 2)))
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Internal function call. */

  lfllUmlRandomStringLength = strtoul(*(argv + 1), &lfllUmlValidation, 10);





  /* Tests the existence of hyphen in the first byte of the random string's length argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 1) + 0) == LFLL_UML_HYPHEN_CHARACTER)
  {
    printf("\n\n\nLocal Error #%i: the random string's length argument contains invalid characters.\n", LFLL_UML_INVALID_ARGUMENT);
    printf("Invalid character: '%c'.\n", LFLL_UML_HYPHEN_CHARACTER);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_ARGUMENT);  /* Program aborted. */
  } /* if */





  /* Tests the existence of invalid characters in the random string's length argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: the random string's length argument contains invalid characters.\n", LFLL_UML_INVALID_ARGUMENT);
    printf("Invalid character: '%c'.\n", *lfllUmlValidation);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_ARGUMENT);  /* Program aborted. */
  } /* if */





  /* External function call. */ 

  lfllUmlResult = LfllUmlCreateRandomString(*(argv + 2), lfllUmlRandomStringLength, lfllUmlRandomString);





  /* Checks if the random string's valid characters set argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #28). */

  if (lfllUmlResult == lfllUmlRandomStringValidCharactersSetNull)
  {
    printf("\n\n\nLocal Error #%i: the random string's valid characters set argument is a null pointer.\n",
           LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_NULL);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the random string's valid characters set argument is empty. */
  /* Warn about the correct use of the program (Local Error #29). */

  if (lfllUmlResult == lfllUmlRandomStringValidCharactersSetEmpty)
  {
    printf("\n\n\nLocal Error #%i: the random string's valid characters set argument is empty.\n",
           LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_EMPTY);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_RANDOM_STRING_VALID_CHARACTERS_SET_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the random string's length argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #30). */

  if (lfllUmlResult == lfllUmlRandomStringInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the random string's length argument has an invalid length.\n",
           LFLL_UML_RANDOM_STRING_INVALID_LENGTH);
    printf("Use: %s <random-string-length> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_RANDOM_STRING_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\nRandom String: %s\n\n\n\n", lfllUmlRandomString);





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCreateRandomString.c,v $ */
