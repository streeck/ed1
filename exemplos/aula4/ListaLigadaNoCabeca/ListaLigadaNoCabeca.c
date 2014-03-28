#include <stdio.h>
#include <stdlib.h>

#include "ListaLigadaNoCabeca.h"

void criar(LISTA_LIGADA *lista) {
  lista->cabeca.proximo = NULL;
  lista->fim = NULL;
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
  lista->fim = NULL;
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

  while (paux != NULL) {
    if (paux->item.chave == chave) {
      *item = paux->item;
      return 1;
    }

    paux = paux->proximo;
  }

  return 0;
}

int inserir_fim(LISTA_LIGADA *lista, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo nó

  if (pnovo != NULL) {
    pnovo->item = *item; //preencho os dados
    pnovo->proximo = NULL; //defino que o próximo é nulo

    if (lista->fim == NULL) { //se a lista for vazia
      lista->cabeca.proximo = pnovo; //inicio aponta para novo
    } else {
      lista->fim->proximo = pnovo; //proximo do fim aponta para novo
    }

    lista->fim = pnovo; //fim aponta para novo

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_LIGADA *lista) {
  if (!vazia(lista)) {
    NO *paux  = &lista->cabeca;

    while (paux->proximo != lista->fim) {
      paux = paux->proximo;
    }

    free(paux->proximo);
    paux->proximo = NULL;
    lista->fim = paux;

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
      if (paux->proximo != lista->fim) {
        paux = paux->proximo;
      } else {
        return 0;
      }
    }

    NO *prem = paux->proximo;
    paux->proximo = paux->proximo->proximo;

    if (prem->proximo == NULL) { //retirei o último item
      lista->fim = paux;
    }

    free(prem);

    return 1;
  } else {
    return 0;
  }
}

