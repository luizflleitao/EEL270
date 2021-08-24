/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/30 16:19:02 $
 * $Log: lfllUmlTestCreateNickname.c,v $
 * Revision 1.1  2019/11/30 16:19:02  luiz.leitao
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
#define LFLL_UML_USERNAME_NULL					31
#define LFLL_UML_USERNAME_EMPTY					32
#define LFLL_UML_USERNAME_INVALID_LENGTH			33
#define LFLL_UML_USERNAME_INVALID_CHARACTER			34
#define LFLL_UML_USERNAME_LASTNAME_EMPTY			35
#define LFLL_UML_NICKNAME_POSSIBILITY_INVALID_LENGTH		36
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS			101










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  char lfllUmlNicknameFirstPossibility[LFLL_UML_NICKNAME_MAXIMUM_LENGTH + 1];
  char lfllUmlNicknameSecondPossibility[LFLL_UML_NICKNAME_MAXIMUM_LENGTH + 1];
  const char lfllUmlWarning[] = "<empty-string>";





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc > LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* External function call. */

  lfllUmlResult = LfllUmlCreateNickname(*(argv + 1), lfllUmlNicknameFirstPossibility,
                                        lfllUmlNicknameSecondPossibility);





  /* Checks if the username argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #31). */

  if (lfllUmlResult == lfllUmlUsernameNull)
  {
    printf("\n\n\nLocal Error #%i: the username argument is a null pointer.\n", LFLL_UML_USERNAME_NULL);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_USERNAME_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the username argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #32). */

  if (lfllUmlResult == lfllUmlUsernameEmpty)
  {
    printf("\n\n\nLocal Error #%i: the username argument is an empty string.\n", LFLL_UML_USERNAME_EMPTY);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_USERNAME_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the username argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #33). */

  if (lfllUmlResult == lfllUmlUsernameInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the username argument has an invalid length.\n", LFLL_UML_USERNAME_INVALID_LENGTH);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_USERNAME_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the username argument contains one or more invalid characters. */
  /* Warn about the correct use of the program (Local Error #34). */

  if (lfllUmlResult == lfllUmlUsernameInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the username argument contains one or more invalid characters.\n",
           LFLL_UML_USERNAME_INVALID_CHARACTER);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_USERNAME_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the last name of the username argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #35). */

  if (lfllUmlResult == lfllUmlUsernameLastnameEmpty)
  {
    printf("\n\n\nLocal Error #%i: the last name of the username argument is an empty string.\n",
           LFLL_UML_USERNAME_LASTNAME_EMPTY);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_USERNAME_LASTNAME_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if one or both nickname's possibilities have an invalid length. */
  /* Warn about the correct use of the program (Local Error #36). */

  if (lfllUmlResult == lfllUmlNicknamePossibilityInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: one or both nickname's possibilities have an invalid length.\n",
           LFLL_UML_NICKNAME_POSSIBILITY_INVALID_LENGTH);
    printf("Use: %s <username>\n\n\n\n", *argv);
    exit(LFLL_UML_NICKNAME_POSSIBILITY_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* If positive, stores the warning message in the corresponding variable. */

  if (*lfllUmlNicknameSecondPossibility == LFLL_UML_EOS)
    sscanf(lfllUmlWarning, "%s", lfllUmlNicknameSecondPossibility);





  /* Shows the result on screen. */

  printf("\n\n\nNickname's first possibility: %s\n", lfllUmlNicknameFirstPossibility);
  printf("Nickname's second possibility: %s\n\n\n\n", lfllUmlNicknameSecondPossibility);





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCreateNickname.c,v $ */
