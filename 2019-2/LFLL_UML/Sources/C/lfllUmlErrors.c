/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 20:25:27 $
 * $Log: lfllUmlErrors.c,v $
 * Revision 1.11  2019/12/07 20:25:27  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.10  2019/12/07 01:59:16  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.9  2019/12/07 00:24:08  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.8  2019/12/06 16:16:52  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.7  2019/11/30 16:23:32  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.6  2019/11/30 08:16:24  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.5  2019/11/29 14:01:28  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.4  2019/11/28 13:30:06  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.3  2019/11/28 10:31:06  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.2  2019/11/27 13:04:02  luiz.leitao
 * Inclusion of new error messages in global variables lfllUml[Cli][Ncurses][Web]ErrorMessages.
 *
 * Revision 1.1  2019/11/26 06:15:41  luiz.leitao
 * Initial revision
 *
 */










/* Inclusion of personalized header files for the project. */

#include "lfllUmlTypes.h"
#include "lfllUmlErrors.h"





/* Definition of global variable lfllUmlCliErrorMessages. */

char *lfllUmlCliErrorMessages[lfllUmlLanguagesNumber][lfllUmlErrorCodesNumber] =
{
  {
    "Successful Operation", /* 0 */
    "Null Pointer in Absolute Path", /* 1 */
    "Empty String in Absolute Path", /* 2 */
    "Null Pointer in File Name", /* 3 */
    "Empty String in File Name", /* 4 */
    "Invalid Length in Absolute Path", /* 5 */
    "Invalid Length in File Name", /* 6 */
    "Invalid Format in Absolute Path", /* 7 */
    "Null Pointer in String", /* 8 */
    "Empty String", /* 9 */
    "Null Pointer in Set of Valid Characters", /* 10 */
    "Empty String in Set of Valid Characters", /* 11 */
    "Invalid Length in String", /* 12 */
    "Invalid Character in String", /* 13 */
    "Null Pointer in Nickname", /* 14 */
    "Empty String in Nickname", /* 15 */
    "Null Pointer in Nickname's Set of Valid Characters", /* 16 */
    "Empty String in Nickname's Set of Valid Characters", /* 17 */
    "Invalid Length in Nickname", /* 18 */
    "Invalid Character in Nickname", /* 19 */
    "Invalid Format in Nickname", /* 20 */
    "Null Pointer in E-mail", /* 21 */
    "Empty String in E-mail", /* 22 */
    "Null Pointer in E-mail's Set of Valid Characters", /* 23 */
    "Empty String in E-mail's Set of Valid Characters", /* 24 */
    "Invalid Length in E-mail", /* 25 */
    "Invalid Character in E-mail", /* 26 */
    "Invalid Format in E-mail", /* 27 */
    "Null Pointer in Random String's Set of Valid Characters", /* 28 */
    "Empty String in Random String's Set of Valid Characters", /* 29 */
    "Invalid Length in Random String", /* 30 */
    "Null Pointer in Username", /* 31 */
    "Empty String in Username", /* 32 */
    "Invalid Length in Username", /* 33 */
    "Invalid Character in Username", /* 34 */
    "Empty String in Username's Last Name", /* 35 */
    "Invalid Length in Nickname's Possibility", /* 36 */
    "Null Pointer in Encoded Password Hash", /* 37 */
    "Empty String in Encoded Password Hash", /* 38 */
    "Invalid Length in Encoded Password Hash", /* 39 */
    "Invalid Character in Encoded Password Hash", /* 40 */
    "Invalid Format in Encoded Password Hash", /* 41 */
    "Invalid Value in Encoded Password Hash's Algorithm ID", /* 42 */
    "Null Pointer in Plaintext Password", /* 43 */
    "Empty String in Plaintext Password", /* 44 */
    "Invalid Value in Crypt Algorithm ID", /* 45 */
    "Invalid Length in Plaintext Password", /* 46 */
    "Invalid Character in Plaintext Password", /* 47 */
    "Null Pointer in Complete Salt", /* 48 */
    "Empty String in Complete Salt", /* 49 */
    "Invalid Length in Complete Salt", /* 50 */
    "Invalid Character in Complete Salt", /* 51 */
    "Invalid Format in Complete Salt", /* 52 */
    "DES Password Hashes Mismatch", /* 53 */
    "MD5 Password Hashes Mismatch", /* 54 */
    "SHA256 Password Hashes Mismatch", /* 55 */
    "SHA512 Password Hashes Mismatch" /* 56 */
  },
  {
    "Operacao Bem-sucedida", /* 0 */
    "Ponteiro Nulo no Caminho Absoluto", /* 1 */
    "String Vazia no Caminho Absoluto", /* 2 */
    "Ponteiro Nulo no Nome do Arquivo", /* 3 */
    "String Vazia no Nome do Arquivo", /* 4 */
    "Tamanho Invalido do Caminho Absoluto", /* 5 */
    "Tamanho Invalido do Nome do Arquivo", /* 6 */
    "Formato Invalido do Caminho Absoluto", /* 7 */
    "Ponteiro Nulo na String", /* 8 */
    "String Vazia", /* 9 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres", /* 10 */
    "String Vazia no Conjunto Valido de Caracteres", /* 11 */
    "Tamanho Invalido da String", /* 12 */
    "Caractere Invalido na String", /* 13 */
    "Ponteiro Nulo no Apelido", /* 14 */
    "String Vazia no Apelido", /* 15 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres do Apelido", /* 16 */
    "String Vazia no Conjunto Valido de Caracteres do Apelido", /* 17 */
    "Tamanho Invalido do Apelido", /* 18 */
    "Caractere Invalido no Apelido", /* 19 */
    "Formato Invalido do Apelido", /* 20 */
    "Ponteiro Nulo no E-mail", /* 21 */
    "String Vazia no E-mail", /* 22 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres do E-mail", /* 23 */
    "String Vazia no Conjunto Valido de Caracteres do E-mail", /* 24 */
    "Tamanho Invalido do E-mail", /* 25 */
    "Caractere Invalido no E-mail", /* 26 */
    "Formato Invalido do E-mail", /* 27 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres da String Aleatoria", /* 28 */
    "String Vazia no Conjunto Valido de Caracteres da String Aleatoria", /* 29 */
    "Tamanho Invalido da String Aleatoria", /* 30 */
    "Ponteiro Nulo no Nome do Usuario", /* 31 */
    "String Vazia no Nome do Usuario", /* 32 */
    "Tamanho Invalido do Nome do Usuario", /* 33 */
    "Caractere Invalido no Nome do Usuario", /* 34 */
    "String Vazia no Ultimo Nome do Nome do Usuario", /* 35 */
    "Tamanho Invalido da Possibilidade de Apelido", /* 36 */
    "Ponteiro Nulo no Hash da Senha Codificada", /* 37 */
    "String Vazia no Hash da Senha Codificada", /* 38 */
    "Tamanho Invalido do Hash da Senha Codificada", /* 39 */
    "Caractere Invalido no Hash da Senha Codificada", /* 40 */
    "Formato Invalido no Hash da Senha Codificada", /* 41 */
    "Valor Invalido do ID do Algoritmo no Hash da Senha Codificada", /* 42 */
    "Ponteiro Nulo na Senha Plana", /* 43 */
    "String Vazia na Senha Plana", /* 44 */
    "Valor Invalido do ID do Algoritmo de Criptografia", /* 45 */
    "Tamanho Invalido da Senha Plana", /* 46 */
    "Caractere Invalido na Senha Plana", /* 47 */
    "Ponteiro Nulo no Salt Completo", /* 48 */
    "String Vazia no Salt Completo", /* 49 */
    "Tamanho Invalido do Salt Completo", /* 50 */
    "Caractere Invalido no Salt Completo", /* 51 */
    "Formato Invalido do Salt Completo", /* 52 */
    "Incompatibilidade Entre as Senhas DES", /* 53 */
    "Incompatibilidade Entre as Senhas MD5", /* 54 */
    "Incompatibilidade Entre as Senhas SHA256", /* 55 */
    "Incompatibilidade Entre as Senhas SHA512" /* 56 */
  }
}; /* lfllUmlCliErrorMessages */





