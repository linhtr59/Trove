# A Makefile to build our 'trove' project

C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror


PROJECT =  trove
DEPS =  trove.h
OBJ     =  trove.o globals.o build.o words.o findword.o fileprocessing.o update.o remove.o


$(PROJECT) : $(OBJ)
	$(C11)	$(CFLAGS)	-o	$(PROJECT)	$(OBJ)	-lm

trove.o : trove.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	trove.c

globals.o : globals.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	globals.c

build.o : build.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	build.c

fileprocessing.o : fileprocessing.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	fileprocessing.c

findword.o : findword.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	findword.c

words.o : words.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	words.c


update.o : update.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	update.c

remove.o : remove.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	remove.c