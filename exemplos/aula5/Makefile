# Makefile for executable

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -Wall

# ****************************************************
# Entries to bring the executable up to date

all: teste clean

teste: main.o ListaDuplamenteLigada.o
	$(CC) $(CFLAGS) -o teste main.o ListaDuplamenteLigada.o

main.o: main.c ListaDuplamenteLigada.h
	$(CC) $(CFLAGS) -c main.c

ListaDuplamenteLigada.o: ListaDuplamenteLigada.c ListaDuplamenteLigada.h
	$(CC) $(CFLAGS) -c ListaDuplamenteLigada.c

clean:
	rm -f *.o

uninstall:
	rm -f teste
