#ifndef LISTALIGADACIRCULAR_H_INCLUDED
#define LISTALIGADACIRCULAR_H_INCLUDED

typedef struct {
  int chave;
  int valor;
} ITEM;

typedef struct NO {
  ITEM item;
  struct NO *proximo;
} NO;

typedef struct {
  NO sentinela;
  NO *fim;
} LISTA_LIGADA_CIRCULAR;

void criar(LISTA_LIGADA_CIRCULAR *lista);
int vazia(LISTA_LIGADA_CIRCULAR *lista);
void apagar_lista(LISTA_LIGADA_CIRCULAR *lista);
void imprimir(LISTA_LIGADA_CIRCULAR *lista);
int buscar(LISTA_LIGADA_CIRCULAR *lista, int chave, ITEM *item);
int inserir_fim(LISTA_LIGADA_CIRCULAR *lista, ITEM *item);
int remover_fim(LISTA_LIGADA_CIRCULAR *lista);
int remover_posicao(LISTA_LIGADA_CIRCULAR *lista, int pos);

#endif // LISTALIGADACIRCULAR_H_INCLUDED
