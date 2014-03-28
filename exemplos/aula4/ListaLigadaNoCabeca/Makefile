# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaLigadaNoCabeca.o
	$(CC) $(CFLAGS) -o teste main.o ListaLigadaNoCabeca.o

main.o: main.c ListaLigadaNoCabeca.h
	$(CC) $(CFLAGS) -c main.c

ListaLigadaNoCabeca.o: ListaLigadaNoCabeca.c ListaLigadaNoCabeca.h
	$(CC) $(CFLAGS) -c ListaLigadaNoCabeca.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