/* Definition of global variable lfllUmlNcursesErrorMessages. */

char *lfllUmlNcursesErrorMessages[lfllUmlLanguagesNumber][lfllUmlErrorCodesNumber] =
{
  {
    "Successful Operation",  /* 0 */
    "Null Pointer in Absolute Path", /* 1 */
    "Empty String in Absolute Path", /* 2 */
    "Null Pointer in File Name", /* 3 */
    "Empty String in File Name", /* 4 */
    "Invalid Length in Absolute Path", /* 5 */
    "Invalid Length in File Name", /* 6 */
    "Invalid Format in Absolute Path", /* 7 */
    "Null Pointer in String", /* 8 */
    "Empty String", /* 9 */
    "Null Pointer in Set of Valid Characters", /* 10 */
    "Empty String in Set of Valid Characters", /* 11 */
    "Invalid Length in String", /* 12 */
    "Invalid Character in String", /* 13 */
    "Null Pointer in Nickname", /* 14 */
    "Empty String in Nickname", /* 15 */
    "Null Pointer in Nickname's Set of Valid Characters", /* 16 */
    "Empty String in Nickname's Set of Valid Characters", /* 17 */
    "Invalid Length in Nickname", /* 18 */
    "Invalid Character in Nickname", /* 19 */
    "Invalid Format in Nickname", /* 20 */
    "Null Pointer in E-mail", /* 21 */
    "Empty String in E-mail", /* 22 */
    "Null Pointer in E-mail's Set of Valid Characters", /* 23 */
    "Empty String in E-mail's Set of Valid Characters", /* 24 */
    "Invalid Length in E-mail", /* 25 */
    "Invalid Character in E-mail", /* 26 */
    "Invalid Format in E-mail", /* 27 */
    "Null Pointer in Random String's Set of Valid Characters", /* 28 */
    "Empty String in Random String's Set of Valid Characters", /* 29 */
    "Invalid Length in Random String", /* 30 */
    "Null Pointer in Username", /* 31 */
    "Empty String in Username", /* 32 */
    "Invalid Length in Username", /* 33 */
    "Invalid Character in Username", /* 34 */
    "Empty String in Username's Last Name", /* 35 */
    "Invalid Length in Nickname's Possibility", /* 36 */
    "Null Pointer in Encoded Password Hash", /* 37 */
    "Empty String in Encoded Password Hash", /* 38 */
    "Invalid Length in Encoded Password Hash", /* 39 */
    "Invalid Character in Encoded Password Hash", /* 40 */
    "Invalid Format in Encoded Password Hash", /* 41 */
    "Invalid Value in Encoded Password Hash's Algorithm ID", /* 42 */
    "Null Pointer in Plaintext Password", /* 43 */
    "Empty String in Plaintext Password", /* 44 */
    "Invalid Value in Crypt Algorithm ID", /* 45 */
    "Invalid Length in Plaintext Password", /* 46 */
    "Invalid Character in Plaintext Password", /* 47 */
    "Null Pointer in Complete Salt", /* 48 */
    "Empty String in Complete Salt", /* 49 */
    "Invalid Length in Complete Salt", /* 50 */
    "Invalid Character in Complete Salt", /* 51 */
    "Invalid Format in Complete Salt", /* 52 */
    "DES Password Hashes Mismatch", /* 53 */
    "MD5 Password Hashes Mismatch", /* 54 */
    "SHA256 Password Hashes Mismatch", /* 55 */
    "SHA512 Password Hashes Mismatch" /* 56 */
  },
  {
    "Operacao Bem-sucedida", /* 0 */
    "Ponteiro Nulo no Caminho Absoluto", /* 1 */
    "String Vazia no Caminho Absoluto", /* 2 */
    "Ponteiro Nulo no Nome do Arquivo", /* 3 */
    "String Vazia no Nome do Arquivo", /* 4 */
    "Tamanho Invalido do Caminho Absoluto", /* 5 */
    "Tamanho Invalido do Nome do Arquivo", /* 6 */
    "Formato Invalido do Caminho Absoluto", /* 7 */
    "Ponteiro Nulo na String", /* 8 */
    "String Vazia", /* 9 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres", /* 10 */
    "String Vazia no Conjunto Valido de Caracteres", /* 11 */
    "Tamanho Invalido da String", /* 12 */
    "Caractere Invalido na String", /* 13 */
    "Ponteiro Nulo no Apelido", /* 14 */
    "String Vazia no Apelido", /* 15 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres do Apelido", /* 16 */
    "String Vazia no Conjunto Valido de Caracteres do Apelido", /* 17 */
    "Tamanho Invalido do Apelido", /* 18 */
    "Caractere Invalido no Apelido", /* 19 */
    "Formato Invalido do Apelido", /* 20 */
    "Ponteiro Nulo no E-mail", /* 21 */
    "String Vazia no E-mail", /* 22 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres do E-mail", /* 23 */
    "String Vazia no Conjunto Valido de Caracteres do E-mail", /* 24 */
    "Tamanho Invalido do E-mail", /* 25 */
    "Caractere Invalido no E-mail", /* 26 */
    "Formato Invalido do E-mail", /* 27 */
    "Ponteiro Nulo no Conjunto Valido de Caracteres da String Aleatoria", /* 28 */
    "String Vazia no Conjunto Valido de Caracteres da String Aleatoria", /* 29 */
    "Tamanho Invalido da String Aleatoria", /* 30 */
    "Ponteiro Nulo no Nome do Usuario", /* 31 */
    "String Vazia no Nome do Usuario", /* 32 */
    "Tamanho Invalido do Nome do Usuario", /* 33 */
    "Caractere Invalido no Nome do Usuario", /* 34 */
    "String Vazia no Ultimo Nome do Nome do Usuario", /* 35 */
    "Tamanho Invalido da Possibilidade de Apelido", /* 36 */
    "Ponteiro Nulo no Hash da Senha Codificada", /* 37 */
    "String Vazia no Hash da Senha Codificada", /* 38 */
    "Tamanho Invalido do Hash da Senha Codificada", /* 39 */
    "Caractere Invalido no Hash da Senha Codificada", /* 40 */
    "Formato Invalido no Hash da Senha Codificada", /* 41 */
    "Valor Invalido do ID do Algoritmo no Hash da Senha Codificada", /* 42 */
    "Ponteiro Nulo na Senha Plana", /* 43 */
    "String Vazia na Senha Plana", /* 44 */
    "Valor Invalido do ID do Algoritmo de Criptografia", /* 45 */
    "Tamanho Invalido da Senha Plana", /* 46 */
    "Caractere Invalido na Senha Plana", /* 47 */
    "Ponteiro Nulo no Salt Completo", /* 48 */
    "String Vazia no Salt Completo", /* 49 */
    "Tamanho Invalido do Salt Completo", /* 50 */
    "Caractere Invalido no Salt Completo", /* 51 */
    "Formato Invalido do Salt Completo", /* 52 */
    "Incompatibilidade Entre as Senhas DES", /* 53 */
    "Incompatibilidade Entre as Senhas MD5", /* 54 */
    "Incompatibilidade Entre as Senhas SHA256", /* 55 */
    "Incompatibilidade Entre as Senhas SHA512" /* 56 */
  }
}; /* lfllUmlNcursesErrorMessages */





