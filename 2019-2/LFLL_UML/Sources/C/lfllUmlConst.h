/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2019/2
 *
 * $Author: luiz.leitao $
 * $Date: 2019/12/07 00:22:00 $
 * $Log: lfllUmlConst.h,v $
 * Revision 1.8  2019/12/07 00:22:00  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.7  2019/12/06 16:14:35  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.6  2019/11/30 16:19:33  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.5  2019/11/30 08:14:36  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.4  2019/11/29 13:59:36  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.3  2019/11/28 13:28:38  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.2  2019/11/27 12:58:49  luiz.leitao
 * Inclusion of new macros.
 *
 * Revision 1.1  2019/11/12 14:15:01  luiz.leitao
 * Initial revision
 *
 */










#ifndef LFLL_UML_CONST_H
#define LFLL_UML_CONST_H  "@(#)lfllUmlConst.h $Revision: 1.8 $" 





#ifndef LFLL_UML_EOS
#define LFLL_UML_EOS						'\0'
#endif  /* #ifndef LFLL_UML_EOS */





#ifndef LFLL_UML_ENGLISH_LANGUAGE_LENGTH
#define LFLL_UML_ENGLISH_LANGUAGE_LENGTH			14
#endif  /* #ifndef LFLL_UML_ENGLISH_LANGUAGE_LENGTH */





#ifndef LFLL_UML_PORTUGUESE_LANGUAGE_LENGTH
#define LFLL_UML_PORTUGUESE_LANGUAGE_LENGTH			17
#endif  /* #ifndef LFLL_UML_PORTUGUESE_LANGUAGE_LENGTH */





#ifndef LFLL_UML_LANGUAGE_MAXIMUM_LENGTH
#define LFLL_UML_LANGUAGE_MAXIMUM_LENGTH			1
#endif  /* #ifndef LFLL_UML_LANGUAGE_MAXIMUM_LENGTH */





#ifndef LFLL_UML_ERROR_CODE_MAXIMUM_LENGTH
#define LFLL_UML_ERROR_CODE_MAXIMUM_LENGTH			3
#endif  /* #ifndef LFLL_UML_ERROR_CODE_MAXIMUM_LENGTH */





#ifndef LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH
#define LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH			4096
#endif  /* #ifndef LFLL_UML_ABSOLUTE_PATH_MAXIMUM_LENGTH */





#ifndef LFLL_UML_FILE_NAME_MAXIMUM_LENGTH
#define LFLL_UML_FILE_NAME_MAXIMUM_LENGTH			255
#endif  /* #ifndef LFLL_UML_FILE_NAME_MAXIMUM_LENGTH */





#ifndef LFLL_UML_SLASH_CHARACTER
#define LFLL_UML_SLASH_CHARACTER				'/'
#endif  /* #ifndef LFLL_UML_SLASH_CHARACTER */





#ifndef LFLL_UML_NICKNAME_MINIMUM_LENGTH
#define LFLL_UML_NICKNAME_MINIMUM_LENGTH			5
#endif  /* #ifndef LFLL_UML_NICKNAME_MINIMUM_LENGTH */





#ifndef LFLL_UML_NICKNAME_MAXIMUM_LENGTH
#define LFLL_UML_NICKNAME_MAXIMUM_LENGTH			65
#endif  /* #ifndef LFLL_UML_NICKNAME_MAXIMUM_LENGTH */





#ifndef LFLL_UML_NICKNAME_VALID_CHARACTERS_SET
#define LFLL_UML_NICKNAME_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyz."
#endif  /* #ifndef LFLL_UML_NICKNAME_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_NICKNAME_NUMBER_OF_DOTS
#define LFLL_UML_NICKNAME_NUMBER_OF_DOTS			1
#endif  /* #ifndef LFLL_UML_NICKNAME_NUMBER_OF_DOTS */





#ifndef LFLL_UML_DOT_CHARACTER
#define LFLL_UML_DOT_CHARACTER					'.'
#endif  /* #ifndef LFLL_UML_DOT_CHARACTER */





