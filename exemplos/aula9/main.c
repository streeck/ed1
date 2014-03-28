/* --------------------------------------------------------------------------------- 

1. Monta a árvore binária de busca com 10 elementos gerados aleatoriamente

2. Realiza operações diversas e opções auxiliares

--------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinariaBusca.h"

int main() {
	ARVORE_BINARIA arv1;

	criar(&arv1);

	int i;

	for (i = 0; i < 10; i++){
		INFO item;
		item.chave = rand() % 26 + 65;
		item.valor = item.chave; // 'A' e 'Z'
		if (buscar(&arv1, &item)){
			printf("%d-%c esta na arvore.\n", item.chave, item.valor);
		} else {
			if (inserir(&arv1, &item)){
				printf("%d-%c inserido.\n", item.chave, item.valor);
			}
		}
	}

	printf("\nImpressao ordenada por chave: \n");
	emordem(&arv1);
	printf("\n");

	printf("Altura: %d\n\n", altura(&arv1));

	INFO item;
	item.chave = 81;

	if (remover(&arv1, item.chave)){
		printf("No (chave: %d) removido com sucesso.\n", item.chave);
	} else {
		printf("No nao encontrado para remocao.\n");
	}

	printf("\nImpressao ordenada por chave: \n");
	emordem(&arv1);
	printf("\n");

	printf("Altura: %d\n\n", altura(&arv1));

	limpar(&arv1);

	return 0;
}