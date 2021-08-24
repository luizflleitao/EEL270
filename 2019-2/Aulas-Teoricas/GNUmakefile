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

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

CFLAGS = -Wall -std=c11

ifeq ($(debug), _MY_DEBUG_)
CFLAGS = -Wall -std=c11 -D_MY_DEBUG_
endif

LFLAGS = -Wall -std=c11

EXE001OBJS = exemplo_001.o
EXE002OBJS = exemplo_002.o
EXE003OBJS = exemplo_003.o
EXE004OBJS = exemplo_004.o
EXE005OBJS = exemplo_005.o
EXE006OBJS = exemplo_006.o
EXE007OBJS = exemplo_007.o
EXE008OBJS = exemplo_008.o
EXE009OBJS = exemplo_009.o
EXE010OBJS = exemplo_010.o
EXE011OBJS = exemplo_011.o
EXE012OBJS = exemplo_012.o
EXE013OBJS = exemplo_013.o
EXE014OBJS = exemplo_014.o
EXE015OBJS = exemplo_015.o
EXE017AOBJS = exemplo_016a.o exemplo_017.o
EXE017BOBJS = exemplo_016b.o exemplo_017.o
EXE017COBJS = exemplo_016c.o exemplo_017.o
EXE017DOBJS = exemplo_016d.o exemplo_017.o
EXE018OBJS = exemplo_018.o
EXE019OBJS = exemplo_019.o
EXE020OBJS = exemplo_020.o
EXE021OBJS = exemplo_021.o
EXE022OBJS = exemplo_022.o
EXE023OBJS = exemplo_023.o
EXE024OBJS = exemplo_024.o
EXE025OBJS = exemplo_025.o
EXE026OBJS = exemplo_026.o
EXE027OBJS = exemplo_027.o
EXE028OBJS = exemplo_028.o
EXE029OBJS = exemplo_029.o
EXE031OBJS = exemplo_030.o exemplo_031.o
EXE033OBJS = exemplo_032.o exemplo_033.o
EXE034OBJS = exemplo_032.o exemplo_034.o
EXE035OBJS = exemplo_035.o
EXE036OBJS = exemplo_036.o
EXE037OBJS = exemplo_037.o
EXE038OBJS = exemplo_038.o
EXE039OBJS = exemplo_039.o
EXE040OBJS = exemplo_040.o
EXE041OBJS = exemplo_041.o
EXE042OBJS = exemplo_042.o
EXE044OBJS = exemplo_043.o exemplo_044.o
EXE046OBJS = exemplo_045.o exemplo_046.o
EXE048OBJS = exemplo_047.o exemplo_048.o
EXE050OBJS = exemplo_049.o exemplo_050.o

AULA01 = exemplo_001\
 	 exemplo_002\
	 exemplo_003

AULA02 = exemplo_004\
	 exemplo_005\
	 exemplo_006\
	 exemplo_007\
	 exemplo_008

AULA04 = exemplo_009\
         exemplo_010

AULA06 = exemplo_011\
	 exemplo_012\
	 exemplo_013\
         exemplo_014\
         exemplo_015\
         exemplo_017a\
         exemplo_017b\
         exemplo_017c\
         exemplo_017d

AULA09 = exemplo_018\
         exemplo_019\
         exemplo_020\
         exemplo_021\
         exemplo_022\
         exemplo_023\
         exemplo_024\
         exemplo_025

AULA10 = exemplo_026\
         exemplo_027\
         exemplo_028\
         exemplo_029

AULA12 = exemplo_031\
         exemplo_033\
         exemplo_034

AULA13 = exemplo_035\
         exemplo_036\
         exemplo_037\
         exemplo_038\
         exemplo_039\
         exemplo_040\
         exemplo_041\
         exemplo_042

AULA14 = exemplo_044\
         exemplo_046\
         exemplo_048\
         exemplo_050

AULA15 = 
EXECS = $(AULA01)\
        $(AULA02)\
        $(AULA04)\
        $(AULA06)\
        $(AULA09)\
        $(AULA10)\
        $(AULA12)\
        $(AULA13)\
        $(AULA14)

LIBS =

ALL = $(EXECS) $(LIBS)

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula01: $(AULA01)

aula02: $(AULA02)

aula04: $(AULA04)

aula06: $(AULA06)

aula09: $(AULA09)

aula10: $(AULA10)

aula12: $(AULA12)

aula13: $(AULA13)

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

exemplo_010: $(EXE010OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE010OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_011: $(EXE011OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE011OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_012: $(EXE012OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE012OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_013: $(EXE013OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE013OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_014: $(EXE014OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE014OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_015: $(EXE015OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE015OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_017a: $(EXE017AOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE017AOBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_017b: $(EXE017BOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE017BOBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_017c: $(EXE017COBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE017COBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_017d: $(EXE017DOBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE017DOBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_018: $(EXE018OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE018OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_019: $(EXE019OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE019OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_020: $(EXE020OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE020OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_021: $(EXE021OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE021OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_022: $(EXE022OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE022OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_023: $(EXE023OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE023OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_024: $(EXE024OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE024OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_025: $(EXE025OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE025OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_026: $(EXE026OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE026OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_027: $(EXE027OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE027OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_028: $(EXE028OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE028OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_029: $(EXE029OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE029OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_031: $(EXE031OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE031OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_033: $(EXE033OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE033OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_034: $(EXE034OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE034OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_035: $(EXE035OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE035OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_036: $(EXE036OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE036OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_037: $(EXE037OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE037OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_038: $(EXE038OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE038OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_039: $(EXE039OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE039OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_040: $(EXE040OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE040OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_041: $(EXE041OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE041OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_042: $(EXE042OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE042OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_044: $(EXE044OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE044OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_046: $(EXE046OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE046OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_048: $(EXE048OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE048OBJS)
	cp $@ $@-$(OS)-$(CC)

exemplo_050: $(EXE050OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE050OBJS)
	cp $@ $@-$(OS)-$(CC)

clean:
	rm -f *.o $(ALL)

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-*

clean-freebsd:
	rm -f *.o $(ALL) *-FreeBSD-*

clean-linux:
	rm -f *.o $(ALL) *-Linux-*

