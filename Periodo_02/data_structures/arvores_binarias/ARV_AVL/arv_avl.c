#include "arv_avl.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no NO;
struct no {
    ITEM *item;
    NO *esq;
    NO *dir;
    int altura;
};

struct avl {
    NO *raiz;
};

//Funções Auxiliares

void avl_apagar_aux(NO *raiz) {
    if(raiz != NULL) {
        avl_apagar_aux(raiz->esq);
        avl_apagar_aux(raiz->dir);
        item_apagar(&(raiz->item));
        free(raiz);
    }
}

int avl_altura_no(NO *raiz) {
    if(raiz != NULL) {
        return raiz->altura;
    }
    return -1;
}

NO *avl_cria_no(ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));
    if(novo != NULL) {
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->item = it;
    }
    return novo;
}

NO *rotacao_direita(NO *a) {
    if(a != NULL) {
        NO *b = a->esq;

        a->esq = b->dir;
        b->dir = a;

        a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
        b->altura = max(avl_altura_no(b->esq), avl_altura_no(b->dir)) + 1;
        
        return b;
    }
    return NULL;
}

NO *rotacao_esquerda(NO *a) {
    if(a != NULL) {
        NO *b = a->dir;

        a->dir = b->esq;
        b->esq = a;

        a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
        b->altura = max(avl_altura_no(b->esq), avl_altura_no(b->dir)) + 1;
        
        return b;
    }
    return NULL;
}

NO *rotacao_esquerda_direita(NO *a) {
    if(a != NULL) {
        a->esq = rotacao_esquerda(a->esq);
        return rotacao_direita(a);
    }
    return NULL;
}

NO *rotacao_direita_esquerda(NO *a) {
    if(a != NULL) {
        a->dir = rotacao_direita(a->dir);
        return rotacao_esquerda(a);
    }
    return NULL;
}

NO *avl_inserir_no(NO *raiz, ITEM *it) {
    if(raiz == NULL) {
        //Encontrou o local certo para inserir novo elemento
        raiz = avl_cria_no(it);
    } else if(item_get_chave(it) < item_get_chave(raiz->item)) {
        //Chave é menor do que do nó atual, buscar à esquerda
        raiz->esq = avl_inserir_no(raiz->esq, it);
    } else if(item_get_chave(it) > item_get_chave(raiz->item)) {
        //Chave é menor do que do nó atual, buscar à direita
        raiz->dir = avl_inserir_no(raiz->dir, it);
    } else {
        //Chave já existe, retorna nó raiz da árvore
        return raiz;
    }

    int altura_esq = avl_altura_no(raiz->esq), altura_dir = avl_altura_no(raiz->dir);
    raiz->altura = max(altura_esq, altura_dir) + 1;

    int fator_balanceamento = altura_esq - altura_dir;

    //Aplica rotações se necessário, para manter estrutura de AVL
    if(fator_balanceamento == -2) {
        if(avl_altura_no(raiz->dir->esq) - avl_altura_no(raiz->dir->dir) <= 0) {
            raiz = rotacao_esquerda(raiz);
        } else {
            raiz = rotacao_direita_esquerda(raiz);
        }
    } else if(fator_balanceamento == 2) {
        if(avl_altura_no(raiz->esq->esq) - avl_altura_no(raiz->esq->dir) >= 0) {
            raiz = rotacao_direita(raiz);
        } else {
            raiz = rotacao_esquerda_direita(raiz);
        }
    }

    return raiz;
}

void troca_max_esq(NO *troca, NO* raiz, NO* ant) {
    if(troca->dir != NULL) {
        troca_max_esq(troca->dir, raiz, troca);
    } else {
        if(raiz == ant)
            ant->esq = troca->esq;
        else
            ant->dir = troca->esq;

        item_apagar(&(raiz->item));
        raiz->item = troca->item;
        free(troca);
        troca = NULL;
    }
}

NO *avl_remover_no(NO *raiz, int chave) {
    if(raiz == NULL) return NULL;

    NO *p;
    if(chave == item_get_chave(raiz->item)) {
        if(raiz->esq == NULL || raiz->dir == NULL) {
            //caso em que raiz tem 0 ou 1 filho
            p = raiz;
            if(raiz->esq == NULL)
                raiz = raiz->dir;
            else
                raiz = raiz->esq;
            item_apagar(&(p->item));
            free(p);
            p = NULL;
        } else {
            //caso em que raiz tem 2 filhos
            troca_max_esq(raiz->esq, raiz, raiz);
        }
    } else if(chave < item_get_chave(raiz->item)) {
        raiz->esq = avl_remover_no(raiz->esq, chave);
    } else {
        raiz->dir = avl_remover_no(raiz->dir, chave);
    }

    if(raiz != NULL) {
        raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1;
        int fator_balanceamento = avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir);
        if(fator_balanceamento == 2) {
            if(avl_altura_no(raiz->esq->esq) - avl_altura_no(raiz->esq->dir) >= 0)
                raiz = rotacao_direita(raiz);
            else
                raiz = rotacao_esquerda_direita(raiz);
        } else if(fator_balanceamento == -2) {
            if(avl_altura_no(raiz->dir->esq) - avl_altura_no(raiz->dir->dir) <= 0)
                raiz = rotacao_esquerda(raiz);
            else
                raiz = rotacao_direita_esquerda(raiz);
        }
    }

    return raiz;
}

//Funções Principais/Interface

AVL *avl_criar(void) {
    AVL *arv = (AVL *)malloc(sizeof(AVL));
    if(arv != NULL) {
        arv->raiz = NULL;
    }
    return arv;
}

void avl_apagar(AVL **arv) {
    if(arv != NULL && *arv != NULL) {
        avl_apagar_aux((*arv)->raiz);
        free(*arv);
        *arv = NULL;
    }
}

bool avl_inserir(AVL *arv, ITEM *it) {
    return (arv->raiz = avl_inserir_no(arv->raiz, it) != NULL);
}

bool avl_remover(AVL *arv, int chave) {
    if(arv == NULL || arv->raiz == NULL) return false;
    arv->raiz = avl_remover_no(arv->raiz, chave);
    return true;
}