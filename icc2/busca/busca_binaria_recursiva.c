#include <stdio.h>

int busca_binaria(int v[], int inicio, int fim, int chave) {
    int meio = (inicio + fim) / 2;
    if(v[meio] == chave) {
        return meio;
    }
    if(v[meio] > chave) {
        busca_binaria(v, inicio, meio - 1, chave);
    } else {
        busca_binaria(v, meio + 1, fim, chave);
    }
}

int main() {
    int v1[] = {-1, 0, 2, 3, 4, 9, 23, 29, 38};
    int v2[] = {-9, -2, 1, 2, 3, 8, 11, 12, 32};

    printf("Índice do 9 no v1: %d\n", busca_binaria(v1, 0, 8, 9));
    printf("Índice do 11 no v2: %d\n", busca_binaria(v2, 0, 8, 11));

    return 0;
}