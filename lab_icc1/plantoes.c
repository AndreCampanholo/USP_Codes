#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[101], assunto[101];
    int numero_usp;
} discente;

int main() {
    int N;
    scanf("%d", &N);
    
    discente *discentes, *discentes_novos, nome, assunto;
    discentes = (discente *)calloc(N, sizeof(discente));

    for(int i = 0; i < N; i++) {
        scanf(" %[^\n]", discentes[i].nome);
        scanf("%d", &discentes[i].numero_usp);
        scanf(" %[^\n]", discentes[i].assunto);
    }

    int M;
    scanf("%d", &M);

    discentes_novos = (discente *)realloc(discentes, (N + M) * sizeof(discente));
    discentes = discentes_novos;

    for(int j = 0; j < M; j++) {
        scanf(" %[^\n]", discentes[j + N].nome);
        scanf("%d", &discentes[j + N].numero_usp);
        scanf(" %[^\n]", discentes[j + N].assunto);
    }

    for(int x = 0; x < N + M; x++) {
        printf("Discente %d: \n", x + 1);
        printf("Nome: %s\n", discentes[x].nome);
        printf("Número USP: %d\n", discentes[x].numero_usp);
        printf("Assunto: %s\n", discentes[x].assunto);
        printf("\n");
    } 

    free(discentes);
    return 0;
}