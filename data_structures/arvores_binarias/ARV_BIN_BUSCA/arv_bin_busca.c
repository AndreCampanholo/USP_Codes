#include "arv_bin.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    ITEM *item;
    struct no *esq;
    struct no *dir;
} NO;

struct arv_bin {
    NO *raiz;
    int profundidade;
};

//Funções Auxiliares

//Insere o novo nó na folha correta da árvore
NO *abb_inserir_no(NO *raiz, NO *novo) {
    if(raiz == NULL) {
        raiz = novo;
    } else if(item_get_chave(novo->item) < item_get_chave(raiz->item)) {
        raiz->esq = abb_inserir_no(raiz->esq, novo);
    } else {
        raiz->dir = abb_inserir_no(raiz->dir, novo);
    }  

    return raiz;
}

bool abb_inserir_bool(NO **raiz, NO *novo) {
    if((*raiz) == NULL) {
        (*raiz) = novo;
        return true;
    }
    if(item_get_chave((*raiz)->item) > item_get_chave(novo->item))
        return abb_inserir_bool(&((*raiz)->esq), novo);
    if(item_get_chave((*raiz)->item) < item_get_chave(novo->item))
        return abb_inserir_bool(&((*raiz)->dir), novo);

    return false;
}

void abb_inserir_iterativo(NO **raiz, NO* novo) {
    if(raiz == NULL || *raiz == NULL) {
        *raiz = novo;
        return;
    }

    NO *r_orig = *raiz;
    NO *anterior = NULL;

    int esq0_dir1;

    while(*raiz != NULL) {
        if(item_get_chave(novo->item) < item_get_chave((*raiz)->item)) {
            anterior = *raiz;
            *raiz = (*raiz)->esq;
            esq0_dir1 = 0;
        } else {
            anterior = *raiz;
            *raiz = (*raiz)->dir;
            esq0_dir1 = 1;
        }
    }

    if(!esq0_dir1) {
        anterior->esq = novo;
    } else {
        anterior->dir = novo;
    }
    
    *raiz = r_orig;
}

//Cria um nó com o item informado
NO* abb_criar_no(ITEM *it) {
    if(it == NULL) return NULL;

    NO *novo = (NO *)malloc(sizeof(NO));
    if(novo != NULL) {
        novo->item = it;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

ITEM *abb_buscar_no(NO *raiz, int chave) {
    if(raiz == NULL) return NULL;
    
    if(chave == item_get_chave(raiz->item)) {
        return raiz->item;
    } else if(chave < item_get_chave(raiz->item)) {
        return abb_buscar_no(raiz->esq, chave);
    } else {
        return abb_buscar_no(raiz->dir, chave);
    }
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant) {
    if(troca->dir != NULL) {
        troca_max_esq(troca->dir, raiz, troca);
    } else {
        if(ant == raiz)  
            ant->esq = troca->esq;
        else   
            ant->dir = troca->esq;

        raiz->item = troca->item;
        free(troca);
        troca = NULL;
    }
}

ITEM *abb_remover_no(NO **raiz, int chave) {
    if(*raiz == NULL) return NULL;
    
    ITEM *item_raiz;
    NO *aux;
    if(item_get_chave((*raiz)->item) == chave) {
        item_raiz = (*raiz)->item;
        //raiz tem 0 ou 1 filho
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL) {
            aux = *raiz;
            if((*raiz)->esq == NULL)    
                *raiz = (*raiz)->dir;
            else 
                *raiz = (*raiz)->esq;
                
        } else {
            //caso em que raiz tem 2 filhos
            troca_max_esq((*raiz)->esq, *raiz, *raiz);
            return item_raiz;
        }
        free(aux);
        aux = NULL;
        return item_raiz;
    } else if(item_get_chave((*raiz)->item) > chave) {
        return abb_remover_no(&(*raiz)->esq, chave);
    } else {
        return abb_remover_no(&(*raiz)->dir, chave);
    }
}

//Destrói completamento um AB em pós-ordem, apagando ela nó por nó
void abb_destruir(NO **no) {
    if(no != NULL && (*no) != NULL) {
        abb_destruir(&((*no)->esq));
        abb_destruir(&((*no)->dir));
        item_apagar(&((*no)->item));
        (*no)->esq = NULL;
        (*no)->dir = NULL;
        free(*no);
        *no = NULL;
    }
}

//Percorre a árvore em pré-ordem
void pre_ordem(NO *r) {
    if(r != NULL) {
        printf("%d\n", item_get_chave(r->item)); //vista nó raiz da sub-árvore
        pre_ordem(r->esq); //percorre a sub-árvore à esquerda
        pre_ordem(r->dir); //percorre a sub-árvore à direita
    }
}

//Percorre a árvore em ordem
void em_ordem(NO *r) {
    if(r != NULL) {
        em_ordem(r->esq); //percorre a sub-árvore à esquerda
        printf("%d\n", item_get_chave(r->item)); //vista nó raiz da sub-árvore
        em_ordem(r->dir); //percorre a sub-árvore à direita
    }
}

//Percorre a árvore em pós-ordem
void pos_ordem(NO *r) {
    if(r != NULL) {
        pos_ordem(r->esq); //percorre a sub-árvore à esquerda
        pos_ordem(r->dir); //percorre a sub-árvore à direita
        printf("%d\n", item_get_chave(r->item)); //vista nó raiz da sub-árvore
    }
}

//Funções Principais
AB *abb_criar(void) {
    AB *a = (AB *)malloc(sizeof(AB));
    if(a != NULL) {
        a->raiz = NULL;
        a->profundidade = -1;
    }
    return a;
}

void abb_apagar(AB **arv) {
    if(arv != NULL && *arv != NULL) {
        abb_destruir(&((*arv)->raiz));
        free(*arv);
        *arv = NULL;
    }
}

bool abb_inserir(AB *arv, ITEM *it) {
    if(arv == NULL || it == NULL) return false;

    NO *novo = abb_criar_no(it);
    if(novo != NULL) {
        //Inserção recursiva
        arv->raiz = abb_inserir_no(arv->raiz, novo);

        //Inserção iterativa
        //abb_inserir_iterativo(&(arv-raiz), novo);

        //Inserção recursiva usando bool
        //abb_inserir_bool(&(arv->raiz), novo);

        return true;
    }
    return false;
}

ITEM *abb_remover(AB *abb, int chave) {
    if(abb == NULL) return NULL;
    return abb_remover_no(&(abb->raiz), chave);
}

ITEM *abb_buscar(AB *arv, int chave) {
    if(arv != NULL) {
        return abb_buscar_no(arv->raiz, chave);
    }
    return NULL;
}

void abb_percorrer(AB *arv, int metodo) {
    if(arv == NULL || metodo < -1 || metodo > 1) {
        printf("Árvore inexistente ou método de percorrimento inválido.\n");
    } else {
        if(metodo == PRE_ORDEM) {
            pre_ordem(arv->raiz);
        } else if(metodo == EM_ORDEM) {
            em_ordem(arv->raiz);
        } else {
            pos_ordem(arv->raiz);
        }
    }
}

int abb_profundidade(NO *r) {
    if(r != NULL) {
        int prof_esq = abb_profundidade(r->esq);
        int prof_dir = abb_profundidade(r->dir);
        //Percorre ambas as sub-árvores e depois visita (calcula qual a maior profundidade)
        if(prof_esq >= prof_dir) {
            return prof_esq + 1;
        } else {
            return prof_dir + 1;
        }
    } 
    return -1;
} //Funcionamento: Pós-ordem