/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/06 16:13:23 $
 * $Log: lfllUmlTypes.h,v $
 * Revision 1.3  2019/12/06 16:13:23  luiz.leitao
 * Inclusion of numbered type lfllUmlCryptAlgorithms.
 *
 * Revision 1.2  2019/11/26 17:09:55  luiz.leitao
 * Inclusion of lfllUmlUserIdentifierType.
 * Inclusion of lfllUmlUserProfileType.
 *
 * Revision 1.1  2019/11/12 13:13:14  luiz.leitao
 * Initial revision
 *
 */










#ifndef LFLL_UML_TYPES_H  /* Begin of preprocessor directive. */
#define LFLL_UML_TYPES_H  "@(#)lfllUmlTypes.h $Revision: 1.3 $"





/* Definition of numbered type lfllUmlLanguageType. */

typedef enum
{
  lfllUmlEnglish = 0,
  lfllUmlPortuguese = 1,
  lfllUmlLanguagesNumber = 2
} lfllUmlLanguageType;





/* Definition of type lfllUmlUserIdentifierType from the basic types of the language. */

typedef unsigned long long lfllUmlUserIdentifierType;





/* Definition of type lfllUmlUserProfileType from the basic types of the language. */

typedef unsigned long long lfllUmlUserProfileType;





/* Definition of numbered type lfllUmlCryptAlgorithms. */

typedef enum
{
  lfllUmlDes = 0,
  lfllUmlMD5 = 1,
  lfllUmlSha256 = 5,
  lfllUmlSha512 = 6
} lfllUmlCryptAlgorithms;





#endif  /* End of preprocessor directive. */










/* $RCSfile: lfllUmlTypes.h,v $ */
