/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 10 - Árvore AVL (Adelson-Velskii e Landis)

	Charles David de Moraes		26/06/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 70
#define TRUE 1
#define FALSE 0

// Frase exibida quando houver erro nas operacoes
#define FRASE_ERROALOCACAO	"Erro de alocacao!\n"
#define FRASE_OPCAO_INVAL	"Opcao invalida!\n"
#define FRASE_ERRO_AVL		"Erro: a arvore nao possui estrutura de AVL!!!\n"

// Definicao do elemento da árvore
typedef struct {
	int ra;
	char nome[MAX];
} Aluno;

// Definicao do nó
typedef struct no {
	Aluno info;
	struct no *esq, *dir;
	short int bal;
} No;

// Definicao da Arvore
typedef No *Arvore;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */

/* Verifica se a árvore informada tem a estrutura de uma árvore AVL.
 * NÃO ALTERAR!!! */
int verificaAVL(Arvore t, int *alt);

/* Inicializa a arvore. */
void inicArvore(Arvore *t);

/* Caso exista um aluno com o RA informado, returne TRUE e atribua
 * em 'a' os dados do aluno. Caso contrário retorne FALSE. */
int consultaAluno(Arvore t, int ra, Aluno *a);

/* Imprime a arvore sob a forma de uma árvore 'deitada'. */
void imprimeArvore(Arvore t, int nivel);

/* Devolve o número de nós da arvore 't'. */
int numeroNosArvore(Arvore t);

/* Devolve a altura da arvore 't'. */
int alturaArvore(Arvore t); 

/* Executa um percurso inordem na arvore, imprimindo todos os elementos. */
void percorreArvore(Arvore t);

/* Libera todos os nós da arvore apontada por 't', bem 
como todas as cadeias que guardam os nomes. */
void liberaArvore(Arvore *t);

/** Rotinas para rotação na árvore **/

/* Rotação simples RR - Rotação Direira */
void RR(Arvore *t);

/* Rotação simples LL - Rotação Esquerda */
void LL(Arvore *t);

/* Rotação dupla RL - Rotação Direita-Esquerda*/
void RL(Arvore *t);

/* Rotação dupla LR - Rotação Esquerda-Direita */
void LR(Arvore *t);

/** Rotinas auxiliares para inserção. */

/* Faz os ajustes quando a sub-árvore esquerda cresceu. */
void SubArvoreEsquerdaCresceu(Arvore *t, int *cresceu);

/* Faz os ajustes quando a sub-árvore direita cresceu. */
void SubArvoreDireitaCresceu(Arvore *t, int *cresceu);

/* Insere o aluno informado como parâmetro caso não exista aluno
 * com o mesmo RA e devolve TRUE. Caso contrário devolve FALSE.
 * A variável 'cresceu' recebe TRUE se a há aumento da altura da
 * árvore e FALSE, caso contrário. */
int insereAlunoAVL(Arvore *t, Aluno a, int *cresceu);

/* Cria um novo nó, com registro do aluno 'a'. */
Arvore novoNo(Aluno a);


