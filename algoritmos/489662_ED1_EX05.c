/* ================================================================== *
	Universidade Federal de Sao Carlos - UFSCar, Sorocaba

	Disciplina: Estruturas de Dados 1
	Prof. Tiago A. Almeida

	Exercício 5 - Lista Duplamente Encadeada – Editor de texto

	Charles David de Moraes		24/04/2013
	RA: 489662
 * ================================================================== */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

// Operacoes que podem ser realizadas.
#define INSERIR			'I'
#define MOVER_POSICAO	'M'
#define BACKSPACE		'B'
#define DELETE			'D'
#define IMPRIMIR		'P'
#define FIM				'F'

// Frase exibida quando houver erro nas operacoes
#define FRASE_ERROALOCACAO	"Erro de alocacao!\n"

// TAD que representa o nó da lista duplamente encadeada
typedef struct no {
	char letra;
	struct no *next;
	struct no *prev;
} Node;

// TAD que representa o editor (este é o nó cabeça)
typedef struct {
	Node *next;
	int cursor;
	int tam;
} Cabeca;
typedef Cabeca* Editor;

/* ================================================================== */
/* ===================== PREAMBULO DAS FUNCOES ====================== */
/* ================================================================== */
/* Percorre a lista, imprimindo todos os caracteres os texto. */
/* NÃO ALTERAR!!! */
void imprimir(Editor editor);

/* Cria o nó cabeça e inicializa tam e cursor iguais a 0. */
int inicEditor(Editor *editor);

/* Retorna (1) se a lista estiver vazia e (0) caso contrário. */
int listaVazia(Editor editor);

/* Insere um novo nó na lista, na posição referente ao cursor do texto.
 * Retorna (1) em caso de sucesso e (0) em caso de erro de alocação. */
int inserir(Editor editor, char c);

/* Move o cursor de acordo com o argumento informado. Pos pode ser
 * negativo, mas o cursor obrigatoriamente deve ficar entre o intervalo
 * 0 e tam. */
void moverPosicao(Editor editor, int pos);

/* Apaga o caractere anterior ao cursor do texto. Caso cursor = 0, ou seja,
 * antes do primeiro caractere do texto, nenhum caractere é removido. */
void backspace(Editor editor);

/* Apaga o caractere posterior ao cursor do texto. Caso cursor = tam, ou seja,
 * depois do último caractere do texto, nenhum caractere é removido. */
void delete(Editor editor);

/* Libera a memória de todos os nós da lista, incluindo o nó cabeça. */
void liberar(Editor *editor);

/* ================================================================== */
/* ======================== ROTINA PRINCIPAL ======================== */
/* ================================================================== */

int main() {
	char opcao; 	    // operacao escolhida pelo usuario
	char c;
	int pos;
	Editor editor;

	if (!inicEditor(&editor)) {
		printf(FRASE_ERROALOCACAO);
		exit(1);
	}
	
	//Enquanto opcao for diferente de SAIR.
	do {

		//Pergunta a opcao que o usuario deseja realizar.
		scanf("%c", &opcao);

		//Verifica qual opcao foi escolhida.
		switch (opcao) {
			
			// opcao I
			case INSERIR:
				scanf("\n%c", &c);
				if (!inserir(editor, c)) {
					printf(FRASE_ERROALOCACAO);
					exit(1);
				}
				break;

			// opcao M
			case MOVER_POSICAO:
				scanf("%d", &pos);
				moverPosicao(editor, pos);
				break;

			// opcao B
			case BACKSPACE:
				backspace(editor);
				break;
				
			// opcao D
			case DELETE:
				delete(editor);
				break;

			// opcao P
			case IMPRIMIR:
				imprimir(editor);
				break;
			
			// opcao F
			case FIM:
				imprimir(editor);
				liberar(&editor);
				break;
		}

	} while (opcao != FIM);
	
	
	return 0;
}

/* ================================================================== */
/* ========== FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS ========= */
/* ================================================================== */

