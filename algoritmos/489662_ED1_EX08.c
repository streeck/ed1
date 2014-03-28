/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 8 - Arvore Binaria

	Charles David de Moraes		09/06/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

// Operacoes que podem ser realizadas.
#define MODO_INSERCAO		1
	#define INSERIR_ESQUERDA	1
	#define INSERIR_DIREITA		2
	#define ANDAR_ESQUERDA 		3
	#define ANDAR_DIREITA 		4
	#define VOLTAR_RAIZ 		5


#define PERCURSO			2
	#define PREORDEM			1
	#define EMORDEM				2
	#define POSORDEM			3

#define REPR_ANINHADA		3
#define REPR_INDENTADA		4
#define INFO				5
#define SAIR				6

// Frase exibida quando houver erro nas operacoes
#define FRASE_ERROALOCACAO	"Erro de alocacao!\n"

/* ================================================================== */
/* ========================= TAD POLINOMIO ========================== */
/* ================================================================== */

// Definicao do elemento da árvore
typedef int elem_t;

// Definicao do nó
typedef struct no {
	elem_t info;
	struct no *esq, *dir;
} No;

// Definicao da Arvore
typedef No *Arvore;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */

/* Cria a raiz da arvore. Retorna TRUE em caso de sucesso e
 * FALSE em caso de erro de alocação */
int criaRaiz(Arvore *raiz, elem_t info);

/* Insere um novo nó à esquerda do nó enviado como argumento.
 * Retorna TRUE, em caso de sucesso.
 * Retorna FALSE:
 * 1- caso o nó enviado como argumento seja nulo;
 * 2- caso o nó enviado como argumento já possua filho à esquerda;
 * 3- caso a operação resulte em erro de alocação. */
int insereEsq(No *p, elem_t info);

/* Insere um novo nó à direita do nó enviado como argumento.
 * Retorna TRUE, em caso de sucesso.
 * Retorna FALSE:
 * 1- caso o nó enviado como argumento seja nulo;
 * 2- caso o nó enviado como argumento já possua filho à direita;
 * 3- caso a operação resulte em erro de alocação. */
int insereDir(No *p, elem_t info);

/* Percurso pré-ordem */
void preorder(Arvore t);

/* Percurso em ordem */
void inorder(Arvore t);

/* Percurso pós-ordem */
void postorder(Arvore t);

/* Libera todos os nós da arvore */
void libera(Arvore* t);

/* Retorna a altura da arvore */
int altura(Arvore t);

/* Retorna a quantidade de nós da arvore */
int numeroNos(Arvore t);

/* Retorna a soma de todos os elementos da árvore */
int soma(Arvore t);

/* Retorna o valor do maior elemento da árvore. */
int maiorElemento(Arvore t);

/* Retorna o valor do menor elemento da árvore. */
int menorElemento(Arvore t);

/* Imprime a representação aninhada da árvore */
void representacaoAninhada(Arvore t);

/* Imprime a representação indentada da árvore */
void representacaoIndentada(Arvore t, int nivel);


/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main() {
	int opcao, opcao2, info, nivel;
	Arvore t, p_insert;
	
	scanf("%d", &info);
	if (!criaRaiz(&t, info)) {
		printf(FRASE_ERROALOCACAO);
		exit(0);
	}

	//Enquanto opcao for diferente de SAIR.
	do {

		//Pergunta a opcao que o usuario deseja realizar.
		scanf("%d", &opcao);

		//Verifica qual opcao foi escolhida.
		switch (opcao) {

			// OPCAO 1
			case MODO_INSERCAO:
			p_insert = t;
			do {
				scanf("%d", &opcao2);
				switch (opcao2) {

					// OPCAO 1
					case INSERIR_ESQUERDA:
					scanf("%d", &info);
					if (!insereEsq(p_insert, info)) {
						printf(FRASE_ERROALOCACAO);
						exit(0);
					}
					break;
					
					// OPCAO 2
					case INSERIR_DIREITA:
					scanf("%d", &info);
					if (!insereDir(p_insert, info)) {
						printf(FRASE_ERROALOCACAO);
						exit(0);
					}
					break;
					
					// OPCAO 3
					case ANDAR_ESQUERDA:
					if (p_insert->esq != NULL) p_insert = p_insert->esq;
					break;
					
					// OPCAO 4
					case ANDAR_DIREITA:
					if (p_insert->dir != NULL) p_insert = p_insert->dir;
					break;
					
					// OPCAO 5
					case VOLTAR_RAIZ:
					p_insert = t;
					break;
				}
			} while (opcao2 != SAIR);

			break;


			// OPCAO 2
			case PERCURSO:
			scanf("%d", &opcao2);
			switch (opcao2) {
				// OPCAO 2.1
				case PREORDEM:
				preorder(t);
				printf("\n");
				break;
				
				// OPCAO 2.2
				case EMORDEM:
				inorder(t);
				printf("\n");
				break;
				
				// OPCAO 2.3
				case POSORDEM:
				postorder(t);
				printf("\n");
				break;
			}
			break;
		
			// OPCAO 3
			case REPR_ANINHADA:
			representacaoAninhada(t);
			printf("\n");
			break;

			// OPCAO 4
			case REPR_INDENTADA:
			nivel = 0;
			representacaoIndentada(t, nivel);
			break;

			// OPCAO 5
			case INFO:
			printf("%d, %d\n", altura(t), numeroNos(t));
			printf("%d, %d, %d\n", soma(t), maiorElemento(t), menorElemento(t));
			break;

			// OPCAO 6
			case SAIR:
			libera(&t);
			break;
		}

	} while (opcao != SAIR);
	
	return 0;
}

