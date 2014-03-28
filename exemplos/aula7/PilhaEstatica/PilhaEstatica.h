#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED

#define TAM 5

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int valor;
} ITEM;

typedef struct {
	ITEM itens[TAM];
	int topo;
} PILHA_ESTATICA;

void criar (PILHA_ESTATICA *pilha);

int vazia (PILHA_ESTATICA *pilha);

int cheia (PILHA_ESTATICA *pilha);

int contar (PILHA_ESTATICA *pilha);

int empilhar (PILHA_ESTATICA *pilha, ITEM *item);

int desempilhar (PILHA_ESTATICA *pilha, ITEM *item);

int frente (PILHA_ESTATICA *pilha, ITEM *item);

void imprime (PILHA_ESTATICA *pilha);

#endif // PILHA_ESTATICA_H_INCLUDED