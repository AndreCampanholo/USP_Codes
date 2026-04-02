#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maior_vetor(int v[], int n) {
    if(n == 0) {
        return v[0];
    }
    if(v[n - 1] > v[n - 2]) {
        swap(&v[n - 1], &v[n - 2]);
    }
    return maior_vetor(v, n - 1);
}

int main() {
    int vet[10] = {1, 9, 0, 2, 3, 20, 5, 6, 7, 8};

    printf("%d\n", maior_vetor(vet, 10));

    return 0;
}