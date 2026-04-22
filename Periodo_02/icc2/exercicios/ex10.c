#include <stdio.h>
//essa porra não faz nada to com preguiça de fazer funcionar

int busca_binaria(int n, int v[], int chave) {
    int meio = (n - 1) / 2;
    if(chave == v[meio]) {
        return meio;
    } else if(chave < v[meio]) {
        meio = meio / 2;
        return busca_binaria(meio, v, chave);
    } else {
        meio = (meio + n - 1) / 2;
    }
}

int main() {
    int vetor[] = {1, 3, 7, 8, 10, 20, 21, 24, 34, 40};

    int chave = 34;

    busca_binaria(10, vetor, chave);
    return 0;
}