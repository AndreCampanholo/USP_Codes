#include "fila.h"
#include <stdlib.h>

#define TAM 10

//nome da struct é fila porém sua estrutura interna é uma pilha, as funções também
struct fila {
    NO *topo;
    int tamanho;
};

typedef struct no NO;

struct no {
    ITEM *conteudo;
    NO *anterior;
};

FILA *fila_criar(void) {
    FILA *fila = (FILA *)malloc(sizeof(FILA));
    if(fila != NULL) {
        fila->topo = NULL;
        fila->tamanho = 0;
        
        return fila;
    }
    return NULL;
}

ITEM *fila_remover(FILA *f) {
    if(f == NULL || fila_vazia(f)) {
        return NULL;
    }

    ITEM *aux = f->topo->conteudo;
    NO *temp = f->topo;
    f->topo = f->topo->anterior;
    temp->anterior = NULL;
    
    free(temp);
    temp = NULL;

    f->tamanho--;

    return aux;
}

bool fila_inserir(FILA *f, ITEM *it) {
    if(f == NULL || it == NULL || fila_cheia(f))
        return false;

    if(fila_vazia(f)) {
        NO *novo = (NO *)malloc(sizeof(NO));
        if(novo == NULL) 
            return false;

        novo->anterior = f->topo;
        novo->conteudo = it;
        f->topo = novo;
        f->tamanho++;

        return true;
    }

    FILA *aux = fila_criar();
    if(aux == NULL) 
        return NULL;
    
    while(!fila_vazia(f)) { 
        NO *novo = (NO *)malloc(sizeof(NO));

        novo->conteudo = fila_remover(f);
        novo->anterior = aux->topo;
        aux->topo = novo;
        aux->tamanho++;
    }

    NO *novo = (NO *)malloc(sizeof(NO));
    novo->conteudo = it;
    novo->anterior = aux->topo;
    aux->topo = novo;
    aux->tamanho++;

    while(aux != NULL) {
        if(fila_vazia(aux)) {
            fila_apagar(&aux);
        } else {
            NO *novo = (NO *)malloc(sizeof(NO));

            novo->conteudo = fila_remover(aux);
            novo->anterior = f->topo;
            f->topo = novo;
            f->tamanho++;
        }
    }

    return true;
}

void fila_apagar(FILA **f) {
    if(f != NULL && *f != NULL) {
        while(!fila_vazia(*f)) {
            fila_remover(*f);
        }
        free(*f);
        *f = NULL;
    }
    return;
}

bool fila_cheia(FILA *fila) {
    if(fila != NULL && fila->tamanho >= TAM) {
        return true;
    }
    return false;
}

bool fila_vazia(FILA *fila) {
    if(fila != NULL && fila->topo == NULL) {
        return true;
    }
    return false;
}