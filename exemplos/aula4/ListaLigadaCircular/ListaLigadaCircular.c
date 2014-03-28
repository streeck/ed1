#include <stdio.h>
#include <stdlib.h>

#include "ListaLigadaCircular.h"

void criar(LISTA_LIGADA_CIRCULAR *lista) {
  lista->sentinela.proximo = &lista->sentinela;
  lista->fim = &lista->sentinela;
}

int vazia(LISTA_LIGADA_CIRCULAR *lista) {
  return (lista->sentinela.proximo == &lista->sentinela);
}

void apagar_lista(LISTA_LIGADA_CIRCULAR *lista) {
  NO *paux = lista->sentinela.proximo;

  while (paux != &lista->sentinela) {
    NO *prem = paux;
    paux = paux->proximo;
    free(prem);
  }

  lista->sentinela.proximo = &lista->sentinela;
  lista->fim = &lista->sentinela;
}

void imprimir(LISTA_LIGADA_CIRCULAR *lista) {
  NO *paux = lista->sentinela.proximo;

  while (paux != &lista->sentinela) {
    printf("%d - %d\n", paux->item.chave, paux->item.valor);
    paux = paux->proximo;
  }
}

int buscar(LISTA_LIGADA_CIRCULAR *lista, int chave, ITEM *item) {
  lista->sentinela.item.chave = chave; //atribui a chave ao sentinela

  NO *paux = &lista->sentinela;

  do {
    paux = paux->proximo;
  } while (paux->item.chave != chave);

  *item = paux->item; //retorno o valor encontrado

  return (paux != &lista->sentinela); //verifico se o valor não é a sentinela
}

int inserir_fim(LISTA_LIGADA_CIRCULAR *lista, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo nó

  if (pnovo != NULL) {
    pnovo->item = *item; //preencho os dados
    pnovo->proximo = &lista->sentinela; //defino que o próximo é a sentinela

    if (lista->fim == &lista->sentinela) { //se a lista for vazia
      lista->sentinela.proximo = pnovo; //inicio aponta para novo
    } else {
      lista->fim->proximo = pnovo; //proximo do fim aponta para novo
    }

    lista->fim = pnovo; //fim aponta para novo

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_LIGADA_CIRCULAR *lista) {
  if (!vazia(lista)) {
    NO *paux = &lista->sentinela;

    while (paux->proximo != lista->fim) {
      paux = paux->proximo;
    }

    free(paux->proximo);
    paux->proximo = &lista->sentinela;
    lista->fim = paux;

    return 1;
  } else {
    return 0;
  }
}

int remover_posicao(LISTA_LIGADA_CIRCULAR *lista, int pos) {
  int i;

  if (!vazia(lista)) { //verifico se a lista está vazia
    NO *paux = &lista->sentinela; //aponta para o elemento anterior a ser retirado

    for (i = 0; i < pos; i++) {
      if (paux->proximo != lista->fim) {
        paux = paux->proximo;
      } else {
        return 0;
      }
    }

    NO *prem = paux->proximo;
    paux->proximo = paux->proximo->proximo;

    if (prem->proximo == &lista->sentinela) { //retirei o último item
      lista->fim = paux;
    }

    free(prem);

    return 1;
  } else {
    return 0;
  }
}
