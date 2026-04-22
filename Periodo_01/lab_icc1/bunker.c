#include <stdio.h>

typedef struct {
    char nome[100], cidade[100];
    int telefone;
} registro;

int main() {
    char nome_arquivo[100];
    scanf("%s", nome_arquivo);

    FILE *f;
    f = fopen(nome_arquivo, "r");
    if(f == NULL) {
        printf("Arquivo %s não encontrado.\n", nome_arquivo);
        return 1;
    }

    int linhas = 0;
    int c;
    while((c = fgetc(f)) != EOF) {
        if(c == '\n')
        linhas++;

    }
    rewind(f);

    registro pessoa[linhas];
    int j = 0, i = 0;
    while(fscanf(f, " %[^,], %d, %[^\n]", pessoa[j].nome, &pessoa[j].telefone, pessoa[j].cidade) == 3) {
        j++;
    }

    char comando = 1, operacao[4], indice[2];
    while(comando != 0) {
        scanf(" %s[^ ] %[^,], %d, %[^\n]", operacao, pessoa[j].nome, &pessoa[j].telefone, pessoa[j].cidade);
        if(operacao == "DEL") {
            indice[1] = pessoa[j].nome;
        }
        j++;
    }

    for(int i = 0; i < j; i++) {
        if(pessoa[i].telefone != 0) {
            printf("%s, %d, %s\n", pessoa[i].nome, pessoa[i].telefone, pessoa[i].cidade);
        }
    }

    free(indice);
    fclose(f);
}