#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');

    char **jogos = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        jogos[i] = (char *)calloc(51, sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        fgets(jogos[i], 51, stdin);
        int tamanho = strlen(jogos[i]);
        if (tamanho > 0 && jogos[i][tamanho - 1] == '\n') {
            jogos[i][tamanho - 1] = '\0';
        }
    }

    qsort(jogos, n, sizeof(char *), compara_strings);

    char jogo_desejado[51];
    fgets(jogo_desejado, 51, stdin);
    int tamanho = strlen(jogo_desejado);
    if (tamanho > 0 && jogo_desejado[tamanho - 1] == '\n') {
        jogo_desejado[tamanho - 1] = '\0';
    }

    int menor = 0, maior = n - 1, meio, result = -1;
    while (menor <= maior) {
        meio = (menor + maior) / 2;
        int comparacao = strcmp(jogos[meio], jogo_desejado);
        if (comparacao == 0) {
            result = meio;
            break;
        } else if (comparacao > 0) {
            maior = meio - 1;
        } else {
            menor = meio + 1;
        }
    }

    if (result != -1) {
        printf("Jogo encontrado na posição %d\n", result);
    } else {
        printf("Jogo nao encontrado\n");
    }

    for (int i = 0; i < n; i++) {
        free(jogos[i]);
    }
    free(jogos);

    return 0;
}