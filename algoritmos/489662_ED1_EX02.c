/* Universidade Federal de Sao Carlos - UFSCar, Sorocaba

  Exercício 2 - Tipos Abstratos de Dados (TAD Conjunto)

  Charles David de Moraes		01/04/2013
  RA: 489662
 														*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10 // trabalha com elementos do universo 0...TAM -1

//Operacoes que podem ser realizadas.
#define INSERCAO	1
#define REMOCAO 	2
#define MEMBRO		3
#define TAMANHO 	4
#define IMPRESSAO 	5
#define MINIMO     	6
#define MAXIMO     	7
#define UNIAO		8
#define INTERSECCAO	9
#define DIFERENCA	10
#define IGUAL		11
#define COPIA   	12
#define SAIR		13

//Resposta para a operacao que verifica se um elemento
//qualquer pertence a um dado conjunto.
#define FALSO		0
#define VERDADEIRO	1

//Frase exibida quando houver erro nas operacoes
#define FRASE_ERRO 		"Operacao invalida!\n"
#define FRASE_ELEM_INVALIDO "Elemento invalido!\n"
#define FRASE_ELEM_NAOENCONTRADO "Elemento nao encontrado!\n"
#define FRASE_CONJ_VAZIO "Conjunto vazio!\n"
#define FRASE_VERDADEIRO "Verdadeiro\n"
#define FRASE_FALSO "Falso\n"

// Definicao do tipo elemento como inteiro
typedef int elem;

// Definicao do TAD Set (Conjunto)
typedef struct {
  elem *v;
} Conjunto;

/* --------------------------------------------- */
/*           PREAMBULO DAS FUNCOES               */
/* --------------------------------------------- */

/* Função união – Une os elementos do conjunto A e B em um conjunto C */
void Uniao(Conjunto *A, Conjunto *B, Conjunto *C);

/* Função Intersecção – Armazena em C os mesmos elementos que estão no conjunto A e B */
void Interseccao(Conjunto *A, Conjunto *B, Conjunto *C);

/* Função diferença – atribui ao conjunto C a diferença entre os conjuntos A e B */
void Diferenca(Conjunto *A, Conjunto *B, Conjunto *C);

/* Função membro – verifica se o elemento está (1) no Conjunto A ou não (0)*/
int Membro(elem x, Conjunto *A);

/* Função CriaConjVazio – Cria um conjunto vazio e retorna o conjunto criado. A variável erro retorna 0 se o conjunto
foi criado corretamente e 1 caso contrario. Deve ser usado como primeira operação sobre um conjunto. */
Conjunto* CriaConjVazio (int *erro);

/* Função insere – Insere o elemento elem no conjunto A e retorna se a execução foi realizada com sucesso(1) ou não(0) */
int Insere(elem x, Conjunto *A);

/* Função remove – Remove o elemento elem do Conjunto A, retorna 1 se o elemento foi retirado e 0 se o elemento não está no
conjunto */
int Remove(elem x, Conjunto *A);

/* Função copia – Faz a copia do conjunto A para o B */
void Copia(Conjunto *A, Conjunto *B);

/* Função min – Retorna o menor elemento do conjunto A. Se o conjunto está vazio retorna TAM */
elem Min(Conjunto *A);

/* Função max – Retorna o maior elemento do conjunto A. Se o conjunto está vazio retorna TAM */
elem Max(Conjunto *A);

/* Função igual – Verifica se o conjunto A é igual a Conjunto B */
int Igual(Conjunto *A, Conjunto *B);

/* Função tamanho – Retorna o tamanho do conjunto A */
int Tamanho(Conjunto *A);

/* Função testaVazio – Verifica se o conjunto A está vazio (1) ou não (0) */
int TestaVazio(Conjunto *A);

/* Função liberar – Libera a memória de um conjunto */
void Libera(Conjunto *A);

