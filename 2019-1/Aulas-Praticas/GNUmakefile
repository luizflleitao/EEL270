#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2019/1
# Prof. Marcelo Luiz Drumond Lanza
# Autor: Luiz Fernando Loureiro Leitao
#
# $Author: luiz.leitao $
# $Date: 2019/04/24 07:41:59 $
# $Log: GNUmakefile,v $
# Revision 1.24  2019/04/24 07:41:59  luiz.leitao
# Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando recursividade e a funcao pow.
#
# Revision 1.23  2019/04/24 07:25:06  luiz.leitao
# Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao while e a funcao CalcularExponencial.
#
# Revision 1.22  2019/04/24 07:10:18  luiz.leitao
# Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao for e a funcao CalcularExponencial.
#
# Revision 1.21  2019/04/24 06:56:09  luiz.leitao
# Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando o laco de repeticao do ... while e a funcao CalcularExponencial.
#
# Revision 1.20  2019/04/24 06:42:46  luiz.leitao
# Implementacao da funcao CalcularSerieHarmonicaAlternada utilizando recursividade e a funcao CalcularExponencial.
#
# Revision 1.19  2019/04/19 02:40:36  luiz.leitao
# Implementacao da funcao CalcularExponencial utilizando o laco de repeticao while.
#
# Revision 1.18  2019/04/19 02:28:58  luiz.leitao
# Implementacao da funcao CalcularExponencial utilizando o laco de repeticao for.
#
# Revision 1.17  2019/04/19 02:16:16  luiz.leitao
# Implementacao da funcao CalcularExponencial utilizando o laco de repeticao do ... while.
#
# Revision 1.16  2019/04/16 14:22:31  luiz.leitao
# Implementacao da funcao CalcularExponencial utilizando recursividade.
#
# Revision 1.15  2019/04/10 16:51:54  luiz.leitao
# Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao while.
#
# Revision 1.14  2019/04/10 16:32:41  luiz.leitao
# Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao for.
#
# Revision 1.13  2019/04/10 16:15:27  luiz.leitao
# Implementacao da funcao CalcularMaximoDivisorComum utilizando o laco de repeticao do ... while.
#
# Revision 1.12  2019/04/10 16:03:52  luiz.leitao
# Implementacao da funcao CalcularMaximoDivisorComum utilizando recursividade.
#
# Revision 1.11  2019/04/05 02:44:32  luiz.leitao
# Implementacao da Serie de Fibonacci utilizando o laco de repeticao while.
#
# Revision 1.10  2019/04/05 02:32:32  luiz.leitao
# Implementacao da Serie de Fibonacci utilizando o laco de repeticao for.
#
# Revision 1.9  2019/04/05 02:18:09  luiz.leitao
# Implementacao da Serie de Fibonacci utilizando o laco de repeticao do ... while.
#
# Revision 1.8  2019/04/05 01:58:27  luiz.leitao
# Implementacao da Serie de Fibonacci utilizando recursividade.
#
# Revision 1.7  2019/03/29 06:30:56  luiz.leitao
# Inclusao dos tipos basicos combinados com os modificadores de sinal e com os modificadores de largura da linguagem C.
#
# Revision 1.6  2019/03/29 06:19:54  luiz.leitao
# Inclusao dos tipos basicos combinados com os modificadores de largura da linguagem C.
#
# Revision 1.5  2019/03/29 06:10:58  luiz.leitao
# Inclusao dos tipos basicos combinados com modificadores de sinal da linguagem C.
#
# Revision 1.4  2019/03/29 05:56:48  luiz.leitao
# Inclusao dos modificadores de sinal combinados com os modificadores de largura da linguagem C.
#
# Revision 1.3  2019/03/29 05:44:48  luiz.leitao
# Inclusao dos modificadores de largura da linguagem C.
#
# Revision 1.2  2019/03/29 05:28:55  luiz.leitao
# Inclusao dos modificadores de sinal da linguagem C.
#
# Revision 1.1  2019/03/29 05:16:54  luiz.leitao
# Initial revision
#










# Macro referente ao nome do sistema operacional utilizado.

OS = $(shell uname -s)





# Macros referentes a compilacao e a link-edicao (gcc como programa padrao).

CC = gcc
LD = gcc





# Declaracao condicional usada quando ha a escolha explicita pelo gcc (make cc=GCC).

ifeq ($(cc), GCC)
CC = gcc
LD = gcc
endif





# Declaracao condicional usada quando ha a escolha explicita pelo clang (make cc=CLANG).

ifeq ($(cc), CLANG)
CC = clang
LD = clang
endif





# Macros referentes aos argumentos passados tanto na compilacao quanto na link-edicao.

CFLAGS = -Wall -std=c99
LFLAGS = -Wall -std=c99





# Macro referente ao comando da criacao da biblioteca estatica.

AR = ar





# Macros referentes aos codigos-objeto da aula pratica 01.

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o
AULA0104OBJS = aula0104.o
AULA0105OBJS = aula0105.o
AULA0106OBJS = aula0106.o
AULA0107OBJS = aula0107.o





