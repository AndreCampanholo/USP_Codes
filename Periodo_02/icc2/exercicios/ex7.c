#include <stdio.h>

int qtd_impares(int n, int v[]) {
    if(n < 0) {
        return 0;
    } else {
        if(v[n - 1] % 2 == 1) {
            return 1 + qtd_impares(n - 1, v);
        } else {
            return qtd_impares(n - 1, v);
        }
    }
}

int main() {
    int v[] = {1, 2, 3, 1, 2, 1, 1, 0, 9};

    printf("%d\n", qtd_impares(9, v));

    return 0;
}