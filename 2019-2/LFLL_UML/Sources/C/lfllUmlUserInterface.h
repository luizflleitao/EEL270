/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/11/26 06:20:18 $
 * $Log: lfllUmlUserInterface.h,v $
 * Revision 1.1  2019/11/26 06:20:18  luiz.leitao
 * Initial revision
 *
 */










#ifndef LFLL_UML_USER_INTERFACE_H  /* Begin of preprocessor directive. */
#define LFLL_UML_USER_INTERFACE_H  "@(#)lfllUmlUserInterface.h $Revision: 1.1 $" 





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"





/* Definition of numbered type lfllUmlUserInterfaceMessageNumberType. */

typedef enum
{
  lfllUmlEnterMessage,
  lfllUmlUserInterfaceMessagesNumber
} lfllUmlUserInterfaceMessageNumberType;





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
LfllUmlGetCliUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);





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
LfllUmlGetNcursesUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);





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
LfllUmlGetWebUserInterfaceMessage(lfllUmlUserInterfaceMessageNumberType, lfllUmlLanguageType);





#endif  /* End of preprocessor directive. */










/* $RCSfile: lfllUmlUserInterface.h,v $ */