#ifndef LFLL_UML_EMAIL_MINIMUM_LENGTH
#define LFLL_UML_EMAIL_MINIMUM_LENGTH				11
#endif  /* #ifndef LFLL_UML_EMAIL_MINIMUM_LENGTH */





#ifndef LFLL_UML_EMAIL_MAXIMUM_LENGTH
#define LFLL_UML_EMAIL_MAXIMUM_LENGTH				1024
#endif  /* #ifndef LFLL_UML_EMAIL_MAXIMUM_LENGTH */





#ifndef LFLL_UML_EMAIL_VALID_CHARACTERS_SET
#define LFLL_UML_EMAIL_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_@"
#endif  /* #ifndef LFLL_UML_EMAIL_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_EMAIL_NUMBER_OF_ATS
#define LFLL_UML_EMAIL_NUMBER_OF_ATS				1
#endif  /* #ifndef LFLL_UML_EMAIL_NUMBER_OF_ATS */





#ifndef LFLL_UML_AT_CHARACTER
#define LFLL_UML_AT_CHARACTER					'@'
#endif  /* #ifndef LFLL_UML_AT_CHARACTER */





#ifndef LFLL_UML_HYPHEN_CHARACTER
#define LFLL_UML_HYPHEN_CHARACTER				'-'
#endif  /* #ifndef LFLL_UML_HYPHEN_CHARACTER */





#ifndef LFLL_UML_RANDOM_STRING_MINIMUM_LENGTH
#define LFLL_UML_RANDOM_STRING_MINIMUM_LENGTH			2
#endif  /* #ifndef LFLL_UML_RANDOM_STRING_MINIMUM_LENGTH */





#ifndef LFLL_UML_RANDOM_STRING_MAXIMUM_LENGTH
#define LFLL_UML_RANDOM_STRING_MAXIMUM_LENGTH			2048
#endif  /* #ifndef LFLL_UML_RANDOM_STRING_MAXIMUM_LENGTH */





#ifndef LFLL_UML_USERNAME_MINIMUM_LENGTH
#define LFLL_UML_USERNAME_MINIMUM_LENGTH			11
#endif  /* #ifndef LFLL_UML_USERNAME_MINIMUM_LENGTH */





#ifndef LFLL_UML_USERNAME_MAXIMUM_LENGTH
#define LFLL_UML_USERNAME_MAXIMUM_LENGTH			256
#endif  /* #ifndef LFLL_UML_USERNAME_MAXIMUM_LENGTH */





#ifndef LFLL_UML_USERNAME_VALID_CHARACTERS_SET
#define LFLL_UML_USERNAME_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .-'"
#endif  /* #ifndef LFLL_UML_USERNAME_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_DES_HASH_LENGTH
#define LFLL_UML_DES_HASH_LENGTH				13
#endif  /* #ifndef LFLL_UML_DES_HASH_LENGTH */





#ifndef LFLL_UML_DES_HASH_VALID_CHARACTERS_SET
#define LFLL_UML_DES_HASH_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_DES_HASH_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_DES_SALT_LENGTH
#define LFLL_UML_DES_SALT_LENGTH				2
#endif  /* #ifndef LFLL_UML_DES_SALT_LENGTH */





#ifndef LFLL_UML_DES_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_DES_SALT_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_DES_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_MD5_HASH_LENGTH
#define LFLL_UML_MD5_HASH_LENGTH				34
#endif  /* #ifndef LFLL_UML_MD5_HASH_LENGTH */





#ifndef LFLL_UML_MD5_HASH_NUMBER_OF_DOLLARS
#define LFLL_UML_MD5_HASH_NUMBER_OF_DOLLARS			3
#endif  /* #ifndef LFLL_UML_MD5_HASH_NUMBER_OF_DOLLARS */





#ifndef LFLL_UML_MD5_HASH_VALID_CHARACTERS_SET
#define LFLL_UML_MD5_HASH_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_MD5_HASH_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_MD5_ENCODED_LENGTH
#define LFLL_UML_MD5_ENCODED_LENGTH				22
#endif  /* #ifndef LFLL_UML_MD5_ENCODED_LENGTH */