/* Percorre a lista, imprimindo todos os caracteres os texto. */
/* NÃO ALTERAR!!! */
void imprimir(Editor editor) {
	if (!listaVazia(editor)) {
		Node *aux;
		for (aux = editor->next; aux != NULL; aux = aux->next) {
			printf("%c", aux->letra);
		}
		printf("\n");
	}
}

/* Cria o nó cabeça e inicializa tam e cursor iguais a 0. */
int inicEditor(Editor *editor) {
	*editor = (Cabeca *)malloc(sizeof(Cabeca));
	if (!editor){
		return FALSE;
	}
	(*editor)->tam = 0;
	(*editor)->cursor = 0;
	(*editor)->next = NULL;
	return TRUE;
}

/* Retorna (1) se a lista estiver vazia e (0) caso contrário. */
int listaVazia(Editor editor) {
	if (editor->tam == 0){
		return TRUE;
	}
	return FALSE;
}

/* Insere um novo nó na lista, na posição referente ao cursor do texto.
 * Retorna (1) em caso de sucesso e (0) em caso de erro de alocação. */
int inserir(Editor editor, char c) {
	Node *novo = (Node *)malloc(sizeof(Node));

	if (novo != NULL){
		novo->letra = c;
		novo->next = NULL;
		novo->prev = NULL;

		Node *aux = editor->next;
		if (editor->cursor == 0){
			if (aux != NULL){
				aux->prev = novo;
				novo->next = aux;
			}
			editor->next = novo;
		}
		else {
			int i;
			for (i = 1; i < editor->cursor; i++){
				aux = aux->next;
			}

			if (aux->next != NULL){
				novo->next = aux->next;
				novo->next->prev = novo;
			}
			aux->next = novo;
			novo->prev = aux;
		}

		editor->tam += 1;
		editor->cursor += 1;
		return TRUE;
	}
	return FALSE;
}

/* Move o cursor de acordo com o argumento informado. Pos pode ser
 * negativo, mas o cursor obrigatoriamente deve ficar entre o intervalo
 * 0 e tam. */
void moverPosicao(Editor editor, int pos) {
	int i;
	if (editor->cursor + pos > editor->tam){
		editor->cursor = editor->tam;
	}
	else {
		if (editor->cursor + pos < 0){
			editor->cursor = 0;
		}
		else {
			editor->cursor += pos;
		}
	}
}

/* Apaga o caractere anterior ao cursor do texto. Caso cursor = 0, ou seja,
 * antes do primeiro caractere do texto, nenhum caractere é removido. */
void backspace(Editor editor) {
	if (editor->cursor > 0){
		int i;
		Node *aux = editor->next;
		Node *del;

		for (i = 1; i < editor->cursor; i++){
			aux = aux->next;
		}
		del = aux;

		if (editor->cursor == 1){
			editor->next = aux->next;
		}
		else {
			aux->prev->next = aux->next;
		}

		if (aux->next != NULL){
			aux->next->prev = aux->prev;
		}

		free(del);
		editor->cursor -= 1;
		editor->tam -= 1;
	}
}

/* Apaga o caractere posterior ao cursor do texto. Caso cursor = tam, ou seja,
 * depois do último caractere do texto, nenhum caractere é removido. */
void delete(Editor editor) {
	if (editor->cursor != editor->tam){
	int i;
	Node *aux = editor->next;

		if (editor->cursor == 0){
			editor->next = aux->next;
			if (aux->next != NULL){
				aux->next->prev = NULL;
			}
		}
		else {
			for (i = 0; i < editor->cursor; i++){
				aux = aux->next;
			}
			aux->prev->next = aux->next;

			if (aux->next != NULL){
				aux->next->prev = aux->prev;
			}
		}
			free(aux);
			editor->tam -= 1;
	}
}

/* Libera a memória de todos os nós da lista, incluindo o nó cabeça. */
void liberar(Editor *editor) {
	int i;
	Node *aux = (*editor)->next;

	for (i = 1; i < (*editor)->tam; i++){
		Node *del = aux;
		aux = aux->next;
		free(del);
	}
	free(*editor);
}