#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

#define TAM 100

//representa o item armazenado
typedef struct{
  int chave;
  int valor;
} ITEM;

//representa a lista de itens
typedef struct{
  ITEM itens[TAM];
  int fim;
} LISTA;

void criar(LISTA *lista);
void imprime(LISTA *lista);
int vazia(LISTA *lista);
int cheia(LISTA *lista);
int inserir_fim(LISTA *lista, ITEM *item);
int inserir_posicao(LISTA *lista, int pos, ITEM *item);
int remover(LISTA *lista, int pos);
int tamanho(LISTA *lista);

#endif // LISTAESTATICA_H_INCLUDED
