# Parametros

CC = gcc
CFLAGS = -Wall

# Comandos

all: teste clean

teste: main.o Racional.o
		$(CC) $(CFLAGS) -o teste main.o Racional.o

main.o: main.c Racional.h
		$(CC) $(CFLAGS) -c main.c

Racional.o: Racional.c Racional.h
		$(CC) $(CFLAGS) -c Racional.c

clean: 
		rm -f *.o

uninstall:
		rm -f teste