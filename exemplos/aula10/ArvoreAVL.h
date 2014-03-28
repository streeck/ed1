#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

typedef struct {
  int chave;
  int valor;
} INFO;


typedef struct NO {
  INFO info;
  int fb; 			//fator de balanceamento
  struct NO *pai; 	//ponteiro para o pai
  struct NO *fesq; 	//ponteiro para o filho da esquerda
  struct NO *fdir; 	//ponteiro para o filho da direita
} NO;


typedef struct {
  NO *raiz;
} ARVORE_AVL;


void criar_arvore_avl(ARVORE_AVL *arv);
void limpar_arvore_avl(ARVORE_AVL *arv);
void limpar_arvore_avl_aux(NO *raiz);
void preordem_aux(NO *raiz);
void preordem(ARVORE_AVL *arv);
void inserir_arvore_avl(ARVORE_AVL *arv, INFO *info);

#endif // ARVOREAVL_H_INCLUDED
