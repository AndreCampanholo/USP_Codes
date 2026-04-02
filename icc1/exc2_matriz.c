#include <stdio.h>

void mult_matriz(int lm1, int cm1, int lm2, int cm2, int matriz1[lm1][cm1], int matriz2[lm2][cm2]) {
    int matriz_resultado[lm1][cm2], i, j, k, soma;
    for(i  = 0; i < lm1; i++) {
        for(j = 0; j < cm2; j++) {
            soma = 0;
            for(k = 0; k < cm1; k++) {
                soma = soma + matriz1[i][k] * matriz2[k][j];
            }
            matriz_resultado[i][j] = soma;
            printf("%d  ", matriz_resultado[i][j]);
        }
        printf("\n");
    }

}

int main() {
    int lm1, cm1, lm2, cm2;
    scanf("%d %d %d %d", &lm1, &cm1, &lm2, &cm2);

    if(cm1 != lm2) {
        return 1;
    }

    int matriz1[lm1][cm1], matriz2[lm2][cm2], result[lm1][cm2];

    for(int i = 0; i < lm1; i++) {
        for(int j = 0; j < cm1; j++) {
            scanf("%d", matriz1[i][j]);
        }
    }
    for(int x = 0; x < lm2; x++) {
        for(int y = 0; y < cm2; y++) {
            scanf("%d", matriz1[x][y]);
        }
    }

    mult_matriz(lm1, cm1, lm2, cm2, matriz1, matriz2);
    printf("%d\n", mult_matriz);
}