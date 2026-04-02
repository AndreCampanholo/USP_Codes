#include <stdio.h>

int soma_vetor(int v[], int n) {
    if(n == 1) {
        return v[n - 1];
    }
    return v[n - 1] + soma_vetor(v, n - 1);
}

int main() {
    int vet[10] = {21, 9, 0, 2, 3, 20, 5, 5, 7, 8};

    printf("%d\n", soma_vetor(vet, 10));

    return 0;
}