#ifndef LFLL_UML_MD5_COMPLETE_SALT_LENGTH
#define LFLL_UML_MD5_COMPLETE_SALT_LENGTH			12
#endif  /* #ifndef LFLL_UML_MD5_COMPLETE_SALT_LENGTH */





#ifndef LFLL_UML_MD5_COMPLETE_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_MD5_COMPLETE_SALT_VALID_CHARACTERS_SET		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./$"
#endif  /* #ifndef LFLL_UML_MD5_COMPLETE_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_MD5_SALT_LENGTH
#define LFLL_UML_MD5_SALT_LENGTH				8
#endif  /* #ifndef LFLL_UML_MD5_SALT_LENGTH */





#ifndef LFLL_UML_MD5_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_MD5_SALT_VALID_CHARACTERS_SET			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_MD5_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_MD5_ID_LENGTH
#define LFLL_UML_MD5_ID_LENGTH					1
#endif  /* #ifndef LFLL_UML_MD5_ID_LENGTH */





#ifndef LFLL_UML_MD5_ID_POSITION
#define LFLL_UML_MD5_ID_POSITION				1
#endif  /* #ifndef LFLL_UML_MD5_ID_POSITION */





#ifndef LFLL_UML_MD5_ID_VALUE
#define LFLL_UML_MD5_ID_VALUE					1
#endif  /* #ifndef LFLL_UML_MD5_ID_VALUE */





#ifndef LFLL_UML_SHA256_HASH_LENGTH
#define LFLL_UML_SHA256_HASH_LENGTH				63
#endif  /* #ifndef LFLL_UML_SHA256_HASH_LENGTH */





#ifndef LFLL_UML_SHA256_HASH_NUMBER_OF_DOLLARS
#define LFLL_UML_SHA256_HASH_NUMBER_OF_DOLLARS			3
#endif  /* #ifndef LFLL_UML_SHA256_HASH_NUMBER_OF_DOLLARS */





#ifndef LFLL_UML_SHA256_HASH_VALID_CHARACTERS_SET
#define LFLL_UML_SHA256_HASH_VALID_CHARACTERS_SET		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_SHA256_HASH_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA256_ENCODED_LENGTH
#define LFLL_UML_SHA256_ENCODED_LENGTH				43
#endif  /* #ifndef LFLL_UML_SHA256_ENCODED_LENGTH */





#ifndef LFLL_UML_SHA256_COMPLETE_SALT_LENGTH
#define LFLL_UML_SHA256_COMPLETE_SALT_LENGTH			20
#endif  /* #ifndef LFLL_UML_SHA256_COMPLETE_SALT_LENGTH */





#ifndef LFLL_UML_SHA256_COMPLETE_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_SHA256_COMPLETE_SALT_VALID_CHARACTERS_SET	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./$"
#endif  /* #ifndef LFLL_UML_SHA256_COMPLETE_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA256_SALT_LENGTH
#define LFLL_UML_SHA256_SALT_LENGTH				16
#endif  /* #ifndef LFLL_UML_SHA256_SALT_LENGTH */





#ifndef LFLL_UML_SHA256_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_SHA256_SALT_VALID_CHARACTERS_SET		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_SHA256_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA256_ID_LENGTH
#define LFLL_UML_SHA256_ID_LENGTH				1
#endif  /* #ifndef LFLL_UML_SHA256_ID_LENGTH */





#ifndef LFLL_UML_SHA256_ID_POSITION
#define LFLL_UML_SHA256_ID_POSITION				1
#endif  /* #ifndef LFLL_UML_SHA256_ID_POSITION */





#ifndef LFLL_UML_SHA256_ID_VALUE
#define LFLL_UML_SHA256_ID_VALUE				5
#endif  /* #ifndef LFLL_UML_SHA256_ID_VALUE */





#ifndef LFLL_UML_SHA512_HASH_LENGTH
#define LFLL_UML_SHA512_HASH_LENGTH				106
#endif  /* #ifndef LFLL_UML_SHA512_HASH_LENGTH */





