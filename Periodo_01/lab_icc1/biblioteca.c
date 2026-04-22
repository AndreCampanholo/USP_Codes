#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int imprimir(int id, char *titulo, char *autor, int ano, int qtd) {
    printf("Livro %d:\n", id);
    printf("Titulo: %s\n", titulo);
    printf("Autor: %s\n", autor);
    printf("Ano: %d\n", ano);
    printf("Quantidade: %d\n", qtd);
}

int main() {
    int N;
    scanf("%d", &N);

    char **matriz_titulo = (char **)calloc(N, sizeof(char *));
    char **matriz_autor = (char **)calloc(N, sizeof(char *));
    int *matriz_ano = (int *)calloc(N, sizeof(int));
    int *qtd_repetidos = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        matriz_titulo[i] = (char *)malloc(100 * sizeof(char));
        matriz_autor[i] = (char *)malloc(50 * sizeof(char));
        qtd_repetidos[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        scanf(" %99[^,], %49[^,], %d", matriz_titulo[i], matriz_autor[i], &matriz_ano[i]);
        for (int j = 0; j < i; j++) {
            if (strcmp(matriz_titulo[j], matriz_titulo[i]) == 0 &&
                strcmp(matriz_autor[j], matriz_autor[i]) == 0 &&
                matriz_ano[j] == matriz_ano[i]) {
                qtd_repetidos[j]++;
                qtd_repetidos[i] = 0;
                break;
            }
        }
    }

    printf("Catalogo de Livros:\n");
    int f = 1;
    int livros_impressos = 0;
    for (int i = 0; i < N; i++) {
        if (qtd_repetidos[i] > 0) {
            livros_impressos++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (qtd_repetidos[i] > 0) {
            imprimir(f, matriz_titulo[i], matriz_autor[i], matriz_ano[i], qtd_repetidos[i]);
            if (f < livros_impressos) {
                printf("\n");
            }
            f++;
        }
    }

    for (int y = 0; y < N; y++) {
        free(matriz_titulo[y]);
        free(matriz_autor[y]);
    }
    free(matriz_titulo);
    free(matriz_autor);
    free(matriz_ano);
    free(qtd_repetidos);

    return 0;
}