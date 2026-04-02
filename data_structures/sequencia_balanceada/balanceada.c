#include <stdio.h>
#include "Pilha.h"

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
}