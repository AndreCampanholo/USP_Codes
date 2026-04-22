#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char sequencia[] = {"((([)]))\0"};
    printf("%d\n", balanceada(sequencia));

    ITEM *it = item_criar(9);

    PILHA *p = pilha_criar();

    pilha_empilhar(p, it);

    printf("%d\n", item_get_chave(pilha_topo(p)));

    ITEM *item = item_criar(72);

    pilha_empilhar(p, item);

    printf("%d\n", item_get_chave(pilha_topo(p)));

    pilha_desempilhar(p);

    if(pilha_topo(p) == NULL) {
        printf("Pilha aponta para NULL.\n");
    } else {
        printf("%d\n", item_get_chave(pilha_topo(p))); 
    }

    pilha_desempilhar(p);

    pilha_apagar(&p);

    return 0;
}