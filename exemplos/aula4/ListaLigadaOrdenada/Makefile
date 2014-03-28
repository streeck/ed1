# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaLigadaOrdenada.o
	$(CC) $(CFLAGS) -o teste main.o ListaLigadaOrdenada.o

main.o: main.c ListaLigadaOrdenada.h
	$(CC) $(CFLAGS) -c main.c

ListaLigadaOrdenada.o: ListaLigadaOrdenada.c ListaLigadaOrdenada.h
	$(CC) $(CFLAGS) -c ListaLigadaOrdenada.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
