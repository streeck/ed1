#include <stdio.h>
#include <stdlib.h>

#include "PilhaEstatica.h"

void criar (PILHA_ESTATICA *pilha){
	pilha->topo = -1;
}

int vazia (PILHA_ESTATICA *pilha){
	return (pilha->topo == -1);
}

int cheia (PILHA_ESTATICA *pilha){
	return (pilha->topo == TAM -1);
}

int contar (PILHA_ESTATICA *pilha){
	return (pilha->topo + 1);
}

int empilhar (PILHA_ESTATICA *pilha, ITEM *item){
	if (cheia(pilha)){
		return 0;
	}
	pilha->topo++;
	pilha->item[pilha->topo] = *item;
	return 1;
}

int desempilhar (PILHA_ESTATICA *pilha, ITEM *item){
	if (vazia(pilha)){
		return 0;
	}
	*item = pilha->item[pilha->topo];
	pilha->topo--;
	return 1;
}

int frente (PILHA_ESTATICA *pilha, ITEM *item){
	if (vazia(pilha)){
		return 0;
	}
	*item = pilha->itens[pilha->topo];
	return 1;
}

void imprime (PILHA_ESTATICA *pilha){
	int i;
	for (i = pilha->topo; i >= 0; i--){
		printf("%d ", pilha->item[i].valor);
	}
	printf("\n");
}

int topo (PILHA_ESTATICA *pilha){
	if (vazia(pilha)){
		return 0;
	}
	return (pilha->topo);
}