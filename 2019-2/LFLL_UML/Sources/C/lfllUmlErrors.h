/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 20:24:51 $
 * $Log: lfllUmlErrors.h,v $
 * Revision 1.11  2019/12/07 20:24:51  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.10  2019/12/07 01:58:25  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.9  2019/12/07 00:23:30  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.8  2019/12/06 16:15:13  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.7  2019/11/30 16:22:48  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.6  2019/11/30 08:15:17  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.5  2019/11/29 14:00:24  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.4  2019/11/28 13:29:13  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.3  2019/11/28 10:30:03  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.2  2019/11/27 13:00:22  luiz.leitao
 * Inclusion of new error values in lfllUmlErrorType.
 *
 * Revision 1.1  2019/11/26 06:15:28  luiz.leitao
 * Initial revision
 *
 */










#ifndef LFLL_UML_ERRORS_H  /* Begin of preprocessor directive. */
#define LFLL_UML_ERRORS_H  "@(#)lfllUmlErrors.h $Revision: 1.11 $" 





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"





/* Definition of numbered type lfllUmlErrorType. */

typedef enum
{
  lfllUmlOk, /* 0 */
  lfllUmlAbsolutePathNull, /* 1 */
  lfllUmlAbsolutePathEmpty, /* 2 */
  lfllUmlFileNameNull, /* 3 */
  lfllUmlFileNameEmpty, /* 4 */
  lfllUmlAbsolutePathInvalidLength, /* 5 */
  lfllUmlFileNameInvalidLength, /* 6 */
  lfllUmlAbsolutePathInvalidFormat, /* 7 */
  lfllUmlStringNull, /* 8 */
  lfllUmlStringEmpty, /* 9 */
  lfllUmlStringValidCharactersSetNull, /* 10 */
  lfllUmlStringValidCharactersSetEmpty, /* 11 */
  lfllUmlStringInvalidLength, /* 12 */
  lfllUmlStringInvalidCharacter, /* 13 */
  lfllUmlNicknameNull, /* 14 */
  lfllUmlNicknameEmpty, /* 15 */
  lfllUmlNicknameValidCharactersSetNull, /* 16 */
  lfllUmlNicknameValidCharactersSetEmpty, /* 17 */
  lfllUmlNicknameInvalidLength, /* 18 */
  lfllUmlNicknameInvalidCharacter, /* 19 */
  lfllUmlNicknameInvalidFormat, /* 20 */
  lfllUmlEmailNull, /* 21 */
  lfllUmlEmailEmpty, /* 22 */
  lfllUmlEmailValidCharactersSetNull, /* 23 */
  lfllUmlEmailValidCharactersSetEmpty, /* 24 */
  lfllUmlEmailInvalidLength, /* 25 */
  lfllUmlEmailInvalidCharacter, /* 26 */
  lfllUmlEmailInvalidFormat, /* 27 */
  lfllUmlRandomStringValidCharactersSetNull, /* 28 */
  lfllUmlRandomStringValidCharactersSetEmpty, /* 29 */
  lfllUmlRandomStringInvalidLength, /* 30 */
  lfllUmlUsernameNull, /* 31 */
  lfllUmlUsernameEmpty, /* 32 */
  lfllUmlUsernameInvalidLength, /* 33 */
  lfllUmlUsernameInvalidCharacter, /* 34 */
  lfllUmlUsernameLastnameEmpty, /* 35 */
  lfllUmlNicknamePossibilityInvalidLength, /* 36 */
  lfllUmlEncodedPasswordHashNull, /* 37 */
  lfllUmlEncodedPasswordHashEmpty, /* 38 */
  lfllUmlEncodedPasswordHashInvalidLength, /* 39 */
  lfllUmlEncodedPasswordHashInvalidCharacter, /* 40 */
  lfllUmlEncodedPasswordHashInvalidFormat, /* 41 */
  lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue, /* 42 */
  lfllUmlPlaintextPasswordNull, /* 43 */
  lfllUmlPlaintextPasswordEmpty, /* 44 */
  lfllUmlCryptAlgorithmIdInvalidValue, /* 45 */
  lfllUmlPlaintextPasswordInvalidLength, /* 46 */
  lfllUmlPlaintextPasswordInvalidCharacter, /* 47 */
  lfllUmlEncodedPasswordHashCompleteSaltNull, /* 48 */
  lfllUmlEncodedPasswordHashCompleteSaltEmpty, /* 49 */
  lfllUmlEncodedPasswordHashCompleteSaltInvalidLength, /* 50 */
  lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter, /* 51 */
  lfllUmlEncodedPasswordHashCompleteSaltInvalidFormat, /* 52 */
  lfllUmlDesEncodedPasswordsMismatch, /* 53 */
  lfllUmlMd5EncodedPasswordsMismatch, /* 54 */
  lfllUmlSha256EncodedPasswordsMismatch, /* 55 */
  lfllUmlSha512EncodedPasswordsMismatch, /* 56 */
  lfllUmlErrorCodesNumber /* 57 */
} lfllUmlErrorType;





/* 
 * char *
 * LfllUmlGetCliErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlErrorType - enter a valid error code of lfllUmlErrorType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a error message.
 *
 * Description:
 * This function returns a corresponding error message at selected language on CLI interface.
 */

char *
LfllUmlGetCliErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);





/* 
 * char *
 * LfllUmlGetNcursesErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlErrorType - enter a valid error code of lfllUmlErrorType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a error message.
 *
 * Description:
 * This function returns a corresponding error message at selected language on Ncurses interface.
 */

char *
LfllUmlGetNcursesErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);





/* 
 * char *
 * LfllUmlGetWebErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);
 *
 * Arguments:
 * lfllUmlErrorType - enter a valid error code of lfllUmlErrorType (I)
 * lfllUmlLanguageType - enter a valid language of lfllUmlLanguageType (I)
 *
 * Returned code:
 * String in chosen language with a error message.
 *
 * Description:
 * This function returns a corresponding error message at selected language on Web interface.
 */

char *
LfllUmlGetWebErrorMessage(lfllUmlErrorType, lfllUmlLanguageType);





#endif  /* End of preprocessor directive. */










/* $RCSfile: lfllUmlErrors.h,v $ */
