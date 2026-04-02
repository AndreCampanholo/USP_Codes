#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item {
    void *dados;
};

ITEM *item_criar(void *dado) {
    ITEM *item = (ITEM *)malloc(sizeof(ITEM));

    if(item != NULL) {
        item->dados = dado;
        return item;
    }

    return NULL;
};

bool item_apagar(ITEM **item) {
    if(item != NULL) {
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
};

// void item_imprimir(ITEM *item) {
//     if(item == NULL){
//         return;
//     }
//     printf("%d\n", item->num);
// };

void *item_get_dados(ITEM *item) {
    if(item != NULL) {
        return item->dados;
    }

    return NULL;
};

bool item_set_dados(ITEM *item, void *dado) {
    if(item != NULL) {
        item->dados = dado;
        return true;
    };
    return false;
};