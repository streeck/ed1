#ifndef PILHA_DINAMICA_H_INCLUDED
#define PILHA_DINAMICA_H_INCLUDED

typedef struct {
	int valor;
} ITEM;

typedef struct NO {
	ITEM item;
	struct NO *anterior;
} NO;

typedef struct {
	int tam;
	NO *topo;
} PILHA_DINAMICA;

void criar (PILHA_DINAMICA *pilha);

int vazia (PILHA_DINAMICA *pilha);

int contar (PILHA_DINAMICA *pilha);

int empilhar (PILHA_DINAMICA *pilha, ITEM *item);

int desempilhar (PILHA_DINAMICA *pilha, ITEM *item);

int frente (PILHA_DINAMICA *pilha, ITEM *item);

void imprime (PILHA_DINAMICA *pilha);

void apagar (PILHA_DINAMICA *pilha);

#endif // PILHA_DINAMICA_H_INCLUDED