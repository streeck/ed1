#include <stdio.h>
#include <stdlib.h>

#include "ListaLigadaOrdenada.h"

int main() {
  int i;

  //criar a lista
  LISTA_LIGADA lista;
  criar(&lista);

  //inserir itens na &lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = 9-i;
    item.valor = rand();
    inserir(&lista, &item);
  }

  imprimir(&lista);
  printf("---\n");

  ITEM item1;
  if (buscar(&lista, 4, &item1)) {
    printf("encontrado: %d - %d\n---\n", item1.chave, item1.valor);
  }

  remover_posicao(&lista, 5);

  imprimir(&lista);
  printf("---\n");

  ITEM item2;
  item2.chave = 4;
  item2.valor = 333;
  inserir(&lista, &item2);

  imprimir(&lista);
  printf("---\n");

  remover_fim(&lista);
  remover_fim(&lista);
  remover_fim(&lista);

  imprimir(&lista);
  printf("---\n");

  apagar_lista(&lista);

  return 0;
}
