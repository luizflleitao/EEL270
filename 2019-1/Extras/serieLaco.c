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

  long double resultado;
  long double numeroAuxiliar1, numeroAuxiliar2;
  unsigned short indiceTermo = 3;



  numeroAuxiliar1 = 2;
  numeroAuxiliar2 = 1;



  if (termo <= 2)
    return termo;



  while (indiceTermo <= termo)
  {
    if (indiceTermo % 2 != 0)
    {
      resultado = 2 * numeroAuxiliar1 + numeroAuxiliar2;
      numeroAuxiliar2 = numeroAuxiliar1;
      numeroAuxiliar1 = resultado;
    }
    else
    {
      resultado = numeroAuxiliar1 - numeroAuxiliar2;
      numeroAuxiliar2 = numeroAuxiliar1;
      numeroAuxiliar1 = resultado;
    }

    indiceTermo++;
  }



  return resultado;

}










/* $RCSfile$ */
