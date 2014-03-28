# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaEstatica.o
	$(CC) $(CFLAGS) -o teste main.o ListaEstatica.o

main.o: main.c ListaEstatica.h
	$(CC) $(CFLAGS) -c main.c

ListaEstatica.o: ListaEstatica.c ListaEstatica.h
	$(CC) $(CFLAGS) -c ListaEstatica.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
