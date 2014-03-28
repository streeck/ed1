/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 6 - Fila Estática

	Charles David de Moraes		24/04/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#define TAM 50

// Frase exibida quando houver erro nas operacoes
#define FRASE_FILA_CHEIA "Erro: Fila cheia!\n"

// TAD que representa a lista estática
typedef struct {
	int tam;
	int ini;
	int fim;
	int elem[TAM];
} Fila;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */

/* Inicializa tam, ini e fim da fila. */
int inicFila(Fila *f);

/* Retorna (1) caso a fila esteja vazia e (0) caso contrário. */
int filaVazia(Fila f);

/* Retorna (1) caso a fila esteja cheia, (0) caso contrário. */
int filaCheia(Fila f);

/* Insere um elemento na fila. Retorna (1) se o elemento foi
 * inserido com sucesso e (0) caso fila cheia. */
int push(Fila *f, int elem);

/* Remove um elemento da fila. Retorna o próprio
 * elemento se foi removido com sucesso e 0 caso fila vazia. */
int pop(Fila *f);

/* Retorna o elemento que está no começo da fila, sem removê-lo!
 * Retorna (0) caso fila vazia. */
int front(Fila f);

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main() {
	int elemento;
	Fila f;
	inicFila(&f);
	
	while (1) {
		scanf("%d", &elemento);
		if (elemento == 0) break;
		
		if (!push(&f, elemento)) {
			printf(FRASE_FILA_CHEIA);
			break;
		}
	}

	while (f.tam > 1) {
		printf("%d ", pop(&f));
		elemento = pop(&f);
		push(&f, elemento);
	}

	printf("\n%d\n", front(f));

	return 0;
}

/* ================================================================== */
/* ========== FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS ========= */
/* ================================================================== */

/* Inicializa tam, ini e fim da fila. */
int inicFila(Fila *f) {
	f->ini = 0;
	f->tam = 0;
	f->fim = 0;
}

/* Retorna (1) caso a fila esteja vazia e (0) caso contrário. */
int filaVazia(Fila f) {
	if (f.tam == 0){
		return 1;
	}
	return 0;
}

/* Retorna (1) caso a fila esteja cheia, (0) caso contrário. */
int filaCheia(Fila f) {
	if (f.tam == TAM){
		return 1;
	}
	return 0;
}

/* Insere um elemento no final da fila. Retorna (1) se o elemento foi
 * inserido com sucesso e (0) caso fila cheia. */
int push(Fila *f, int elem) {
	if (filaCheia(*f)){
		return 0;
	}
	f->elem[f->fim] = elem;
	f->tam++;
	f->fim = (f->fim + 1) % TAM;
	return 1;
}

/* Remove o elemento que está no começo da fila. Retorna o próprio
 * elemento se foi removido com sucesso e 0 caso fila vazia. */
int pop(Fila *f) {
	if (filaVazia(*f)){
		return 0;
	}
	int aux;
	aux = f->elem[f->ini];
	f->tam--;
	f->ini = (f->ini + 1) % TAM;
	return aux;
}

/* Retorna o elemento que está no começo da fila, sem removê-lo!
 * Retorna (0) caso fila vazia. */
int front(Fila f) {
	if (filaVazia(f)){
		return 0;
	}
	return (f.elem[f.ini]);
}