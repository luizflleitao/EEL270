/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 20:27:36 $
 * $Log: lfllUmlFunctions.c,v $
 * Revision 1.11  2019/12/07 20:27:36  luiz.leitao
 * Implementation of LfllUmlCheckPassword function.
 *
 * Revision 1.10  2019/12/07 02:01:12  luiz.leitao
 * Implementation of LfllUmlEncodePasswordWithSpecificSalt function.
 *
 * Revision 1.9  2019/12/07 00:26:36  luiz.leitao
 * Implementation of LfllUmlEncodePasswordWithSpecificAlgorithm function.
 *
 * Revision 1.8  2019/12/06 16:19:34  luiz.leitao
 * Implementation of LfllUmlGetCryptAlgorithm function.
 *
 * Revision 1.7  2019/11/30 16:21:47  luiz.leitao
 * Implementation of LfllUmlCreateNickname function.
 *
 * Revision 1.6  2019/11/30 08:19:20  luiz.leitao
 * Implementation of LfllUmlCreateRandomString function.
 *
 * Revision 1.5  2019/11/29 13:58:45  luiz.leitao
 * Implementation of LfllUmlCheckEmail function.
 *
 * Revision 1.4  2019/11/28 13:27:47  luiz.leitao
 * Implementation of LfllUmlCheckNickname function.
 *
 * Revision 1.3  2019/11/28 10:35:23  luiz.leitao
 * Implementation of LfllUmlCheckStringField function.
 *
 * Revision 1.2  2019/11/27 12:57:32  luiz.leitao
 * Implementation of LfllUmlGetAbsoluteFileName function.
 *
 * Revision 1.1  2019/11/12 14:14:40  luiz.leitao
 * Initial revision
 *
 */










/* Preprocessor directive for Linux environment. */

#ifdef __linux__
#define _XOPEN_SOURCE						500
#endif





/* Inclusion of the header file from the standard library related to the previous preprocessor directive. */

#include <unistd.h>





/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlFunctions.h"
#include "lfllUmlConst.h"
#include "lfllUmlErrors.h"










/* 
 * lfllUmlLanguageType
 * LfllUmlGetLanguageIndex(char *);
 *
 * Arguments:
 * char * - string related to the desired language (I)
 *
 * Returned code:
 * lfllUmlEnglish (0) - Corresponding value of English.
 * lfllUmlPortuguese (1) - Corresponding value of Portuguese. 
 *
 * Description:
 * This function returns the value of the selected language.
 */

lfllUmlLanguageType
LfllUmlGetLanguageIndex(char *lfllUmlLanguage)
{

  /* Tests if the string is a null pointer. */

  if (lfllUmlLanguage == NULL)  /* if (!lfllUmlLanguage) */ 
    return lfllUmlEnglish;  /* 0 */



  /* Tests if the string is empty. */

  if (*lfllUmlLanguage == LFLL_UML_EOS)
    return lfllUmlEnglish;  /* 0 */



  /* Tests the size of the string. */

  if ((strlen(lfllUmlLanguage) != LFLL_UML_ENGLISH_LANGUAGE_LENGTH) &&
      (strlen(lfllUmlLanguage) != LFLL_UML_PORTUGUESE_LANGUAGE_LENGTH))
    return lfllUmlEnglish;  /* 0 */



  /* Tests if the string doesn't correspond to "lfllUmlEnglish" argument. */

  if ((strlen(lfllUmlLanguage) == LFLL_UML_ENGLISH_LANGUAGE_LENGTH) &&
      (strcmp(lfllUmlLanguage, "lfllUmlEnglish") != 0))
    return lfllUmlEnglish;  /* 0 */



  /* Tests if the string doesn't correspond to "lfllUmlPortuguese" argument. */

  if ((strlen(lfllUmlLanguage) == LFLL_UML_PORTUGUESE_LANGUAGE_LENGTH) &&
      (strcmp(lfllUmlLanguage, "lfllUmlPortuguese") != 0))
    return lfllUmlEnglish;  /* 0 */



  /* Tests if the string corresponds to "lfllUmlEnglish" argument. */

  if ((strlen(lfllUmlLanguage) == LFLL_UML_ENGLISH_LANGUAGE_LENGTH) &&
      (strcmp(lfllUmlLanguage, "lfllUmlEnglish") == 0))
    return lfllUmlEnglish;  /* 0 */



  return lfllUmlPortuguese;  /* 1 */

} /* LfllUmlGetLanguageIndex */










/* 
 * lfllUmlErrorType
 * LfllUmlGetAbsoluteFileName(char *, char *, char *);
 *
 * Arguments:
 * char * - absolute path directory (I)
 * char * - file name (I)
 * char * - string resulting from the concatenation of the first two arguments (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlAbsolutePathNull (1) - String related to the absolute path is a null pointer.
 * lfllUmlAbsolutePathEmpty (2) - String related to the absolute path is empty.
 * lfllUmlFileNameNull (3) - String related to the file name is a null pointer.
 * lfllUmlFileNameEmpty (4) - String related to the file name is empty.
 * lfllUmlAbsolutePathInvalidLength (5) - String related to the absolute path exceeds the
 * maximum allowed length.
 * lfllUmlFileNameInvalidLength (6) - String related to the file name exceeds the maximum
 * allowed length.
 * lfllUmlAbsolutePathInvalidFormat (7) - String related to the absolute path has an
 * invalid format.
 *
 * Description:
 * This function receives the absolute path directory (containing or not the final slash)
 * and the file name in the first two arguments. Moreover, returns in the third argument
 * the string resulting from the concatenation of the first two arguments. Finnaly, it
 * returns 0 in case of success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlGetAbsoluteFileName(char *lfllUmlAbsolutePath, char *lfllUmlFileName, char *lfllUmlConcatenationResult)
{

  /* Local variables inside LfllUmlGetAbsoluteFileName function. */

  size_t lfllUmlAbsolutePathLength, lfllUmlFileNameLength;
  unsigned short lfllUmlAbsolutePathIndex;



  /* Checks if the string is a null pointer. */

  if (lfllUmlAbsolutePath == NULL)  /* if (!lfllUmlAbsolutePath) */ 
    return lfllUmlAbsolutePathNull;  /* 1 */



  /* Checks if the string is empty. */

  if (*lfllUmlAbsolutePath == LFLL_UML_EOS)
    return lfllUmlAbsolutePathEmpty;  /* 2 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlFileName == NULL)  /* if (!lfllUmlFileName) */ 
    return lfllUmlFileNameNull;  /* 3 */



  /* Checks if the string is empty. */

  if (*lfllUmlFileName == LFLL_UML_EOS)
    return lfllUmlFileNameEmpty;  /* 4 */



  /* Internal function call. */

  lfllUmlAbsolutePathLength = strlen(lfllUmlAbsolutePath);



  /* Checks if the variable contains an invalid length. */

  if (lfllUmlAbsolutePathLength >= LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH)
    return lfllUmlAbsolutePathInvalidLength;  /* 5 */



  /* Internal function call. */

  lfllUmlFileNameLength = strlen(lfllUmlFileName);



  /* Checks if the variable contains an invalid length. */

  if (lfllUmlFileNameLength >= LFLL_UML_FILE_NAME_MAXIMUM_LENGTH)
    return lfllUmlFileNameInvalidLength;  /* 6 */



  /* Checks if the absolute path starts with a slash. */

  if (*lfllUmlAbsolutePath != LFLL_UML_SLASH_CHARACTER)
    return lfllUmlAbsolutePathInvalidFormat;  /* 7 */



  /* Checks if the absolute path contains two slashs in a row. */

  for (lfllUmlAbsolutePathIndex = 0;
       *(lfllUmlAbsolutePath + lfllUmlAbsolutePathIndex) != LFLL_UML_EOS;
       lfllUmlAbsolutePathIndex++)
    if ((*(lfllUmlAbsolutePath + lfllUmlAbsolutePathIndex) == LFLL_UML_SLASH_CHARACTER) &&
        (*(lfllUmlAbsolutePath + (lfllUmlAbsolutePathIndex + 1)) == LFLL_UML_SLASH_CHARACTER))
      return lfllUmlAbsolutePathInvalidFormat;  /* 7 */



  /* Checks if the penultimate character of lfllUmlAbsolutePath is equal or different from slash. */
  /* Internal function call. */

  if (*(lfllUmlAbsolutePath + (lfllUmlAbsolutePathLength - 1)) == LFLL_UML_SLASH_CHARACTER)
    snprintf(lfllUmlConcatenationResult,
             (lfllUmlAbsolutePathLength + lfllUmlFileNameLength + 1),
             "%s%s", lfllUmlAbsolutePath, lfllUmlFileName);
  else
    snprintf(lfllUmlConcatenationResult,
             (lfllUmlAbsolutePathLength + 1 + lfllUmlFileNameLength + 1),
             "%s/%s", lfllUmlAbsolutePath, lfllUmlFileName);



  return lfllUmlOk;  /* 0 */

} /* LfllUmlGetAbsoluteFileName */










