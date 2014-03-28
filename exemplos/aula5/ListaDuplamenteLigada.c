#include <stdio.h>
#include <stdlib.h>

#include "ListaDuplamenteLigada.h"

void criar(LISTA_DUPLAMENTE_LIGADA *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
}

int vazia(LISTA_DUPLAMENTE_LIGADA *lista) {
  return (lista->inicio == NULL);
}

void apagar_lista(LISTA_DUPLAMENTE_LIGADA *lista) {
  if (!vazia(lista)) {
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

void imprimir(LISTA_DUPLAMENTE_LIGADA *lista) {
  NO *paux = lista->inicio;

  while (paux != NULL) {
    printf("%d - %d\n", paux->item.chave, paux->item.valor);
    paux = paux->proximo;
  }
}

void imprimir_inverso(LISTA_DUPLAMENTE_LIGADA *lista) {
  NO *paux = lista->fim; // aponta para o final da lista

  // enquanto nao chegar no inicio da lista
  while (paux != NULL) {
    printf("%d - %d\n", paux->item.chave, paux->item.valor);
    paux = paux->anterior;
  }

}

int buscar(LISTA_DUPLAMENTE_LIGADA *lista, int chave, ITEM *item) {
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

int inserir_inicio(LISTA_DUPLAMENTE_LIGADA *lista, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo n�

  if (pnovo != NULL) { //verifica se existe mem�ria dispon�vel
    //preencho os dados
    pnovo->item = *item;
    pnovo->proximo = lista->inicio;
    pnovo->anterior = NULL;

    if (lista->inicio != NULL) {
      lista->inicio->anterior = pnovo;
    } else {
      lista->fim = pnovo; //ajusta ponteiro para fim
    }

    lista->inicio = pnovo; //ajusta ponteiro in�cio

    return 1;
  } else {
    return 0;
  }
}

int inserir_fim(LISTA_DUPLAMENTE_LIGADA *lista, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo n�

  if (pnovo != NULL) { //verifica se existe mem�ria dispon�vel
    //preencho os dados
    pnovo->item = *item;
    pnovo->proximo = NULL;
    pnovo->anterior = lista->fim;

    if (lista->fim != NULL) {
      lista->fim->proximo = pnovo;
    } else {
      lista->inicio = pnovo; //ajusta ponteiro para in�cio
    }

    lista->fim = pnovo; //ajusta ponteiro fim

    return 1;
  } else {
    return 0;
  }
}


int remover_inicio(LISTA_DUPLAMENTE_LIGADA *lista) {
  if (!vazia(lista)) { //verifica se a lista n�o est� vazia
    NO *paux = lista->inicio;

    if (lista->inicio == lista->fim) { //lista com um elemento
      lista->inicio = NULL;
      lista->fim = NULL;
    } else { //lista com mais de um elemento
      lista->inicio->proximo->anterior = NULL;
      lista->inicio = lista->inicio->proximo;
    }

    free(paux); //removo o n� da mem�ria

    return 1;
  } else {
    return 0;
  }
}

int remover_fim(LISTA_DUPLAMENTE_LIGADA *lista) {
  if (!vazia(lista)) { //verifica se a lista n�o est� vazia
    NO *paux = lista->fim;

    if (lista->inicio == lista->fim) { //lista com um elemento
      lista->inicio = NULL;
      lista->fim = NULL;
    } else { //lista com mais de um elemento
      lista->fim->anterior->proximo = NULL;
      lista->fim = lista->fim->anterior;
    }

    free(paux); //removo o n� da mem�ria

    return 1;
  } else {
    return 0;
  }
}

int inserir_posicao(LISTA_DUPLAMENTE_LIGADA *lista, int pos, ITEM *item) {
  int i;

  if (!vazia(lista)) { //verifica se a lista n�o est� vazia
    NO *pnovo = (NO *)malloc(sizeof(NO)); //crio um novo n�

    if (pnovo != NULL) { //verifica se existe mem�ria dispon�vel
      //preencho os dados
      pnovo->item = *item;

      if (pos == 0) { //adiciona na primeira posi��o
        pnovo->proximo = lista->inicio;
        lista->inicio->anterior = pnovo;
        lista->inicio = pnovo;
      } else {
        NO *paux = lista->inicio;

        //encontro a posi��o de inser��o
        for (i = 0; i < pos; i++) {
          if (paux != lista->fim) {
            paux = paux->proximo;
          } else {
            return 0;
          }
        }

        //faz as liga��es para a inser��o do novo elemento
        pnovo->proximo = paux;
        pnovo->anterior = paux->anterior;
        paux->anterior->proximo = pnovo;
        paux->anterior = pnovo;
      }

      return 1;
    }
  }

  return 0;
}

int remover_posicao(LISTA_DUPLAMENTE_LIGADA *lista, int pos) {
  if (!vazia(lista)) { //verifico se a lista est� vazia
    int i;
    NO *paux = lista->inicio;

    //encontro a posi��o de remo��o
    for (i = 0; i < pos; i++) {
      if (paux != lista->fim) {
        paux = paux->proximo;
      } else { //posi��o fora da lista
        return 0;
      }
    }

    if (paux == lista->inicio) { //remove o primeiro item
      lista->inicio = paux->proximo;
    } else { //remove item no meio da lista
      paux->anterior->proximo = paux->proximo;
    }

    if (paux == lista->fim) { //remove o �ltimo item
      lista->fim = paux->anterior;
    } else { //remove item no meio da lista
      paux->proximo->anterior = paux->anterior;
    }

    free(paux); //remove o item da mem�ria

    return 1;
  }

  return 0;
}