# Macros referentes aos codigos-objeto da aula pratica 02.

AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o





# Macros referentes aos codigos-objeto da aula pratica 03.

AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o





# Macros referentes aos codigos-objeto da aula pratica 04.

AULA0402AOBJS = aula0401a.o aula0402.o
AULA0402BOBJS = aula0401b.o aula0402.o
AULA0402COBJS = aula0401c.o aula0402.o
AULA0402DOBJS = aula0401d.o aula0402.o





# Macros referentes aos codigos-objeto da aula pratica 05.

AULA0502AOBJS = aula0501a.o aula0502.o
AULA0502BOBJS = aula0501b.o aula0502.o
AULA0502COBJS = aula0501c.o aula0502.o
AULA0502DOBJS = aula0501d.o aula0502.o
AULA0502EOBJS = aula0501e.o aula0502.o





# Macros referentes a criacao da biblioteca estatica.

LIBMATEMATICAOBJS = aula0401a.o
LIBMATEMATICA = libmatematica.a





# Macro referente aos executaveis da aula pratica 01.

AULA01 = aula0101\
	 aula0102\
	 aula0103\
	 aula0104\
	 aula0105\
	 aula0106\
	 aula0107





# Macro referente aos executaveis da aula pratica 02.

AULA02 = aula0202a\
	 aula0202b\
	 aula0202c\
	 aula0202d





# Macro referente aos executaveis da aula pratica 03.

AULA03 = aula0302a\
	 aula0302b\
	 aula0302c\
	 aula0302d





# Macro referente aos executaveis da aula pratica 04.

AULA04 = aula0402a\
	 aula0402b\
	 aula0402c\
	 aula0402d





# Macro referente aos executaveis da aula pratica 05.

AULA05 = aula0502a\
	 aula0502b\
	 aula0502c\
	 aula0502d\
	 aula0502e





# Macro referente aos executaveis das aulas praticas de 01 a 10.

EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04) $(AULA05)





# Macro referente as bibliotecas estaticas.

LIBS = $(LIBMATEMATICA)





# Macro referente aos executaveis e as bibliotecas das aulas praticas de 01 a 10.

ALL = $(EXECS) $(LIBS)










# Rotulo padrao da ferramenta make (regra implicita).

.c.o:
	$(CC) $(CFLAGS) -c $<





# Rotulo referente a dependencia ALL (valor da macro ALL).

all: $(ALL)





# Rotulos referentes as dependencias (valores das macros) da aula pratica 01.

aula01: $(AULA01)

aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0104: $(AULA0104OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0105: $(AULA0105OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0106: $(AULA0106OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0107: $(AULA0107OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
	cp $@ $@-$(OS)-$(CC)





# Rotulos referentes as dependencias (valores das macros) da aula pratica 02.

aula02: $(AULA02)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp $@ $@-$(OS)-$(CC)





# Rotulos referentes as dependencias (valores das macros) da aula pratica 03.

aula03: $(AULA03)

aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp $@ $@-$(OS)-$(CC)





# Rotulos referentes as dependencias (valores das macros) da aula pratica 04.

aula04: $(AULA04)

aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)
	cp $@ $@-$(OS)-$(CC)





# Rotulos referentes as dependencias (valores das macros) da aula pratica 05.

aula05: $(AULA05)

aula0502a: $(AULA0502AOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502AOBJS) -L. -lmatematica
	cp $@ $@-$(OS)-$(CC)

aula0502b: $(AULA0502BOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502BOBJS) -L. -lmatematica
	cp $@ $@-$(OS)-$(CC)

aula0502c: $(AULA0502COBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502COBJS) -L. -lmatematica
	cp $@ $@-$(OS)-$(CC)

aula0502d: $(AULA0502DOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502DOBJS) -L. -lmatematica
	cp $@ $@-$(OS)-$(CC)

aula0502e: $(AULA0502EOBJS) $(LIBMATEMATICA)
	$(LD) $(LFLAGS) -o $@ $(AULA0502EOBJS) -L. -lm
	cp $@ $@-$(OS)-$(CC)





# Rotulos referentes as dependencias (valores das macros) da biblioteca estatica.

libmatematica.a: $(LIBMATEMATICAOBJS)
	$(AR) -r $@ $(LIBMATEMATICAOBJS)





# Rotulo referente a exclusao de todos os codigos-objeto e executaveis gerados, exceto os executaveis
# que indicam a combinacao entre sistema operacional e compilador/link-editor.


clean:
	rm -f *.o $(ALL)





# Rotulo referente a exclusao de todos os codigos-objeto e executaveis gerados.

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-*





# Rotulo referente a exclusao de todos os codigos-objeto e executaveis gerados no FreeBSD.

clean-freebsd:
	rm -f *.o *-FreeBSD-*





# Rotulo referente a exclusao de todos os codigos-objeto e executaveis gerados no Linux.

clean-linux:
	rm -f *.o *-Linux-*










# $RCSfile: GNUmakefile,v $
