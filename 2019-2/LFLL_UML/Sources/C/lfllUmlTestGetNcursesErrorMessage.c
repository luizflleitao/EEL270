/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/26 07:29:57 $
 * $Log: lfllUmlTestGetNcursesErrorMessage.c,v $
 * Revision 1.1  2019/11/26 07:29:57  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlErrors.h"





/* Inclusion of macros. */

#define LFLL_UML_EOS					'\0'
#define LFLL_UML_NUMBER_OF_ARGUMENTS			3
#define LFLL_UML_ENGLISH_VALUE				0
#define LFLL_UML_PORTUGUESE_VALUE			1





/* Local error codes. */

#define LFLL_UML_OK					0
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS		101
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





  /* Begin Ncurses interface. */

  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_MAGENTA);  
  bkgd(COLOR_PAIR(1));





  /* Tests the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc != LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    move(2, 1);
    printw("Local Error #%i: invalid number of arguments.", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    move(3, 1);
    printw("Use: %s <language value> <error code value>", *argv);
    move(5, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlLanguageType. */

  lfllUmlLanguageValue = (lfllUmlLanguageType) strtoul(*(argv + 1), &lfllUmlValidation, 10);





  /* Tests the existence of hyphen in the first byte of the first argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 1) + 0) == '-')
  {
    move(2, 1);
    printw("Local Error #%i: one or more arguments have invalid characters.", LFLL_UML_INVALID_CHARACTER);
    move(3, 1);
    printw("Invalid character: '-'.");
    move(4, 1);
    printw("Use: %s <language value> <error code value>\n\n\n\n", *argv);
    move(6, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the existence of invalid characters in the first argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    move(2, 1);
    printw("Local Error #%i: one or more arguments have invalid characters.", LFLL_UML_INVALID_CHARACTER);
    move(3, 1);
    printw("Invalid character: '%c'.", *lfllUmlValidation);
    move(4, 1);
    printw("Use: %s <language value> <error code value>", *argv);
    move(6, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered. */
  /* Warn about the correct use of the program (Local Error #103). */

  if (lfllUmlLanguageValue >= lfllUmlLanguagesNumber)
  {
    move(2, 1);
    printw("Local Error #%i: invalid language value.", LFLL_UML_INVALID_LANGUAGES_NUMBER);
    move(3, 1);
    printw("Use: %s <language value> <error code value>", *argv);
    move(5, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_LANGUAGES_NUMBER);  /* Program aborted. */
  } /* if */





  /* Conversion of string to lfllUmlErrorType. */

  lfllUmlErrorCodeValue = (lfllUmlErrorType) strtoul(*(argv + 2), &lfllUmlValidation, 10);





  /* Tests the existence of hyphen in the first byte of the second argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 2) + 0) == '-')
  {
    move(2, 1);
    printw("Local Error #%i: one or more arguments have invalid characters.", LFLL_UML_INVALID_CHARACTER);
    move(3, 1);
    printw("Invalid character: '-'.");
    move(4, 1);
    printw("Use: %s <language value> <error code value>\n\n\n\n", *argv);
    move(6, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the existence of invalid characters in the second argument. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    move(2, 1);
    printw("Local Error #%i: one or more arguments have invalid characters.", LFLL_UML_INVALID_CHARACTER);
    move(3, 1);
    printw("Invalid character: '%c'.", *lfllUmlValidation);
    move(4, 1);
    printw("Use: %s <language value> <error code value>", *argv);
    move(6, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Tests the validity of the number entered. */
  /* Warn about the correct use of the program (Local Error #104). */

  if (lfllUmlErrorCodeValue >= lfllUmlErrorCodesNumber)
  {
    move(2, 1);
    printw("Local Error #%i: invalid error code value.", LFLL_UML_INVALID_ERROR_CODES_NUMBER);
    move(3, 1);
    printw("Use: %s <language value> <error code value>", *argv);
    move(5, 1);
    printw("Press any key to exit.");
    refresh();
    getch();
    endwin();
    exit(LFLL_UML_INVALID_ERROR_CODES_NUMBER);  /* Program aborted. */
  } /* if */





  /* Function call. */

  lfllUmlResult = LfllUmlGetNcursesErrorMessage((char) lfllUmlErrorCodeValue, (char) lfllUmlLanguageValue);





  /* Shows the result on screen. */

  move(2, 1);
  printw("%s", lfllUmlResult);
  move(4, 1);





  /* Shows the exit message. */

  if (lfllUmlLanguageValue == LFLL_UML_ENGLISH_VALUE)
    printw("Press any key to exit.");
  else
    printw("Pressione qualquer tecla para sair.");





  /* Exit Ncurses interface. */

  refresh();
  getch();
  endwin();





  return LFLL_UML_OK;  /* Successful return. */

} /* main */





/* $RCSfile: lfllUmlTestGetNcursesErrorMessage.c,v $ */