/* 
 * lfllUmlErrorType
 * LfllUmlCheckStringField(char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - string related to the desired test (I)
 * char * - set of valid characters for the string (I)
 * size_t - minimum allowed length for the string (I)
 * size_t - maximum allowed length for the string (I)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlStringNull (8) - the string is a null pointer.
 * lfllUmlStringEmpty (9) - the string is empty.
 * lfllUmlStringValidCharactersSetNull (10) - string related to the set of valid characters
 * is a null pointer.
 * lfllUmlStringValidCharactersSetEmpty (11) - string related to the set of valid characters
 * is empty.
 * lfllUmlStringInvalidLength (12) - the string has a invalid length.
 * lfllUmlStringInvalidCharacter (13) - the string contains a character which doesn't
 * belong to the set of valid characters.
 *
 * Description:
 * This function receives, respectively, the desired string, its valid set of
 * characters, the minimum and the maximum allowed sizes. It returns 0 in case of
 * success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCheckStringField(char *lfllUmlString, char *lfllUmlStringValidCharactersSet,
                        size_t lfllUmlStringMinimumAllowedLength, size_t lfllUmlStringMaximumAllowedLength)
{

  /* Local variables inside LfllUmlCheckStringField function. */

  unsigned short lfllUmlStringIndex;
  size_t lfllUmlStringLength;



  /* Checks if the string is a null pointer. */

  if (lfllUmlString == NULL)  /* if (!lfllUmlString) */ 
    return lfllUmlStringNull;  /* 8 */



  /* Checks if the string is empty. */

  if (*lfllUmlString == LFLL_UML_EOS)
    return lfllUmlStringEmpty;  /* 9 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlStringValidCharactersSet == NULL)  /* if (!lfllUmlStringValidCharactersSet) */ 
    return lfllUmlStringValidCharactersSetNull;  /* 10 */



  /* Checks if the string is empty. */

  if (*lfllUmlStringValidCharactersSet == LFLL_UML_EOS)
    return lfllUmlStringValidCharactersSetEmpty;  /* 11 */



  /* Internal function call. */

  lfllUmlStringLength = strlen(lfllUmlString);



  /* Checks if the varaiable contains an invalid value. */

  if (lfllUmlStringLength < lfllUmlStringMinimumAllowedLength)
    return lfllUmlStringInvalidLength;  /* 12 */



  /* Checks if the varaiable contains an invalid value. */

  if (lfllUmlStringLength > lfllUmlStringMaximumAllowedLength)
    return lfllUmlStringInvalidLength;  /* 12 */



  /* Checks if the string contains an invalid character. */

  for (lfllUmlStringIndex = 0; lfllUmlStringIndex < lfllUmlStringLength; lfllUmlStringIndex++)
    if (strchr(lfllUmlStringValidCharactersSet, *(lfllUmlString + lfllUmlStringIndex)) == NULL)
      return lfllUmlStringInvalidCharacter;  /* 13 */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCheckStringField */










/* 
 * lfllUmlErrorType
 * LfllUmlCheckNickname(char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - nickname (I)
 * char * - set of valid characters for the nickname (I)
 * size_t - minimum allowed length for the nickname (I)
 * size_t - maximum allowed length for the nickname (I)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlNicknameNull (14) - the nickname is a null pointer.
 * lfllUmlNicknameEmpty (15) - the nickname is an empty string.
 * lfllUmlNicknameValidCharactersSetNull (16) - nickname's set of valid characters
 * is a null pointer.
 * lfllUmlNicknameValidCharactersSetEmpty (17) - nickname's set of valid characters
 * is empty.
 * lfllUmlNicknameInvalidLength (18) - the nickname has an invalid length.
 * lfllUmlNicknameInvalidCharacter (19) - the nickname contains a character which
 * doesn't belong to the set of valid characters.
 * lfllUmlNicknameInvalidFormat (20) - the nickname has an invalid format.
 *
 * Description:
 * This function receives, respectively, a nickname, its valid set of characters,
 * the minimum and the maximum allowed sizes. It returns 0 in case of success or
 * an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCheckNickname(char *lfllUmlNickname, char *lfllUmlNicknameValidCharactersSet,
                     size_t lfllUmlNicknameMinimumAllowedLength, size_t lfllUmlNicknameMaximumAllowedLength)
{

  /* Local variables inside LfllUmlCheckNickname function. */

  unsigned short lfllUmlNicknameIndex;
  unsigned short lfllUmlNicknameDotsCounter = 0;
  size_t lfllUmlNicknameLength;
  lfllUmlErrorType lfllUmlResult;



  /* External function call. */

  lfllUmlResult = LfllUmlCheckStringField(lfllUmlNickname, lfllUmlNicknameValidCharactersSet,
                                          lfllUmlNicknameMinimumAllowedLength,
                                          lfllUmlNicknameMaximumAllowedLength);



  /* Checks if the string is a null pointer. */

  if (lfllUmlResult == lfllUmlStringNull)
    return lfllUmlNicknameNull;  /* 14 */



  /* Checks if the string is empty. */

  if (lfllUmlResult == lfllUmlStringEmpty)
    return lfllUmlNicknameEmpty;  /* 15 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetNull) 
    return lfllUmlNicknameValidCharactersSetNull;  /* 16 */



  /* Checks if the string is empty. */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetEmpty)
    return lfllUmlNicknameValidCharactersSetEmpty;  /* 17 */



  /* Checks if the string contains a invalid length. */

  if (lfllUmlResult == lfllUmlStringInvalidLength)
    return lfllUmlNicknameInvalidLength;  /* 18 */



  /* Checks if the string contains a invalid character. */

  if (lfllUmlResult == lfllUmlStringInvalidCharacter)
    return lfllUmlNicknameInvalidCharacter;  /* 19 */



  /* Internal function call. */

  lfllUmlNicknameLength = strlen(lfllUmlNickname);



  /* Increases the counter any time a dot character is found. */

  for (lfllUmlNicknameIndex = 0; lfllUmlNicknameIndex < lfllUmlNicknameLength; lfllUmlNicknameIndex++)
    if (*(lfllUmlNickname + lfllUmlNicknameIndex) == LFLL_UML_DOT_CHARACTER)
      lfllUmlNicknameDotsCounter++;



  /* Checks if the string has a invalid format. */

  if ((lfllUmlNicknameDotsCounter != LFLL_UML_NICKNAME_NUMBER_OF_DOTS) ||
      (*(lfllUmlNickname + 0) == LFLL_UML_DOT_CHARACTER) ||
      (*(lfllUmlNickname + (lfllUmlNicknameLength - 1)) == LFLL_UML_DOT_CHARACTER))
    return lfllUmlNicknameInvalidFormat;  /* 20 */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCheckNickname */










