/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/28 13:26:23 $
 * $Log: lfllUmlTestCheckNickname.c,v $
 * Revision 1.1  2019/11/28 13:26:23  luiz.leitao
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
#define LFLL_UML_NICKNAME_NULL					14
#define LFLL_UML_NICKNAME_EMPTY					15
#define LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_NULL		16
#define LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_EMPTY		17
#define LFLL_UML_NICKNAME_INVALID_LENGTH			18
#define LFLL_UML_NICKNAME_INVALID_CHARACTER			19
#define LFLL_UML_NICKNAME_INVALID_FORMAT			20
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
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* External function call. */ 

  lfllUmlResult = LfllUmlCheckNickname(*(argv + 1),
                                       LFLL_UML_NICKNAME_VALID_CHARACTERS_SET,
                                       LFLL_UML_NICKNAME_MINIMUM_LENGTH,
                                       LFLL_UML_NICKNAME_MAXIMUM_LENGTH);





  /* Checks if the nickname argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #14). */

  if (lfllUmlResult == lfllUmlNicknameNull)
  {
    printf("\n\n\nLocal Error #%i: the nickname argument is a null pointer.\n", LFLL_UML_NICKNAME_NULL);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname argument is empty. */
  /* Warn about the correct use of the program (Local Error #15). */

  if (lfllUmlResult == lfllUmlNicknameEmpty)
  {
    printf("\n\n\nLocal Error #%i: the nickname argument is empty.\n", LFLL_UML_NICKNAME_EMPTY);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname's set of valid characters argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #16). */

  if (lfllUmlResult == lfllUmlNicknameValidCharactersSetNull)
  {
    printf("\n\n\nLocal Error #%i: the nickname's set of valid characters is a null pointer.\n",
           LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_NULL);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname's set of valid characters argument is a empty string. */
  /* Warn about the correct use of the program (Local Error #17). */

  if (lfllUmlResult == lfllUmlNicknameValidCharactersSetEmpty)
  {
    printf("\n\n\nLocal Error #%i: the nickname's set of valid characters is an empty string.\n",
           LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_EMPTY);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_VALID_CHARACTERS_SET_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname argument has a invalid length. */
  /* Warn about the correct use of the program (Local Error #18). */

  if (lfllUmlResult == lfllUmlNicknameInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the nickname argument has an invalid length.\n", LFLL_UML_NICKNAME_INVALID_LENGTH);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname argument contains a invalid character. */
  /* Warn about the correct use of the program (Local Error #19). */

  if (lfllUmlResult == lfllUmlNicknameInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the nickname argument contains one or more characters which don't belong to the set of valid characters.\n", LFLL_UML_NICKNAME_INVALID_CHARACTER);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the nickname argument has a invalid format. */
  /* Warn about the correct use of the program (Local Error #20). */

  if (lfllUmlResult == lfllUmlNicknameInvalidFormat)
  {
    printf("\n\n\nLocal Error #%i: the nickname argument has an invalid format.\n", LFLL_UML_NICKNAME_INVALID_FORMAT);
    printf("Use: %s <first-name>.<last-name>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_INVALID_FORMAT);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\nSuccess.\n\n\n\n");





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCheckNickname.c,v $ */
