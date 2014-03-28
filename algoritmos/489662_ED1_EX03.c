/* Universidade Federal de Sao Carlos - UFSCar, Sorocaba

  Disciplina: Estruturas de Dados 1
  Prof. Tiago A. Almeida

  Exercício 3 - Lista Estática (Lista Telefônica)

  Instrucoes
  ----------

  Este arquivo contem o codigo que auxiliara no desenvolvimento do
  exercicio. Voce precisara completar as funcoes requisitadas.

  Voce nao podera criar nenhuma outra funcao. Complete apenas as rotinas
  fornecidas. 														*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100 // trabalha com elementos do universo 0...TAM -1

//Operacoes que podem ser realizadas.
#define INSERIR		1
#define REMOVER 	2
#define BUSCAR		3
#define ALTERAR 	4
#define LISTAR 		5
#define SAIR		6

//Resposta de operacoes
#define FALSO		0
#define VERDADEIRO	1

//Frase exibida quando houver erro nas operacoes
#define FRASE_ERROALOCACAO	"Erro de alocacao!\n"
#define FRASE_P_JAEXISTENTE "Proprietario ja existente!\n"
#define FRASE_P_NAOENCONTRADO "Proprietario nao encontrado!\n"
#define FRASE_LISTA_CHEIA 	"Lista cheia!\n"
#define FRASE_LISTA_VAZIA 	"Lista vazia!\n"

// Definicao do Proprietario do Lote
typedef struct {
	char *nome;  // Campo nome devera ser alocado dinamicamente
	int cod_lote;
	unsigned long telefone;
} Proprietario;

// Definicao da Lista
typedef struct {
	Proprietario prop[TAM];
	int tamanho;
} Lista;

/* --------------------------------------------- */
/*           PREAMBULO DAS FUNCOES               */
/* --------------------------------------------- */

/* Imprime o registro enviado como argumento
 * NÃO ALTERAR!!! */
void imprimirRegistro(Proprietario prop);

/* Inicializa a lista com tamanho igual a zero */
void inicLista(Lista *L);

/* Remove todos os registros da lista. É importante liberar a memória
 * alocada em cada registro. */
void limparLista(Lista *L);

/* Retorna o tamanho da lista */
int tamanhoLista(Lista *L);

/* Retorna (1) se a lista estiver cheia, (0) caso contrário. */
int listaCheia(Lista *L);

/* Retorna (1) se a lista estiver vazia, (0) caso contrário. */
int listaVazia(Lista *L);

/* Abre "espaço" na lista para ser feita uma inserção. Desloca uma posição
 * para frente todos os registros entre pos_inicial e o último da lista.
 * NÃO é preciso chamar esta função na Inserção! A função main já cuida
 * disso. Retorna (1) em caso de sucesso e (0) se a lista estiver cheia. */
int expandirLista(Lista *L, int pos_inicial);

/* Remove um "espaço" da lista após uma remoção. Desloca uma posição
 * para trás todos os registros entre pos_inicial e o último da lista.
 * NÃO é preciso chamar esta função na Remoção! A função main já cuida
 * disso. Retorna (1) em caso de sucesso e (0) se a lista estiver vazia. */
int reduzirLista(Lista *L, int pos_inicial);

/* Insere um novo proprietario na posição informada como argumento. É
 * preciso alocar dinamicamente o nome do proprietario com o tamanho exato
 * necessario. Retorna (1) em caso de sucesso e (0) em caso de erro de
 * alocação. */
int inserir(Lista *L, Proprietario prop, int posicao);

/* Remove o proprietario da posição informada como argumento. É preciso
 * liberar a memória alocada para o nome. Retorna (1) em caso de sucesso
 * e (0) se a lista estiver vazia. */
int remover(Lista *L, int posicao);

/* Realiza a busca binária pelo proprietario informado. Deve-se incrementar
 * o número de comparações a cada laço.
 * Caso o proprietario tenha sido encontrado, deve retornar encontrado
 * VERDADEIRO e sua posição.
 * Caso o proprietario não tenha sido encontrado, deve retornar encontrado
 * FALSO e a posição do sucessor imediato.
 * Caso a lista esteja vazia, deve retornar encontrado FALSO e a posição 0. */
int buscaBinaria(Lista *L, Proprietario prop, int *comparacoes, int *posicao);

/* Imprime todos os registros da lista. */
void listar(Lista *L);

/* --------------------------------------------- */
/*               ROTINA PRINCIPAL                */
/* --------------------------------------------- */

