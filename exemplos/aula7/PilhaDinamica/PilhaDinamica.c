#include <stdio.h>
#include <stdlib.h>

#include "PilhaDinamica.h"

void criar (PILHA_DINAMICA *pilha){
	pilha->topo = NULL;
	pilha->tam = 0;	
}

int vazia (PILHA_DINAMICA *pilha){
	return (pilha->topo == NULL);
}

int contar (PILHA_DINAMICA *pilha){
	return (pilha->tam);
}

int empilhar (PILHA_DINAMICA *pilha, ITEM *item){
	NO *pnovo = (NO *)malloc(sizeof(NO));

	if (pnovo == NULL){
		return 0;
	}

	pnovo->item = *item;
	pnovo->anterior = pilha->topo;
	pilha->topo = pnovo;
	pilha->tam++;
	return 1;
}

int desempilhar (PILHA_DINAMICA *pilha, ITEM *item){
	if (vazia(pilha)){
		return 0;
	}
	*item = pilha->topo->item;
	NO *prem = pilha->topo;
	pilha->topo = pilha->topo->anterior;
	pilha->tam--;
	free(prem)
	return 1;
}

int frente (PILHA_DINAMICA *pilha, ITEM *item){
	if (vazia(pilha)){
		return 0;
	}
	*item = pilha->topo;
	return 1;
}

void imprime (PILHA_DINAMICA *pilha){
	NO *paux = pilha->topo;

	while (paux != NULL){
		printf("%d ", paux->item.valor);
		paux = paux->anterior;
	}
}

void apagar (PILHA_DINAMICA *pilha){
	if (vazia(pilha)){

	}

	NO *paux = pilha->topo;

	while (paux != NULL){
		NO *prem = paux;
		paux = paux->anterior;
		free (prem);
	}
	pilha->topo = NULL;
	pilha->tam = 0;
}