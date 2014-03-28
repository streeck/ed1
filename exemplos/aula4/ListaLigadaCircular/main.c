#include <stdio.h>
#include <stdlib.h>

#include "ListaLigadaCircular.h"

int main() {
int i;

  //criar a lista
  LISTA_LIGADA_CIRCULAR lista;
  criar(&lista);

  //inserir itens na &lista
  for (i = 0; i < 10; i++) {
    ITEM item;
    item.chave = i;
    item.valor = rand();
    inserir_fim(&lista, &item);
  }

  imprimir(&lista);

  ITEM item1;
  if (buscar(&lista, 9, &item1)) {
    printf("encontrado: %d - %d\n---\n", item1.chave, item1.valor);
  }

  remover_posicao(&lista, 9);

  ITEM item2;
  item2.chave = 111;
  item2.valor = 333;
  inserir_fim(&lista, &item2);

  imprimir(&lista);

  apagar_lista(&lista);

  return 0;
}
