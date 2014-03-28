#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinariaBusca.h"



// ---> ROTINAS BASICAS DE CRIACAO E INSERCAO

// inicializa a estrutura de dados da árvore
void criar (ARVORE_BINARIA *arv) {
	arv->raiz = NULL;
}


// cria o nó raiz e inicializa o primeiro nó da árvore
int criar_raiz (ARVORE_BINARIA *arv, INFO *info){
	arv->raiz = (NO*)malloc(sizeof(NO));

	if (arv->raiz != NULL) {
		arv->raiz->fesq = NULL;
		arv->raiz->fdir = NULL;
		arv->raiz->info = *info;
		return 1;
	}

	return 0;
}


// Insere um novo nó a direita do nó informado
NO *inserir_direita(NO *no, INFO *info) {
	if (no != NULL) {
		no->fdir = (NO*)malloc(sizeof(NO));
		no->fdir->fesq = NULL;
		no->fdir->fdir = NULL;
		no->fdir->info = *info;
		return no->fdir;
	}
	return NULL;
}


// Insere um novo nó a esquerda do nó informado
NO *inserir_esquerda (NO *no, INFO *info) {
	if (no != NULL) {
		no->fesq = (NO*)malloc(sizeof(NO));
		no->fesq->fesq = NULL;
		no->fesq->fdir = NULL;
		no->fesq->info = *info;
		return no->fesq;
	}
	return NULL;
}

/* ----------------------------------------------- */
/* REALIZA INSERÇÃO EM UMA ÁRVORE BINÁRIA DE BUSCA */
/* ----------------------------------------------- */
int inserir_aux(NO *no, INFO *info) {
	if (no->info.chave > info->chave){
		if (no->fesq == NULL){
			return (inserir_esquerda(no, info) != NULL);
		} else {
			return inserir_aux(no->fesq, info);
		}
	} else {
		if (no->fdir == NULL){
			return (inserir_direita(no, info) != NULL);
		} else {
			return inserir_aux(no->fdir, info);
		}
	}
}


// REALIZA INSERÇÃO A PARTIR DA RAIZ
int inserir(ARVORE_BINARIA *arv, INFO *info) {
	if (arv->raiz == NULL){
		return criar_raiz(arv, info);
	} else{
		return inserir_aux(arv->raiz, info);
	}
}
/* --------------------------------------------- */


/* ----------------------------------------------- */
/* REALIZA PESQUISA EM UMA ÁRVORE BINÁRIA DE BUSCA */
/* ----------------------------------------------- */
int buscar_aux(NO *no, INFO *info) {
	if (no == NULL){
		return 0;
	} else{
		if (no->info.chave > info->chave){
			return buscar_aux(no->fesq, info);
		} else{
			if (no->info.chave < info->chave){
				return buscar_aux(no->fdir, info);
			} else{
				info->valor = no->info.valor;
				return 1;
			}
		} 
	}
}


// REALIZA PESQUISA A PARTIR DA RAIZ
int buscar(ARVORE_BINARIA *arv, INFO *info) {
	return buscar_aux(arv->raiz, info);
}
/* --------------------------------------------- */


/* ---------------------------------------------- */
/* REALIZA REMOÇÃO EM UMA ÁRVORE BINÁRIA DE BUSCA */
/* ---------------------------------------------- */
int remover_aux(ARVORE_BINARIA *arv, NO *pant, NO *prem, int chave) {
	if (prem == NULL){
		return 0;
	} else {
		if (prem->info.chave > chave){
			return remover_aux(arv, prem, prem->fesq, chave);
		} else {
			if (prem->info.chave < chave){
				return remover_aux(arv, prem, prem->fdir, chave);
			} else {
				//caso em que existe apenas 1 filho.
				if (prem->fdir == NULL || prem->fesq == NULL){
					NO *pprox = (prem->fdir == NULL) ? prem->fesq : prem->fdir;
					if (pant == NULL){
						arv->raiz = pprox;
					} else {
						if (pant->fdir == prem){
							pant->fdir = pprox;
						} else {
							pant->fesq = pprox;
						}
						free (prem);
					}
				} else { //caso em que nó tem dois filhos;
					trocar_max_esq(prem, prem, prem->fesq);
				}
			}
		}
		return 1;
	}
}

// TROCA COM O MAXIMO DA SUB-ARVORE A ESQUERDA
void trocar_max_esq(NO *prem, NO *pant, NO *pno) {
	if (pno->fdir != NULL){
		trocar_max_esq(prem, pno, pno->fdir);
	} else {
		//raiz da sub-arvore a esquerda tem filhos a direita.
		if (pant != prem){
			pant->fdir = pno->fesq;
		} else {
			pant->fesq = pno->fesq;
		}
		prem->info = pno->info;
		free(pno);
	}
}


// REALIZA BUSCA PELA CHAVE A SER REMOVIDA A PARTIR DA RAIZ
int remover(ARVORE_BINARIA *arv, int chave) {
	if (arv->raiz != NULL){
		return remover_aux(arv, NULL, arv->raiz, chave);
	}
	return 0;
}
/* --------------------------------------------- */


// ---> ROTINA DE PERCURSO EM-ORDEM
void emordem_aux (NO *raiz) {
	if (raiz != NULL) {
		emordem_aux(raiz->fesq);
		printf("%d-%c\n", raiz->info.chave, raiz->info.valor);
		emordem_aux(raiz->fdir);
	}
}

void emordem (ARVORE_BINARIA *arv) {
	emordem_aux(arv->raiz);
}



// ---> ROTINAS AUXILIARES
void limpar_aux (NO *raiz) {
	if (raiz != NULL) {
		limpar_aux(raiz->fesq);
		limpar_aux(raiz->fdir);
		free(raiz);
	}
}

void limpar (ARVORE_BINARIA *arv) {
	limpar_aux(arv->raiz);
	arv->raiz = NULL;
}



int altura_aux (NO *raiz) {
	if (raiz == NULL) {
		return -1;
	} else {
		int altesq = altura_aux(raiz->fesq);
		int altdir = altura_aux(raiz->fdir);
		return ((altesq > altdir) ? altesq : altdir) + 1;
	}
}

int altura (ARVORE_BINARIA *arv) {
	return altura_aux(arv->raiz);
}

