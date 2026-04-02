#include <stdio.h>

int main() {
    FILE *f;

    int tamanho = 0;

    char nome_arquivo[100], c;
    scanf("%99s", nome_arquivo);

    f = fopen(nome_arquivo, "r");
    if (f == NULL) {
        printf("Arquivo %s não foi encontrado.\n", nome_arquivo);
        return 1;
    }

    int g;
    while((g = fgetc(f)) != EOF) {
        tamanho++;
    }

    printf("%d\n", tamanho);

    fclose(f);
    return 0;
}