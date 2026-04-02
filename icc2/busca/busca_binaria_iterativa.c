#include <stdio.h>

int bbi(int v[], int chave, int ini, int fim) {
    int meio = (ini + fim) / 2;
    while(v[meio] != chave) {
        if(v[meio] > chave) {
            meio = (ini + meio - 1) / 2;
        } else if(v[meio] < chave) {
            meio = (meio + 1 + fim) / 2;
        }
    }

    return meio;
}

int main() {
    int v1[] = {-1, 0, 2, 3, 4, 9, 23, 29, 38};
    int v2[] = {-9, -2, 1, 2, 3, 8, 11, 12, 32};

    printf("Índice do 9 no v1: %d\n", bbi(v1, 38, 0, 8));
    printf("Índice do 11 no v2: %d\n", bbi(v2, -9, 0, 8));

    return 0;
}