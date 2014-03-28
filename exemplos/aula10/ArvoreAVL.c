#include "ArvoreAVL.h"

#include <stdlib.h>
#include <stdio.h>


void criar_arvore_avl(ARVORE_AVL *arv) {
  arv->raiz = NULL;
}


void limpar_arvore_avl_aux(NO *raiz) {
  if (raiz != NULL) {
    limpar_arvore_avl_aux(raiz->fesq);
    limpar_arvore_avl_aux(raiz->fdir);
    free(raiz);
  }
}

void limpar_arvore_avl(ARVORE_AVL *arv) {
  limpar_arvore_avl_aux(arv->raiz);
  arv->raiz = NULL;
}


void preordem_aux(NO *raiz) {
  if (raiz != NULL) {
    printf("%d\n", raiz->info.chave);
    preordem_aux(raiz->fesq);
    preordem_aux(raiz->fdir);
  } else {
    printf("NULL\n");
  }
}

void preordem(ARVORE_AVL *arv) {
  preordem_aux(arv->raiz);
  printf("-----------\n");
}

/*==================*/
/* ROTACOES SIMPLES */
/*==================*/

NO *rot_dir(NO *no) {
  NO *aux = no->fesq;

  if (no->pai != NULL) { //verifica se no não é a raiz da árvore
    if (no->pai->fesq == no)
      no->pai->fesq = aux;
    else
      no->pai->fdir = aux;
  }

  aux->pai = no->pai;
  no->fesq = aux->fdir;
  if (no->fesq != NULL) no->fesq->pai = no;
  aux->fdir = no;
  no->pai = aux;

  return(aux);
}

NO *rot_esq(NO *no) {
  NO *aux = no->fdir;

  if (no->pai != NULL) { //verifica se no não é a raiz
    if (no->pai->fesq == no)
      no->pai->fesq = aux;
    else
      no->pai->fdir = aux;
  }

  aux->pai = no->pai;
  no->fdir = aux->fesq;
  if (no->fdir != NULL) no->fdir->pai = no;
  aux->fesq = no;
  no->pai = aux;

  return(aux);
}

/*=================*/
/* ROTACOES DUPLAS */
/*=================*/

NO *rot_esq_dir(NO *no) {
  rot_esq(no->fesq);
  return(rot_dir(no));
}

NO *rot_dir_esq(NO *no) {
  rot_dir(no->fdir);
  return(rot_esq(no));
}

/*====================*/
/* ROTINA DE INSERCAO */
/*====================*/

NO *inserir_arvore_avl_aux(NO *raiz, INFO *info, int *atualiza_fb) {
  if (raiz == NULL) {
    raiz = (NO *) malloc(sizeof(NO));
    raiz->fesq = raiz->fdir = raiz->pai = NULL;
    raiz->info = *info;
    raiz->fb = 0;
    *atualiza_fb = 1; //inseriu, atualiza os fbs
  } else {
    if (raiz->info.chave > info->chave) { //desce pela esquerda
      raiz->fesq = inserir_arvore_avl_aux(raiz->fesq, info, atualiza_fb);
      raiz->fesq->pai = raiz;

      if (*atualiza_fb) {
        switch (raiz->fb) {
        case -1:
          raiz->fb = 0;
          *atualiza_fb = 0;
          break;
        case 0:
          raiz->fb = 1;
          break;
        case 1:
          if (raiz->fesq->fb == 1) { //sinais iguais, rotação simples
            raiz = rot_dir(raiz);
            raiz->fb = 0;
            raiz->fdir->fb = 0;
          } else { //rotação dupla
            raiz = rot_esq_dir(raiz);

            if (raiz->fb == 1) {
              raiz->fesq->fb = 0;
              raiz->fdir->fb = -1;
            } else {
              raiz->fesq->fb = 1;
              raiz->fdir->fb = 0;
            }

            raiz->fb = 0;
          }

          *atualiza_fb = 0;
          break;
        }
      }
    } else { //desce pela direita
      raiz->fdir = inserir_arvore_avl_aux(raiz->fdir, info, atualiza_fb);
      raiz->fdir->pai = raiz;

      if (*atualiza_fb) {
        switch (raiz->fb) {
        case -1:
          if (raiz->fdir->fb == -1) { //sinais iguais, rotação simples
            raiz = rot_esq(raiz);
            raiz->fb = 0;
            raiz->fesq->fb = 0;
          } else { //rotação dupla
            raiz = rot_dir_esq(raiz);

            if (raiz->fb == 1) {
              raiz->fesq->fb = 0;
              raiz->fdir->fb = -1;
            } else {
              raiz->fesq->fb = 1;
              raiz->fdir->fb = 0;
            }

            raiz->fb = 0;
          }

          *atualiza_fb = 0;
          break;
        case 0:
          raiz->fb = -1;
          break;
        case 1:
          raiz->fb = 0;
          *atualiza_fb = 0;
          break;
        }
      }
    }
  }

  return(raiz);
}

void inserir_arvore_avl(ARVORE_AVL *arv, INFO *info) {
  int atualiza_fb = 0;
  arv->raiz = inserir_arvore_avl_aux(arv->raiz, info, &atualiza_fb);
}
