# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ArvoreBinariaBusca.o
	$(CC) $(CFLAGS) -o teste main.o ArvoreBinariaBusca.o

main.o: main.c ArvoreBinariaBusca.h
	$(CC) $(CFLAGS) -c main.c

ArvoreBinariaBusca.o: ArvoreBinariaBusca.c ArvoreBinariaBusca.h
	$(CC) $(CFLAGS) -c ArvoreBinariaBusca.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
