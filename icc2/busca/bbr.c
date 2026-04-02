#include <stdio.h>

int bbr(int v[], int chave, int ini, int fim) {
    int meio = (ini + fim) / 2;
    if(v[meio] > chave) {
        bbr(v, chave, ini, meio - 1);
    } else if(v[meio] < chave) {
        bbr(v, chave, meio + 1, fim);
    } else {
        return meio;
    }
}

int main() {
    int v1[] = {-1, 0, 2, 3, 4, 9, 23, 29, 38};
    int v2[] = {-9, -2, 1, 2, 3, 8, 11, 12, 32};

    printf("Índice do 9 no v1: %d\n", bbr(v1, 9, 0, 8));
    printf("Índice do 11 no v2: %d\n", bbr(v2, 11, 0, 8));

    return 0;
}