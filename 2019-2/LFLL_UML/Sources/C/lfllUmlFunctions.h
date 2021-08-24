/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 20:26:44 $
 * $Log: lfllUmlFunctions.h,v $
 * Revision 1.11  2019/12/07 20:26:44  luiz.leitao
 * Inclusion of LfllUmlCheckPassword function prototype.
 *
 * Revision 1.10  2019/12/07 02:00:14  luiz.leitao
 * Inclusion of LfllUmlEncodePasswordWithSpecificSalt function prototype.
 *
 * Revision 1.9  2019/12/07 00:25:08  luiz.leitao
 * Inclusion of LfllUmlEncodePasswordWithSpecificAlgorithm function prototype.
 *
 * Revision 1.8  2019/12/06 16:18:29  luiz.leitao
 * Inclusion of LfllUmlGetCryptAlgorithm function prototype.
 *
 * Revision 1.7  2019/11/30 16:20:12  luiz.leitao
 * Inclusion of LfllUmlCreateNickname function prototype.
 *
 * Revision 1.6  2019/11/30 08:18:06  luiz.leitao
 * Inclusion of LfllUmlCreateRandomString function prototype.
 *
 * Revision 1.5  2019/11/29 13:57:08  luiz.leitao
 * Inclusion of LfllUmlCheckEmail function prototype.
 *
 * Revision 1.4  2019/11/28 13:26:57  luiz.leitao
 * Inclusion of LfllUmlCheckNickname function prototype.
 *
 * Revision 1.3  2019/11/28 10:34:31  luiz.leitao
 * Inclusion of LfllUmlCheckStringField function prototype.
 *
 * Revision 1.2  2019/11/27 12:56:22  luiz.leitao
 * Inclusion of LfllUmlGetAbsoluteFilename function prototype.
 *
 * Revision 1.1  2019/11/12 13:21:23  luiz.leitao
 * Initial revision
 *
 */










#ifndef LFLL_UML_FUNCTIONS_H  /* Begin of preprocessor directive. */
#define LFLL_UML_FUNCTIONS_H  "@(#)lfllUmlFunctions.h $Revision: 1.11 $" 





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
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
LfllUmlGetLanguageIndex(char *);





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
LfllUmlGetAbsoluteFileName(char *, char *, char *);





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
 * lfllUmlStringInvalidLength (12) - the string has an invalid length.
 * lfllUmlStringInvalidCharacter (13) - the string contains a character which doesn't
 * belong to the set of valid characters.
 *
 * Description:
 * This function receives, respectively, the desired string, its valid set of
 * characters, the minimum and the maximum allowed sizes. It returns 0 in case of
 * success or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCheckStringField(char *, char *, size_t, size_t);





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
LfllUmlCheckNickname(char *, char *, size_t, size_t);





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
LfllUmlCheckEmail(char *, char *, size_t, size_t);





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
 * lfllUmlRandomStringInvalidLength (30) - the random string has an invalid length.
 *
 * Description:
 * This function receives in the first two arguments, respectively, the random
 * string valid character's set and the desired length. Moreover, returns in
 * the third argument a random string. Finally, it returns 0 in case of success
 * or an integer positive value in case of error.
 */

lfllUmlErrorType
LfllUmlCreateRandomString(char *, size_t, char *);





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
LfllUmlCreateNickname(char *, char *, char *);





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
LfllUmlGetCryptAlgorithm(char *, lfllUmlCryptAlgorithms *);





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
LfllUmlEncodePasswordWithSpecificAlgorithm(char *, lfllUmlCryptAlgorithms, char *);





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
LfllUmlEncodePasswordWithSpecificSalt(char *, char *, char *);





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
LfllUmlCheckPassword(char *, char *);











#endif  /* End of preprocessor directive. */










/* $RCSfile: lfllUmlFunctions.h,v $ */
