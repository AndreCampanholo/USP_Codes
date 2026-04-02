#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item {
    int num;
};

ITEM *item_criar(int chave) {
    ITEM *item = (ITEM *)malloc(sizeof(ITEM));
    item->num = chave;
    return item;
};

bool item_apagar(ITEM **item) {
    if(item != NULL) {
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
};

void item_imprimir(ITEM *item) {
    if(item == NULL){
        return;
    }
    printf("%d\n", item->num);
};

int item_get_chave(ITEM *item) {
    if(item != NULL) {
        return item->num;
    }
    return 0;
};

bool item_set_chave(ITEM *item, int chave) {
    if(item != NULL) {
        item->num = chave;
        return true;
    };
    return false;
};