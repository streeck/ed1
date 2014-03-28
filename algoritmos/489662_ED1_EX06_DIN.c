/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 6 - Fila Dinâmica

	Charles David de Moraes		24/04/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#include <stdlib.h>

// Frase exibida quando houver erro nas operacoes
#define FRASE_ERRO_ALOC "Erro de alocacao!\n"

// TAD que representa o nó da lista
typedef struct no{
	int elem;
	struct no *next;
} Node;

// TAD que representa o nó cabeça
typedef struct{
	int tam;
	Node *next;
} Cabeca;

typedef Cabeca * Fila;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */

/* Aloca a memória para o nó cabeça, com as devidas inicializações. */
int inicFila(Fila *f);

/* Retorna (1) caso a fila esteja vazia e (0) caso contrário. */
int filaVazia(Fila f);

/* Libera a memória de todos os nós, inclusive o nó cabeça. */
void libera(Fila *f);

/* Insere um elemento no final da fila. Retorna (1) se o elemento foi
 * inserido com sucesso e (0) caso erro de alocação. */
int push(Fila f, int elem);

/* Remove o elemento que está no começo da fila. Retorna o próprio
 * elemento se foi removido com sucesso e (0) caso fila vazia. */
int pop(Fila f);

/* Retorna o elemento que está no começo da fila, sem removê-lo!
 * Retorna (0) caso fila vazia. */
int front(Fila f);

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main(){
	int elemento;
	Fila f;
	
	if (!inicFila(&f)) {
		printf(FRASE_ERRO_ALOC);
		exit(1);
	}

	while (1) {
		scanf("%d", &elemento);
		if (elemento == 0) break;
		
		if(!push(f, elemento)){
			printf(FRASE_ERRO_ALOC);
			exit(1);
		}
	}

	while(f->tam > 1){
		printf("%d ", pop(f));
		elemento = pop(f);
		push(f, elemento);
	}

	printf("\n%d\n", front(f));
	libera(&f);

	return 0;
}

/* ================================================================== */
/* ========== FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS ========= */
/* ================================================================== */

/* Aloca a memória para o nó cabeça, com as devidas inicializações. */
int inicFila(Fila *f){
	*f = (Cabeca *)malloc(sizeof(Cabeca));
	if(f == NULL){
		return 0;
	}
	(*f)->tam = 0;
	(*f)->next = NULL;
	return 1;
}

/* Retorna (1) caso a fila esteja vazia e (0) caso contrário. */
int filaVazia(Fila f){
	if (f->next == NULL){
		return 1;
	}
	return 0;
}

/* Libera a memória de todos os nós, inclusive o nó cabeça. */
void libera(Fila *f){
	Node *aux = (*f)->next;
	while (aux != NULL){
		Node *del = aux;
		aux = aux->next;
		free(del);
	}
	free(*f);
}

/* Insere um elemento no final da fila. Retorna (1) se o elemento foi
 * inserido com sucesso e (0) caso erro de alocação. */
int push(Fila f, int elem){
	Node *novo = (Node *)malloc(sizeof(Node));
	if (novo == NULL){
		return 0;
	}
	novo->elem = elem;
	novo->next = NULL;
	if (f->tam == 0){
		f->next = novo;
	}
	else {
		Node *aux = f->next;
		while (aux->next != NULL){
			aux = aux->next;
		}
		aux->next = novo;
	}
	f->tam++;
	return 1;
}

/* Remove o elemento que está no começo da fila. Retorna o próprio
 * elemento se foi removido com sucesso e (0) caso fila vazia. */
int pop(Fila f){
	if (filaVazia(f)){
		return 0;
	}
	int elem;
	elem = f->next->elem;
	f->next = f->next->next;
	f->tam--;
	return elem;
}

/* Retorna o elemento que está no começo da fila, sem removê-lo!
 * Retorna (0) caso fila vazia. */
int front(Fila f){
	if (filaVazia(f)){
		return 0;
	}
	return (f->next->elem);
}