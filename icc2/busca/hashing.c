#include <stdio.h>

#define B 17

typedef struct {
    int chave, valor;
} hash_t;

hash_t table[B];

int hash(int chave) {
    return chave % B;
}

void inserir(int chave, int valor) {
    int origInd = hash(chave);

    for (int i = 0; i < B; i++) {
        int pos = (origInd + i) % B;
        if(table[pos].chave == -1) {
            table[pos].chave = chave;
            table[pos].valor = valor;
            return;
        } else {
            return;
        }
    }
    return;
}

int busca(int chave) {
    int origInd = hash(chave);

    for (int i = 0; i < B; i++) {
        int pos = (origInd + i) % B;
        if (table[pos].chave == -1) {
            return -1;
        }
        if (table[pos].chave == chave) {
            return table[pos].valor;
        }
    }
    return -1;
}

// void remover(int chave) {

// }

int main() {

    for(int i = 0; i < B; i++) {
        table[i].chave = -1;
    }

    inserir(4, 8);
    inserir(8, 3);
    inserir(2, 9);
    inserir(9, 3);
    inserir(1, 2);
    inserir(4, 8);

    printf("%d\n", busca(4));

    return 0;
}