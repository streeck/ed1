# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaLigada.o
	$(CC) $(CFLAGS) -o teste main.o ListaLigada.o

main.o: main.c ListaLigada.h
	$(CC) $(CFLAGS) -c main.c

ListaLigada.o: ListaLigada.c ListaLigada.h
	$(CC) $(CFLAGS) -c ListaLigada.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
