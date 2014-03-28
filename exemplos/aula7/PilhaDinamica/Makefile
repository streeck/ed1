# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o PilhaDinamica.o
	$(CC) $(CFLAGS) -o teste main.o PilhaDinamica.o

main.o: main.c PilhaDinamica.h
	$(CC) $(CFLAGS) -c main.c

PilhaDinamica.o: PilhaDinamica.c PilhaDinamica.h
	$(CC) $(CFLAGS) -c PilhaDinamica.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
