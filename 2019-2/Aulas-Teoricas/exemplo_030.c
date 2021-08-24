/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: <nome completo>
 * Descricao: <descricao sucinta sobre o programa>
 *
 * $Author$
 * $Date$
 * $Log$
 */

#include "exemplo_030.h"

boolean
ValidarDigitoVerificadorDre (byte digito1, 
                             byte digito2, 
                             byte digito3, 
                             byte digito4, 
                             byte digito5, 
                             byte digito6, 
                             byte digito7, 
                             byte digito8, 
                             byte digitoVerificador)
{
  unsigned short soma;

  soma = digito1 + 
         digito2 * 2 + 
         digito3 * 3 +
         digito4 * 4 +
         digito5 * 5 +
         digito6 * 6 +
         digito7 * 7 +
         digito8 * 8; 

  if ((soma % 10) != digitoVerificador)
    return falso;

  return verdadeiro;

}

/* $RCSfile$ */