#ifndef LFLL_UML_SHA512_HASH_NUMBER_OF_DOLLARS
#define LFLL_UML_SHA512_HASH_NUMBER_OF_DOLLARS			3
#endif  /* #ifndef LFLL_UML_SHA512_HASH_NUMBER_OF_DOLLARS */





#ifndef LFLL_UML_SHA512_HASH_VALID_CHARACTERS_SET
#define LFLL_UML_SHA512_HASH_VALID_CHARACTERS_SET		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_SHA512_HASH_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA512_ENCODED_LENGTH
#define LFLL_UML_SHA512_ENCODED_LENGTH				86
#endif  /* #ifndef LFLL_UML_SHA512_ENCODED_LENGTH */





#ifndef LFLL_UML_SHA512_COMPLETE_SALT_LENGTH
#define LFLL_UML_SHA512_COMPLETE_SALT_LENGTH			20
#endif  /* #ifndef LFLL_UML_SHA512_COMPLETE_SALT_LENGTH */





#ifndef LFLL_UML_SHA512_COMPLETE_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_SHA512_COMPLETE_SALT_VALID_CHARACTERS_SET	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./$"
#endif  /* #ifndef LFLL_UML_SHA512_COMPLETE_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA512_SALT_LENGTH
#define LFLL_UML_SHA512_SALT_LENGTH				16
#endif  /* #ifndef LFLL_UML_SHA512_SALT_LENGTH */





#ifndef LFLL_UML_SHA512_SALT_VALID_CHARACTERS_SET
#define LFLL_UML_SHA512_SALT_VALID_CHARACTERS_SET		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"
#endif  /* #ifndef LFLL_UML_SHA512_SALT_VALID_CHARACTERS_SET */





#ifndef LFLL_UML_SHA512_ID_LENGTH
#define LFLL_UML_SHA512_ID_LENGTH				1
#endif  /* #ifndef LFLL_UML_SHA512_ID_LENGTH */





#ifndef LFLL_UML_SHA512_ID_POSITION
#define LFLL_UML_SHA512_ID_POSITION				1
#endif  /* #ifndef LFLL_UML_SHA512_ID_POSITION */





#ifndef LFLL_UML_SHA512_ID_VALUE
#define LFLL_UML_SHA512_ID_VALUE				6
#endif  /* #ifndef LFLL_UML_SHA512_ID_VALUE */





#ifndef LFLL_UML_HASH_ID_POSITION
#define LFLL_UML_HASH_ID_POSITION				1
#endif  /* #ifndef LFLL_UML_HASH_ID_POSITION */





#ifndef LFLL_UML_DOLLAR_CHARACTER
#define LFLL_UML_DOLLAR_CHARACTER				'$'
#endif  /* #ifndef LFLL_UML_DOLLAR_CHARACTER */





#ifndef LFLL_UML_ZERO_CHARACTER_ASCII_VALUE
#define LFLL_UML_ZERO_CHARACTER_ASCII_VALUE			'0'
#endif /* LFLL_UML_ZERO_CHARACTER_ASCII_VALUE */





#ifndef LFLL_UML_SPACE_CHARACTER
#define LFLL_UML_SPACE_CHARACTER				' '
#endif  /* #ifndef LFLL_UML_SPACE_CHARACTER */





#ifndef LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH
#define LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH		8
#endif /* LFLL_UML_PLAINTEXT_PASSWORD_MINIMUM_LENGTH */





#ifndef LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH
#define LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH		127
#endif /* LFLL_UML_PLAINTEXT_PASSWORD_MAXIMUM_LENGTH */





#ifndef LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET
#define LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .-'\"()[]{}!?@#$%&*/\\+=,;:"
#endif  /* #ifndef LFLL_UML_PLAINTEXT_PASSWORD_VALID_CHARACTERS_SET */





#endif  /* #ifndef LFLL_UML_CONST_H */










/* $RCSfile: lfllUmlConst.h,v $ */
