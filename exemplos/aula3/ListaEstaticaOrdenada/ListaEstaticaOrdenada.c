#include "ListaEstaticaOrdenada.h"
#include <stdio.h>

void criar(LISTA *lista){
  lista->fim = -1;
}

int vazia(LISTA *lista){
  return (lista->fim == -1);
}

int cheia(LISTA *lista){
  return (lista->fim == TAM - 1);
}

int tamanho(LISTA *lista){
  return lista->fim + 1;
}

void imprimir(LISTA *lista){
  int i;

  if (!vazia(lista)) {
    for (i = 0; i <= lista->fim; i++) {
      printf("%d - %d\n", lista->itens[i].chave,
             lista->itens[i].valor);
    }
  }
}

int inserir_ordenado(LISTA *lista, ITEM *item) {
  if (!cheia(lista)) { //verifica se existe espaço
    int pos = lista->fim+1;

    //move os itens até encontrar a posição de inserção
    while (pos > 0 && lista->itens[pos-1].chave > item->chave) {
      lista->itens[pos] = lista->itens[pos-1];
      pos--;
    }

    lista->itens[pos] = *item; //insire novo item
    lista->fim++; //incrementa tamanho da lista
    return 1;
  }

  return 0;
}

int busca_sequencial(LISTA *lista, int chave, ITEM *item) {
  int i;

  for (i = 0; i <= lista->fim; i++) { //pecorre a lista
    if (lista->itens[i].chave == chave) { //se encontrar a chave
      *item = lista->itens[i]; //armazeno o elemento
      return 1; //indica que encontrou
    } else if (lista->itens[i].chave > chave) { //se a chave é maior
      return 0; //indica que não encontrou
    }
  }

  return 0; //indica que não encontrou
}

int busca_binaria(LISTA *lista, int chave, ITEM *item) {
  int esq = 0;
  int dir = lista->fim;

  while (esq <= dir) {
    int meio = (esq + dir) / 2; //calcula meio do vetor

    if (lista->itens[meio].chave == chave) { //encontrou a chave
      *item = lista->itens[meio];
      return 1;
    }

    if (lista->itens[meio].chave > chave) { //o meio é maior que a chave
      dir = meio - 1; //desconsidero os itens maiores que o meio
    } else {
      esq = meio + 1; //desconsidero os itens menores que o meio
    }
  }

  return 0;
}
