#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

void criar(ARVORE_BINARIA *arv){
	arv->raiz = NULL;
}

NO *criar_raiz(ARVORE_BINARIA *arv, INFO *info){
	arv->raiz = (NO *)malloc(sizeof(NO));	

	if (arv->raiz == NULL){
		return arv->raiz;
	}

	arv->raiz->fesq = NULL;
	arv->raiz->fdir = NULL;
	arv->raiz->info = *info;
	return arv->raiz;
}

NO *inserir_direita(NO *no, INFO *info){
	if (no != NULL){
		no->fdir = (NO *)malloc(sizeof(NO));

		if (no->fdir == NULL){
			return NULL;
		}

		no->fdir->fesq = NULL;
		no->fdir->fdir = NULL;
		no->fdir->info = *info;
		return no->fdir;
	}
	return NULL;
}

NO *inserir_esquerda(NO *no, INFO *info){
	if (no != NULL){
		no->fesq = (NO *)malloc(sizeof(NO));

		if (no->fesq == NULL){
			return NULL;
		}

		no->fesq->fdir = NULL;
		no->fesq->fesq = NULL;
		no->fesq->info = *info;
		return no->fesq;
	}
	return NULL;
}

void preordem_aux(NO *raiz){
	if (raiz != NULL){
		printf("%c", raiz->info.valor);
		preordem_aux(raiz->fesq);
		preordem_aux(raiz->fdir);
	}
}

void preordem(ARVORE_BINARIA *arv){
	preordem_aux(arv->raiz);
}

void emordem_aux(NO *raiz){
	if (raiz != NULL){
		emordem_aux(raiz->fesq);
		printf("%c", raiz->info.valor);
		emordem_aux(raiz->fdir);
	}
}

void emordem(ARVORE_BINARIA *arv){
	emordem_aux(arv->raiz);
}

void posordem_aux(NO *raiz){
	if (raiz != NULL){
		posordem_aux(raiz->fesq);
		posordem_aux(raiz->fdir);
		printf("%c", raiz->info.valor);
	}
}

void posordem(ARVORE_BINARIA *arv){
	posordem_aux(arv->raiz);
}

void limpar_aux(NO *raiz){
	if (raiz != NULL){
		limpar_aux(raiz->fesq);
		limpar_aux(raiz->fdir);
		free(raiz);
	}
}

void limpar(ARVORE_BINARIA *arv){
	limpar_aux(arv->raiz);
	arv->raiz = NULL;
}