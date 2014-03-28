# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaEstaticaOrdenada.o
	$(CC) $(CFLAGS) -o teste main.o ListaEstaticaOrdenada.o

main.o: main.c ListaEstaticaOrdenada.h
	$(CC) $(CFLAGS) -c main.c

ListaEstatica.o: ListaEstaticaOrdenada.c ListaEstaticaOrdenada.h
	$(CC) $(CFLAGS) -c ListaEstaticaOrdenada.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
