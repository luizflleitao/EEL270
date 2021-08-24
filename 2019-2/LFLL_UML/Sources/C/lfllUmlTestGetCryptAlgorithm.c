/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/06 16:12:50 $
 * $Log: lfllUmlTestGetCryptAlgorithm.c,v $
 * Revision 1.1  2019/12/06 16:12:50  luiz.leitao
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

#define LFLL_UML_NUMBER_OF_ARGUMENTS					2





/* Local error codes. */

#define LFLL_UML_OK							0
#define LFLL_UML_ENCODED_PASSWORD_HASH_NULL				37
#define LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY				38
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH			39
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER		40
#define LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT			41
#define LFLL_UML_ENCODED_PASSWORD_HASHS_ALGORITHM_ID_INVALID_VALUE	42
#define LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS				101










/* Implementation of tests program. */

int
main(int argc, char **argv)
{

  /* Local variables inside main function. */

  lfllUmlErrorType lfllUmlResult;
  lfllUmlCryptAlgorithms *lfllUmlCryptAlgorithmId;





  /* Pointer initialization. */

  lfllUmlCryptAlgorithmId = (lfllUmlCryptAlgorithms *) malloc(sizeof(lfllUmlCryptAlgorithms));





  /* Checks the number of arguments in the program. */
  /* Warn about the correct use of the program (Local Error #101). */

  if (argc > LFLL_UML_NUMBER_OF_ARGUMENTS)
  {
    printf("\n\n\nLocal Error #%i: invalid number of arguments.\n", LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_INVALID_NUMBER_OF_ARGUMENTS);  /* Program aborted. */
  } /* if */





  /* External function call. */

  lfllUmlResult = LfllUmlGetCryptAlgorithm(*(argv + 1), lfllUmlCryptAlgorithmId);





  /* Checks if the encoded password hash's argument is a null pointer. */
  /* Warn about the correct use of the program (Local Error #37). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashNull)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument is a null pointer.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_NULL);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_NULL);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument is an empty string. */
  /* Warn about the correct use of the program (Local Error #38). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashEmpty)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument is an empty string.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_EMPTY);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument has an invalid length. */
  /* Warn about the correct use of the program (Local Error #39). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidLength)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument has an invalid length.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_LENGTH);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument contains one or more invalid characters. */
  /* Warn about the correct use of the program (Local Error #40). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidCharacter)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument contains one or more invalid characters.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_CHARACTER);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument has an invalid format. */
  /* Warn about the correct use of the program (Local Error #41). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashInvalidFormat)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument has an invalid format.\n",
           LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASH_INVALID_FORMAT);  /* Program aborted. */
  } /* if */





  /* Checks if the encoded password hash's argument algorithm id has an invalid value. */
  /* Warn about the correct use of the program (Local Error #42). */

  if (lfllUmlResult == lfllUmlEncodedPasswordHashsAlgorithmIdInvalidValue)
  {
    printf("\n\n\nLocal Error #%i: the encoded password hash's argument algorithm id has an invalid value.\n",
           LFLL_UML_ENCODED_PASSWORD_HASHS_ALGORITHM_ID_INVALID_VALUE);
    printf("Use: %s '<encoded-password-hash>'\n\n\n\n", *argv);
    exit(LFLL_UML_ENCODED_PASSWORD_HASHS_ALGORITHM_ID_INVALID_VALUE);  /* Program aborted. */
  } /* if */





  /* If positive, shows the result on screen. */

  if (*lfllUmlCryptAlgorithmId == lfllUmlDes)
    printf("\n\n\nCrypt Algortihm: DES\n\n\n\n");





  /* If positive, shows the result on screen. */

  if (*lfllUmlCryptAlgorithmId == lfllUmlMD5)
    printf("\n\n\nCrypt Algortihm: MD5\n\n\n\n");

  



  /* If positive, shows the result on screen. */

  if (*lfllUmlCryptAlgorithmId == lfllUmlSha256)
    printf("\n\n\nCrypt Algortihm: SHA256\n\n\n\n");





  /* If positive, shows the result on screen. */

  if (*lfllUmlCryptAlgorithmId == lfllUmlSha512)
    printf("\n\n\nCrypt Algortihm: SHA512\n\n\n\n");





  return LFLL_UML_OK;  /* Successful return. */

} /* main */










/* $RCSfile: lfllUmlTestGetCryptAlgorithm.c,v $ */
