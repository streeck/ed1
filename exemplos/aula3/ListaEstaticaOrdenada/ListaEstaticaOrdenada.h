#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED

#define TAM 100

typedef struct {
  int chave;
  int valor;
} ITEM ;

typedef struct {
  ITEM itens[TAM];
  int fim;
} LISTA;

void criar(LISTA *lista);
void imprimir(LISTA *lista);
int vazia(LISTA *lista);
int cheia(LISTA *lista);
int tamanho(LISTA *lista);

int inserir_ordenado(LISTA *lista, ITEM *item);
int busca_sequencial(LISTA *lista, int chave, ITEM *item);
int busca_binaria(LISTA *lista, int chave, ITEM *item);

#endif // LISTAORDENADA_H_INCLUDED
