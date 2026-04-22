#include "deque.h"
#include "item.h"
#include <stdbool.h>
#include <stdlib.h>

#define TAM 10

typedef struct no_ {
    ITEM *conteudo;
    struct no_ *proximo;
} NO;

struct deque_ {
    NO *inicio;
    NO *fim;
    int tamanho;
};

DEQUE *deque_criar(void) {
    DEQUE *dq = (DEQUE *)malloc(sizeof(DEQUE));
    if(dq != NULL) {
        dq->inicio = NULL;
        dq->fim = NULL;
        dq->tamanho = 0;
        return dq;
    }
    return NULL;
}

void deque_apagar(DEQUE **dq) {
    if(dq != NULL && *dq != NULL) {
        while(!deque_vazio(*dq)) {
            ITEM *item = deque_remover_inicio(*dq);
            item_apagar(&item);
        }
        free(*dq);
        *dq = NULL;
    }
}

bool deque_inserir_inicio(DEQUE *dq, ITEM *it) {
    if(dq != NULL && it != NULL && !deque_cheio(dq)) {
        NO *novo = (NO *)malloc(sizeof(NO));
        if(novo != NULL) {
            novo->conteudo = it;
            novo->proximo = dq->inicio;
            dq->inicio = novo;
            
            if(dq->fim == NULL) {  // Deque estava vazio
                dq->fim = novo;
            }
            
            dq->tamanho++;
            return true;
        }
    }
    return false;
}

bool deque_inserir_fim(DEQUE *dq, ITEM *it) {
    if(dq != NULL && it != NULL && !deque_cheio(dq)) {
        NO *novo = (NO *)malloc(sizeof(NO));
        if(novo != NULL) {
            novo->conteudo = it;
            novo->proximo = NULL;
            
            if(dq->fim == NULL) {
                dq->inicio = novo;
                dq->fim = novo;
            } else {
                dq->fim->proximo = novo;
                dq->fim = novo;
            }
            dq->tamanho++;

            return true;
        }
    }
    return false;
}

ITEM *deque_remover_inicio(DEQUE *dq) {
    if(dq == NULL || deque_vazio(dq)) 
        return NULL;

    ITEM *aux = dq->inicio->conteudo;
    NO *p = dq->inicio;
    dq->inicio = dq->inicio->proximo;
    
    if(dq->inicio == NULL) {
        dq->fim = NULL;
    }
    
    p->proximo = NULL;
    free(p);
    p = NULL;
    dq->tamanho--;
    return aux;
}

ITEM *deque_remover_fim(DEQUE *dq) {
    if(dq == NULL || deque_vazio(dq))
        return NULL;

    NO *frente = dq->inicio;
    NO *tras = NULL;
    
    while(frente != dq->fim) {
        tras = frente;
        frente = frente->proximo;
    }

    if(tras == NULL)
        dq->inicio = NULL;

    if(tras != NULL)
        tras->proximo = NULL;
    
    ITEM *aux = frente->conteudo;
    dq->fim = tras;
    dq->tamanho--;
    free(frente);
    frente = NULL;
    return aux;
}

bool deque_cheio(DEQUE *dq) {
    if(dq != NULL && dq->tamanho >= TAM)
        return true;
    
    return false;
}

bool deque_vazio(DEQUE *dq) {
    if(dq != NULL && dq->tamanho == 0) {
        return true;
    }
    return false;
}