/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main() {
	int info, ra, nivel;
	Aluno aluno;
	Arvore t;
	char acao;
	int cresceu;
	int altura;

	inicArvore(&t);

	//Enquanto opcao for diferente de SAIR
	do { 

		//Pergunta a opcao que o usuario deseja realizar
		scanf("\n%c", &acao);

		//Verifica qual opcao foi escolhida.
		switch (acao) {

			case 'i':
				scanf("%d %[^\n]",&aluno.ra, aluno.nome);

				info = insereAlunoAVL(&t, aluno, &cresceu);
				if (info == FALSE)
					printf("RA %d ja estava presente na arvore de dados.\n", aluno.ra);
				
				else if(info == -1){
					printf(FRASE_ERROALOCACAO);
					exit(0);
				}
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
				if (!verificaAVL(t, &altura))
					printf(FRASE_ERRO_AVL);

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

/* Verifica se a árvore informada tem a estrutura de uma árvore AVL.
 * NÃO ALTERAR!!! */
int verificaAVL(Arvore t, int *alt) {
	int altEsq, altDir, bal, resEsq, resDir;
	
	if (t == NULL) {
		*alt = 0;
		return TRUE;
	}

	resEsq = verificaAVL(t->esq, &altEsq);
	resDir = verificaAVL(t->dir, &altDir);
	bal = t->bal;

	*alt = ((altEsq<altDir) ? altDir : altEsq) + 1;

	return ((bal >= -1) && (bal <= +1)
		&& (bal == (altDir-altEsq))
		&& resEsq && resDir);
}

/* Inicializa a arvore. */
void inicArvore(Arvore *t) {
	*t = NULL;
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
		printf("%d, %s\n", t->info.ra, t->info.nome);
		percorreArvore(t->dir);
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

/** Rotinas para rotação na árvore **/

/* Rotação simples RR - Rotação Direira */
void RR(Arvore *t) {
	No *aux = *t;
	No *temp = aux->esq;
	*t = temp;
	aux->esq = temp->dir;
	temp->dir = aux;
}

/* Rotação simples LL - Rotação Esquerda */
void LL(Arvore *t) {
	No *aux = *t;
	No *temp = aux->dir;
	*t = temp;
	aux->dir = temp->esq;
	temp->esq = aux;
}

/* Rotação dupla RL - Rotação Direita-Esquerda*/
void RL(Arvore *t) {
	RR(&(*t)->dir);
	LL(&(*t));
}

/* Rotação dupla LR - Rotação Esquerda-Direita*/
void LR(Arvore *t) {
	LL(&(*t)->esq);
	RR(&(*t));
}

/** Rotinas auxiliares para inserção. */

/* Cria um novo nó, com registro do aluno 'a'. */
Arvore novoNo(Aluno a) {
	No *novo = (No *)malloc(sizeof(No));
	
	if (novo == NULL){
		return novo;
	}

	novo->esq = NULL;
	novo->dir = NULL;
	novo->bal = 0;
	novo->info.ra = a.ra;
	strcpy(novo->info.nome, a.nome);

	return novo;
}

/* Faz os ajustes quando a sub-árvore esquerda cresceu. */
void SubArvoreEsquerdaCresceu(Arvore *t, int *cresceu) {
	switch ((*t)->bal){

		case 1:
			(*t)->bal = 0;
			*cresceu = FALSE;
		break;

		case 0:
			(*t)->bal = -1;
			*cresceu = TRUE;
		break;

		//Desbalanceado
		case -1:
			switch ((*t)->esq->bal){
				//Rotação dupla
				case 1:
					LR(&(*t));
					switch ((*t)->bal){
						case 1:
							(*t)->esq->bal = -1;
							(*t)->dir->bal = 0;
						break;

						case -1:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 1;
						break;

						case 0:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 0;
						break;
					}
					(*t)->bal = 0;
				break;

				//Rotação simples
				case -1:
					RR(&(*t));
					(*t)->bal = 0;
					(*t)->dir->bal = 0;
				break;
			}
			*cresceu = FALSE;
		break;
	}
}

/* Faz os ajustes quando a sub-árvore direita cresceu. */
void SubArvoreDireitaCresceu(Arvore *t, int *cresceu) {
	switch ((*t)->bal){
		case -1:
			(*t)->bal = 0;
			*cresceu = FALSE;
		break;

		case 0:
			(*t)->bal = 1;
			*cresceu = TRUE;
		break;

		//Desbalanceado
		case 1:
			switch ((*t)->dir->bal){
				//Rotação dupla
				case -1:
					RL(&(*t));
					switch ((*t)->bal){
						case 1:
							(*t)->esq->bal = -1;
							(*t)->dir->bal = 0;
						break;

						case -1:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 1;
						break;

						case 0:
							(*t)->esq->bal = 0;
							(*t)->dir->bal = 0;
						break;
					}
					(*t)->bal = 0;
				break;

				//Rotação simples
				case 1:
					LL(&(*t));
					(*t)->bal = 0;
					(*t)->esq->bal = 0;
				break;
			}
			*cresceu = FALSE;
		break;
	}
}

/* Insere o aluno informado como parâmetro caso não exista aluno
 * com o mesmo RA e devolve TRUE. Caso contrário devolve FALSE.
 * A variável 'cresceu' recebe TRUE se a há aumento da altura da
 * árvore e FALSE, caso contrário. */
int insereAlunoAVL(Arvore *t, Aluno a, int *cresceu) {
	if (*t == NULL){
		*t = novoNo(a);
		*cresceu = (*t == NULL) ? FALSE : TRUE;
		return (*t == NULL) ? -1 : TRUE;
	} else {
		if ((*t)->info.ra > a.ra){
			if (!insereAlunoAVL(&(*t)->esq, a, cresceu)){
				return FALSE;
			}
			if (*cresceu){
				SubArvoreEsquerdaCresceu(&(*t), cresceu);
			}
			return TRUE;
		} else {
			if ((*t)->info.ra < a.ra){
				if (!insereAlunoAVL(&(*t)->dir, a, cresceu)){
					return FALSE;
				}
				if (*cresceu){
					SubArvoreDireitaCresceu(&(*t), cresceu);
				}
				return TRUE;
			}
		}
	}
	//Ocorre quando já existe ra.
	*cresceu = FALSE;
	return FALSE;
}
