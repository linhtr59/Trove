# a makefile to construct the trove project
PROJECT = trove
HEADER = $(PROJECT).h
OBJ = trove.o globals.o 

C11 = cc -std=c11
CFLAGS = -Wall -Werror

$(PROJECT) : $(OBJ)
        $(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

%.o : %.c $(HEADERS)
        $(C11) $(CFLAGS) -c $<

clean:
        rm -f $(PROJECT) $(OBJ)


# ##CC=gcc
# CFLAGS=-I.
# DEPS = hellomake.h

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# hellomake: hellomake.o hellofunc.o 
# 	$(CC) -o hellomake hellomake.o hellofunc.o 