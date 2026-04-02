#include <stdio.h>

int maior(int v[], int n) {
    if(n == 1) {
        return v[0];
    } else {
        int aux = maior(v, n - 1);
        if(aux > v[n - 1]) {
            return aux;
        } else {
            return v[n - 1];
        }
    }
}

int main() {
    int vetor[] = {1, 4, 9, -2, 14, 1};

    printf("%d\n", maior(vetor, 6));

    return 0;
}