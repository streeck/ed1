#include <stdio.h>
#include <stdlib.h>

#include "ListaDuplamenteLigada.h"

int main() {
  int i;

  //criar a &lista
  LISTA_DUPLAMENTE_LIGADA lista;
  criar(&lista);

  //inserir itens na &lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = i;
    item.valor = rand();
    if (i%2==0) {
      inserir_inicio(&lista, &item);
    } else {
      inserir_fim(&lista, &item);
    }
  }

  imprimir(&lista);
  printf("---\n");
  imprimir_inverso(&lista);
  printf("---\n");

  {
    ITEM item;
    if (buscar(&lista, 8, &item)) {
      printf("encontrado: %d - %d\n---\n", item.chave, item.valor);
    }

    for (i = 0; i < 3; i++) {
      remover_inicio(&lista);
    }
  }

  // tenta inserir novo ITEM em posicao invalida
  ITEM item;
  item.chave = rand();
  item.valor = 111;
  inserir_posicao(&lista, 9, &item);
  

  imprimir(&lista);
  printf("---\n");

  // insere 5 itens no final da lista
  for (i = 0; i < 5; i++) {
    ITEM item;
    item.chave = rand();
    item.valor = i;
    inserir_fim(&lista, &item);
  }

  imprimir(&lista);
  printf("---\n");

  // remove 3 ultimos itens da lista
  for (i = 0; i < 3; i++) {
    remover_fim(&lista);
  }

  // remove o primeiro no
  remover_posicao(&lista, 0);

  imprimir(&lista);
  printf("---\n");

  apagar_lista(&lista);

  return 0;
}
