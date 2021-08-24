/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/26 06:25:26 $
 * $Log: lfllUmlUserInterface.c,v $
 * Revision 1.1  2019/11/26 06:25:26  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlUserInterface.h"





/* Definition of global variable lfllUmlCliUserInterfaceMessages. */

char *lfllUmlCliUserInterfaceMessages[lfllUmlLanguagesNumber][lfllUmlUserInterfaceMessagesNumber] =
{
  {
    "Enter"
  },
  {
    "Entrar"
  }
}; /* lfllUmlCliUserInterfaceMessages */





/* Definition of global variable lfllUmlNcursesUserInterfaceMessages. */

char *lfllUmlNcursesUserInterfaceMessages[lfllUmlLanguagesNumber][lfllUmlUserInterfaceMessagesNumber] =
{
  {
    "Enter"
  },
  {
    "Entrar"
  }
}; /* lfllUmlNcursesUserInterfaceMessages */





/* Definition of global variable lfllUmlWebUserInterfaceMessages. */

char *lfllUmlWebUserInterfaceMessages[lfllUmlLanguagesNumber][lfllUmlUserInterfaceMessagesNumber] =
{
  {
    "Enter"
  },
  {
    "Entrar"
  }
}; /* lfllUmlWebUserInterfaceMessages */





/* 
 * char *
 * LfllUmlGetCliUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlUserInterfaceMessageNumberType - enter a given string of lfllUmlUserInterfaceMessageNumberType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a message for user interface.
 *
 * Description:
 * This function returns a corresponding user interface message at selected language on CLI interface.
 */

char *
LfllUmlGetCliUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType lfllUmlUserInterfaceMessageValue,
                                  lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlCliUserInterfaceMessages[lfllUmlLanguageValue][lfllUmlUserInterfaceMessageValue];

} /* LfllUmlGetCliUserInterfaceMessage */





/* 
 * char *
 * LfllUmlGetNcursesUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlUserInterfaceMessageNumberType - enter a given string of lfllUmlUserInterfaceMessageNumberType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a message for user interface.
 *
 * Description:
 * This function returns a corresponding user interface message at selected language on Ncurses interface.
 */

char *
LfllUmlGetNcursesUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType lfllUmlUserInterfaceMessageValue,
                                      lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlNcursesUserInterfaceMessages[lfllUmlLanguageValue][lfllUmlUserInterfaceMessageValue];

} /* LfllUmlGetNcursesUserInterfaceMessage */





/* 
 * char *
 * LfllUmlGetWebUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlUserInterfaceMessageNumberType - enter a given string of lfllUmlUserInterfaceMessageNumberType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a message for user interface.
 *
 * Description:
 * This function returns a corresponding user interface message at selected language on Web interface.
 */

char *
LfllUmlGetWebUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType lfllUmlUserInterfaceMessageValue,
                                  lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlWebUserInterfaceMessages[lfllUmlLanguageValue][lfllUmlUserInterfaceMessageValue];

} /* LfllUmlGetWebUserInterfaceMessage */










/* $RCSfile: lfllUmlUserInterface.c,v $ */
