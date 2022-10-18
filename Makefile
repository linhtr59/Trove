# A Makefile to build our 'trove' project

C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror


PROJECT =  trove
DEPS =  trove.h
OBJ     =  trove.o build.o hash.o globals.o list.o findword.o fileprocessing.o update.o remove.o


$(PROJECT) : $(OBJ)
	$(C11)	$(CFLAGS)	-o	$(PROJECT)	$(OBJ)	-lm

trove.o : trove.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	trove.c

globals.o : globals.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	globals.c

fileprocessing.o : fileprocessing.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	fileprocessing.c

hash.o : hash.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	hash.c

list.o : list.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	list.c

build.o : build.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	build.c


findword.o : findword.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	findword.c

update.o : update.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	update.c

remove.o : remove.c $(DEPS)
	$(C11)	$(CFLAGS)	-c	remove.c