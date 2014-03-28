# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o PilhaEstatica.o
	$(CC) $(CFLAGS) -o teste main.o PilhaEstatica.o

main.o: main.c PilhaEstatica.h
	$(CC) $(CFLAGS) -c main.c

PilhaEstatica.o: PilhaEstatica.c PilhaEstatica.h
	$(CC) $(CFLAGS) -c PilhaEstatica.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
