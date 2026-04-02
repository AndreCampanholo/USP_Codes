#include <stdio.h>

int soma_arranjo(int v[], int n) {
    if(n == 1) {
        return v[0];
    } else {
        return v[n - 1] + soma_arranjo(v, n - 1);
    }
}

int main() {
    int vetor[] = {1, 5, 7, 2, -1, 7};

    printf("%d\n", soma_arranjo(vetor, 6));

    return 0;
}