/* Função imprimir – Imprime o conteúdo do conjunto */
void Imprimir(Conjunto *A);

/* Função inicializar – Inicializa o conjunto C a cada função que o utilize */
void Inicializar(Conjunto *C);


/* --------------------------------------------- */
/*               ROTINA PRINCIPAL                */
/* --------------------------------------------- */

int main(){
	char labelConj; // rotulo do conjunto empregado nas operacoes
	int erro;       // flag de erro na criacao dos conjuntos
	int Opcao;      // operacao escolhida pelo usuario
	Conjunto *A, *B, *C;
	elem valor, min, max;

	// conjunto A
	A = CriaConjVazio(&erro);
	if (erro){
		printf("Erro de alocacao!\n");
		exit(1);
	}

	// conjunto B
	B = CriaConjVazio(&erro);
	if (erro){
		printf("Erro de alocacao!\n");
		exit(1);
	}

	// conjunto C onde serao armazenados os resultados das operacoes
	C = CriaConjVazio(&erro);
	if (erro){
		printf("Erro de alocacao!\n");
		exit(1);
	}


	//Enquanto Opcao for diferente de SAIR.
	do {

		//Pergunta a Opcao que o usuario deseja realizar.
		scanf("%d", &Opcao);

		//Verifica qual Opcao foi escolhida.
		switch (Opcao) {

			// Opcao 1
			case INSERCAO:

				scanf("%d \n%c", &valor, &labelConj);

				if (labelConj == 'A') //insere em A
					if (Insere(valor, A) == FALSO) //se der problema
						printf(FRASE_ELEM_INVALIDO); //imprime frase
					else {
						printf("A = ");
						Imprimir(A);
					}
				else if (labelConj == 'B') // insere em B
						if (Insere(valor, B) == FALSO)
							printf(FRASE_ELEM_INVALIDO);
						else {
							printf("B = ");
							Imprimir(B);
						}
				else
					printf(FRASE_ERRO);

				break;

			// Opcao 2
			case REMOCAO:

				scanf("%d \n%c", &valor, &labelConj);

				if (labelConj == 'A') // remove de A
					if (Remove(valor, A) == FALSO) //se der problema
						printf(FRASE_ELEM_NAOENCONTRADO); //imprime frase
					else {
						printf("A = ");
						if (TestaVazio(A)) {
							printf(FRASE_CONJ_VAZIO);
						} else {
							Imprimir(A);
						}
					}

				else if (labelConj == 'B') // remove de B
					if (Remove(valor, B) == FALSO)
						printf(FRASE_ELEM_NAOENCONTRADO);
					else {
						printf("B = ");
						if (TestaVazio(B)) {
							printf(FRASE_CONJ_VAZIO);
						} else {
							Imprimir(B);
						}
					}

				else
					printf(FRASE_ERRO);

				break;

			// Opcao 3
			case MEMBRO:

				scanf("%d \n%c", &valor, &labelConj);

				if (labelConj == 'A') // procura em A
					if (Membro(valor, A) == FALSO) //se der problema
						printf(FRASE_FALSO); //imprime frase
					else
						printf(FRASE_VERDADEIRO); //imprime frase

				else if (labelConj == 'B') // procura em B
					if (Membro(valor, B) == FALSO)
						printf(FRASE_FALSO);
					else
						printf(FRASE_VERDADEIRO);
				else
					printf(FRASE_ERRO);

				break;

			// Opcao 4
			case TAMANHO:

				scanf("\n%c", &labelConj);

				if (labelConj == 'A') // verifica A
					printf("%d\n", Tamanho(A));
				else if (labelConj == 'B') // verifica B
					printf("%d\n", Tamanho(B));
				else
					printf(FRASE_ERRO);

				break;

			// Opcao 5
			case IMPRESSAO:

				printf("A = ");
				if (TestaVazio(A)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(A);
				}

				printf("B = ");
				if (TestaVazio(B)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(B);
				}

				break;

			// Opcao 6
			case MINIMO:

				scanf("\n%c", &labelConj);

				if (labelConj == 'A') { // verifica A
					min = Min(A);
					if (min == TAM) // se conjunto vazio
						printf(FRASE_CONJ_VAZIO); // imprime frase
					else
						printf("%d\n", min); //imprime frase

				} else if (labelConj == 'B') { // verifica B
					min = Min(B);
					if (min == TAM) // se conjunto vazio
						printf(FRASE_CONJ_VAZIO); // imprime frase
					else
						printf("%d\n", min); //imprime frase

				} else
					printf(FRASE_ERRO);

				break;

			// Opcao 7
			case MAXIMO:

				scanf("\n%c", &labelConj);

				if (labelConj == 'A') { // verifica A
					max = Max(A);
					if (max == TAM) // se conjunto vazio
						printf(FRASE_CONJ_VAZIO); // imprime frase
					else
						printf("%d\n", max); //imprime frase

				} else if (labelConj == 'B') { // verifica B
					max = Max(B);
					if (max == TAM) // se conjunto vazio
						printf(FRASE_CONJ_VAZIO); // imprime frase
					else
						printf("%d\n", max); //imprime frase

				} else
					printf(FRASE_ERRO);

				break;

			// Opcao 8
			case UNIAO:

				Inicializar(C);
				Uniao(A, B, C);
				if (TestaVazio(C)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(C);
				}

				break;

			// Opcao 9
			case INTERSECCAO:

				Inicializar(C);
				Interseccao(A, B, C);
				if (TestaVazio(C)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(C);
				}

				break;

			// Opcao 10
			case DIFERENCA:

				Inicializar(C);
				Diferenca(A, B, C);
				if (TestaVazio(C)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(C);
				}

				break;

			// Opcao 11
			case IGUAL:

				if (Igual(A, B) == FALSO)
					printf(FRASE_FALSO);
				else
					printf(FRASE_VERDADEIRO);

				break;

			// Opcao 12
			case COPIA:
				Copia(A, B);
				printf("A = ");
				if (TestaVazio(A)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(A);
				}

				printf("B = ");
				if (TestaVazio(B)) {
					printf(FRASE_CONJ_VAZIO);
				} else {
					Imprimir(B);
				}

				break;

			// Opcao 13
			case SAIR:
				Libera(A);
				Libera(B);
				Libera(C);

				break;
		}

	} while (Opcao != SAIR);

	return (0);
}


