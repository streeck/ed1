# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ArvoreBinaria.o
	$(CC) $(CFLAGS) -o teste main.o ArvoreBinaria.o

main.o: main.c ArvoreBinaria.h
	$(CC) $(CFLAGS) -c main.c

ArvoreBinaria.o: ArvoreBinaria.c ArvoreBinaria.h
	$(CC) $(CFLAGS) -c ArvoreBinaria.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