/* 
 * lfllUmlErrorType
 * LfllUmlCheckEmail(char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - e-mail address (I)
 * char * - set of valid characters for the e-mail (I)
 * size_t - minimum allowed length for the e-mail (I)
 * size_t - maximum allowed length for the e-mail (I)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlEmailNull (21) - the e-mail is a null pointer.
 * lfllUmlEmailEmpty (22) - the email is an empty string.
 * lfllUmlEmailValidCharactersSetNull (23) - e-mail's set of valid characters
 * is a null pointer.
 * lfllUmlEmailValidCharactersSetEmpty (24) - e-mail's set of valid characters
 * is empty.
 * lfllUmlEmailInvalidLength (25) - the e-mail has an invalid length.
 * lfllUmlEmailInvalidCharacter (26) - the e-mail contains a character which
 * doesn't belong to the set of valid characters.
 * lfllUmlEmailInvalidFormat (27) - the e-mail has an invalid format.
 *
 * Description:
 * This function receives, respectively, an e-mail address, its valid set of
 * characters, the minimum and the maximum allowed sizes. It returns 0 in case
 * of sucess or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCheckEmail(char *lfllUmlEmail, char *lfllUmlEmailValidCharactersSet,
                  size_t lfllUmlEmailMinimumAllowedLength, size_t lfllUmlEmailMaximumAllowedLength)
{

  /* Local variables inside LfllUmlCheckEmail function. */

  unsigned short lfllUmlEmailIndex;
  unsigned short lfllUmlEmailAtsCounter = 0;
  size_t lfllUmlEmailLength;
  lfllUmlErrorType lfllUmlResult;



  /* External function call. */

  lfllUmlResult = LfllUmlCheckStringField(lfllUmlEmail, lfllUmlEmailValidCharactersSet,
                                          lfllUmlEmailMinimumAllowedLength,
                                          lfllUmlEmailMaximumAllowedLength);



  /* Checks if the string is a null pointer. */

  if (lfllUmlResult == lfllUmlStringNull)
    return lfllUmlEmailNull;  /* 21 */



  /* Checks if the string is empty. */

  if (lfllUmlResult == lfllUmlStringEmpty)
    return lfllUmlEmailEmpty;  /* 22 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetNull) 
    return lfllUmlEmailValidCharactersSetNull;  /* 23 */



  /* Checks if the string is empty. */

  if (lfllUmlResult == lfllUmlStringValidCharactersSetEmpty)
    return lfllUmlEmailValidCharactersSetEmpty;  /* 24 */



  /* Checks if the string contains an invalid length. */

  if (lfllUmlResult == lfllUmlStringInvalidLength)
    return lfllUmlEmailInvalidLength;  /* 25 */



  /* Checks if the string contains an invalid character. */

  if (lfllUmlResult == lfllUmlStringInvalidCharacter)
    return lfllUmlEmailInvalidCharacter;  /* 26 */



  /* Internal function call. */

  lfllUmlEmailLength = strlen(lfllUmlEmail);



  /* Increases the counter any time an at character is found. */

  for (lfllUmlEmailIndex = 0; lfllUmlEmailIndex < lfllUmlEmailLength; lfllUmlEmailIndex++)
    if (*(lfllUmlEmail + lfllUmlEmailIndex) == LFLL_UML_AT_CHARACTER)
      lfllUmlEmailAtsCounter++;



  /* Checks if the string has an invalid format. */

  if ((lfllUmlEmailAtsCounter != LFLL_UML_EMAIL_NUMBER_OF_ATS) ||
      (*(lfllUmlEmail + 0) == LFLL_UML_AT_CHARACTER) ||
      (*(lfllUmlEmail + (lfllUmlEmailLength - 1)) == LFLL_UML_AT_CHARACTER))
    return lfllUmlEmailInvalidFormat;  /* 27 */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCheckEmail */










/* 
 * lfllUmlErrorType
 * LfllUmlCreateRandomString(char *, size_t, char *);
 *
 * Arguments:
 * char * - random string valid character's set (I)
 * size_t - random string's length (I)
 * char * - random string (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlRandomStringValidCharactersSetNull (28) - the random string's valid
 * characters set is a null pointer.
 * lfllUmlRandomStringValidCharactersSetEmpty (29) - the random string's valid
 * characters set is an empty string.
 * lfllUmlRandomStringInvalidLength (30) - the random string has a invalid length.
 *
 * Description:
 * This function receives in the first two arguments, respectively, the random
 * string valid character's set and the desired length. Moreover, returns in
 * the third argument a random string. Finally, it returns 0 in case of success
 * or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCreateRandomString(char *lfllUmlRandomStringValidCharactersSet,
                          size_t lfllUmlRandomStringLength, char *lfllUmlRandomString)
{

  /* Local variables inside LfllUmlCreateRandomString function. */

  unsigned long long lfllUmlRandomStringSum = 0;
  unsigned long long lfllUmlRandomStringAuxiliary;
  unsigned short lfllUmlRandomStringIndex;
  size_t lfllUmlRandomStringValidCharactersSetLength;
  unsigned lfllUmlRandomStringSeed;



  /* Checks if the string is a null pointer. */

  if (lfllUmlRandomStringValidCharactersSet == NULL)
    return lfllUmlRandomStringValidCharactersSetNull;  /* 28 */



  /* Checks if the string is empty. */

  if (*lfllUmlRandomStringValidCharactersSet == LFLL_UML_EOS)
    return lfllUmlRandomStringValidCharactersSetEmpty;  /* 29 */



  /* Checks if the string contains an invalid length. */

  if (lfllUmlRandomStringLength < LFLL_UML_RANDOM_STRING_MINIMUM_LENGTH)
    return lfllUmlRandomStringInvalidLength;  /* 30 */ 



  /* Checks if the string contains an invalid length. */

  if (lfllUmlRandomStringLength > LFLL_UML_RANDOM_STRING_MAXIMUM_LENGTH)
    return lfllUmlRandomStringInvalidLength;  /* 30 */



  /* Sets the creation of the seed. */

  lfllUmlRandomStringSeed = (unsigned) time(NULL);



  /* Internal function call. */

  srand(lfllUmlRandomStringSeed);



  /* Internal function call. */

  lfllUmlRandomStringValidCharactersSetLength = strlen(lfllUmlRandomStringValidCharactersSet);



  /* Loop for the creation of the random string. */

  for (lfllUmlRandomStringIndex = 0; lfllUmlRandomStringIndex < lfllUmlRandomStringLength; lfllUmlRandomStringIndex++)
  {
    lfllUmlRandomStringAuxiliary = rand() % lfllUmlRandomStringValidCharactersSetLength;
    lfllUmlRandomStringSum += lfllUmlRandomStringAuxiliary * (lfllUmlRandomStringLength - 1 - lfllUmlRandomStringIndex);
    *(lfllUmlRandomString + lfllUmlRandomStringIndex) = *(lfllUmlRandomStringValidCharactersSet + lfllUmlRandomStringAuxiliary);
  } /* for */



  /* Addition of the null byte character at the end of the string. */

  lfllUmlRandomStringIndex++;
  *(lfllUmlRandomString + lfllUmlRandomStringIndex) = LFLL_UML_EOS;



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCreateRandomString */










