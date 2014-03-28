#include <stdio.h>
#include <stdlib.h>

#include "ListaEstatica.h"

int main() {
  int i;

  LISTA lista;
  criar(&lista);

  for (i = 0; i < 5; i++) {
    ITEM item;
    item.chave = i;
    item.valor = 1;
    inserir_fim(&lista, &item);
  }

  imprime(&lista);

  printf("tamanho: %d\n--\n", tamanho(&lista));

  ITEM item1;
  item1.chave = 5;
  item1.valor = 2;
  inserir_posicao(&lista, 0, &item1);

  imprime(&lista);

  printf("tamanho: %d\n--\n", tamanho(&lista));

  ITEM item2;
  item2.chave = 6;
  item2.valor = 3;
  inserir_posicao(&lista, 3, &item2);

  imprime(&lista);

  printf("tamanho: %d\n--\n", tamanho(&lista));

  ITEM item3;
  item3.chave = 7;
  item3.valor = 4;
  inserir_posicao(&lista, 7, &item3);

  imprime(&lista);

  printf("tamanho: %d\n--\n", tamanho(&lista));

  return 0;
}
