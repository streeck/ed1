#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"

int main(){
	ARVORE_BINARIA arv1;

	criar(&arv1);

	NO *node;
	INFO item;

	item.chave = 1; 
	item.valor = '+';
	node = criar_raiz(&arv1, &item);

	item.chave = 2;
	item.valor = 'A';
	inserir_esquerda(node, &item);

	item.chave = 3;
	item.valor = '*';
	node = inserir_direita(node, &item);

	item.chave = 4;
	item.valor = 'B';
	inserir_esquerda(node, &item);

	item.chave = 5;
	item.valor = 'C';
	node = inserir_direita(node, &item);

	emordem(&arv1);
	printf("\n");

	preordem(&arv1);
	printf("\n");

	posordem(&arv1);
	printf("\n");

	return 0;
}