/* 
 * lfllUmlErrorType
 * LfllUmlCreateNickname(char *, char *, char *);
 *
 * Arguments:
 * char * - username (I)
 * char * - nickname's first possibility (O)
 * char * - nickname's second possibility (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlUsernameNull (31) - the username argument is a null pointer.
 * lfllUmlUsernameEmpty (32) - the username argument is an empty string.
 * lfllUmlUsernameInvalidLength (33) - the username argument has an invalid
 * length.
 * lfllUmlUsernameInvalidCharacter (34) - the username argument contains one
 * ore more invalid characters.
 * lfllUmlUsernameLastnameEmpty (35) - the last name of the username is empty.
 * lfllUmlNicknamePossibilityInvalidLength (36) - one or both nickname's
 * possibilities have an invalid length.
 *
 * Description:
 * This function receives in the first argument a username. Furthermore, returns
 * in the second and in the third argument, respectively, the first and the
 * second possibilty of nickname from the given username. Lastly, it returns 0
 * in case of success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCreateNickname(char *lfllUmlUsername, char *lfllUmlNicknameFirstPossibility,
                      char *lfllUmlNicknameSecondPossibility)
{

  /* Local variables inside LfllUmlCreateNickname function. */

  char lfllUmlUsernameFirstname[LFLL_UML_USERNAME_MAXIMUM_LENGTH + 1] = "";
  char lfllUmlUsernamePenultimatename[LFLL_UML_USERNAME_MAXIMUM_LENGTH + 1] = "";
  char lfllUmlUsernameLastname[LFLL_UML_USERNAME_MAXIMUM_LENGTH + 1] = "";
  unsigned short lfllUmlUsernameIndex;
  unsigned short lfllUmlUsernameFirstnameIndex;
  unsigned short lfllUmlUsernamePenultimatenameIndex;
  unsigned short lfllUmlUsernameLastnameIndex;
  size_t lfllUmlUsernameLength;
  size_t lfllUmlUsernameFirstnameLength;
  size_t lfllUmlUsernamePenultimatenameLength;
  size_t lfllUmlUsernameLastnameLength;
  size_t lfllUmlNicknameFirstPossibilityLength;
  size_t lfllUmlNicknameSecondPossibilityLength;
  char lfllUmlUsernameWordDelimeter[] = " ";
  char *lfllUmlUsernameWordPointer;



  /* Checks if the string is a null pointer. */

  if (lfllUmlUsername == NULL)
    return lfllUmlUsernameNull;  /* 31 */



  /* Checks if the string is empty. */

  if (*lfllUmlUsername == LFLL_UML_EOS)
    return lfllUmlUsernameEmpty;  /* 32 */



  /* Internal function call. */

  lfllUmlUsernameLength = strlen(lfllUmlUsername);



  /* Checks if the string contains an invalid length. */

  if (lfllUmlUsernameLength < LFLL_UML_USERNAME_MINIMUM_LENGTH)
    return lfllUmlUsernameInvalidLength;  /* 33 */



  /* Checks if the string contains an invalid length. */

  if (lfllUmlUsernameLength > LFLL_UML_USERNAME_MAXIMUM_LENGTH)
    return lfllUmlUsernameInvalidLength;  /* 33 */



  /* Checks if the string contains an invalid character. */

  for (lfllUmlUsernameIndex = 0; lfllUmlUsernameIndex < lfllUmlUsernameLength; lfllUmlUsernameIndex++)
    if (strchr(LFLL_UML_USERNAME_VALID_CHARACTERS_SET, *(lfllUmlUsername + lfllUmlUsernameIndex)) == NULL)
      return lfllUmlUsernameInvalidCharacter;  /* 34 */



  /* Internal function call. */

  lfllUmlUsernameWordPointer = strtok(lfllUmlUsername, lfllUmlUsernameWordDelimeter);



  /* Loop going through the entire argument. */

  while (lfllUmlUsernameWordPointer != NULL)
  {

    /* If positive, stores the first word in the corresponding variable. */

    if (*lfllUmlUsernameFirstname == LFLL_UML_EOS)
       sscanf(lfllUmlUsernameWordPointer, "%s", lfllUmlUsernameFirstname);


    /* If positive, stores the last word in the corresponding variable. */

    else if (*lfllUmlUsernameLastname == LFLL_UML_EOS)
      sscanf(lfllUmlUsernameWordPointer, "%s", lfllUmlUsernameLastname);


    /* If positive, stores the penultimate and the last word in their
       correspondings variables. */

    else 
    {
      sscanf(lfllUmlUsernameLastname, "%s", lfllUmlUsernamePenultimatename);
      sscanf(lfllUmlUsernameWordPointer, "%s", lfllUmlUsernameLastname);
    } /* else */


    /* Internal function call. */

    lfllUmlUsernameWordPointer = strtok(NULL, lfllUmlUsernameWordDelimeter);
  } /* while */



  /* Checks if the last name is empty. */

  if (*lfllUmlUsernameLastname == LFLL_UML_EOS)
    return lfllUmlUsernameLastnameEmpty;  /* 35 */



  /* Internal function call. */

  lfllUmlUsernameFirstnameLength = strlen(lfllUmlUsernameFirstname);



  /* If positive, calls the internal function. */

  if (*lfllUmlUsernamePenultimatename != LFLL_UML_EOS)
    lfllUmlUsernamePenultimatenameLength = strlen(lfllUmlUsernamePenultimatename);



  /* Internal function call. */

  lfllUmlUsernameLastnameLength = strlen(lfllUmlUsernameLastname);



  /* Internal function call. */

  for (lfllUmlUsernameFirstnameIndex = 0;
       lfllUmlUsernameFirstnameIndex < lfllUmlUsernameFirstnameLength;
       lfllUmlUsernameFirstnameIndex++)
    *(lfllUmlUsernameFirstname + lfllUmlUsernameFirstnameIndex) =
                               tolower(*(lfllUmlUsernameFirstname + lfllUmlUsernameFirstnameIndex));



  /* If positive, calls the internal function. */

  if (*lfllUmlUsernamePenultimatename != LFLL_UML_EOS)
    for (lfllUmlUsernamePenultimatenameIndex = 0;
         lfllUmlUsernamePenultimatenameIndex < lfllUmlUsernamePenultimatenameLength;
         lfllUmlUsernamePenultimatenameIndex++)
      *(lfllUmlUsernamePenultimatename + lfllUmlUsernamePenultimatenameIndex) =
                                       tolower(*(lfllUmlUsernamePenultimatename + lfllUmlUsernamePenultimatenameIndex));



  /* Internal function call. */

  for (lfllUmlUsernameLastnameIndex = 0;
       lfllUmlUsernameLastnameIndex < lfllUmlUsernameLastnameLength;
       lfllUmlUsernameLastnameIndex++)
    *(lfllUmlUsernameLastname + lfllUmlUsernameLastnameIndex) =
                               tolower(*(lfllUmlUsernameLastname + lfllUmlUsernameLastnameIndex));



  /* Internal function call. */

  snprintf(lfllUmlNicknameFirstPossibility,
           (lfllUmlUsernameFirstnameLength + 1 + lfllUmlUsernameLastnameLength + 1),
           "%s.%s", lfllUmlUsernameFirstname, lfllUmlUsernameLastname);



  /* Internal function call. */

  lfllUmlNicknameFirstPossibilityLength = strlen(lfllUmlNicknameFirstPossibility); 


 
  /* Checks if the first nickname possibility has an invalid length. */

  if (lfllUmlNicknameFirstPossibilityLength > LFLL_UML_NICKNAME_MAXIMUM_LENGTH)
    return lfllUmlNicknamePossibilityInvalidLength;  /* 36 */



  /* If positive, calls the internal function. If not, it receives a null byte.*/

  if (*lfllUmlUsernamePenultimatename != LFLL_UML_EOS)
    snprintf(lfllUmlNicknameSecondPossibility,
             (lfllUmlUsernameFirstnameLength + 1 + lfllUmlUsernamePenultimatenameLength + 1),
             "%s.%s", lfllUmlUsernameFirstname, lfllUmlUsernamePenultimatename); 
  else
    *lfllUmlNicknameSecondPossibility = LFLL_UML_EOS;



  /* Internal function call. */

  lfllUmlNicknameSecondPossibilityLength = strlen(lfllUmlNicknameSecondPossibility); 


 
  /* Checks if the second nickname possibility has an invalid length. */

  if (lfllUmlNicknameSecondPossibilityLength > LFLL_UML_NICKNAME_MAXIMUM_LENGTH)
    return lfllUmlNicknamePossibilityInvalidLength;  /* 36 */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCreateNickname */










/* 
 * lfllUmlErrorType
 * LfllUmlGetCryptAlgorithm(char *, lfllUmlCryptAlgorithms *);
 *
 * Arguments:
 * char * - encoded password hash (I)
 * lfllUmlCryptAlgorithms * - corresponding algorithm ID (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlEncodedPasswordHashNull (37) - the encoded password hash's argument is
 * a null pointer.
 * lfllUmlEncodedPasswordHashEmpty (38) - the encoded password hash's argument is
 * an empty string.
 * lfllUmlEncodedPasswordHashInvalidLength (39) - the encoded password hash's
 * argument has an invalid length.
 * lfllUmlEncodedPasswordHashInvalidCharacter (40) - the encoded password hash's
 * argument contains one ore more invalid characters.
 * lfllUmlEncodedPasswordHashInvalidFormat (41) - the encoded password hash's
 * argument has an invalid format.
 * lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue (42) - the encoded password
 * hash's algorithm ID argument contains an invalid value.
 *
 * Description:
 * This function receives in the first argument an encoded password hash. Moreover,
 * returns in the second argument the corresponding algorithm ID. Finally, it returns
 * 0 in case of success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlGetCryptAlgorithm(char *lfllUmlEncodedPasswordHash, lfllUmlCryptAlgorithms *lfllUmlCryptAlgorithmId)
{

  /* Local variables inside LfllUmlGetCryptAlgorithm function. */

  size_t lfllUmlEncodedPasswordHashLength;
  unsigned short lfllUmlEncodedPasswordHashIndex;



  /* Checks if the string is a null pointer. */

  if (lfllUmlEncodedPasswordHash == NULL)
    return lfllUmlEncodedPasswordHashNull;  /* 37 */



  /* Checks if the string is empty. */

  if (*lfllUmlEncodedPasswordHash == LFLL_UML_EOS)
    return lfllUmlEncodedPasswordHashEmpty;  /* 38 */



  /* Internal function call. */

  lfllUmlEncodedPasswordHashLength = strlen(lfllUmlEncodedPasswordHash);



  /* Checks if the string has an invalid length. */

  if ((lfllUmlEncodedPasswordHashLength != LFLL_UML_DES_HASH_LENGTH) &&
      (lfllUmlEncodedPasswordHashLength != LFLL_UML_MD5_HASH_LENGTH) &&
      (lfllUmlEncodedPasswordHashLength != LFLL_UML_SHA256_HASH_LENGTH) &&
      (lfllUmlEncodedPasswordHashLength != LFLL_UML_SHA512_HASH_LENGTH))
    return lfllUmlEncodedPasswordHashInvalidLength;  /* 39 */



  /* If the hash's length corresponds to the DES's, checks if the hash is valid. */

  if (lfllUmlEncodedPasswordHashLength == LFLL_UML_DES_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlEncodedPasswordHashIndex = 0;
         lfllUmlEncodedPasswordHashIndex < lfllUmlEncodedPasswordHashLength;
         lfllUmlEncodedPasswordHashIndex++)
      if (strchr(LFLL_UML_DES_HASH_VALID_CHARACTERS_SET, *(lfllUmlEncodedPasswordHash + lfllUmlEncodedPasswordHashIndex)) == NULL)
        return lfllUmlEncodedPasswordHashInvalidCharacter;   /* 40 */


    /* Function's parameter receives its corresponding value. */

    *lfllUmlCryptAlgorithmId = lfllUmlDes;

  } /* if */



  /* If the hash's length corresponds to the MD5's, checks if the hash is valid. */

  if (lfllUmlEncodedPasswordHashLength == LFLL_UML_MD5_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlEncodedPasswordHashIndex = (LFLL_UML_MD5_ID_LENGTH + 1 + 1);
         lfllUmlEncodedPasswordHashIndex < lfllUmlEncodedPasswordHashLength;
         lfllUmlEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_MD5_HASH_VALID_CHARACTERS_SET, *(lfllUmlEncodedPasswordHash + lfllUmlEncodedPasswordHashIndex)) == NULL)
          && (lfllUmlEncodedPasswordHashIndex != (LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_MD5_ID_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlEncodedPasswordHash + LFLL_UML_MD5_ID_POSITION) - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE) != LFLL_UML_MD5_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* Function's parameter receives its corresponding value. */

    *lfllUmlCryptAlgorithmId = lfllUmlMD5;
    
  } /* if */



  /* If the hash's length corresponds to the SHA256's, checks if the hash is valid. */

  if (lfllUmlEncodedPasswordHashLength == LFLL_UML_SHA256_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlEncodedPasswordHashIndex = (LFLL_UML_SHA256_ID_LENGTH + 1 + 1);
         lfllUmlEncodedPasswordHashIndex < lfllUmlEncodedPasswordHashLength;
         lfllUmlEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_SHA256_HASH_VALID_CHARACTERS_SET, *(lfllUmlEncodedPasswordHash + lfllUmlEncodedPasswordHashIndex)) == NULL)
          && (lfllUmlEncodedPasswordHashIndex != (LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA256_ID_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA256_ID_POSITION) - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE) != LFLL_UML_SHA256_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* Function's parameter receives its corresponding value. */

    *lfllUmlCryptAlgorithmId = lfllUmlSha256;
    
  } /* if */



  /* If the hash's length corresponds to the SHA512's, checks if the hash is valid. */

  if (lfllUmlEncodedPasswordHashLength == LFLL_UML_SHA512_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlEncodedPasswordHashIndex = (LFLL_UML_SHA512_ID_LENGTH + 1 + 1);
         lfllUmlEncodedPasswordHashIndex < lfllUmlEncodedPasswordHashLength;
         lfllUmlEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_SHA512_HASH_VALID_CHARACTERS_SET, *(lfllUmlEncodedPasswordHash + lfllUmlEncodedPasswordHashIndex)) == NULL)
          && (lfllUmlEncodedPasswordHashIndex != (LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA512_ID_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1) != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlEncodedPasswordHash + LFLL_UML_SHA512_ID_POSITION) - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE) != LFLL_UML_SHA512_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* Function's parameter receives its corresponding value. */

    *lfllUmlCryptAlgorithmId = lfllUmlSha512;
    
  } /* if */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlGetCryptAlgorithm */










