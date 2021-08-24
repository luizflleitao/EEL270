/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/28 10:26:52 $
 * $Log: lfllUmlTestCheckStringField.c,v $
 * Revision 1.1  2019/11/28 10:26:52  luiz.leitao
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

#define LFLL_UML_NUMBER_OF_ARGUMENTS				5





/* Local error codes. */

#define LFLL_UML_OK						0
#define LFLL_UML_STRING_NULL					8
#define LFLL_UML_STRING_EMPTY					9
#define LFLL_UML_STRING_VALID_CHARACTERS_SET_NULL		10
#define LFLL_UML_STRING_VALID_CHARACTERS_SET_EMPTY		11
#define LFLL_UML_STRING_INVALID_LENGTH				12
#define LFLL_UML_STRING_INVALID_CHARACTER			13
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS			101
#define LFLL_UML_ARGUMENT_INVALID_CHARACTER			102










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  char *lfllUmlValidation;
  size_t lfllUmlStringMinimumAllowedLength;
  size_t lfllUmlStringMaximumAllowedLength;





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if ((argc > LFLL_UML_NUMBER_OF_ARGUMENTS) ||
      (argc == (LFLL_UML_NUMBER_OF_ARGUMENTS - 4)) ||
      (argc == (LFLL_UML_NUMBER_OF_ARGUMENTS - 3)))
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Internal function call. */

  lfllUmlStringMinimumAllowedLength = strtoul(*(argv + 1), &lfllUmlValidation, 10);





  /* Checks the validity of the arguments in the program. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 1) + 0) == '-')
  {
    printf("\n\n\nLocal Error #%i: one or more arguments contain invalid characters.\n", LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Invalid character: '-'.\n");
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks the validity of the arguments in the program. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: one or more arguments contain invalid characters.\n", LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Invalid character: '%c'.\n", *lfllUmlValidation);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Internal function call. */

  lfllUmlStringMaximumAllowedLength = strtoul(*(argv + 2), &lfllUmlValidation, 10);





  /* Checks the validity of the arguments in the program. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 2) + 0) == '-')
  {
    printf("\n\n\nLocal Error #%i: one or more arguments contain invalid characters.\n", LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Invalid character: '-'.\n");
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks the validity of the arguments in the program. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: one or more arguments contain invalid characters.\n", LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Invalid character: '%c'.\n", *lfllUmlValidation);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Function call. */ 

  lfllUmlResult = LfllUmlCheckStringField(*(argv + 3), *(argv + 4),
                                          lfllUmlStringMinimumAllowedLength,
                                          lfllUmlStringMaximumAllowedLength);





  /* Checks if the string argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #8). */

  if (lfllUmlResult == lfllUmlStringNull)
  {
    printf("\n\n\nLocal Error #%i: the string argument is a null pointer.\n", LFLL_UML_STRING_NULL);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the string argument is empty. */
  /* Warn about the correct use of the program (Local Error #9). */

  if (lfllUmlResult == lfllUmlStringEmpty)
  {
    printf("\n\n\nLocal Error #%i: the string argument is empty.\n", LFLL_UML_STRING_EMPTY);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the set of valid characters argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #10). */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetNull)
  {
    printf("\n\n\nLocal Error #%i: the set of valid characters argument is a null pointer.\n",
           LFLL_UML_STRING_VALID_CHARACTERS_SET_NULL);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_VALID_CHARACTERS_SET_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the set of valid characters argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #11). */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetEmpty)
  {
    printf("\n\n\nLocal Error #%i: the set of valid characters argument is an empty string.\n",
           LFLL_UML_STRING_VALID_CHARACTERS_SET_EMPTY);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_VALID_CHARACTERS_SET_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the string argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #12). */

  if (lfllUmlResult == lfllUmlStringInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the string argument has an invalid length.\n", LFLL_UML_STRING_INVALID_LENGTH);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the string argument contains an invalid character. */
  /* Warn about the correct use of the program (Local Error #13). */

  if (lfllUmlResult == lfllUmlStringInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the string argument contains one or more characters which don't belong to the set of valid characters.\n", LFLL_UML_STRING_INVALID_CHARACTER);
    printf("Use: %s <minimum allowed size> <maximum allowed size> <string> <set of valid characters>\n\n\n\n", *argv);
    exit(LFLL_UML_STRING_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\nSuccess.\n\n\n\n");





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCheckStringField.c,v $ */