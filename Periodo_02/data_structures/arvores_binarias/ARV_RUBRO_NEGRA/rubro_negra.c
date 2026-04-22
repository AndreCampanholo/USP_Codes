#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    struct no *esq, *dir;
    int cor;
    int info;
} NO;

typedef struct llrb {
    NO *raiz;
    int profundidade;
} ARV;

ARV *criar_llrb(void) {
    ARV *llrb = (ARV *)malloc(sizeof(ARV));
    if(llrb != NULL) {
        llrb->raiz = NULL;
        llrb->profundidade = 0;
    }
    return llrb;
}

void inverte_cor(NO *r) {
    r->cor = !r->cor;
    if(r->esq != NULL) r->esq->cor = !r->esq->cor;
    if(r->dir != NULL) r->dir->cor = !r->dir->cor;
}

NO *criar_no(int data) {
    NO *novo = (NO *)malloc(sizeof(NO));
    if(novo != NULL) {
        novo->cor = 1;
        novo->info = data;
        novo->esq = NULL;
        novo->dir = NULL;
    }   
    return novo;
}

NO *rotacao_direita(NO *raiz) {
    NO *b;
    b = raiz->esq;

    raiz->esq = b->dir;
    b->dir = raiz;
    b->cor = raiz->cor;
    raiz->cor = 1;

    return b;
}

NO *rotacao_esquerda(NO *raiz) {
    NO *b;
    b = raiz->dir;

    raiz->dir = b->esq;
    b->esq = raiz;
    b->cor = raiz->cor;
    raiz->cor = 1;

    return b;
}

NO *insere_llrb(NO *raiz, int data) {
    if(raiz == NULL) {
        raiz = criar_no(data);
        return raiz;
    }

    if(data < raiz->info) 
        raiz->esq = insere_llrb(raiz->esq, data);
    else if(data > raiz->info)
        raiz->dir = insere_llrb(raiz->dir, data);

    if(raiz->dir->cor && !raiz->esq->cor)
        raiz = rotacao_esquerda(raiz);
    if(raiz->esq->cor && raiz->esq->esq->cor) 
        raiz = rotacao_direita(raiz);
    if(raiz->esq->cor && raiz->dir->cor)
        inverte_cor(raiz);

    return raiz;
}

NO *propaga_esquerda(NO *h) {
    if(!h->esq->cor && !h->esq->esq->cor) {
        inverte_cor(h);
        if(h->dir->esq->cor) {
            h->dir = rotacao_direita(h->dir);
            h = rotacao_esquerda(h);
            inverte_cor(h);
        }
    }
    return h;
}

NO *propaga_direita(NO *h) {
    if(h->esq->cor) h = rotacao_direita(h);
    
    if(!h->dir->cor && !h->dir->esq->cor) {
        inverte_cor(h);
        if(h->esq->esq->cor) {
            h = rotacao_direita(h);
            inverte_cor(h);
        }
    }
}

NO *restaura(NO *h) {
    if(h->dir->cor && !h->esq->cor)
        h = rotacao_esquerda(h);
    if(h->esq->cor && h->esq->esq->cor)
        h = rotacao_direita(h);
    if(h->esq->cor && h->dir->cor)
        inverte_cor(h);

    return h;
}

NO *min(NO *h) {
    while(h->esq != NULL) 
        h = h->esq;
    return h;
}

NO *remove_min(NO *h) {
    if(h->esq == NULL) {
        free(h);
        h = NULL;
    }
    if(!h->esq->cor && !h->esq->esq->cor)
        h = propaga_esquerda(h);
    h->esq = remove_min(h->esq);
    return restaura(h);
}

NO *remover_no(NO *h, int chave) {
    if(h == NULL) return NULL;

    if(h->info == chave) {
        //caso em que h é nó folha ou possui apenas 1 filho
        if(h->esq == NULL || h->dir == NULL) {
            NO *p = h;
            if(h->esq == NULL) h = h->dir;
            else h = h->esq;
            free(p);
            p = NULL;
        } //caso em que h possui dois filhos
        else {
            h = propaga_direita(h);
            NO *x = min(h->dir);
            h->info = x->info; //troca as chaves
            h->dir = remove_min(h->dir);
        }
    } else {
        if(chave < h->info) {
            h = propaga_esquerda(h);
            h->esq = remover_no(h->esq, chave);
        } else {
            h = propaga_direita(h);
            h->dir = remover_no(h->dir, chave);
        }
    }
    if(h != NULL) h = restaura(h); //volta da recursão ajustanto cores das arestas

    return h;
}