/* 
 * lfllUmlErrorType
 * LfllUmlEncodePasswordWithSpecificAlgorithm(char *, lfllUmlCryptAlgorithms, char *);
 *
 * Arguments:
 * char * - plaintext password (I)
 * lfllUmlCryptAlgorithms - corresponding crypt algorithm ID (I)
 * char * - encoded password hash (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlPlaintextPasswordNull (43) - the plaintext password's argument is a null pointer.
 * lfllUmlPlaintextPasswordEmpty (44) - the plaintext password's argument is an empty string.
 * lfllUmlCryptAlgorithmIdInvalidValue (45) - the crypt algorithm ID's argument has an invalid
 * value.
 * lfllUmlPlaintextPasswordInvalidLength (46) - the plaintext password's argument has an
 * invalid length.
 * lfllUmlPlaintextPasswordInvalidCharacter (47) - the plaintext password's argument contains
 * one ore more invalid characters.
 *
 * Description:
 * This function receives in the first and in the second argument, respectively, a plaintext
 * password and the value of the desired crypt algorithm. Furthermore, returns in the third
 * argument the encoded password hash. Lastly, it returns 0 in case of success or an integer
 * positive value in case of error.
 */

lfllUmlErrorType
LfllUmlEncodePasswordWithSpecificAlgorithm(char *lfllUmlPlaintextPassword,
                                           lfllUmlCryptAlgorithms lfllUmlCryptAlgorithmIdValue,
                                           char *lfllUmlEncodedPasswordHash)
{

  /* Local variables inside LfllUmlEncodePasswordWithSpecificAlgorithm function. */

  char lfllUmlEncodedPasswordDesSalt[LFLL_UML_DES_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordMd5Salt[LFLL_UML_MD5_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordSha256Salt[LFLL_UML_SHA256_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordSha512Salt[LFLL_UML_SHA512_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordMd5CompleteSalt[LFLL_UML_MD5_HASH_NUMBER_OF_DOLLARS +
                                             LFLL_UML_MD5_ID_LENGTH +
                                             LFLL_UML_MD5_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordSha256CompleteSalt[LFLL_UML_SHA256_HASH_NUMBER_OF_DOLLARS +
                                                LFLL_UML_SHA256_ID_LENGTH +
                                                LFLL_UML_SHA256_SALT_LENGTH + 1];
  char lfllUmlEncodedPasswordSha512CompleteSalt[LFLL_UML_SHA512_HASH_NUMBER_OF_DOLLARS +
                                                LFLL_UML_SHA512_ID_LENGTH +
                                                LFLL_UML_SHA512_SALT_LENGTH + 1];
  const char *lfllUmlEncodedPasswordMd5Id = "$1$";
  const char *lfllUmlEncodedPasswordSha256Id = "$5$";
  const char *lfllUmlEncodedPasswordSha512Id = "$6$";
  size_t lfllUmlPlaintextPasswordLength;
  unsigned short lfllUmlPlaintextPasswordIndex;



  /* Checks if the string is a null pointer. */

  if (lfllUmlPlaintextPassword == NULL)
    return lfllUmlPlaintextPasswordNull;  /* 43 */



  /* Checks if the string is empty. */

  if (*lfllUmlPlaintextPassword == LFLL_UML_EOS)
    return lfllUmlPlaintextPasswordEmpty;  /* 44 */



  /* Checks if crypt algorithm ID has an invalid value. */

  if ((lfllUmlCryptAlgorithmIdValue != lfllUmlDes) &&
      (lfllUmlCryptAlgorithmIdValue != lfllUmlMD5) &&
      (lfllUmlCryptAlgorithmIdValue != lfllUmlSha256) &&
      (lfllUmlCryptAlgorithmIdValue != lfllUmlSha512))
    return lfllUmlCryptAlgorithmIdInvalidValue;  /* 45 */



  /* Internal function call. */

  lfllUmlPlaintextPasswordLength = strlen(lfllUmlPlaintextPassword);



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength < LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength > LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Checks if the string contains an invalid character. */

  for (lfllUmlPlaintextPasswordIndex = 0;
         lfllUmlPlaintextPasswordIndex < lfllUmlPlaintextPasswordLength;
         lfllUmlPlaintextPasswordIndex++)
    if (strchr(LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET,
                 *(lfllUmlPlaintextPassword + lfllUmlPlaintextPasswordIndex)) == NULL)
      return lfllUmlPlaintextPasswordInvalidCharacter;  /* 47 */



  /* If the crypt algorithm ID corresponds to DES, encodes the plaintext password. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlDes)
  {

    /* External function call. */

    LfllUmlCreateRandomString(LFLL_UML_DES_SALT_VALID_CHARACTERS_SET, LFLL_UML_DES_SALT_LENGTH, lfllUmlEncodedPasswordDesSalt);


    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordDesSalt));

  } /* if */



  /* If the crypt algorithm ID corresponds to MD5, encodes the plaintext password. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlMD5)
  {

    /* External function call. */

    LfllUmlCreateRandomString(LFLL_UML_MD5_SALT_VALID_CHARACTERS_SET, LFLL_UML_MD5_SALT_LENGTH, lfllUmlEncodedPasswordMd5Salt);



    /* Internal function call. */

    snprintf(lfllUmlEncodedPasswordMd5CompleteSalt,
             (LFLL_UML_MD5_HASH_NUMBER_OF_DOLLARS + LFLL_UML_MD5_ID_LENGTH + LFLL_UML_MD5_SALT_LENGTH + 1),
             "%s%s$", lfllUmlEncodedPasswordMd5Id, lfllUmlEncodedPasswordMd5Salt);



    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordMd5CompleteSalt));

  } /* if */



  /* If the crypt algorithm ID corresponds to SHA256, encodes the plaintext password. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlSha256)
  {

    /* External function call. */

    LfllUmlCreateRandomString(LFLL_UML_SHA256_SALT_VALID_CHARACTERS_SET, LFLL_UML_SHA256_SALT_LENGTH,
                              lfllUmlEncodedPasswordSha256Salt);



    /* Internal function call. */

    snprintf(lfllUmlEncodedPasswordSha256CompleteSalt,
             (LFLL_UML_SHA256_HASH_NUMBER_OF_DOLLARS + LFLL_UML_SHA256_ID_LENGTH + LFLL_UML_SHA256_SALT_LENGTH + 1),
             "%s%s$", lfllUmlEncodedPasswordSha256Id, lfllUmlEncodedPasswordSha256Salt);



    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordSha256CompleteSalt));

  } /* if */



  /* If the crypt algorithm ID corresponds to SHA512, encodes the plaintext password. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlSha512)
  {

    /* External function call. */

    LfllUmlCreateRandomString(LFLL_UML_SHA512_SALT_VALID_CHARACTERS_SET, LFLL_UML_SHA512_SALT_LENGTH,
                              lfllUmlEncodedPasswordSha512Salt);



    /* Internal function call. */

    snprintf(lfllUmlEncodedPasswordSha512CompleteSalt,
             (LFLL_UML_SHA512_HASH_NUMBER_OF_DOLLARS + LFLL_UML_SHA512_ID_LENGTH + LFLL_UML_SHA512_SALT_LENGTH + 1),
             "%s%s$", lfllUmlEncodedPasswordSha512Id, lfllUmlEncodedPasswordSha512Salt);



    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordSha512CompleteSalt));

  } /* if */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlEncodePasswordWithSpecificAlgorithm */










