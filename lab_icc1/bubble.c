#include <stdio.h>

void bubblesort(int *vetor, int tamanho) {
    int x, y, temp;
    for(x = 0; x < tamanho - 1; x++) {
        for(y = x + 1; y < tamanho; y++) {
            if(vetor[x] >= vetor[y]) {
                temp = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int array[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    bubblesort(array, N);
    for(int a = 0; a < N; a++){
        if(a == N - 1) {
            printf("%d\n", array[a]);
        } else {
            printf("%d ", array[a]);
        }
    }
}