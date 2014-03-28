#ifndef LISTADUPLAMENTELIGADA_H_INCLUDED
#define LISTADUPLAMENTELIGADA_H_INCLUDED

typedef struct {
    int chave;
    int valor;
} ITEM;

typedef struct NO {
    ITEM item;
    struct NO *proximo;
    struct NO *anterior;
} NO;

typedef struct {
    NO *inicio;
    NO *fim;
} LISTA_DUPLAMENTE_LIGADA;

void criar(LISTA_DUPLAMENTE_LIGADA *lista);
int vazia(LISTA_DUPLAMENTE_LIGADA *lista);
void apagar_lista(LISTA_DUPLAMENTE_LIGADA *lista);
void imprimir(LISTA_DUPLAMENTE_LIGADA *lista);
void imprimir_inverso(LISTA_DUPLAMENTE_LIGADA *lista);
int buscar(LISTA_DUPLAMENTE_LIGADA *lista, int chave, ITEM *item);
int inserir_inicio(LISTA_DUPLAMENTE_LIGADA *lista, ITEM *item);
int inserir_fim(LISTA_DUPLAMENTE_LIGADA *lista, ITEM *item);
int remover_inicio(LISTA_DUPLAMENTE_LIGADA *lista);
int remover_fim(LISTA_DUPLAMENTE_LIGADA *lista);
int inserir_posicao(LISTA_DUPLAMENTE_LIGADA *lista, int pos, ITEM *item);
int remover_posicao(LISTA_DUPLAMENTE_LIGADA *lista, int pos);

#endif // LISTADUPLAMENTELIGADA_H_INCLUDED
