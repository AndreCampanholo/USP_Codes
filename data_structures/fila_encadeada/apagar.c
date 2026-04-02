#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
    NO *inicio;
    NO *final;
    int tamanho;
};

struct no {
    NO *proximo;
    ITEM *item;
};

void fila_apagar(FILA **f) {
    if(f == NULL || (*f) == NULL) {
        return;
    }
    if(fila_vazia(*f)) {
        free(*f);
        (*f) = NULL;
        return;
    } else {
        NO *aux;
        aux = (*f)->inicio;
        (*f)->inicio = aux->proximo;
        (*f)->tamanho--;
        item_apagar(&(aux->item));
        free(aux);
        aux = NULL;
        fila_apagar(f);
    }
}