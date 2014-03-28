#include "ListaEstatica.h"
#include <stdio.h>

void criar(LISTA *lista) {
  lista->fim = -1;
}

int vazia(LISTA *lista) {
  return (lista->fim == -1);
}

int cheia(LISTA *lista) {
  return (lista->fim == TAM - 1);
}

int tamanho(LISTA *lista) {
  return lista->fim + 1;
}

void imprime(LISTA *lista) {
  int i;

  if (!vazia(lista)) {
    for (i = 0; i <= lista->fim; i++) {
      printf("%d - %d\n", lista->itens[i].chave,
             lista->itens[i].valor);
    }
  }
}

int inserir_fim(LISTA *lista, ITEM *item) {
  if (!cheia(lista)) {
    lista->fim++;
    lista->itens[lista->fim] = *item;
    return 1;
  } else {
    return 0;
  }
}

int inserir_posicao(LISTA *lista, int pos, ITEM *item) {
  int i;

  //verifica se existe espaço e se a posição está na lista
  if (!cheia(lista) && pos <= lista->fim + 1) {
    for (i = lista->fim; i >= pos; i--) { //movo os itens
      lista->itens[i + 1] = lista->itens[i];
    }

    lista->itens[pos] = *item; //insiro novo item
    lista->fim++; //incremento tamanho

    return 1;
  } else {
    return 0;
  }
}

int remover(LISTA *lista, int pos) {
  int i;

  if (pos <= lista->fim) {
    for (i = pos; i < lista->fim; i++) {
      lista->itens[i] = lista->itens[i + 1];
    }

    lista->fim--;

    return 1;
  } else {
    return 0;
  }
}