/* ================================================================== */
/* ========== FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS ========= */
/* ================================================================== */

/* Cria a raiz da arvore. Retorna TRUE em caso de sucesso e
 * FALSE em caso de erro de alocação */
int criaRaiz(Arvore *raiz, elem_t info) {
	*raiz = (No *)malloc(sizeof(No));

	if (*raiz == NULL){
		return FALSE;
	}

	(*raiz)->esq = NULL;
	(*raiz)->dir = NULL;
	(*raiz)->info = info;
	return TRUE;
}


/* Insere um novo nó à esquerda do nó enviado como argumento.
 * Retorna TRUE, em caso de sucesso.
 * Retorna FALSE:
 * 1- caso o nó enviado como argumento seja nulo;
 * 2- caso o nó enviado como argumento já possua filho à esquerda;
 * 3- caso a operação resulte em erro de alocação. */
int insereEsq(No *p, elem_t info) {
	if (p == NULL || p->esq != NULL){
		return FALSE;
	}
	p->esq = (No *)malloc(sizeof(No));
	
	if (p->esq == NULL){
		return FALSE;
	}

	p->esq->esq = NULL;
	p->esq->dir = NULL;
	p->esq->info = info;
	return TRUE;
}


/* Insere um novo nó à direita do nó enviado como argumento.
 * Retorna TRUE, em caso de sucesso.
 * Retorna FALSE:
 * 1- caso o nó enviado como argumento seja nulo;
 * 2- caso o nó enviado como argumento já possua filho à direita;
 * 3- caso a operação resulte em erro de alocação. */
int insereDir(No *p, elem_t info) {
	if (p == NULL || p->dir != NULL){
		return FALSE;
	}
	p->dir = (No *)malloc(sizeof(No));
	
	if (p->dir == NULL){
		return FALSE;
	}

	p->dir->esq = NULL;
	p->dir->dir = NULL;
	p->dir->info = info;
	return TRUE;
}


/* Percurso pré-ordem */
void preorder(Arvore t) {
	if (t != NULL){
		printf("%d ", t->info);
		preorder(t->esq);
		preorder(t->dir);
	}
}


/* Percurso em ordem */
void inorder(Arvore t) {
	if (t != NULL){
		inorder(t->esq);
		printf("%d ", t->info);
		inorder(t->dir);
	}
}


/* Percurso pós-ordem */
void postorder(Arvore t) {
	if (t != NULL){
		postorder(t->esq);
		postorder(t->dir);
		printf("%d ", t->info);
	}
}


/* Libera todos os nós da arvore */
void libera(Arvore* t) {
	if (*t != NULL){
		libera(&(*t)->esq);
		libera(&(*t)->dir);
		free(*t);
	}
	*t = NULL;
}


/* Retorna a altura da arvore */
int altura(Arvore t) {
	if (t == NULL){
		return 0;
	} else{
		int esquerda = altura(t->esq);
		int direita = altura(t->dir);
		return ((esquerda > direita) ? esquerda : direita) + 1;
	}
}


/* Retorna a quantidade de nós da arvore */
int numeroNos(Arvore t) {
	if (t == NULL){
		return 0;
	} else{
		int esquerda = numeroNos(t->esq);
		int direita = numeroNos(t->dir);
		return (esquerda + direita) + 1;
	}
}


/* Retorna a soma de todos os elementos da árvore */
int soma(Arvore t) {
	if (t == NULL){
		return 0;
	} else{
		int esquerda = soma(t->esq);
		int direita = soma(t->dir);
		return (esquerda + direita) + t->info;
	}
}


/* Retorna o valor do maior elemento da árvore. */
int maiorElemento(Arvore t) {
	int maior = t->info;
	if (t->esq != NULL){
		int esquerda = maiorElemento(t->esq);
		if (esquerda > maior){
			maior = esquerda;
		}
	}
	if (t->dir != NULL){
		int direita = maiorElemento(t->dir);
		if (direita > maior){
			maior = direita;
		}
	}
	return maior;
}


/* Retorna o valor do menor elemento da árvore. */
int menorElemento(Arvore t) {
	int menor = t->info;
	if (t->esq != NULL){
		int esquerda = menorElemento(t->esq);
		if (esquerda < menor){
			menor = esquerda;
		}
	}
	if (t->dir != NULL){
		int direita = menorElemento(t->dir);
		if (direita < menor){
			menor = direita;
		}
	}
	return menor;
}


/* Imprime a representação aninhada da árvore */
void representacaoAninhada(Arvore t) {
	if (t != NULL){
		printf("{%d", t->info);
		if (t->esq != NULL){
			printf(",");
		}
		representacaoAninhada(t->esq);
		if (t->dir != NULL){
			printf(",");
		}
		representacaoAninhada(t->dir);
		if (t != NULL){
			printf("}");
		}
	}
}


/* Imprime a representação indentada da árvore */
void representacaoIndentada(Arvore t, int nivel) {
	if (t != NULL){
		if (nivel != 0){
			int i;
			for (i = 0; i < nivel; i++){
				printf("\t");
			}
		}
		printf("%d\n", t->info);
		representacaoIndentada(t->esq, nivel + 1);
		if (t == NULL){
			nivel--;
		}
		representacaoIndentada(t->dir, nivel + 1);
		if (t == NULL){
			nivel--;
		}
	}
}