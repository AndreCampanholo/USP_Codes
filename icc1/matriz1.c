#include <stdio.h>

int main() {
    int matriz[3][4], soma = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            soma += matriz[i][j];
        }
    }

    printf("----------------\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            if(j == 3) {
                printf("%d\n", matriz[i][j]);
            } else {
            printf("%d  ", matriz[i][j]);
            }
        }
    }
    printf("%d\n", soma);
}