#include <stdio.h>
#include <stdlib.h>

#include "ArvoreAVL.h"

int main() {

  ARVORE_AVL arv;
  
  criar_arvore_avl(&arv);

  int valores[] = {10, 5, 20, 1, 3, 4, 8, 30, 40, 35, 50, 45, 55, 51, 99};

  int i;
  for (i=0; i < 10; i++) {
    INFO info;
    info.chave = valores[i];
    info.valor = valores[i];
    inserir_arvore_avl(&arv, &info);
  }

  preordem(&arv);

  limpar_arvore_avl(&arv);

  return 0;
}
