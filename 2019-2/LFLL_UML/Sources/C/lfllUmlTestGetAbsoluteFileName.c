/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/27 11:26:35 $
 * $Log: lfllUmlTestGetAbsoluteFileName.c,v $
 * Revision 1.1  2019/11/27 11:26:35  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlFunctions.h"
#include "lfllUmlErrors.h"
#include "lfllUmlConst.h"





/* Inclusion of macro. */

#define LFLL_UML_NUMBER_OF_ARGUMENTS				3





/* Local error codes. */

#define LFLL_UML_OK						0
#define LFLL_UML_ABSOLUTE_PATH_NULL				1
#define LFLL_UML_ABSOLUTE_PATH_EMPTY				2
#define LFLL_UML_FILE_NAME_NULL					3
#define LFLL_UML_FILE_NAME_EMPTY				4
#define LFLL_UML_ABSOLUTE_PATH_INVALID_LENGTH			5
#define LFLL_UML_FILE_NAME_INVALID_LENGTH			6
#define LFLL_UML_ABSOLUTE_PATH_INVALID_FORMAT			7
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS			101






/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  char lfllUmlConcatenationResult[LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH +
                                  LFLL_UML_FILE_NAME_MAXIMUM_LENGTH + 1];




  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc > LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Function call. */ 

  lfllUmlResult = LfllUmlGetAbsoluteFileName(*(argv + 1), *(argv + 2), lfllUmlConcatenationResult);





  /* Checks if the absolute path argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #1). */

  if (lfllUmlResult == lfllUmlAbsolutePathNull)
  {
    printf("\n\n\nLocal Error #%i: absolute path argument is a null pointer.\n", LFLL_UML_ABSOLUTE_PATH_NULL);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_ABSOLUTE_PATH_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the absolute path argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #2). */

  if (lfllUmlResult == lfllUmlAbsolutePathEmpty)
  {
    printf("\n\n\nLocal Error #%i: absolute path argument is an empty string.\n", LFLL_UML_ABSOLUTE_PATH_EMPTY);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_ABSOLUTE_PATH_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the file name argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #3). */

  if (lfllUmlResult == lfllUmlFileNameNull)
  {
    printf("\n\n\nLocal Error #%i: file name argument is a null pointer.\n", LFLL_UML_FILE_NAME_NULL);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_FILE_NAME_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the file name argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #4). */

  if (lfllUmlResult == lfllUmlFileNameEmpty)
  {
    printf("\n\n\nLocal Error #%i: absolute path argument is an empty string.\n", LFLL_UML_FILE_NAME_EMPTY);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_FILE_NAME_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the absolute path argument exceeds the maximum allowed length. */
  /* Warn about the correct use of the program (Local Error #5). */

  if (lfllUmlResult == lfllUmlAbsolutePathInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: absolute path argument exceeds the maximum allowed length.\n",
           LFLL_UML_ABSOLUTE_PATH_INVALID_LENGTH);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_ABSOLUTE_PATH_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the file name argument exceeds the maximum allowed length. */
  /* Warn about the correct use of the program (Local Error #6). */

  if (lfllUmlResult == lfllUmlFileNameInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: file name argument exceeds the maximum allowed length.\n",
           LFLL_UML_FILE_NAME_INVALID_LENGTH);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_FILE_NAME_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the absolute path argument has an invalid format. */
  /* Warn about the correct use of the program (Local Error #7). */

  if (lfllUmlResult == lfllUmlAbsolutePathInvalidFormat)
  {
    printf("\n\n\nLocal Error #%i: absolute path argument has an invalid format.\n",
           LFLL_UML_ABSOLUTE_PATH_INVALID_FORMAT);
    printf("Use: %s <absolute path> <file name>\n\n\n\n", *argv);
    exit(LFLL_UML_ABSOLUTE_PATH_INVALID_FORMAT);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\n%s\n\n\n\n", lfllUmlConcatenationResult);





  return LFLL_UML_OK;  /* Successful return. */

} /* main */





/* $RCSfile: lfllUmlTestGetAbsoluteFileName.c,v $ */
