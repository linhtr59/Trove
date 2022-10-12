# a makefile to construct the trove project
PROJECT = trove
HEADER = $(PROJECT).h
OBJ = trove.o globals.o filenames.o findfiles.o indexing.o remove.o update.o words.o

C11 = cc -std=c11
CFLAGS = -Wall -Werror

$(PROJECT) : $(OBJ)
        $(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

%.o : %.c $(HEADERS)
        $(C11) $(CFLAGS) -c $<

clean:
        rm -f $(PROJECT) $(OBJ)