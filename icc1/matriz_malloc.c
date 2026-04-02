#include <stdio.h>
#include <stdlib.h>

int multiplicar(int lin1, int col1, int lin2, int col2, int matriz1[][col1], int matriz2[][col2]) {
    int matriz_result[lin1][col2], k;
    for(int i = 0; i < lin1; i++) {
        for(int j = 0; j < col2; j++) {
            int soma = 0;
            for(k = 0; k < col1; k++) {
                soma += matriz1[i][k] *  matriz2[k][j];
            }
            matriz_result[i][j] = soma;
            printf("%d  ", matriz_result[i][j]);
        }
        printf("\n");
    }
    return matriz_result[lin1][col2];
}

int ler_matriz(int lin, int col, int matriz[lin][col]) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz[lin][col];
}

int main() {
    int lin1, col1, lin2, col2;
    scanf("%d %d %d %d", &lin1, &col1, &lin2, &col2);

    if(col1 != lin2) {
        return 1;
    }

    int matriz1[lin1][col1], matriz2[lin2][col2], matriz_resultado[lin1][col2];
    matriz1[lin1][col1] = ler_matriz(lin1, col1, matriz1[lin1][col1]);
    matriz1[lin2][col2] = ler_matriz(lin2, col2, matriz1[lin2][col2]);
    matriz_resultado[lin1][col2] = multiplicar(lin1, col1, lin2, col2, matriz1[lin1][col1], matriz2[lin2][col2]);

    return 0;
}