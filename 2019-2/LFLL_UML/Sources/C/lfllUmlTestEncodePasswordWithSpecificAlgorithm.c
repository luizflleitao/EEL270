/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 00:27:36 $
 * $Log: lfllUmlTestEncodePasswordWithSpecificAlgorithm.c,v $
 * Revision 1.1  2019/12/07 00:27:36  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of header files from the standard library. */

#include <stdio.h>
#include <stdlib.h>





/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlFunctions.h"
#include "lfllUmlErrors.h"
#include "lfllUmlConst.h"





/* Inclusion of macro. */

#define LFLL_UML_NUMBER_OF_ARGUMENTS					3





/* Local error codes. */

#define LFLL_UML_OK							0
#define LFLL_UML_PLAINTEXT_PASSWORD_NULL				43
#define LFLL_UML_PLAINTEXT_PASSWORD_EMPTY				44
#define LFLL_UML_CRYPT_ALGORITHM_INVALID_VALUE				45
#define LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH			46
#define LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER			47
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS				101
#define LFLL_UML_ARGUMENT_INVALID_CHARACTER				102










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  lfllUmlCryptAlgorithms lfllUmlCryptAlgorithmIdValue;
  char *lfllUmlEncodedPasswordHash;
  char *lfllUmlValidation;





  /* Pointer initialization. */

  lfllUmlEncodedPasswordHash = (char *) malloc(sizeof(char *));





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if ((argc > LFLL_UML_NUMBER_OF_ARGUMENTS) || (argc == (LFLL_UML_NUMBER_OF_ARGUMENTS - 2)))
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* Internal function call. */

  lfllUmlCryptAlgorithmIdValue = (lfllUmlCryptAlgorithms) strtoul(*(argv + 1), &lfllUmlValidation, 10);




  /* Checks if the crypt algorithm id's argument contains an invalid character. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*(*(argv + 1) + 0) == LFLL_UML_HYPHEN_CHARACTER)
  {
    printf("\n\n\nLocal Error #%i: the crypt algorithm id's argument contains an invalid character.\n",
           LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the crypt algorithm id's argument contains an invalid character. */
  /* Warn about the correct use of the program (Local Error #102). */

  if (*lfllUmlValidation != LFLL_UML_EOS)
  {
    printf("\n\n\nLocal Error #%i: the crypt algorithm id's argument contains an invalid character.\n",
           LFLL_UML_ARGUMENT_INVALID_CHARACTER);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_ARGUMENT_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* External function call. */

  lfllUmlResult = LfllUmlEncodePasswordWithSpecificAlgorithm(*(argv + 2),
                                                             lfllUmlCryptAlgorithmIdValue,
                                                             lfllUmlEncodedPasswordHash);





  /* Checks if the plaintext password's argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #43). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordNull)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument is a null pointer.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_NULL);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #44). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordEmpty)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument is an empty string.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_EMPTY);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_EMPTY);  /* Program aborted. */
  } /* if */




  /* Checks if the crypt algorithm id's argument contains an invalid value. */
  /* Warn about the correct use of the program (Local Error #45). */

  if (lfllUmlResult == lfllUmlCryptAlgorithmIdInvalidValue)
  {
    printf("\n\n\nLocal Error #%i: the crypt algorithm id's argument contains an invalid value.\n",
           LFLL_UML_CRYPT_ALGORITHM_INVALID_VALUE);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_CRYPT_ALGORITHM_INVALID_VALUE);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #46). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument has an invalid length.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the plaintext password's argument contains an invalid character. */
  /* Warn about the correct use of the program (Local Error #47). */

  if (lfllUmlResult == lfllUmlPlaintextPasswordInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the plaintext password's argument contains one ore more invalid characters.\n",
           LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER);
    printf("Use: %s <crypt-algorithm-id> '<plaintext-password>'\n\n\n\n", *argv);
    exit(LFLL_UML_PLAINTEXT_PASSWORD_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* If positive, shows the result on screen. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlDes)
    printf("\n\n\nEncoded Password Hash (DES): %s\n\n\n\n", lfllUmlEncodedPasswordHash);





  /* If positive, shows the result on screen. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlMD5)
    printf("\n\n\nEncoded Password Hash (MD5): %s\n\n\n\n", lfllUmlEncodedPasswordHash);

  



  /* If positive, shows the result on screen. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlSha256)
    printf("\n\n\nEncoded Password Hash (SHA256): %s\n\n\n\n", lfllUmlEncodedPasswordHash);





  /* If positive, shows the result on screen. */

  if (lfllUmlCryptAlgorithmIdValue == lfllUmlSha512)
    printf("\n\n\nEncoded Password Hash (SHA512): %s\n\n\n\n", lfllUmlEncodedPasswordHash);





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestEncodePasswordWithSpecificAlgorithm.c,v $ */
