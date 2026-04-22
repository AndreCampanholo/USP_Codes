#include "fila.h"
#include "item.h"
#include <stdlib.h>

#define TAM 11

struct fila {
    ITEM *seq[TAM];
    int inicio;
    int final;
    int tamanho;
};

FILA *fila_criar(void) {
    FILA *f = (FILA *)malloc(sizeof(FILA));
    if(f != NULL) {
        f->inicio = 0;
        f->final = 0;
        f->tamanho = 0;
        return f;
    }
    return NULL;
}

void fila_apagar(FILA **f) {
    if(f != NULL && *f != NULL) {
        while(!fila_vazia(*f)) {
            item_apagar(&(*f)->seq[(*f)->inicio]);
            (*f)->seq[(*f)->inicio] = NULL;
            ((*f)->inicio) = ((*f)->inicio + 1) % TAM;
            (*f)->tamanho--;
        } 
        free(*f);
        (*f) = NULL;
    }
}

bool fila_inserir(FILA *f, ITEM *it) {
    if(f != NULL && !fila_cheia(f)) {
        f->seq[f->final] = it;
        f->final = (f->final + 1) % TAM;
        f->tamanho++;
        return true;
    }
    return false;
}

ITEM *fila_remover(FILA *f) {
    if(f != NULL && !fila_vazia(f)) {
        ITEM *it = f->seq[f->inicio];
        f->seq[f->inicio] = NULL;
        f->inicio = (f->inicio + 1) % TAM;
        f->tamanho--;
        return it;
    }
    return NULL;
}

ITEM *fila_frente(FILA *f) {
    if(f != NULL && !fila_vazia(f)) {
        ITEM *it = f->seq[f->inicio];
        return it;
    }
    return NULL;
}

ITEM *fila_atras(FILA *f) {
    if(f != NULL && !fila_vazia(f)) {
        ITEM *it = f->seq[(f->final - 1 + TAM) % TAM];
        return it;
    }
    return NULL;
}

int fila_tamanho(FILA *f) {
    if(f != NULL) {
        return f->tamanho;
    }
    return -1;
}

bool fila_vazia(FILA *f) {
    if(f != NULL && f->tamanho == 0) {
        return true;
    }
    return false;
}

bool fila_cheia(FILA *f) {
    if(f != NULL && f->tamanho >= TAM) {
        return true;
    }
    return false;
}