#include <stdio.h>
#include <stdlib.h>

void hash_inserir(int table[], int N, int chave) {
    int pos = chave % N;
    for(int i = 0; i < N; i++) {
        if(table[pos] == 0) {
            table[pos] = chave;
            return;
        } else {
            pos = (1 + i) % (N - 1);
        }
    }
    printf("Tabela de hashing cheia. Impossível inserir.\n");
}

void hash_remover(int table[], int N, int chave) {
    for(int i = 0; i < N; i++) {
        if(table[i] == chave) {
            table[i] = 0;
            return;
        }
    }
}

int main() {
    int *hash_table = (int *)calloc(10, sizeof(int));

    hash_inserir(hash_table, 10, 41);
    hash_inserir(hash_table, 10, 10);
    hash_inserir(hash_table, 10, 8);
    hash_inserir(hash_table, 10, 7);
    hash_inserir(hash_table, 10, 13);
    hash_inserir(hash_table, 10, 52);
    hash_inserir(hash_table, 10, 1);
    hash_inserir(hash_table, 10, 89);
    hash_inserir(hash_table, 10, 17);
    hash_inserir(hash_table, 10, 41);
    //hash_inserir(hash_table, 10, 15);

    for(int i = 0; i < 10; i++) {
        printf("%d ", hash_table[i]);
    }
    printf("\n");

    hash_remover(hash_table, 10, 7);
    //hash_inserir(hash_table, 10, 66);

    for(int i = 0; i < 10; i++) {
        printf("%d ", hash_table[i]);
    }
    printf("\n");

    free(hash_table);

    return 0;
}