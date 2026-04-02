#include "arv_bin.h"
#include "item.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
void ab_inserir_no(NO* raiz, NO *no, int lado, int chave_pai) {
    //Supondo que não existam itens repetidos e inserções ocorram somente em lugares vagos
    if(raiz != NULL) {
        ab_inserir_no(raiz->esq, no, lado, chave_pai);
        ab_inserir_no(raiz->dir, no, lado, chave_pai);
        //Percorre toda a árvore e depois visita (realiza inserção neste caso)
        if(chave_pai == item_get_chave(raiz->item)) {
            if(lado == FILHO_ESQ) {
                raiz->esq = no;
            } else if(lado == FILHO_DIR) {
                raiz->dir = no;
            }
        }
    }
    return;
} //Funcionamento: Pós-ordem

//Cria um nó com o item informado
NO* ab_criar_no(ITEM *it) {
    if(it == NULL) return NULL;

    NO *novo = (NO *)malloc(sizeof(NO));
    if(novo != NULL) {
        novo->item = it;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

//Destrói completamento um AB, apagando ela nó por nó
void ab_destruir(NO **no) {
    if(no != NULL && (*no) != NULL) {
        ab_destruir(&((*no)->esq));
        ab_destruir(&((*no)->dir));
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

int qtd_nos(NO *r) {
    if(r == NULL) return 0;
    return 1 + qtd_nos(r->esq) + qtd_nos(r->dir);
} //Funcionamento: Pré-Ordem

void maior_item(NO *r, int *max) {
    if(r == NULL) return;
    if(item_get_chave(r->item) > *max) *max = item_get_chave(r->item);
    maior_item(r->esq, max);
    maior_item(r->dir, max);
} //Funcionamento: Pré-Ordem

int somatorio_itens(NO *r) {
    if(r == NULL) return 0;
    return item_get_chave(r->item) + somatorio_itens(r->esq) + somatorio_itens(r->dir);
}

int profundidade(NO *r) {
    if(r == NULL) return -1;
    int prof_esq = profundidade(r->esq);
    int prof_dir = profundidade(r->dir);
    return (prof_esq >= prof_dir ? prof_esq : prof_dir) + 1;
}

bool estritamente_binaria(NO *r) {
    if((r->esq == NULL && r->dir != NULL) || (r->esq != NULL && r->dir == NULL)) return false;
    if(r->esq != NULL && r->dir != NULL) return estritamente_binaria(r->esq) && estritamente_binaria(r->dir);
    return true;
}

bool abc_inserir_no(NO **raiz, int chave) {
    if(*raiz == NULL) {
        NO *novo = ab_criar_no(item_criar(chave));
        if(novo != NULL) *raiz = novo;
        return true;
    }
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
        NO *novo = ab_criar_no(item_criar(chave));
        if(novo != NULL) (*raiz)->esq = novo;
        return true;
    }
    if((*raiz)->esq != NULL && (*raiz)->dir == NULL) {
        NO *novo = ab_criar_no(item_criar(chave));
        if(novo != NULL) (*raiz)->dir = novo;
        return true;
    }
    int altura_esq = profundidade((*raiz)->esq);
    int altura_dir = profundidade((*raiz)->dir);
    if(qtd_nos((*raiz)->esq) == pow(2, altura_esq + 1) - 1 && qtd_nos((*raiz)->dir) == pow(2, altura_dir + 1) - 1) 
        return abc_inserir_no(&((*raiz)->esq), chave);
    else 
        return abc_inserir_no(&((*raiz)->dir), chave);
}

// NO *abc_inserir_no(NO *raiz, int chave) {
//     if(raiz == NULL) {
//         return ab_criar_no(item_criar(chave));
//     }
//     if(raiz->esq == NULL && raiz->dir == NULL) {
//         raiz->esq = ab_criar_no(item_criar(chave));
//         return raiz;
//     }
//     if(raiz->esq != NULL && raiz->dir == NULL) {
//         raiz->dir = ab_criar_no(item_criar(chave));
//         return raiz;
//     }
    
//     int altura_esq = profundidade(raiz->esq);
//     int altura_dir = profundidade(raiz->dir);
//     if(qtd_nos(raiz->esq) == pow(2, altura_esq + 1) - 1 && qtd_nos(raiz->dir) == pow(2, altura_dir + 1) - 1) {
//         raiz->esq = abc_inserir_no(raiz->esq, chave);
//     } else {
//         raiz->dir = abc_inserir_no(raiz->dir, chave);
//     }
//     return raiz;
// }

bool perfeitamente_balanceada(NO *raiz) {
    if(raiz == NULL) return true;

    int qtd_esq = qtd_nos(raiz->esq);
    int qtd_dir = qtd_nos(raiz->dir);

    if(abs(qtd_esq - qtd_dir) <= 1) 
        return perfeitamente_balanceada(raiz->esq) && perfeitamente_balanceada(raiz->dir);

    return false;
}

//Funções Principais
AB *ab_criar(void) {
    AB *a = (AB *)malloc(sizeof(AB));
    if(a != NULL) {
        a->raiz = NULL;
        a->profundidade = -1;
    }
    return a;
}

void ab_apagar(AB **arv) {
    if(arv != NULL && *arv != NULL) {
        ab_destruir(&((*arv)->raiz));
        free(*arv);
        *arv = NULL;
    }
}

bool ab_inserir(AB *arv, ITEM *it, int lado, int chave_pai) {
    if(arv->raiz == NULL) {
        return((arv->raiz = ab_criar_no(it)) != NULL);
    }
    NO *novo = ab_criar_no(it);
    if(novo != NULL) {
        ab_inserir_no(arv->raiz, novo, lado, chave_pai);
        return true;
    }
    return false;
}

void ab_percorrer(AB *arv, int metodo) {
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

int ab_profundidade(AB *ab) {
    if(ab != NULL && ab->raiz != NULL) return profundidade(ab->raiz);
    return 0;
}

int ab_qtd_nos(AB *ab) {
    if(ab != NULL && ab->raiz != NULL) return qtd_nos(ab->raiz);
    return 0;
}

int ab_maior_item(AB *ab) {
    if(ab != NULL && ab->raiz != NULL) {
        int max = item_get_chave(ab->raiz->item);
        maior_item(ab->raiz, &max);
        return max;
    }
    return 0;
}

int ab_somatorio_itens(AB *ab) {
    if(ab != NULL && ab->raiz != NULL) return somatorio_itens(ab->raiz);
    return 0;
}

bool ab_estritamente_binaria(AB *ab) {
    if(ab != NULL && ab->raiz == NULL) return true;
    if(ab != NULL && ab->raiz != NULL) return estritamente_binaria(ab->raiz);
    return false;
}

bool ab_completa_cheia(AB *ab) {
    if(ab != NULL) {
        int altura = ab_profundidade(ab);
        if(ab->raiz == NULL || ab_qtd_nos(ab) == pow(2, altura + 1) - 1) return true;
    }
    return false;
}

bool abc_inserir(AB *ab, int chave) {
    if(ab != NULL) return abc_inserir_no(ab->raiz, chave);
    return false;
}

bool ab_perfeitamente_balanceada(AB *ab) {
    if(ab == NULL) return false;
    return perfeitamente_balanceada(ab->raiz);
}