/* --------------------------------------------- */
/* FUNCOES QUE DETERMINAM AS OPERACOES POSSIVEIS */
/* --------------------------------------------- */

/* Função união – Une os elementos do conjunto A e B em um conjunto C */
void Uniao (Conjunto *A, Conjunto *B, Conjunto *C) {
	int i;
	for(i = 0; i < TAM; i++){
		C->v[i] = A->v[i] || B->v[i];
	}
}

/* Função Intersecção – Armazena em C os mesmos elementos que estão no conjunto A e B */
void Interseccao(Conjunto *A, Conjunto *B, Conjunto *C) {
	int i;
	for(i = 0; i < TAM; i++){
		if(A->v[i] == B->v[i]){
			C->v[i] = A->v[i];
		}
	}
}

/* Função diferença – Atribui ao conjunto C a diferença entre os conjuntos A e B */
void Diferenca(Conjunto *A, Conjunto *B, Conjunto *C){
	int i;
	for(i = 0; i < TAM; i++){
		if(A->v[i] == VERDADEIRO){
			if(B->v[i] == FALSO){
				C->v[i] = VERDADEIRO;
			}
		}
	}
}

/* Função membro – verifica se o elemento está (1) no Conjunto A ou não (0)*/
int Membro(elem x, Conjunto *A) {
	if(x > TAM - 1 || x < 0){
		return FALSO;
	}
	if(A->v[x] == VERDADEIRO){
		return VERDADEIRO;
	}
}

