/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/12 14:13:44 $
 * $Log: lfllUmlTestGetLanguageIndex.c,v $
 * Revision 1.1  2019/11/12 14:13:44  luiz.leitao
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





/* Inclusion of macros. */

#define LFLL_UML_NUMBER_OF_ARGUMENTS			2
#define LFLL_UML_STRING_MAXIMUM_LENGTH			65




/* Local error codes. */

#define LFLL_UML_OK					0
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS		101
#define LFLL_UML_INVALID_LENGTH				102





/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variable inside main function. */

  lfllUmlLanguageType lfllUmlLanguageResult;





  /* Tests the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc != LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <lfllUmlEnglish>\n", *argv);
    printf("Use: %s <lfllUmlPortuguese>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Tests the length of the string. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (strlen(*(argv + 1)) > LFLL_UML_STRING_MAXIMUM_LENGTH)
  {
    printf("\n\n\nLocal Error #%i: the string exceeds maximum permitted.\n", LFLL_UML_INVALID_LENGTH);
    printf("Use: %s <lfllUmlEnglish>\n", *argv);
    printf("Use: %s <lfllUmlPortuguese>\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Function call. */

  lfllUmlLanguageResult = LfllUmlGetLanguageIndex(*(argv + 1));





  /* Shows the result on screen. */

  printf("\n\n\nThe returned value is: %u.\n\n\n\n", lfllUmlLanguageResult);



  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestGetLanguageIndex.c,v $ */
