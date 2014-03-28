# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaLigadaCircular.o
	$(CC) $(CFLAGS) -o teste main.o ListaLigadaCircular.o

main.o: main.c ListaLigadaCircular.h
	$(CC) $(CFLAGS) -c main.c

ListaLigadaCircular.o: ListaLigadaCircular.c ListaLigadaCircular.h
	$(CC) $(CFLAGS) -c ListaLigadaCircular.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
