#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct {
	int chave;
	int valor;
} INFO;

typedef struct  NO {
	INFO info;
	struct NO *fesq;
	struct NO *fdir;
} NO;

typedef struct {
	NO *raiz;
} ARVORE_BINARIA;

void criar(ARVORE_BINARIA *arv);

NO *criar_raiz(ARVORE_BINARIA *arv, INFO *info);

NO *inserir_direita(NO *no, INFO *info);

NO *inserir_esquerda(NO *no, INFO *info);

void preordem_aux(NO *raiz);

void preordem(ARVORE_BINARIA *arv);

void emordem_aux(NO *raiz);

void emordem(ARVORE_BINARIA *arv);

void posordem_aux(NO *raiz);

void posordem(ARVORE_BINARIA *arv);

void limpar_aux(NO *raiz);

void limpar(ARVORE_BINARIA *arv);

#endif // ARVOREBINARIA_H_INCLUDED