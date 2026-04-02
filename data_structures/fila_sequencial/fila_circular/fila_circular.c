#include "fila.h"
#include "item.h"
#include <stdlib.h>

#define TAM 10

struct fila {
    ITEM *fila_circular[TAM + 1];
    int inicio;
    int fim;
};

FILA *fila_criar(void) {
    FILA *f = (FILA *)malloc(sizeof(FILA));
    if(f != NULL) {
        f->inicio = 0;
        f->fim = 0;
    }
    return f;
}

void fila_apagar(FILA **f) {
    if(f != NULL && *f != NULL) {
        while(!fila_vazia(*f)) {
            fila_remover(*f);
        }
        free(*f);
        *f = NULL;
    }
}

//Implementando novamente para fixação

bool fila_inserir(FILA *f, ITEM *it) {
    if(f != NULL && !fila_cheia(f)) {
        f->fila_circular[f->fim] = it;
        f->fim = (f->fim + 1) % (TAM + 1);
        return true;
    }
    return false;
}

void fila_apagar(FILA **f) {
    if(f != NULL && *f != NULL) {
        while(!fila_vazia(*f)) {
            fila_remover(*f);
        }
        free(*f);
        *f = NULL;
    }
}

ITEM *fila_remover(FILA *f) {
    if(f == NULL || fila_vazia(f)) {
        return NULL;
    }

    ITEM *aux = f->fila_circular[f->inicio];
    f->inicio = (f->inicio + 1) % (TAM + 1);
    return aux;
}

bool fila_cheia(FILA *f) {
    if(f != NULL && f->fim == (f->inicio + TAM) % (TAM + 1)) {
        return true;
    }
    return false;
}

bool fila_vazia(FILA *f) {
    if(f != NULL && f->fim == f->inicio) {
        return true;
    }
    return false;
}

ITEM *fila_frente(FILA *f) {
    if(f != NULL && !fila_vazia(f)) {
        return f->fila_circular[f->inicio];
    }
    return NULL;
}

ITEM *fila_atras(FILA *f) {
    if(f != NULL && !fila_vazia(f)) {
        return f->fila_circular[f->fim];
    }
    return NULL;
}

int fila_tamanho(FILA *f) {
    if(f == NULL) {
        return -1;
    }
    return (f->fim - f->inicio + (TAM + 1)) % (TAM + 1);
}