/* Definition of global variable lfllUmlWebErrorMessages. */

char *lfllUmlWebErrorMessages[lfllUmlLanguagesNumber][lfllUmlErrorCodesNumber] =
{
  {
    "Successful Operation", /* 0 */
    "Null Pointer in Absolute Path", /* 1 */
    "Empty String in Absolute Path", /* 2 */
    "Null Pointer in File Name", /* 3 */
    "Empty String in File Name", /* 4 */
    "Invalid Length in Absolute Path", /* 5 */
    "Invalid Length in File Name", /* 6 */
    "Invalid Format in Absolute Path", /* 7 */
    "Null Pointer in String", /* 8 */
    "Empty String", /* 9 */
    "Null Pointer in Set of Valid Characters", /* 10 */
    "Empty String in Set of Valid Characters", /* 11 */
    "Invalid Length in String", /* 12 */
    "Invalid Character in String", /* 13 */
    "Null Pointer in Nickname", /* 14 */
    "Empty String in Nickname", /* 15 */
    "Null Pointer in Nickname's Set of Valid Characters", /* 16 */
    "Empty String in Nickname's Set of Valid Characters", /* 17 */
    "Invalid Length in Nickname", /* 18 */
    "Invalid Character in Nickname", /* 19 */
    "Invalid Format in Nickname", /* 20 */
    "Null Pointer in E-mail", /* 21 */
    "Empty String in E-mail", /* 22 */
    "Null Pointer in E-mail's Set of Valid Characters", /* 23 */
    "Empty String in E-mail's Set of Valid Characters", /* 24 */
    "Invalid Length in E-mail", /* 25 */
    "Invalid Character in E-mail", /* 26 */
    "Invalid Format in E-mail", /* 27 */
    "Null Pointer in Random String's Set of Valid Characters", /* 28 */
    "Empty String in Random String's Set of Valid Characters", /* 29 */
    "Invalid Length in Random String", /* 30 */
    "Null Pointer in Username", /* 31 */
    "Empty String in Username", /* 32 */
    "Invalid Length in Username", /* 33 */
    "Invalid Character in Username", /* 34 */
    "Empty String in Username's Last Name", /* 35 */
    "Invalid Length in Nickname's Possibility", /* 36 */
    "Null Pointer in Encoded Password Hash", /* 37 */
    "Empty String in Encoded Password Hash", /* 38 */
    "Invalid Length in Encoded Password Hash", /* 39 */
    "Invalid Character in Encoded Password Hash", /* 40 */
    "Invalid Format in Encoded Password Hash", /* 41 */
    "Invalid Value in Encoded Password Hash's Algorithm ID", /* 42 */
    "Null Pointer in Plaintext Password", /* 43 */
    "Empty String in Plaintext Password", /* 44 */
    "Invalid Value in Crypt Algorithm ID", /* 45 */
    "Invalid Length in Plaintext Password", /* 46 */
    "Invalid Character in Plaintext Password", /* 47 */
    "Null Pointer in Complete Salt", /* 48 */
    "Empty String in Complete Salt", /* 49 */
    "Invalid Length in Complete Salt", /* 50 */
    "Invalid Character in Complete Salt", /* 51 */
    "Invalid Format in Complete Salt", /* 52 */
    "DES Password Hashes Mismatch", /* 53 */
    "MD5 Password Hashes Mismatch", /* 54 */
    "SHA256 Password Hashes Mismatch", /* 55 */
    "SHA512 Password Hashes Mismatch" /* 56 */
  },
  {
    "Opera&ccedil;&atilde;o Bem-sucedida", /* 0 */
    "Ponteiro Nulo no Caminho Absoluto", /* 1 */
    "String Vazia no Caminho Absoluto", /* 2 */
    "Ponteiro Nulo no Nome do Arquivo", /* 3 */
    "String Vazia no Nome do Arquivo", /* 4 */
    "Tamanho Inv&aacute;lido do Caminho Absoluto", /* 5 */
    "Tamanho Inv&aacute;lido do Nome do Arquivo", /* 6 */
    "Formato Inv&aacute;lido do Caminho Absoluto", /* 7 */
    "Ponteiro Nulo na String", /* 8 */
    "String Vazia", /* 9 */
    "Ponteiro Nulo no Conjunto V&aacute;lido de Caracteres", /* 10 */
    "String Vazia no Conjunto V&aacute;lido de Caracteres", /* 11 */
    "Tamanho Inv&aacute;lido da String", /* 12 */
    "Caractere Inv&aacute;lido na String", /* 13 */
    "Ponteiro Nulo no Apelido", /* 14 */
    "String Vazia no Apelido", /* 15 */
    "Ponteiro Nulo no Conjunto V&aacute;lido de Caracteres do Apelido", /* 16 */
    "String Vazia no Conjunto V&aacute;lido de Caracteres do Apelido", /* 17 */
    "Tamanho Inv&aacute;lido do Apelido", /* 18 */
    "Caractere Inv&aacute;lido no Apelido", /* 19 */
    "Formato Inv&aacute;lido do Apelido", /* 20 */
    "Ponteiro Nulo no E-mail", /* 21 */
    "String Vazia no E-mail", /* 22 */
    "Ponteiro Nulo no Conjunto V&aacute;lido de Caracteres do E-mail", /* 23 */
    "String Vazia no Conjunto V&aacute;lido de Caracteres do E-mail", /* 24 */
    "Tamanho Inv&aacute;lido do E-mail", /* 25 */
    "Caractere Inv&aacute;lido no E-mail", /* 26 */
    "Formato Inv&aacute;lido do E-mail", /* 27 */
    "Ponteiro Nulo no Conjunto V&aacute;lido de Caracteres da String Aleat&oacute;ria", /* 28 */
    "String Vazia no Conjunto V&aacute;lido de Caracteres da String Aleat&oacute;ria", /* 29 */
    "Tamanho Inv&aacute;lido da String Aleat&oacute;ria", /* 30 */
    "Ponteiro Nulo no Nome do Usu&aacute;rio", /* 31 */
    "String Vazia no Nome do Usu&aacute;rio", /* 32 */
    "Tamanho Inv&aacute;lido do Nome do Usu&aacute;rio", /* 33 */
    "Caractere Inv&aacute;lido no Nome do Usu&aacute;rio", /* 34 */
    "String Vazia no &Uacute;ltimo Nome do Nome do Usu&aacute;rio", /* 35 */
    "Tamanho Inv&aacute;lido da Possibilidade de Apelido", /* 36 */
    "Ponteiro Nulo no Hash da Senha Codificada", /* 37 */
    "String Vazia no Hash da Senha Codificada", /* 38 */
    "Tamanho Inv&aacute;lido do Hash da Senha Codificada", /* 39 */
    "Caractere Inv&aacute;lido no Hash da Senha Codificada", /* 40 */
    "Formato Inv&aacute;lido no Hash da Senha Codificada", /* 41 */
    "Valor Inv&aacute;lido do ID do Algoritmo no Hash da Senha Codificada", /* 42 */
    "Ponteiro Nulo na Senha Plana", /* 43 */
    "String Vazia na Senha Plana", /* 44 */
    "Valor Inv&aacute;lido do ID do Algoritmo de Criptografia", /* 45 */
    "Tamanho Inv&aacute;lido da Senha Plana", /* 46 */
    "Caractere Inv&aacute;lido na Senha Plana", /* 47 */
    "Ponteiro Nulo no Salt Completo", /* 48 */
    "String Vazia no Salt Completo", /* 49 */
    "Tamanho Inv&aacute;lido do Salt Completo", /* 50 */
    "Caractere Inv&aacute;lido no Salt Completo", /* 51 */
    "Formato Inv&aacute;lido do Salt Completo", /* 52 */
    "Incompatibilidade Entre as Senhas DES", /* 53 */
    "Incompatibilidade Entre as Senhas MD5", /* 54 */
    "Incompatibilidade Entre as Senhas SHA256", /* 55 */
    "Incompatibilidade Entre as Senhas SHA512" /* 56 */
  }
}; /* lfllUmlWebErrorMessages */





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
LfllUmlGetCliErrorMessage(lfllUmlErrorType lfllUmlErrorCodeValue, lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlCliErrorMessages[lfllUmlLanguageValue][lfllUmlErrorCodeValue];

} /* LfllUmlGetCliErrorMessage */





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
LfllUmlGetNcursesErrorMessage(lfllUmlErrorType lfllUmlErrorCodeValue, lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlNcursesErrorMessages[lfllUmlLanguageValue][lfllUmlErrorCodeValue];

} /* LfllUmlGetNcursesErrorMessage */





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
LfllUmlGetWebErrorMessage(lfllUmlErrorType lfllUmlErrorCodeValue, lfllUmlLanguageType lfllUmlLanguageValue)
{

  return lfllUmlWebErrorMessages[lfllUmlLanguageValue][lfllUmlErrorCodeValue];

} /* LfllUmlGetWebErrorMessage */










/* $RCSfile: lfllUmlErrors.c,v $ */
