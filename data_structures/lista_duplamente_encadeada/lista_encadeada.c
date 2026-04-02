#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

#define TAM 100

typedef struct no {
    ITEM *conteudo;
    struct no *proximo;
} NO;

struct lista_ {
    NO *inicio;
    NO *fim;
    int tamanho;
    bool ordenada;
};

//FUNÇÕES AUXILIARES
bool lista_inserir_fim(LISTA *l, ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo != NULL) {
        novo->conteudo = it;
        novo->proximo = NULL;

        if(lista_vazia(l)) {
            l->inicio = novo;
        } else {
            l->fim->proximo = novo;
        }
        l->fim = novo;
        l->tamanho++;

        return true;
    }
    return false;
}

bool lista_inserir_ordenada(LISTA *l, ITEM *it) {
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL) {
        return false;
    }

    novo->conteudo = it;
    novo->proximo = NULL;

    if (lista_vazia(l)) {
        l->inicio = novo;
        l->fim = novo;
        l->tamanho++;
        return true;
    }

    NO *anterior = NULL;
    NO *atual = l->inicio;

    while(atual != NULL && item_get_chave(atual->conteudo) < item_get_chave(it)) {
        anterior = atual;
        atual = atual->proximo;
    }

    if(anterior == NULL) {
        novo->proximo = l->inicio; //l->inicio == NULL;
        l->inicio = novo;
        if(l->fim == NULL) {
            l->fim = novo;
        }
    } else {
        novo->proximo = atual;
        anterior->proximo = novo;
        if(atual == NULL) {
            l->fim = novo;
        }
    }
    l->tamanho++;
    return true;
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
        p = l->inicio;
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

//FUNÇÕES PRINCIPAIS
LISTA *lista_criar(bool ordenada) {
    LISTA *l = (LISTA *)malloc(sizeof(LISTA));

    if(l != NULL) {
        l->inicio = NULL;
        l->fim = NULL;
        l->tamanho = 0;
        l->ordenada = ordenada;
    }

    return l;
}

bool lista_inserir(LISTA *l, ITEM *it) {
    if(l != NULL && it != NULL && !lista_cheia(l)) {
        if(l->ordenada) {
            return lista_inserir_ordenada(l, it);
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

    NO *tras = NULL;
    NO *frente = l->inicio;

    while(frente != NULL && item_get_chave(frente->conteudo) != chave) {
        tras = frente;
        frente = frente->proximo;
    }

    if(frente != NULL) {
        if(frente == l->inicio) {
            l->inicio = frente->proximo;
            frente->proximo = NULL;
        } else if(frente == l->fim) {
            l->fim = tras;
            l->fim->proximo = NULL;
        } else {
            tras->proximo = frente->proximo;
            frente->proximo = NULL;
        }
        ITEM *it = frente->conteudo;
        free(frente);
        l->tamanho--;
        return it;
    }
    return NULL;
}

ITEM *lista_busca(LISTA *l, int chave) {
    ITEM *it;

    if(l != NULL) {
        if(!l->ordenada) {
            return lista_buscar_recursiva(l->inicio, chave);
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