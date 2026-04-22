#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

#define TAM 100

typedef struct no {
    ITEM *conteudo;
    struct no *proximo;
} NO;

struct lista{
    NO *cabeca;
    NO *fim;
    int tamanho;
    bool ordenada;
};

bool lista_inserir_fim(LISTA *l, ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo != NULL) {
        novo->conteudo = it;
        novo->proximo = NULL;

        if(lista_vazia(l)) {
            l->cabeca->proximo = novo;
        } else {
            l->fim->proximo = novo;
        }
        l->fim = novo;
        l->tamanho++;

        return true;
    }
    return false;
}

//FUNÇÕES PRINCIPAIS
LISTA *lista_criar(bool ordenada) {
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));

    NO *cabeca = (NO *)malloc(sizeof(NO));

    if(l != NULL) {
        l->cabeca->proximo = NULL;
        l->fim = NULL;
        l->tamanho = 0;
        l->ordenada = ordenada;
    }

    return l;
}

bool lista_inserir(LISTA *l, ITEM *it) {
    if(l != NULL && !lista_cheia(l)) {
        if(l->ordenada) {

        } else {
            return lista_inserir_fim(l, it);
        }
    }

    return false;
}

ITEM *lista_remover(LISTA *l, int chave) {
    if(l == NULL || lista_vazia(l)) {
        return NULL;
    }

    NO *frente = l->cabeca;
    ITEM *it;

    while(frente->proximo != NULL && item_get_chave(frente->proximo->conteudo) != chave) {
        frente = frente->proximo;
    }

    if(frente->proximo != NULL) {
        NO *tras = frente;
        frente = frente->proximo;
        it = frente->conteudo;
        tras->proximo = frente->proximo;
        if(frente == l->fim) {
            l->fim = tras;
        }
        l->tamanho--;
        frente->proximo = NULL;
        free(frente);
        return it;
    }
    return NULL;
}

ITEM *lista_buscar_recursiva(NO *n, int chave) {
    if(n == NULL) {
        return NULL;
    }
    if(item_get_chave(n->conteudo) == chave) {
        return n->conteudo;
    }
    return lista_buscar_recursiva(n->proximo, chave);
}

ITEM *lista_busca_ordenada(LISTA *l, int chave)
{
    NO *p = NULL;
    if (l != NULL)
    {
        p = l->cabeca->proximo;
        while (p != NULL && item_get_chave(p->conteudo) < chave)
        {
            p = p->proximo;
        }
        if (p == NULL || item_get_chave(p->conteudo) > chave)
            return (NULL);
        else
        {
            return (p->conteudo);
        }
    }
    return (p);
}

ITEM *lista_busca(LISTA *l, int chave) {
    ITEM *it;

    if(l != NULL) {
        if(!l->ordenada) {
            return lista_buscar_recursiva(l->cabeca->proximo, chave);
        } else {
            return lista_busca_ordenada(l, chave);
        }
    }
    
}

bool lista_apagar(LISTA **l) {
    if(l == NULL || *l == NULL) {
        return true;
    }
    while(!lista_vazia(*l)) {

    }
}

bool lista_vazia(LISTA *l) {
    if(l == NULL || l->tamanho == 0) {
        return true;
    }
    return false;
}

bool lista_cheia(LISTA *l) {
    if(l != NULL && l->tamanho == TAM) {
        return true;
    }
    return false;
}