/* 
 * lfllUmlErrorType
 * LfllUmlEncodePasswordWithSpecificSalt(char *, char *, char *);
 *
 * Arguments:
 * char * - plaintext password (I)
 * char * - complete salt (I)
 * char * - encoded password hash (O)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlPlaintextPasswordNull (43) - the plaintext password's argument is a null pointer.
 * lfllUmlPlaintextPasswordEmpty (44) - the plaintext password's argument is an empty string.
 * lfllUmlCryptAlgorithmIdInvalidValue (45) - the crypt algorithm ID's argument has an invalid
 * value.
 * lfllUmlPlaintextPasswordInvalidLength (46) - the plaintext password's argument has an
 * invalid length.
 * lfllUmlPlaintextPasswordInvalidCharacter (47) - the plaintext password's argument contains
 * one ore more invalid characters.
 * lfllUmlEncodedPasswordHashCompleteSaltNull (48) - the complete salt's argument is a null
 * pointer.
 * lfllUmlEncodedPasswordHashCompleteSaltEmpty (49) - the complete salt's argument is an
 * empty string.
 * lfllUmlEncodedPasswordHashCompleteSaltInvalidLength (50) - the complete salt's argument
 * has an invalid length.
 * lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter (51) - the complete salt's argument
 * contains one or more invalid characters.
 * lfllUmlEncodedPasswordHashCompleteSaltInvalidFormat (52) - the complete salt's argument
 * has an invalid format.
 *
 * Description:
 * This function receives in the first and in the second argument, respectively, a plaintext
 * password and a complete salt. Moreover, returns in the third argument the encoded password
 * hash. Finally, it returns 0 in case of success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlEncodePasswordWithSpecificSalt(char *lfllUmlPlaintextPassword, char *lfllUmlEncodedPasswordHashCompleteSalt,
                                      char *lfllUmlEncodedPasswordHash)
{

  /* Local variables inside LfllUmlEncodePasswordWithSpecificSalt function. */

  size_t lfllUmlPlaintextPasswordLength;
  unsigned short lfllUmlPlaintextPasswordIndex;
  size_t lfllUmlEncodedPasswordHashCompleteSaltLength;
  unsigned short lfllUmlEncodedPasswordHashCompleteSaltIndex;
  lfllUmlCryptAlgorithms lfllUmlCryptAlgorithmIdValue;



  /* Checks if the string is a null pointer. */

  if (lfllUmlPlaintextPassword == NULL)
    return lfllUmlPlaintextPasswordNull;  /* 43 */



  /* Checks if the string is empty. */

  if (*lfllUmlPlaintextPassword == LFLL_UML_EOS)
    return lfllUmlPlaintextPasswordEmpty;  /* 44 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlEncodedPasswordHashCompleteSalt == NULL)
    return lfllUmlEncodedPasswordHashCompleteSaltNull;  /* 48 */



  /* Checks if the string is empty. */

  if (*lfllUmlEncodedPasswordHashCompleteSalt == LFLL_UML_EOS)
    return lfllUmlEncodedPasswordHashCompleteSaltEmpty;  /* 49 */



  /* Internal function call. */

  lfllUmlPlaintextPasswordLength = strlen(lfllUmlPlaintextPassword);



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength < LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength > LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Checks if the string contains an invalid character. */

  for (lfllUmlPlaintextPasswordIndex = 0;
         lfllUmlPlaintextPasswordIndex < lfllUmlPlaintextPasswordLength;
         lfllUmlPlaintextPasswordIndex++)
    if (strchr(LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET,
                 *(lfllUmlPlaintextPassword + lfllUmlPlaintextPasswordIndex)) == NULL)
      return lfllUmlPlaintextPasswordInvalidCharacter;  /* 47 */



  /* Internal function call. */

  lfllUmlEncodedPasswordHashCompleteSaltLength = strlen(lfllUmlEncodedPasswordHashCompleteSalt);



  /* Checks if the string has an invalid length. */

  if ((lfllUmlEncodedPasswordHashCompleteSaltLength != LFLL_UML_DES_SALT_LENGTH) &&
      (lfllUmlEncodedPasswordHashCompleteSaltLength != LFLL_UML_MD5_COMPLETE_SALT_LENGTH) &&
      (lfllUmlEncodedPasswordHashCompleteSaltLength != LFLL_UML_SHA256_COMPLETE_SALT_LENGTH) &&
      (lfllUmlEncodedPasswordHashCompleteSaltLength != LFLL_UML_SHA512_COMPLETE_SALT_LENGTH))
    return lfllUmlEncodedPasswordHashCompleteSaltInvalidLength;  /* 50 */



  /* Checks if the salt's length doesn't corrrespond to DES's. */

  if (lfllUmlEncodedPasswordHashCompleteSaltLength != LFLL_UML_DES_SALT_LENGTH)
  {

    /* Gets the crypt ID value from the string. */

    lfllUmlCryptAlgorithmIdValue = (lfllUmlCryptAlgorithms) *(lfllUmlEncodedPasswordHashCompleteSalt + LFLL_UML_HASH_ID_POSITION) -
                                                            LFLL_UML_ZERO_CHARACTER_ASCII_VALUE;


    /* Checks if crypt algorithm ID has an invalid value. */

    if ((lfllUmlCryptAlgorithmIdValue != lfllUmlMD5) &&
        (lfllUmlCryptAlgorithmIdValue != lfllUmlSha256) &&
        (lfllUmlCryptAlgorithmIdValue != lfllUmlSha512))
      return lfllUmlCryptAlgorithmIdInvalidValue;  /* 45 */

  } /* if */



  /* If the salt's length corresponds to DES's, encode the plaintext password. */

  if (lfllUmlEncodedPasswordHashCompleteSaltLength == LFLL_UML_DES_SALT_LENGTH)
  {

    /* Checks if the string contains an invalid character. */

    for (lfllUmlEncodedPasswordHashCompleteSaltIndex = 0;
         lfllUmlEncodedPasswordHashCompleteSaltIndex < lfllUmlEncodedPasswordHashCompleteSaltLength;
         lfllUmlEncodedPasswordHashCompleteSaltIndex++)
      if (strchr(LFLL_UML_DES_SALT_VALID_CHARACTERS_SET,
                 *(lfllUmlEncodedPasswordHashCompleteSalt + lfllUmlEncodedPasswordHashCompleteSaltIndex)) == NULL)
        return lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter;  /* 51 */


    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordHashCompleteSalt));

  } /* if */



  /* If the salt's length corresponds to MD5's, encode the plaintext password. */

  if (lfllUmlEncodedPasswordHashCompleteSaltLength == LFLL_UML_MD5_COMPLETE_SALT_LENGTH)
  {

    /* Checks if the string contains an invalid character. */

    for (lfllUmlEncodedPasswordHashCompleteSaltIndex = 0;
         lfllUmlEncodedPasswordHashCompleteSaltIndex < lfllUmlEncodedPasswordHashCompleteSaltLength;
         lfllUmlEncodedPasswordHashCompleteSaltIndex++)
      if (strchr(LFLL_UML_MD5_COMPLETE_SALT_VALID_CHARACTERS_SET,
                 *(lfllUmlEncodedPasswordHashCompleteSalt + lfllUmlEncodedPasswordHashCompleteSaltIndex)) == NULL)
        return lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter;  /* 51 */


    /* Checks if the string has an invalid format. */

    if ((*lfllUmlEncodedPasswordHashCompleteSalt != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_MD5_ID_LENGTH + 1)) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashCompleteSaltInvalidFormat;  /* 52 */


    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordHashCompleteSalt));

  } /* if */



  /* If the salt's length and crypt ID corresponds to SHA256's, encode the plaintext password. */

  if ((lfllUmlEncodedPasswordHashCompleteSaltLength == LFLL_UML_SHA256_COMPLETE_SALT_LENGTH) &&
      (lfllUmlCryptAlgorithmIdValue == lfllUmlSha256))
  {

    /* Checks if the string contains an invalid character. */

    for (lfllUmlEncodedPasswordHashCompleteSaltIndex = 0;
         lfllUmlEncodedPasswordHashCompleteSaltIndex < lfllUmlEncodedPasswordHashCompleteSaltLength;
         lfllUmlEncodedPasswordHashCompleteSaltIndex++)
      if (strchr(LFLL_UML_SHA256_COMPLETE_SALT_VALID_CHARACTERS_SET,
                 *(lfllUmlEncodedPasswordHashCompleteSalt + lfllUmlEncodedPasswordHashCompleteSaltIndex)) == NULL)
        return lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter;  /* 51 */


    /* Checks if the string has an invalid format. */

    if ((*lfllUmlEncodedPasswordHashCompleteSalt != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_SHA256_ID_LENGTH + 1)) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashCompleteSaltInvalidFormat;  /* 52 */


    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordHashCompleteSalt));

  } /* if */



  /* If the salt's length and crypt ID corresponds to SHA512's, encode the plaintext password. */

  if ((lfllUmlEncodedPasswordHashCompleteSaltLength == LFLL_UML_SHA512_COMPLETE_SALT_LENGTH) &&
      (lfllUmlCryptAlgorithmIdValue == lfllUmlSha512))
  {

    /* Checks if the string contains an invalid character. */

    for (lfllUmlEncodedPasswordHashCompleteSaltIndex = 0;
         lfllUmlEncodedPasswordHashCompleteSaltIndex < lfllUmlEncodedPasswordHashCompleteSaltLength;
         lfllUmlEncodedPasswordHashCompleteSaltIndex++)
      if (strchr(LFLL_UML_SHA512_COMPLETE_SALT_VALID_CHARACTERS_SET,
                 *(lfllUmlEncodedPasswordHashCompleteSalt + lfllUmlEncodedPasswordHashCompleteSaltIndex)) == NULL)
        return lfllUmlEncodedPasswordHashCompleteSaltInvalidCharacter;  /* 51 */


    /* Checks if the string has an invalid format. */

    if ((*lfllUmlEncodedPasswordHashCompleteSalt != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_SHA512_ID_LENGTH + 1)) != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlEncodedPasswordHashCompleteSalt + (LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashCompleteSaltInvalidFormat;  /* 52 */


    /* Double internal function call. */

    strcpy(lfllUmlEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlEncodedPasswordHashCompleteSalt));

  } /* if */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlEncodePasswordWithSpecificSalt */










