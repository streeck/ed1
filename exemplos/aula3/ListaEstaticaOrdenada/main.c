#include <stdio.h>
#include <stdlib.h>

#include "ListaEstaticaOrdenada.h"

int main() {
  int i;

  LISTA lista;
  criar(&lista);

  for (i = 0; i < 15; i++) {
    ITEM item;
    item.chave = rand()%15;
    item.valor = i;
    inserir_ordenado(&lista, &item);
  }

  imprimir(&lista);

  ITEM item;
  if (busca_binaria(&lista, 5, &item)) {
    printf("encontrado: %d - %d\n\n", item.chave, item.valor);
  }

  return 0;
}