int main(){

	int Opcao; // operacao escolhida pelo usuario
	Lista L;
	Proprietario prop;
	prop.nome = (char *) malloc (256 * sizeof(char));

	// auxiliares
	int posicao, numero_comparacoes;

	inicLista(&L);

	//Enquanto Opcao for diferente de SAIR.
	do {

		//Pergunta a Opcao que o usuario deseja realizar.
		scanf("%d", &Opcao);

		//Verifica qual Opcao foi escolhida.
		switch (Opcao) {
			
		// Opcao 1
		case INSERIR:
			scanf("\n%[^\n] \n%d \n%ld", prop.nome, &prop.cod_lote, &prop.telefone);

			numero_comparacoes = 0;
			if (buscaBinaria(&L, prop, &numero_comparacoes, &posicao) == VERDADEIRO) {
				printf(FRASE_P_JAEXISTENTE);
			} else {
				
				if (expandirLista(&L, posicao) == FALSO) {
					printf(FRASE_LISTA_CHEIA);
				} else {
					if (inserir(&L, prop, posicao) == FALSO) {
						printf(FRASE_ERROALOCACAO);
						exit(1);
					} else {
						printf("%d \n", numero_comparacoes);
					}
				}
			}
			break;

		// Opcao 2
		case REMOVER:
			scanf("\n%[^\n]", prop.nome);
			
			numero_comparacoes = 0;
			if (buscaBinaria(&L, prop, &numero_comparacoes, &posicao) == FALSO) {
				printf(FRASE_P_NAOENCONTRADO);
			} else {
				if (remover(&L, posicao) == FALSO) {
					printf(FRASE_LISTA_VAZIA);
				} else {
					reduzirLista(&L, posicao);
					printf("%d \n", numero_comparacoes);
				}
			}			
			break;

		// Opcao 3
		case BUSCAR:
			scanf("\n%[^\n]", prop.nome);
			
			numero_comparacoes = 0;			
			if (buscaBinaria(&L, prop, &numero_comparacoes, &posicao) == FALSO) {
				printf(FRASE_P_NAOENCONTRADO);
			} else {
				imprimirRegistro(L.prop[posicao]);
				printf("%d \n", numero_comparacoes);
			}
			break;
		
		// Opcao 4
		case ALTERAR:
			scanf("\n%[^\n]", prop.nome);
			
			numero_comparacoes = 0;
			if (buscaBinaria(&L, prop, &numero_comparacoes, &posicao) == FALSO) {
				printf(FRASE_P_NAOENCONTRADO);
			} else {
				
				// Proprietario encontrado
				imprimirRegistro(L.prop[posicao]);
				
				// Remover o registro antigo
				remover(&L, posicao);
				reduzirLista(&L, posicao);
				
				// Inserir o registro novo
				scanf("\n%[^\n] \n%d \n%ld", prop.nome, &prop.cod_lote, &prop.telefone);

				numero_comparacoes = 0;
				if (buscaBinaria(&L, prop, &numero_comparacoes, &posicao) == VERDADEIRO) {
					printf(FRASE_P_JAEXISTENTE);
				} else {
					
					if (expandirLista(&L, posicao) == FALSO) {
						printf(FRASE_LISTA_CHEIA);
					} else {
						if (inserir(&L, prop, posicao) == FALSO) {
							printf(FRASE_ERROALOCACAO);
							exit(1);
						} else {
							printf("%d \n", numero_comparacoes);
						}
					}
				}
			}			
			break;

		// Opcao 5
		case LISTAR:
			if (tamanhoLista(&L) == 0) printf(FRASE_LISTA_VAZIA);
			else listar(&L);
			break;

		// Opcao 6
		case SAIR:
			limparLista(&L);
			break;
		}

	} while (Opcao != SAIR);
	
	return (0);
}


/* --------------------------------------------- */
/* FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS */
/* --------------------------------------------- */

/* Imprime o registro enviado como argumento
 * NÃO ALTERAR!!! */
void imprimirRegistro(Proprietario prop) {
	printf("%s L:%d T:%ld\n", prop.nome, prop.cod_lote, prop.telefone);
}

/* Inicializa a lista com tamanho igual a zero */
void inicLista(Lista *L) {
	L->tamanho = 0;
}

/* Remove todos os registros da lista. É importante liberar a memória
 * alocada em cada registro. */
void limparLista(Lista *L) {
	int i;
	for (i = 0; i < L->tamanho; i++){
		free(L->prop[i].nome);
	}
	L->tamanho = 0;
}

