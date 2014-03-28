#ifndef ARVORE_BINARIA_BUSCA_H_INCLUDED
#define ARVORE_BINARIA_BUSCA_H_INCLUDED


// Estrutura para armazenar os dados (informações)
typedef struct {
	int chave;
	char valor;
} INFO;

// Estrutura de um nó
typedef struct NO {
	INFO info;
	struct NO *fesq;
	struct NO *fdir;
} NO;

// Raiz da árvore - nó de referência para as operações
typedef struct {
	NO *raiz;
} ARVORE_BINARIA;


// ---> ROTINAS BASICAS DE CRIACAO E INSERCAO

// inicializa a estrutura de dados da árvore
void criar(ARVORE_BINARIA *arv);

// cria o nó raiz e inicializa o primeiro nó da árvore
int criar_raiz(ARVORE_BINARIA *arv, INFO *info);

// Insere um novo nó a direita do nó informado
NO *inserir_direita(NO *no, INFO *info);

// Insere um novo nó a esquerda do nó informado
NO *inserir_esquerda(NO *no, INFO *info);

/* ---------------------------------- */
/* ROTINAS DA ÁRVORE BINARIA DE BUSCA */
/* ---------------------------------- */

// Funções de inserção
int inserir_aux(NO *no, INFO *info);
int inserir(ARVORE_BINARIA *arv, INFO *info);

// Funções de busca
int buscar_aux(NO *no, INFO *info);
int buscar(ARVORE_BINARIA *arv, INFO *info);

// Funções de remoção
int remover_aux(ARVORE_BINARIA *arv, NO *pant, NO *prem, int chave);
void trocar_max_esq(NO *prem, NO *pant, NO *pno);
int remover(ARVORE_BINARIA *arv, int chave);

/* ---------------------------------- */


// ---> ROTINAS DE PERCURSO (VARREDURA)
void emordem_aux(NO *raiz);
void emordem(ARVORE_BINARIA *arv);


// ---> ROTINAS AUXILIARES
void limpar_aux(NO *raiz);
void limpar(ARVORE_BINARIA *arv);

int altura_aux(NO *raiz);
int altura(ARVORE_BINARIA *arv);

#endif // ARVORE_BINARIA_BUSCA_H_INCLUDED