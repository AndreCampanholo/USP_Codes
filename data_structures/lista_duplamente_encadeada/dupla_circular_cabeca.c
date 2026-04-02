#include "item.h"
#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct no_ NO;

struct lista_ {
    NO *sentinela;
    NO *fim;
    int tamanho;
    bool ordenada;
};

struct no_ {
    ITEM *conteudo;
    NO *proximo;
    NO *anterior;
};

//Funções Auxiliares
bool lista_inserir_fim(LISTA *l, ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo != NULL) {
        l->fim->proximo = novo;
        novo->anterior = l->fim;
        l->fim = novo;
        l->fim->proximo = l->sentinela;
        l->sentinela->anterior = l->fim;
        l->fim->conteudo = it;
        l->tamanho++;
        return true;
    }

    return false;
}

bool lista_inserir_ordenado(LISTA *l, ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo != NULL) {
        NO *aux = l->sentinela->proximo;

        while(aux != l->sentinela && item_get_chave(aux->conteudo) < item_get_chave(it)) {
            aux = aux->proximo;
        }

        if(aux == l->sentinela->proximo) {
            novo->proximo = l->sentinela->proximo;
            novo->anterior = l->sentinela;
            l->sentinela->proximo->anterior = novo;
            l->sentinela->proximo = novo;
        } else if(aux == l->sentinela) {
            l->sentinela->anterior = novo;
            novo->proximo = l->sentinela;
            novo->anterior = l->fim;
            l->fim->proximo = novo;
            l->fim = novo;
        } else {
            aux->anterior->proximo = novo;
            novo->anterior = aux->anterior;
            aux->anterior = novo;
            novo->proximo = aux;
        }

        novo->conteudo = it;
        l->tamanho++;

        return true;
    }

    return false;
}

ITEM *lista_remover_ordenado(LISTA *l, int chave) {
    item_set_chave(l->sentinela->conteudo, chave);

    NO *aux = l->sentinela->proximo;
    while(item_get_chave(aux->conteudo) < chave) {
        aux = aux->proximo;
    }

    if(aux == l->sentinela || item_get_chave(aux->conteudo) != chave) {
        return NULL;
    }

    if(aux == l->fim) {
        if(aux->anterior == l->sentinela) {
            l->fim = NULL;
        } else {
            l->fim = aux->anterior;
        }
    }

    ITEM *it = aux->conteudo;
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    l->tamanho--;
    free(aux);
    aux = NULL;

    return it;
}

ITEM *lista_remover_n_ordenado(LISTA *l, int chave) {
    item_set_chave(l->sentinela->conteudo, chave);

    NO *aux = l->sentinela->proximo;
    while(item_get_chave(aux->conteudo) != chave) {
        aux = aux->proximo;
    }

    if(aux == l->sentinela) {
        return NULL; // Item not found
    }

    // Update l->fim if removing the last node
    if(aux == l->fim) {
        if(aux->anterior == l->sentinela) {
            // List will become empty
            l->fim = NULL;
        } else {
            l->fim = aux->anterior;
        }
    }

    ITEM *it = aux->conteudo;
    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    l->tamanho--;
    free(aux);
    aux = NULL;

    return it;
}

//Funções Principais

LISTA *lista_criar(bool ordenada) {
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));
    if(l != NULL) {
        NO *novo = (NO *)malloc(sizeof(NO));
        if(novo != NULL) {
            l->sentinela = novo;
            l->fim = NULL; // Empty list, no real nodes yet
            l->tamanho = 0;
            l->ordenada = ordenada;
            l->sentinela->conteudo = NULL;
            l->sentinela->proximo = l->sentinela;
            l->sentinela->anterior = l->sentinela;
            return l;
        }
    }
    return NULL;
}

bool lista_vazia(LISTA *l) {
    return (l == NULL || l->sentinela->proximo == l->sentinela);
}

bool lista_cheia(LISTA *l) {
    return false; // Lista ligada não tem limite teórico de tamanho
}

void lista_apagar(LISTA **l) {
    if(l != NULL && *l != NULL) {
        while(!lista_vazia(*l)) {
            ITEM *aux = lista_remover(*l, item_get_chave((*l)->sentinela->proximo->conteudo));
            item_apagar(&aux);
        }
        (*l)->sentinela->proximo = NULL;
        (*l)->sentinela->anterior = NULL;
        free((*l)->sentinela);
        (*l)->sentinela = NULL;
        free(*l);
        *l = NULL;
    }
}

bool lista_inserir(LISTA *l, ITEM *it) {
    if(l == NULL || it == NULL || lista_cheia(l))
        return false;

    if(lista_vazia(l)) {
        NO *novo = (NO *)malloc(sizeof(NO));
        if(novo != NULL) {
            novo->conteudo = it;
            l->sentinela->proximo = novo;
            novo->anterior = l->sentinela;
            l->sentinela->anterior = novo;
            l->fim = novo;
            l->fim->proximo = l->sentinela;
            l->tamanho++;
            return true;
        }
        return false;
    }
    
    if(l->ordenada) {
        return lista_inserir_ordenado(l, it);
    } else {
        return lista_inserir_fim(l, it);
    }
} 

ITEM *lista_remover(LISTA *l, int chave) {
    if(l != NULL && !lista_vazia(l)) {
        if(l->ordenada) {
            return lista_remover_ordenado(l, chave);
        } else {
            return lista_remover_n_ordenado(l, chave);
        }
    }
    return NULL;
}