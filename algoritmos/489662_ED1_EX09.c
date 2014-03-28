/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 9 - Arvore Binaria de Busca

	Charles David de Moraes		18/06/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 	70
#define TRUE 	1
#define FALSE 	0

// Frase exibida quando houver erro nas operacoes
#define FRASE_ERROALOCACAO	"Erro de alocacao!\n"
#define FRASE_OPCAO_INVAL   "Opcao invalida!\n"

// Definicao do elemento da árvore
typedef struct {
	int ra;
	char nome[MAX];
} Aluno;

// Definicao do nó
typedef struct no {
	Aluno info;
	struct no *esq, *dir;
} No;

// Definicao da Arvore
typedef No *Arvore;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */

/* Inicializa uma arvore */
void inicArvore(Arvore *t);

/* Insere o aluno informado como parâmetro na árvore e retorna
 * TRUE. Caso já exista um aluno com o mesmo RA, não é feita a
 * inserção e retorna FALSE. Retorne -1 em caso de erro de
 * alocação.
 * IMPORTANTE: O aluno deve ser inserido em ordem crescente de ra.
 * Não se esqueça de alocar memória para o registro */
int insereAluno(Arvore *t, Aluno a);

/* Remove o aluno que possui o RA informado e retorna TRUE.
 * Retorna FALSE, caso o aluno não seja encontrado. */
int removeAluno(Arvore *t, int ra);

/* Caso exista um aluno com o RA informado, returne TRUE e atribua
 * em 'a' os dados do aluno. Caso contrário retorne FALSE. */
int consultaAluno(Arvore t, int ra, Aluno *a);

/* Imprime a arvore sob a forma de uma árvore 'deitada'. */
void imprimeArvore(Arvore t, int nivel);

/* Libera todos os nós da arvore apontada por 't', bem 
como todas as cadeias que guardam os nomes. */
void liberaArvore(Arvore *t);

/* Devolve o número de nós da arvore 't'. */
int numeroNosArvore(Arvore t);

/* Devolve a altura da arvore 't'. */
int alturaArvore(Arvore t); 

/* Executa um percurso inordem na arvore, imprimindo todos os elementos. */
void percorreArvore(Arvore t);


/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main() {
	int info, ra, nivel;
	Aluno aluno;
	Arvore t;
	char acao;

	inicArvore(&t);

	//Enquanto opcao for diferente de SAIR
	do { 

		//Pergunta a opcao que o usuario deseja realizar
		scanf("\n%c", &acao);

		//Verifica qual opcao foi escolhida.
		switch (acao) { 

			case 'i':
				scanf("%d %[^\n]",&aluno.ra, aluno.nome);

				info = insereAluno(&t, aluno);
				if (info == FALSE)
					printf("RA %d ja estava presente na arvore de dados.\n", aluno.ra);
				
				else if(info == -1){
					printf(FRASE_ERROALOCACAO);
					exit(0);
				}
				break;
			
			case 'r':
				scanf("%d",&ra);
				if (removeAluno(&t, ra))
					printf("Aluno removido com sucesso.\n");
				else
					printf("RA %d nao encontrado na arvore de dados.\n", ra);
				break;

			case 'c':
				scanf("%d",&ra);
				if (consultaAluno(t, ra, &aluno))
					printf("%d, %s\n", aluno.ra, aluno.nome);
				else
					printf("RA %d nao encontrado na arvore de dados.\n", ra);
				break;

			case 'd':
				nivel = 0;
			  	imprimeArvore(t, nivel);
				break;

			case 'n':
				printf("Numero de nos na arvore de dados: %d.\n", numeroNosArvore(t));
				break;

			case 'a':
				printf("Altura da arvore de dados: %d.\n", alturaArvore(t));
				break;

			case 'p':
				percorreArvore(t);
				break;

			case 'x':
				liberaArvore(&t);
				break;

			default:
				printf(FRASE_OPCAO_INVAL);
				break;
		}

	} while (acao != 'x');

	printf("Processamento finalizado\n");
	return 0;
}

/* ================================================================== */
/* ========== FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS ========= */
/* ================================================================== */


/* Inicializa uma arvore */
void inicArvore(Arvore *t) {
	*t = NULL;
}

/* Insere o aluno informado como parâmetro na árvore e retorna
 * TRUE. Caso já exista um aluno com o mesmo RA, não é feita a
 * inserção e retorna FALSE. Retorne -1 em caso de erro de
 * alocação.
 * IMPORTANTE: O aluno deve ser inserido em ordem crescente de ra.
 * Não se esqueça de alocar memória para o registro */