/* Retorna o tamanho da lista */
int tamanhoLista(Lista *L) {
	return L->tamanho;
}

/* Retorna (1) se a lista estiver cheia, (0) caso contrário. */
int listaCheia(Lista *L) {
	if (L->tamanho == TAM){
		return VERDADEIRO;
	}
	else{
		return FALSO;
	}
}

/* Retorna (1) se a lista estiver vazia, (0) caso contrário. */
int listaVazia(Lista *L) {
	if (L->tamanho == 0){
		return VERDADEIRO;
	}
	else{
		return FALSO;
	}
}

/* Abre "espaço" na lista para ser feita uma inserção. Desloca uma posição
 * para frente todos os registros entre pos_inicial e o último da lista.
 * NÃO é preciso chamar esta função na Inserção! A função main já cuida
 * disso. Retorna (1) em caso de sucesso e (0) se a lista estiver cheia. */
int expandirLista(Lista *L, int pos_inicial) {
	int i;
	if (listaCheia(L)){
		return FALSO;
	}
	else{
		for (i = L->tamanho - 1; i >= pos_inicial; i--){
			L->prop[i + 1] = L->prop[i];
		}
		return VERDADEIRO;
	}
}

/* Remove um "espaço" da lista após uma remoção. Desloca uma posição
 * para trás todos os registros entre pos_inicial e o último da lista.
 * NÃO é preciso chamar esta função na Remoção! A função main já cuida
 * disso. Retorna (1) em caso de sucesso e (0) se a lista estiver vazia. */
int reduzirLista(Lista *L, int pos_inicial) {	
	int i;
	if (listaVazia(L) == VERDADEIRO){
		return FALSO;
	}
	else{
		for (i = pos_inicial; i <= L->tamanho - 1; i++){
			L->prop[i] = L->prop[i + 1];
		}
		return VERDADEIRO;
	}
}

/* Insere um novo proprietario na posição informada como argumento. É
 * preciso alocar dinamicamente o nome do proprietario com o tamanho exato
 * necessario. Retorna (1) em caso de sucesso e (0) em caso de erro de
 * alocação. */
int inserir(Lista *L, Proprietario prop, int posicao) {
	L->prop[posicao].nome = malloc(strlen(prop.nome) + 1);
	if(!L->prop[posicao].nome){
		return FALSO;
	}
	else{
		strcpy(L->prop[posicao].nome, prop.nome);
		L->prop[posicao].cod_lote = prop.cod_lote;
		L->prop[posicao].telefone = prop.telefone;
		L->tamanho++;
		return VERDADEIRO;
	}
}

/* Remove o proprietario da posição informada como argumento. É preciso
 * liberar a memória alocada para o nome. Retorna (1) em caso de sucesso
 * e (0) se a lista estiver vazia. */
int remover(Lista *L, int posicao) {
	if(listaVazia(L)){
		return FALSO;
	}
	else{
		free(L->prop[posicao].nome);
		L->tamanho--;	
		return VERDADEIRO;
	}
}

/* Realiza a busca binária pelo proprietario informado. Deve-se incrementar
 * o número de comparações a cada laço.
 * Caso o proprietario tenha sido encontrado, deve retornar encontrado
 * VERDADEIRO e sua posição.
 * Caso o proprietario não tenha sido encontrado, deve retornar encontrado
 * FALSO e a posição do sucessor imediato.
 * Caso a lista esteja vazia, deve retornar encontrado FALSO e a posição 0. */
int buscaBinaria(Lista *L, Proprietario prop, int *comparacoes, int *posicao) {
	if(listaVazia(L) == VERDADEIRO){
		*comparacoes = 0;
		*posicao = 0;
		return FALSO;
	}
	else{
		int esq = 0;
		int dir = L->tamanho - 1;
		int meio;

		while (esq <= dir){
			meio = (esq + dir) / 2;
			*comparacoes = *comparacoes + 1;

			if (strcmp(L->prop[meio].nome, prop.nome) == 0){
				*posicao = meio;
				return VERDADEIRO;
			}
			else{
				if (strcmp(L->prop[meio].nome, prop.nome) > 0){
					dir = meio - 1;
				}
				else{
					esq = meio + 1;
				}
			}
		}
		*posicao = esq;
		return FALSO;
	}
}

/* Imprime todos os registros da lista. */
void listar(Lista *L) {
	int i;
	for (i = 0; i < L->tamanho; i++){
		imprimirRegistro(L->prop[i]);
	}
}