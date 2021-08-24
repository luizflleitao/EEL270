/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 20:24:17 $
 * $Log: lfllUmlTestCheckPassword.c,v $
 * Revision 1.1  2019/12/07 20:24:17  luiz.leitao
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

#define LFLL_UML_NUMBER_OF_ARGUMENTS						3





/* Local error codes. */

#define LFLL_UML_OK								0
#define LFLL_UML_ENCODED_PASSWORD_HASH_NULL					37
#define LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY					38
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH				39
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER			40
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT				41
#define LFLL_UML_ENCODED_PASSWORD_HASH_ALGORITHM_ID_INVALID_VALUE		42
#define LFLL_UML_PLAINTEXT_PASSWORD_NULL					43
#define LFLL_UML_PLAINTEXT_PASSWORD_EMPTY					44
#define LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH				46
#define LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER				47
#define LFLL_UML_DES_ENCODED_PASSWORDS_MISMATCH					53
#define LFLL_UML_MD5_ENCODED_PASSWORDS_MISMATCH					54
#define LFLL_UML_SHA256_ENCODED_PASSWORDS_MISMATCH				55
#define LFLL_UML_SHA512_ENCODED_PASSWORDS_MISMATCH				56
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS					101










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
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* External function call. */ 

  lfllUmlResult = LfllUmlCheckPassword(*(argv + 1), *(argv + 2));





  /* Checks if the plaintext password's argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #43). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordNull)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument is a null pointer.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_NULL);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #44). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordEmpty)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument is an empty string.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_EMPTY);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #37). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashNull)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument is a null pointer.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_NULL);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #38). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashEmpty)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument is an empty string.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #46). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument has an invalid length.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #39). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument has an invalid length.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument contains one or more invalid characters. */
  /* Warn about the correct use of the program (Local Error #47). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument contains one or more invalid characters.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument contains one or more invalid characters. */
  /* Warn about the correct use of the program (Local Error #40). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument contains one or more invalid characters.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument has an invalid format. */
  /* Warn about the correct use of the program (Local Error #41). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidFormat)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument has an invalid format.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT);  /* Program aborted. */
  } /* if */





  /* Checks if the crypt ID of the encoded password hash's argument has an invalid value. */
  /* Warn about the correct use of the program (Local Error #42). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue)
  {
    printf("\n\n\nLocal Error #%i: the crypt ID of the encoded password hash's argument has an invalid value.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_ALGORITHM_ID_INVALID_VALUE);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_ALGORITHM_ID_INVALID_VALUE);  /* Program aborted. */
  } /* if */





  /* Checks if the DES password hashes are equal. */
  /* Warn about the correct use of the program (Local Error #53). */

  if (lfllUmlResult == lfllUmlDesEncodedPasswordsMismatch)
  {
    printf("\n\n\nLocal Error #%i: the DES password hashes don't match.\n",
           LFLL_UML_DES_ENCODED_PASSWORDS_MISMATCH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_DES_ENCODED_PASSWORDS_MISMATCH);  /* Program aborted. */
  } /* if */





  /* Checks if the MD5 password hashes are equal. */
  /* Warn about the correct use of the program (Local Error #54). */

  if (lfllUmlResult == lfllUmlMd5EncodedPasswordsMismatch)
  {
    printf("\n\n\nLocal Error #%i: the MD5 password hashes don't match.\n",
           LFLL_UML_MD5_ENCODED_PASSWORDS_MISMATCH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_MD5_ENCODED_PASSWORDS_MISMATCH);  /* Program aborted. */
  } /* if */





  /* Checks if the SHA256 password hashes are equal. */
  /* Warn about the correct use of the program (Local Error #55). */

  if (lfllUmlResult == lfllUmlSha256EncodedPasswordsMismatch)
  {
    printf("\n\n\nLocal Error #%i: the SHA256 password hashes don't match.\n",
           LFLL_UML_SHA256_ENCODED_PASSWORDS_MISMATCH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_SHA256_ENCODED_PASSWORDS_MISMATCH);  /* Program aborted. */
  } /* if */





  /* Checks if the SHA512 password hashes are equal. */
  /* Warn about the correct use of the program (Local Error #56). */

  if (lfllUmlResult == lfllUmlSha512EncodedPasswordsMismatch)
  {
    printf("\n\n\nLocal Error #%i: the SHA512 password hashes don't match.\n",
           LFLL_UML_SHA512_ENCODED_PASSWORDS_MISMATCH);
    printf("Use: %s '<plaintext-password>' '<encoded-hash-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_SHA512_ENCODED_PASSWORDS_MISMATCH);  /* Program aborted. */
  } /* if */





  /* Shows the result on screen. */

  printf("\n\n\nSuccess.\n\n\n\n");





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestCheckPassword.c,v $ */
