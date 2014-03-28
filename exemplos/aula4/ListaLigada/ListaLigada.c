#include <stdio.h>
#include <stdlib.h>

#include "ListaLigada.h"

// inicializa campos inicio e fim da LISTA com NULL
void criar(LISTA_LIGADA *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
}

// verifica se inicio da lista � NULL
int vazia(LISTA_LIGADA *lista) {
  return (lista->inicio == NULL);
}

void imprimir(LISTA_LIGADA *lista) {
  NO *paux = lista->inicio;

  while (paux != NULL) {
    printf("%d - %d\n", paux->item.chave, paux->item.valor);
    paux = paux->proximo;
  }
}

void apagar_lista(LISTA_LIGADA *lista){
  if (!vazia(lista)){
    NO *paux = lista->inicio;
  
    while (paux != NULL) {
      NO *prem = paux;
      paux = paux->proximo;
      free(prem);
    } 
  }
  
  lista->inicio = NULL;
  lista->fim = NULL;
}

int buscar(LISTA_LIGADA *lista, int chave,  ITEM *item) {
  NO *paux = lista->inicio;

  while (paux != NULL) {
    if (paux->item.chave == chave) {
      *item = paux->item;
      return 1;
    }
    paux = paux->proximo;
  }

  return 0;
}

// Insere na ultima posicao
int inserir(LISTA_LIGADA *lista, ITEM *item) {
  //cria um novo n�
  NO *pnovo = (NO *)malloc(sizeof(NO));

  if (pnovo != NULL) { //verifica se a mem�ria foi alocada
    pnovo->item = *item; //preenche os dados
    pnovo->proximo = NULL; //define que o pr�ximo � nulo

    if (vazia(lista)) { //se a lista for vazia
      lista->inicio = pnovo; //inicio aponta para novo
    } else {
      lista->fim->proximo = pnovo; //proximo do fim aponto para novo
    }

    lista->fim = pnovo; //fim aponta para novo

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_LIGADA *lista) {
  if (!vazia(lista)) {
    //procura o pen�ltimo n�
    NO *paux  = lista->inicio;
    while (paux->proximo != NULL && paux->proximo != lista->fim) {
      paux = paux->proximo;
    }

    if (lista->inicio == lista->fim) {//a lista tem um n�
      free(paux->proximo); //libera o �nico n�
      lista->inicio = lista->fim = NULL; //lista vazia
    } else {
      free(lista->fim); //libera �ltimo n�
      lista->fim = paux; //pen�ltimo n� vira �ltimo
      lista->fim->proximo = NULL;
    }

    return 1;
  } else {
    return 0;
  }
}

