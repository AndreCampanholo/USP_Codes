#include <stdio.h>

int encontrar_caminho(char **labirinto, int **visitado, int linha, int coluna, int lin, int col) {
    if (linha < 0 || linha >= lin || coluna < 0 || coluna >= col || 
        labirinto[linha][coluna] == '#' || visitado[linha][coluna]) {
        return 0;
    }

    visitado[linha][coluna] = 1;

    if (labirinto[linha][coluna] == 'P') {
        return 1;
    }

    int direcoes[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int proxima_linha = linha + direcoes[i][0];
        int proxima_coluna = coluna + direcoes[i][1];
        if (encontrar_caminho(labirinto, visitado, proxima_linha, proxima_coluna, lin, col)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int lin, col;
    scanf("%d %d", &lin, &col);

    char **labirinto = (char **)malloc(lin * sizeof(char *));
    int **visitado = (int **)malloc(lin * sizeof(int *));
    for (int i = 0; i < lin; i++) {
        labirinto[i] = (char *)malloc(col * sizeof(char));
        visitado[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            visitado[i][j] = 0;
        }
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            scanf(" %c", &labirinto[i][j]);
        }
    }

    int posicao_linha = -1, posicao_coluna = -1;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (labirinto[i][j] == 'J') {
                posicao_linha = i;
                posicao_coluna = j;
            }
        }
    }

    if (encontrar_caminho(labirinto, visitado, posicao_linha, posicao_coluna, lin, col)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    for (int i = 0; i < lin; i++) {
        free(labirinto[i]);
        free(visitado[i]);
    }
    free(labirinto);
    free(visitado);

    return 0;
}