int insereAluno(Arvore *t, Aluno a) {
	if (*t == NULL){
		*t = (No *)malloc(sizeof(No));
		
		if (*t == NULL){
			return -1;
		}

		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->info.ra = a.ra;
		strcpy((*t)->info.nome, a.nome);
		return TRUE;
	} else {
		if ((*t)->info.ra > a.ra){
			return insereAluno(&(*t)->esq, a);
		} else {
			if ((*t)->info.ra < a.ra){
				return insereAluno(&(*t)->dir, a);
			}
		}
	}
	//Ocorre quando já existe ra.
	return FALSE;
}

/* Remove o aluno que possui o RA informado e retorna TRUE.
 * Retorna FALSE, caso o aluno não seja encontrado. */
int removeAluno(Arvore *t, int ra) {
	if (*t == NULL){
		//caso onde não é encontrado RA.
		return FALSE;
	} else {
		if ((*t)->info.ra > ra){
			return removeAluno(&(*t)->esq, ra);
		} else {
			if ((*t)->info.ra < ra){
				return removeAluno(&(*t)->dir, ra);
			} else {
				//caso onde o No possui 2 filhos.
				if ((*t)->esq != NULL && (*t)->dir != NULL){
					No *del = *t;
					No *aux = (*t)->dir;
					if (aux->esq == NULL){
						aux->esq = (*t)->esq;
						*t = aux;
					} else {
						while (aux->esq->esq != NULL){
							aux = aux->esq;
						}
						No *root = aux->esq;
						aux->esq = aux->esq->dir;
						root->esq = (*t)->esq;
						root->dir = (*t)->dir;
						*t = root;
					}
					free(del);
					del = NULL;
					return TRUE;
				} else {
					No *del = *t;
					*t = ((*t)->esq == NULL) ? (*t)->dir : (*t)->esq;
					free(del);
					del = NULL;
					return TRUE;
				}
			}
		}
	}
}

/* Caso exista um aluno com o RA informado, returne TRUE e atribua
 * em 'a' os dados do aluno. Caso contrário retorne FALSE. */
int consultaAluno(Arvore t, int ra, Aluno *a) {
	if (t == NULL){
		// caso nao seja encontrado o RA.
		return FALSE;
	} else {
		if (t->info.ra > ra){
			return consultaAluno(t->esq, ra, a);
		} else {
			if (t->info.ra < ra){
				return consultaAluno(t->dir, ra, a);
			} else {
				if (t->info.ra == ra){
					*a = t->info;
					return TRUE;
				}
			}
		}
	}
}

/* Imprime a arvore sob a forma de uma árvore 'deitada'. */
void imprimeArvore(Arvore t, int nivel){
	if (t != NULL){
		if (nivel != 0){
			int i;
			for (i = 0; i < nivel; i++){
				printf("\t");
			}
		}
		printf("%d, %s\n", t->info.ra, t->info.nome);
		imprimeArvore(t->esq, nivel + 1);
		if (t == NULL){
			nivel--;
		}
		imprimeArvore(t->dir, nivel + 1);
		if (t == NULL){
			nivel--;
		}
	}
}

/* Devolve o número de nós da arvore 't'. */
int numeroNosArvore(Arvore t){
	if (t == NULL){
		return 0;
	} else{
		int esquerda = numeroNosArvore(t->esq);
		int direita = numeroNosArvore(t->dir);
		return (esquerda + direita) + 1;
	}	
}

/* Devolve a altura da arvore 't'. */
int alturaArvore(Arvore t){
	if (t == NULL){
		return 0;
	} else{
		int esquerda = alturaArvore(t->esq);
		int direita = alturaArvore(t->dir);
		return ((esquerda > direita) ? esquerda : direita) + 1;
	}
}

/* Executa um percurso inordem na arvore, imprimindo todos os elementos. */
void percorreArvore(Arvore t){
	if (t != NULL){
		percorreArvore(t->esq);
		percorreArvore(t->dir);
		printf("%d, %s\n", t->info.ra, t->info.nome);
	}
}

/* Libera todos os nós da arvore apontada por 't', bem 
como todas as cadeias que guardam os nomes. */
void liberaArvore(Arvore *t){
	if (*t != NULL){
		liberaArvore(&(*t)->esq);
		liberaArvore(&(*t)->dir);
		free(*t);
	}
	*t = NULL;
}