/* 
 * lfllUmlErrorType
 * LfllUmlCheckPassword(char *, char *);
 *
 * Arguments:
 * char * - plaintext password (I)
 * char * - encoded password hash (I)
 *
 * Returned code:
 * lfllUmlOk (0) - Successful return.
 * lfllUmlEncodedPasswordHashNull (37) - the encoded password hash's argument is a null
 * pointer.
 * lfllUmlEncodedPasswordHashEmpty (38) - the encoded password hash's argument is an
 * empty string.
 * lfllUmlEncodedPasswordHashInvalidLength (39) - the encoded password hash's argument
 * has an invalid length.
 * lfllUmlEncodedPasswordHashInvalidCharacter (40) - the encoded password hash's argment
 * contains one ore more invalid characters.
 * lfllUmlEncodedPasswordHashInvalidFormat (41) - the encoded password hash's argument
 * has an invalid format.
 * lfllUmlEncodedPasswordHashAlgorithmIdInvalidValue (42) - the crypt ID of the encoded
 * password hash's argument has an invalid value.
 * lfllUmlPlaintextPasswordNull (43) - the plaintext password's argument is a null pointer.
 * lfllUmlPlaintextPasswordEmpty (44) - the plaintext password's argument is an empty string.
 * lfllUmlPlaintextPasswordInvalidLength (46) - the plaintext password's argument has an
 * invalid length.
 * lfllUmlPlaintextPasswordInvalidCharacter (47) - the plaintext password's argument contains
 * one ore more invalid characters.
 * lfllUmlDesEncodedPasswordsMismatch (52) - the DES password hashes don't match.
 * lfllUmlMd5EncodedPasswordsMismatch (53) - the MD5 password hashes don't match.
 * lfllUmlSha256EncodedPasswordsMismatch (54) - the SHA256 password hashes don't match.
 * lfllUmlSha512EncodedPasswordsMismatch (55) - the SHA512 password hashes don't match.
 *
 * Description:
 * This function receives in the first and in the second argument, respectively, a plaintext
 * password and a encoded password hash. Lastly, it returns 0 in case of success or an integer
 * positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCheckPassword(char *lfllUmlPlaintextPassword, char *lfllUmlUserEncodedPasswordHash)
{

  /* Local variables inside LfllUmlCheckPassword function. */

  char lfllUmlDesEncodedPasswordHash[LFLL_UML_DES_HASH_LENGTH + 1];
  char lfllUmlDesEncodedPasswordSalt[LFLL_UML_DES_SALT_LENGTH + 1];
  char lfllUmlMd5EncodedPasswordHash[LFLL_UML_MD5_HASH_LENGTH + 1];
  char lfllUmlMd5EncodedPasswordSalt[LFLL_UML_MD5_SALT_LENGTH + 1];
  char lfllUmlSha256EncodedPasswordHash[LFLL_UML_SHA256_HASH_LENGTH + 1];
  char lfllUmlSha256EncodedPasswordSalt[LFLL_UML_SHA256_SALT_LENGTH + 1];
  char lfllUmlSha512EncodedPasswordHash[LFLL_UML_SHA512_HASH_LENGTH + 1];
  char lfllUmlSha512EncodedPasswordSalt[LFLL_UML_SHA512_SALT_LENGTH + 1];
  size_t lfllUmlPlaintextPasswordLength;
  size_t lfllUmlUserEncodedPasswordHashLength;
  unsigned short lfllUmlDesEncodedPasswordSaltIndex;
  unsigned short lfllUmlMd5EncodedPasswordSaltIndex;
  unsigned short lfllUmlSha256EncodedPasswordSaltIndex;
  unsigned short lfllUmlSha512EncodedPasswordSaltIndex;
  unsigned short lfllUmlUserEncodedPasswordHashIndex;
  unsigned short lfllUmlPlaintextPasswordIndex;



  /* Checks if the string is a null pointer. */

  if (lfllUmlPlaintextPassword == NULL)
    return lfllUmlPlaintextPasswordNull;  /* 43 */



  /* Checks if the string is empty. */

  if (*lfllUmlPlaintextPassword == LFLL_UML_EOS)
    return lfllUmlPlaintextPasswordEmpty;  /* 44 */



  /* Checks if the string is a null pointer. */

  if (lfllUmlUserEncodedPasswordHash == NULL)
    return lfllUmlEncodedPasswordHashNull;  /* 37 */



  /* Checks if the string is empry. */

  if (*lfllUmlUserEncodedPasswordHash == LFLL_UML_EOS)
    return lfllUmlEncodedPasswordHashEmpty;  /* 38 */



  /* Internal function call. */

  lfllUmlPlaintextPasswordLength = strlen(lfllUmlPlaintextPassword);



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength < LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Checks if the string has an invalid length. */

  if (lfllUmlPlaintextPasswordLength > LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH)
    return lfllUmlPlaintextPasswordInvalidLength;  /* 46 */



  /* Internal function call. */

  lfllUmlUserEncodedPasswordHashLength = strlen(lfllUmlUserEncodedPasswordHash);



  /* Checks if the string has an invalid length. */

  if ((lfllUmlUserEncodedPasswordHashLength != LFLL_UML_DES_HASH_LENGTH) &&
      (lfllUmlUserEncodedPasswordHashLength != LFLL_UML_MD5_HASH_LENGTH) &&
      (lfllUmlUserEncodedPasswordHashLength != LFLL_UML_SHA256_HASH_LENGTH) &&
      (lfllUmlUserEncodedPasswordHashLength != LFLL_UML_SHA512_HASH_LENGTH))
    return lfllUmlEncodedPasswordHashInvalidLength;  /* 39 */



  /* Checks if the string contains an invalid character. */

  for (lfllUmlPlaintextPasswordIndex = 0;
         lfllUmlPlaintextPasswordIndex < lfllUmlPlaintextPasswordLength;
         lfllUmlPlaintextPasswordIndex++)
    if (strchr(LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET,
               *(lfllUmlPlaintextPassword + lfllUmlPlaintextPasswordIndex)) == NULL)
      return lfllUmlPlaintextPasswordInvalidCharacter;  /* 47 */



  /* If the password hash's length corresponds to DES's, encodes the plaintext password. */

  if (lfllUmlUserEncodedPasswordHashLength == LFLL_UML_DES_HASH_LENGTH)
  {

    /* Checks if the string contains an invalid character. */

    for (lfllUmlUserEncodedPasswordHashIndex = 0;
         lfllUmlUserEncodedPasswordHashIndex < lfllUmlUserEncodedPasswordHashLength;
         lfllUmlUserEncodedPasswordHashIndex++)
      if (strchr(LFLL_UML_DES_HASH_VALID_CHARACTERS_SET,
                 *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex)) == NULL)
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* The salt receives its characters. */

    for (lfllUmlDesEncodedPasswordSaltIndex = 0, lfllUmlUserEncodedPasswordHashIndex = 0;
         lfllUmlDesEncodedPasswordSaltIndex < LFLL_UML_DES_SALT_LENGTH;
         lfllUmlDesEncodedPasswordSaltIndex++, lfllUmlUserEncodedPasswordHashIndex++)
      *(lfllUmlDesEncodedPasswordSalt + lfllUmlDesEncodedPasswordSaltIndex) =
      *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex);


    /* Double internal function call. */

    strcpy(lfllUmlDesEncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlDesEncodedPasswordSalt));


    /* Checks if the strings are equal. */
    /* Internal function call. */

    if (strcmp(lfllUmlUserEncodedPasswordHash, lfllUmlDesEncodedPasswordHash) != 0)  /* if (!strcmp(...))*/
      return lfllUmlDesEncodedPasswordsMismatch;  /* 53 */

  } /* if */



  /* If the password hash's length corresponds to MD5's, encodes the plaintext password. */

  if (lfllUmlUserEncodedPasswordHashLength == LFLL_UML_MD5_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlUserEncodedPasswordHashIndex = (LFLL_UML_MD5_ID_LENGTH + 1 + 1);
         lfllUmlUserEncodedPasswordHashIndex < lfllUmlUserEncodedPasswordHashLength;
         lfllUmlUserEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_MD5_HASH_VALID_CHARACTERS_SET,
                  *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex)) == NULL) &&
          (lfllUmlUserEncodedPasswordHashIndex != (LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlUserEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_MD5_ID_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlUserEncodedPasswordHash + LFLL_UML_MD5_ID_POSITION)
        - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE)
        != LFLL_UML_MD5_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* The salt receives its characters. */

    for (lfllUmlMd5EncodedPasswordSaltIndex = 0, lfllUmlUserEncodedPasswordHashIndex = 0;
         lfllUmlMd5EncodedPasswordSaltIndex < (1 + LFLL_UML_MD5_ID_LENGTH + 1 + LFLL_UML_MD5_SALT_LENGTH + 1);
         lfllUmlMd5EncodedPasswordSaltIndex++, lfllUmlUserEncodedPasswordHashIndex++)
      *(lfllUmlMd5EncodedPasswordSalt + lfllUmlMd5EncodedPasswordSaltIndex) =
      *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex);


    /* Double internal function call. */

    strcpy(lfllUmlMd5EncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlMd5EncodedPasswordSalt));


    /* Checks if the strings are equal. */
    /* Internal function call. */

    if (strcmp(lfllUmlUserEncodedPasswordHash, lfllUmlMd5EncodedPasswordHash) != 0)  /* if (!strcmp(...))*/
      return lfllUmlMd5EncodedPasswordsMismatch;  /* 54 */

  } /* if */



  /* If the password hash's length corresponds to SHA256's, encodes the plaintext password. */

  if (lfllUmlUserEncodedPasswordHashLength == LFLL_UML_SHA256_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlUserEncodedPasswordHashIndex = (LFLL_UML_SHA256_ID_LENGTH + 1 + 1);
         lfllUmlUserEncodedPasswordHashIndex < lfllUmlUserEncodedPasswordHashLength;
         lfllUmlUserEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_SHA256_HASH_VALID_CHARACTERS_SET,
                  *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex)) == NULL) &&
          (lfllUmlUserEncodedPasswordHashIndex != (LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlUserEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_SHA256_ID_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlUserEncodedPasswordHash + LFLL_UML_SHA256_ID_POSITION)
        - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE)
        != LFLL_UML_SHA256_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* The salt receives its characters. */

    for (lfllUmlSha256EncodedPasswordSaltIndex = 0, lfllUmlUserEncodedPasswordHashIndex = 0;
         lfllUmlSha256EncodedPasswordSaltIndex < (1 + LFLL_UML_SHA256_ID_LENGTH + 1 + LFLL_UML_SHA256_SALT_LENGTH + 1);
         lfllUmlSha256EncodedPasswordSaltIndex++, lfllUmlUserEncodedPasswordHashIndex++)
      *(lfllUmlSha256EncodedPasswordSalt + lfllUmlSha256EncodedPasswordSaltIndex) =
      *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex);


    /* Double internal function call. */

    strcpy(lfllUmlSha256EncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlSha256EncodedPasswordSalt));


    /* Checks if the strings are equal. */
    /* Internal function call. */

    if (strcmp(lfllUmlUserEncodedPasswordHash, lfllUmlSha256EncodedPasswordHash) != 0)  /* if (!strcmp(...))*/
      return lfllUmlSha256EncodedPasswordsMismatch;  /* 55 */

  } /* if */



  /* If the password hash's length corresponds to SHA512's, encodes the plaintext password. */

  if (lfllUmlUserEncodedPasswordHashLength == LFLL_UML_SHA512_HASH_LENGTH)
  {

    /* Checks if the hash contains an invalid character. */

    for (lfllUmlUserEncodedPasswordHashIndex = (LFLL_UML_SHA512_ID_LENGTH + 1 + 1);
         lfllUmlUserEncodedPasswordHashIndex < lfllUmlUserEncodedPasswordHashLength;
         lfllUmlUserEncodedPasswordHashIndex++)
      if ((strchr(LFLL_UML_SHA512_HASH_VALID_CHARACTERS_SET,
                  *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex)) == NULL) &&
          (lfllUmlUserEncodedPasswordHashIndex != (LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1)))
        return lfllUmlEncodedPasswordHashInvalidCharacter;  /* 40 */


    /* Checks if the hash has an invalid format. */

    if ((*lfllUmlUserEncodedPasswordHash != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_SHA512_ID_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER) ||
        (*(lfllUmlUserEncodedPasswordHash + (LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1))
        != LFLL_UML_DOLLAR_CHARACTER))
      return lfllUmlEncodedPasswordHashInvalidFormat;  /* 41 */


    /* Checks if the hash's algorithm id has an invalid value. */

    if ((*(lfllUmlUserEncodedPasswordHash + LFLL_UML_SHA512_ID_POSITION)
        - LFLL_UML_ZERO_CHARACTER_ASCII_VALUE)
        != LFLL_UML_SHA512_ID_VALUE)
      return lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue;  /* 42 */


    /* The salt receives its characters. */

    for (lfllUmlSha512EncodedPasswordSaltIndex = 0, lfllUmlUserEncodedPasswordHashIndex = 0;
         lfllUmlSha512EncodedPasswordSaltIndex < (1 + LFLL_UML_SHA512_ID_LENGTH + 1 + LFLL_UML_SHA512_SALT_LENGTH + 1);
         lfllUmlSha512EncodedPasswordSaltIndex++, lfllUmlUserEncodedPasswordHashIndex++)
      *(lfllUmlSha512EncodedPasswordSalt + lfllUmlSha512EncodedPasswordSaltIndex) =
      *(lfllUmlUserEncodedPasswordHash + lfllUmlUserEncodedPasswordHashIndex);


    /* Double internal function call. */

    strcpy(lfllUmlSha512EncodedPasswordHash, crypt(lfllUmlPlaintextPassword, lfllUmlSha512EncodedPasswordSalt));


    /* Checks if the strings are equal. */
    /* Internal function call. */

    if (strcmp(lfllUmlUserEncodedPasswordHash, lfllUmlSha512EncodedPasswordHash) != 0)  /* if (!strcmp(...))*/
      return lfllUmlSha512EncodedPasswordsMismatch;  /* 56 */

  } /* if */



  return lfllUmlOk;  /* 0 */

} /* LfllUmlCheckPassword */










/* $RCSfile: lfllUmlFunctions.c,v $ */