# Parametros

CC = gcc
CFLAGS = -Wall

# Comandos

all: teste clean

teste: main.o Complexo.o
		$(CC) $(CFLAGS) -o teste main.o Complexo.o

main.o: main.c Complexo.h
		$(CC) $(CFLAGS) -c main.c

Complexo.o: Complexo.c Complexo.h
		$(CC) $(CFLAGS) -c Complexo.c

clean: 
		rm -f *.o

uninstall:
		rm -f teste