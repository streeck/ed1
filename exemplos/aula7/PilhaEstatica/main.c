#include <stdio.h>
#include <stdlib.h>

#include "PilhaEstatica.h"

int main(){
	int i;

	PILHA_ESTATICA pilha;

	for (i = 0; i < 5; i++){
		ITEM item;
		item.valor = i;
		
		if (empilhar(&pilha, &item)){
			printf("Entrou na pilha: %d - T: %d\n", item.valor, topo(&pilha));
		}
		else {
			printf("%d: Pilha cheia.\n", item.valor);
		}
	}
	printf("\nPilha atual: ");
	imprime(&pilha);
	printf("\n");

	printf("Tamanho: %d\n--\n", contar(&pilha));

	ITEM item1;
	item1.valor = 100;

	if (empilhar(&pilha, &item1)){
		printf("Entrou na pilha: %d - T: %d\n", item1.valor, topo(&pilha));
	}
	else {
		printf("%d: Pilha cheia.\n", item1.valor);
	}

	printf("\nPilha atual: ");
	imprime(&pilha);
	printf("\n");

	printf("Tamanho: %d\n--\n", contar(&pilha));

	frente(&pilha, &item1);

	printf("Elemento do topo: %d\n--\n, item1.valor");

	if (desempilhar(&pilha, &item1)){
		printf("Saiu da pilha: %d - T: %d\n", item1.valor, topo(&pilha));
	}
	else {
		printf("Pilha vazia.\n", item1.valor);
	}

	item1.valor = 9;
	if (empilhar(&pilha, &item1)){
		printf("Entrou na pilha: %d - T: %d\n", item1.valor, topo(&pilha));
	}
	else {
		printf("%d: Pilha cheia.\n", item1.valor);
	}

	printf("\nPilha atual: ");
	imprime(&pilha);
	printf("\n");

	printf("Tamanho: %d\n--\n", contar(&pilha));

	return 0;
}