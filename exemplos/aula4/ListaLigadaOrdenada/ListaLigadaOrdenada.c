#include <stdio.h>
#include <stdlib.h>

#include "ListaLigadaOrdenada.h"

void criar(LISTA_LIGADA *lista) {
  lista->cabeca.proximo = NULL;
}

int vazia(LISTA_LIGADA *lista) {
  return (lista->cabeca.proximo == NULL);
}

void apagar_lista(LISTA_LIGADA *lista) {
  NO *paux = lista->cabeca.proximo;

  while (paux != NULL) {
    NO *prem = paux;
    paux = paux->proximo;
    free(prem);
  }

  lista->cabeca.proximo = NULL;
}

void imprimir(LISTA_LIGADA *lista) {
  NO *paux = lista->cabeca.proximo;

  while (paux != NULL) {
    printf("%d - %d\n", paux->item.chave, paux->item.valor);
    paux = paux->proximo;
  }
}

int buscar(LISTA_LIGADA *lista, int chave, ITEM *item) {
  NO *paux = lista->cabeca.proximo;

  while (paux != NULL) { //precorre a lista
    if (paux->item.chave == chave) { //se a chave for igual
      *item = paux->item;
      return 1;
    } else if (paux->item.chave > chave) { //se a chave na lista for maior
      return 0;
    }

    paux = paux->proximo;
  }

  return 0;
}

int inserir(LISTA_LIGADA *lista, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo nó

  if (pnovo != NULL) {
    pnovo->item = *item; //preencho os dados
    pnovo->proximo = NULL; //defino que o próximo é nulo

    NO *paux = &lista->cabeca; //armazena posição anterior da de inserção

    while ((paux->proximo != NULL) &&
           (paux->proximo->item.chave < item->chave)) {
      paux = paux->proximo;
    }

    pnovo->proximo = paux->proximo;
    paux->proximo = pnovo;

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_LIGADA *lista) {
  if (!vazia(lista)) {
    NO *paux = &lista->cabeca;

    while (paux->proximo->proximo != NULL) {
      paux = paux->proximo;
    }

    NO *prem = paux->proximo;
    paux->proximo = NULL;
    free(prem);

    return 1;
  } else {
    return 0;
  }
}

int remover_posicao(LISTA_LIGADA *lista, int pos) {
  int i;

  if (!vazia(lista)) { //verifico se a lista está vazia
    NO *paux = &lista->cabeca; //aponta para o elemento anterior a ser retirado

    for (i = 0; i < pos; i++) {
      if (paux->proximo->proximo != NULL) {
        paux = paux->proximo;
      } else {
        return 0;
      }
    }

    NO *prem = paux->proximo;
    paux->proximo = paux->proximo->proximo;
    free(prem);

    return 1;
  } else {
    return 0;
  }
}


