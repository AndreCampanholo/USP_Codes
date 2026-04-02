#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>

#define TAM 100

struct lista {
    ITEM *lista[TAM];
    int inicio;
    int fim;
    int tamanho;
    bool ordenada;
};

LISTA *lista_criar(bool ordenada) {
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));
    if(l != NULL) {
        l->inicio = 0;
        l->fim = 0;
        l->tamanho = 0;
        l->ordenada = ordenada;
    }
    return l;
}

bool lista_inserir_fim(LISTA *l, ITEM *it) {
    if(l != NULL) {
        l->lista[l->fim] = it;
        l->fim++;
        l->tamanho++;
        return 1;
    }
    return 0;
}

int lista_busca_sequencial(LISTA *l, int x) {
    if(l != NULL && !lista_vazia(l) && !l->ordenada) {
        for(int i = 0; i < l->fim; i++) {
            if(item_get_chave(l->lista[i]) == x) {
                return i;
            }
        }
    } else if(l != NULL && !lista_vazia(l) && l->ordenada) {
        for(int i = 0; i < l->fim || item_get_chave(l->lista[i]) >= x; i++) {
            if(item_get_chave(l->lista[i]) == x) {
                return i;
            }
        }
    }
    return -1;
}

bool lista_inserir_posicao(LISTA *l, int posicao, ITEM *it) {
    // if(l != NULL)
}

bool lista_inserir(LISTA *l, ITEM *it) {
    if(l != NULL) {
        if(!l->ordenada) {
            l->lista[l->fim] = it;
        }
    }
}

