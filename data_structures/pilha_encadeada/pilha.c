#include "pilha.h"
#include <stdlib.h>

struct no {
    ITEM *item;
    NO* anterior;
};

struct pilha {
    NO *topo;
    int tamanho;
};

PILHA *pilha_criar(void) {
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
};

void pilha_apagar(PILHA **pilha){
    NO *aux;
    if(*pilha != NULL) {
        while((*pilha)->topo != NULL) {
            aux = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            item_apagar(&(aux->item));
            free(aux);
            aux = NULL;
        }
        (*pilha)->topo = NULL;
        free(*pilha);
        *pilha = NULL;
    }
};

bool pilha_vazia(PILHA *pilha) {
    if(pilha->topo == NULL) {
        return true;
    } else {
        return false;
    }
};

bool pilha_cheia(PILHA *pilha) {
    if(pilha->tamanho >= TAM) {
        return true;
    } else {
        return false;
    }
};

int pilha_tamanho(PILHA *pilha) {
    if(pilha == NULL) {
        return 0;
    }
    return pilha->tamanho;
};

ITEM *pilha_topo(PILHA *pilha) {
    if(pilha == NULL || pilha->topo == NULL) {
        return NULL;
    }
    return pilha->topo->item;
};

bool pilha_empilhar(PILHA *pilha, ITEM *item) {
    if(pilha == NULL || pilha_cheia(pilha)) {
        return false;
    } else {
        NO *novo = (NO *)malloc(sizeof(NO));
        NO *aux;
        aux = pilha->topo;
        pilha->topo = novo;
        novo->item = item;
        pilha->topo->anterior = aux;
        aux = NULL;
        pilha->tamanho++;
        return true;
    }
};

ITEM *pilha_desempilhar(PILHA *pilha) {
    if(pilha == NULL || pilha->topo == NULL) {
        return NULL;
    } else {
        NO *aux;
        aux = pilha->topo;
        ITEM *item = aux->item;
        pilha->topo = pilha->topo->anterior;
        aux->anterior = NULL;
        pilha->tamanho--;
        free(aux);
        aux = NULL;
        return item;
    }
};

bool balanceada(char *sequencia) {
    PILHA *p = pilha_criar();

    for(int i = 0; sequencia[i] != '\0'; i++) {
        ITEM *it = item_criar(sequencia[i]);
        if(sequencia[i] == '(' || sequencia[i] == '{' || sequencia[i] == '[') {
            pilha_empilhar(p, it);
        } else if(sequencia[i] == ')') {
            if(item_get_chave(pilha_topo(p)) != '(') {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            } else if(item_get_chave(pilha_topo(p)) == '(') {
                ITEM *topo = pilha_desempilhar(p);
                item_apagar(&topo);
            } else {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            }
        } else if(sequencia[i] == '}') {
            if(pilha_vazia(p)) {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            } else if(item_get_chave(pilha_topo(p)) == '{') {
                ITEM *topo = pilha_desempilhar(p);
                item_apagar(&topo);
            } else {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            }
        } else if(sequencia[i] == ']') {
            if(pilha_vazia(p)) {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            } else if(item_get_chave(pilha_topo(p)) == '[') {
                ITEM *topo = pilha_desempilhar(p);
                item_apagar(&topo);
            } else {
                item_apagar(&it);
                pilha_apagar(&p);
                return 0;
            }
        }
    }

    if(pilha_vazia(p)) {
        pilha_apagar(&p);
        return 1;
    } else {
        pilha_apagar(&p);
        return 0;
    }
};

PILHA *pilha_inverter(PILHA *p) {
    if(p == NULL || pilha_vazia(p))
        return p;

    PILHA *aux = pilha_criar();
    if(aux == NULL)
        return NULL;

    // Move todos os elementos da pilha original para a auxiliar
    while(!pilha_vazia(p)) {
        ITEM *item = pilha_desempilhar(p);
        if(item == NULL || !pilha_empilhar(aux, item)) {
            // Se falhar, restaura os elementos e retorna erro
            while(!pilha_vazia(aux)) {
                pilha_empilhar(p, pilha_desempilhar(aux));
            }
            pilha_apagar(&aux);
            return NULL;
        }
    }

    p->topo = aux->topo;
    p->tamanho = aux->tamanho;
    aux->topo = NULL;
    free(aux);
    aux = NULL;
    
    return p;
}