#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2019/1
# Prof. Marcelo Luiz Drumond Lanza
#
# Autor: <nome completo>
# Descricao: <descricao sucinta sobre o programa>
#
# $Author$
# $Date$
# $Log$

OS = $(shell uname -s)

CC = gcc
LD = gcc

ifeq ($(cc), GCC)
CC = gcc
LD = gcc
endif

ifeq ($(cc), CLANG)
CC = clang
LD = clang
endif
 
CFLAGS = -Wall -std=c99
LFLAGS = -Wall -std=c99

EXE001OBJS = exemplo_001.o
EXE002OBJS = exemplo_002.o
EXE003OBJS = exemplo_003.o
EXE004OBJS = exemplo_004.o
EXE005OBJS = exemplo_005.o
EXE006OBJS = exemplo_006.o
EXE007OBJS = exemplo_007.o
EXE008OBJS = exemplo_008.o
EXE009OBJS = exemplo_009.o

EXECS = exemplo_001\
	exemplo_002\
	exemplo_003\
	exemplo_004\
	exemplo_005\
	exemplo_006\
	exemplo_007\
	exemplo_008\
	exemplo_009

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)

exemplo_001: $(EXE001OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE001OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_002: $(EXE002OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE002OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_003: $(EXE003OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE003OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_004: $(EXE004OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE004OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_005: $(EXE005OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE005OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_006: $(EXE006OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE006OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_007: $(EXE007OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE007OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_008: $(EXE008OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE008OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_009: $(EXE009OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE009OBJS)
	cp $@ $@-$(OS)-$(CC)

clean:
	rm -f *.o $(EXECS)

clean-all:
	rm -f *.o $(EXECS) *-FreeBSD-* *-Linux-*

clean-freebsd:
	rm -f *.o *-FreeBSD-*

clean-linux:
	rm -f *.o *-Linux-*











