#include "abb.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    ITEM *item;
    struct no *esq;
    struct no *dir;
} NO;

struct abb {
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

void troca_max_esq(NO *troca, NO *raiz, NO *ant) {
    if(troca->dir != NULL) {
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }
    if(raiz == ant)
        ant->esq = troca->esq;
    else
        ant->dir = troca->esq;

    ITEM *item_movido = troca->item;
    troca->item = NULL;
    item_apagar(&(raiz->item));
    raiz->item = item_movido;
    
    free(troca);
}

bool abb_remover_aux (NO **raiz, int chave){
    if(*raiz == NULL) return false;

    NO *p;
    if(chave == item_get_chave((*raiz)->item)) {
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL) {/*Caso 1 se resume ao caso 2: há um filho ou nenhum*/
            p = *raiz;
            if((*raiz)->esq == NULL)
                *raiz = (*raiz)->dir;
            else
                *raiz = (*raiz)->esq;
            item_apagar(&(p->item));
            free(p);
            p = NULL;
        } else /*Caso 3: há ambos os filhos*/
            troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
        return true; 
    } else {
        if(chave < item_get_chave((*raiz)->item))
            return abb_remover_aux (&(*raiz)->esq, chave);
        else
            return abb_remover_aux (&(*raiz)->dir, chave);
    }
}

//Percorre a árvore binária em ordem
void em_ordem(NO *raiz) {
    if(raiz == NULL) return;
    em_ordem(raiz->esq);
    printf("%d\n", item_get_chave(raiz->item));
    em_ordem(raiz->dir);
}

//Retorna a altura da árvore binária
int abb_altura(NO *raiz) {
    if(raiz == NULL) return 0;

    int altura_esq = abb_altura(raiz->esq);
    int altura_dir = abb_altura(raiz->dir);

    if(altura_esq > altura_dir) 
        return 1 + altura_esq;
    return 1 + altura_dir;
}

//Verifica se todos os nós possuem 0 ou 2 filhos
bool qtd_par_de_filhos(NO *raiz) {
    if(raiz == NULL) return true;
    
    bool tem_esq = (raiz->esq != NULL);
    bool tem_dir = (raiz->dir != NULL);
    
    if(tem_esq != tem_dir) return false;
    
    return qtd_par_de_filhos(raiz->esq) && qtd_par_de_filhos(raiz->dir);
}

//Conta a quantidade de nós da árvore
void abb_contar_nos(NO *raiz, int *cont) {
    if(raiz == NULL) return;

    (*cont)++;
    abb_contar_nos(raiz->esq, cont);
    abb_contar_nos(raiz->dir, cont);
}

//Funções Principais
ABB *abb_criar(void) {
    ABB *a = (ABB *)malloc(sizeof(ABB));
    if(a != NULL) {
        a->raiz = NULL;
        a->profundidade = -1;
    }
    return a;
}

void abb_apagar(ABB **arv) {
    if(arv != NULL && *arv != NULL) {
        abb_destruir(&((*arv)->raiz));
        free(*arv);
        *arv = NULL;
    }
}

bool abb_inserir(ABB *arv, ITEM *it) {
    if(arv == NULL || it == NULL) return false;

    NO *novo = abb_criar_no(it);
    if(novo != NULL) {
        arv->raiz = abb_inserir_no(arv->raiz, novo);

        return true;
    }
    return false;
}

bool abb_remover(ABB *T, int chave){
    if (T != NULL)
    return (abb_remover_aux(&T->raiz, chave));
    return false;
}

void abb_imprimir(ABB *arv) {
    em_ordem(arv->raiz);
}

ITEM *abb_busca(ABB *arv, int chave) {
    if(arv != NULL) {
        return abb_buscar_no(arv->raiz, chave);
    }
    return NULL;
}

bool abb_vazia(ABB *arv) {
    if(arv == NULL || arv->raiz == NULL) {
        return true;
    }
    return false;
}

//Verifica se a árvore está perfeitamente balanceada
bool abb_perfeitamente_balanceada(ABB *arv) {
    if(arv == NULL || arv->raiz == NULL) return true;
    
    int altura = abb_altura(arv->raiz);
    int qtd_nos = 0;
    abb_contar_nos(arv->raiz, &qtd_nos);

    int qtd_nos_desejada = 1;
    for(int i = 0; i < altura; i++) {
        qtd_nos_desejada = qtd_nos_desejada * 2;
    }
    qtd_nos_desejada -= 1;
    
    if(qtd_par_de_filhos(arv->raiz) && qtd_nos == qtd_nos_desejada) {
        return true;
    }
    return false;
}