/* Função CriaConjVazio – Cria um conjunto vazio e retorna o conjunto criado. A variável erro retorna 0 se o conjunto
foi criado corretamente e 1 caso contrario. Deve ser usado como primeira operação sobre um conjunto. */
Conjunto * CriaConjVazio(int *erro) {
	Conjunto *X;
	X = (Conjunto *)malloc(sizeof(Conjunto));

	if(!X){
		*erro = VERDADEIRO;
	}

	X->v = (elem *)calloc(TAM, sizeof(elem));

	if(!X->v){
		*erro = VERDADEIRO;
	}
	else{
		*erro = FALSO;
		return X;
	}
}

/* Função insere – Insere o elemento elem no conjunto A e retorna se a execução foi realizada com sucesso(1) ou não(0) */
int Insere(elem x, Conjunto *A) {
	if(x > TAM - 1 || x < 0){
		return FALSO;
	}
	if(A->v[x] == FALSO || A->v[x] == VERDADEIRO){
		A->v[x] = VERDADEIRO;
		return VERDADEIRO;
	}
}

/* Função remove – Remove o elemento elem do Conjunto A, retorna 1 se o elemento foi retirado e 0 se o elemento não está no
conjunto */
int Remove(elem x, Conjunto *A) {
	if(x > TAM - 1 || x < 0){
		return FALSO;
	}
	if(A->v[x] == VERDADEIRO){
		A->v[x] = FALSO;
		return VERDADEIRO;
	}
}


/* Função copia – Faz a copia do conjunto A para o B */
void Copia(Conjunto *A, Conjunto *B) {
	int i;
	for(i = 0; i < TAM; i++){
		B->v[i] = A->v[i];
	}
}

/* Função min – Retorna o menor elemento do conjunto A. Se o conjunto está vazio retorna TAM */
elem Min(Conjunto *A) {
	int i;
	for(i = 0; i < TAM; i++){
		if(A->v[i] == VERDADEIRO){
			return i;
		}
	}
	return TAM;
}

/* Função max – Retorna o maior elemento do conjunto A. Se o conjunto está vazio retorna TAM */
elem Max(Conjunto *A) {
	int i;
	for(i = TAM - 1; i >= 0; i--){
		if(A->v[i] == VERDADEIRO){
			return i;
		}
	}
	return TAM;
}

/* Função igual – Verifica se o conjunto A é igual a Conjunto B */
int Igual(Conjunto *A, Conjunto *B){
	int i;
	for(i = 0; i < TAM; i++){
		if(A->v[i] != B->v[i]){
			return FALSO;
		}
	}
	return VERDADEIRO;
}

/* Função tamanho – Retorna o tamanho do conjunto A */
int Tamanho(Conjunto *A){
	int i, cont = 0;
	for(i = 0; i < TAM; i++){
		if(A->v[i] == VERDADEIRO){
			cont++;
		}
	}
	return cont;
}

/* Função testaVazio – Verifica se o conjunto A está vazio (1) ou não (0) */
int TestaVazio(Conjunto *A){
	int i;
	for(i = 0; i < TAM; i++){
		if(A->v[i] == VERDADEIRO){
			return FALSO;
		}
	}
	return VERDADEIRO;
}

/* Função liberar – Libera a memória de um conjunto */
void Libera (Conjunto *A){
	free(A->v);
	free(A);
}

/* Função imprimir – Imprime o conteúdo do conjunto */
void Imprimir(Conjunto *A){
	int i;
	for(i = 0; i < TAM; i++){
		if (A->v[i] == VERDADEIRO){
			printf("%d ", i);
		}
	}
	printf("\n");
}

/* Função inicializar – Inicializa o conjunto C a cada função que o utilize */
void Inicializar(Conjunto *C){
	int i;
	for(i = 0; i < TAM; i++){
		C->v[i] = FALSO;
	}
}
