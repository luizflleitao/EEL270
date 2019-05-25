/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2019/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Luiz Fernando Loureiro Leitao
 *
 * $Author$
 * $Date$
 * $Log$
 */










#include "serie.h"





long double
CalcularSerieAlternada(unsigned short termo)
{

  if (termo <= 2)
    return termo;


  if ((termo % 2) == 0)
    return ((-1.0) * CalcularSerieAlternada(termo - 2) + CalcularSerieAlternada(termo - 1));


  return ((2.0) * CalcularSerieAlternada(termo - 1) + CalcularSerieAlternada(termo - 2));

}










/* $RCSfile$ */
