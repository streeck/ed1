#include <stdio.h>
#include <stdlib.h>

#include "ListaLigada.h"

int main() {
  int i;

  //criar a lista
  LISTA_LIGADA lista;
  criar(&lista);

  //inserir itens na lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = i;
    item.valor = rand();
    inserir(&lista, &item);
  }

  printf("--- Lista --- \n");
  imprimir(&lista);

  ITEM item;
  if (buscar(&lista, 5, &item)){
    printf("\nEncontrado: %d - %d\n", item.chave, item.valor);
  }

  for (i = 0; i < 10; i++) {
    remover_fim(&lista);
  }

  apagar_lista(&lista);

  return 0;
}
