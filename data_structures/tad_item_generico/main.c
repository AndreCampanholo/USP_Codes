#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

//na main o cliente decide o que o item vai guardar
//por exemplo, suponha que se queira guardar as informações nome e idade de uma pessoa
typedef struct pessoa {
    char *nome;
    int idade;
} Pessoa;

int main() {
    Pessoa *andre = (Pessoa *)malloc(sizeof(Pessoa));
    if(andre != NULL) {
        andre->idade = 18;
        strcpy(andre->nome, "André Paschoalini");
    }

    ITEM *dado = item_criar(andre);

    Pessoa *eu = item_get_dados(dado);

    printf("%d - ", eu->idade);
    printf("%s\n", eu->nome);

    item_apagar(&dado);
    free(andre);

    return 0;
}