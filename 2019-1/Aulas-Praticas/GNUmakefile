#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2019/1
# Prof. Marcelo Luiz Drumond Lanza
# Autor: Luiz Fernando Loureiro Leitao
#
# $Author: luiz.leitao $
# $Date: 2019/03/29 06:30:56 $
# $Log: GNUmakefile,v $
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





# Macros referentes aos codigos-objeto da aula pratica 01.

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o
AULA0104OBJS = aula0104.o
AULA0105OBJS = aula0105.o
AULA0106OBJS = aula0106.o
AULA0107OBJS = aula0107.o





# Macro referente aos executaveis da aula pratica 01.

AULA01 = aula0101\
	 aula0102\
	 aula0103\
	 aula0104\
	 aula0105\
	 aula0106\
	 aula0107





# Macro referente aos executaveis das aulas praticas de 01 a 10.

EXECS = $(AULA01) 





# Macro referente aos executaveis e as bibliotecas das aulas praticas de 01 a 10.

ALL = $(EXECS)










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
