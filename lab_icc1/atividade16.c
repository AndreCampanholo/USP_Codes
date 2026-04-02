#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho_titulo;
    scanf("%d", &tamanho_titulo);
    while (getchar() != '\n');

    char titulo[tamanho_titulo + 1];
    fgets(titulo, tamanho_titulo + 1, stdin);
    while(getchar() != '\n');

    int *letras_iguais, qtd_impar = 0;
    letras_iguais = (int *)calloc(tamanho_titulo, sizeof(int));

    for(int i = 0; i < tamanho_titulo - 1; i++) {
        letras_iguais[i]++; 
        int x = i - 1;
        if(x >= 0) {
            for(; x >= 0; x--) {
                if(titulo[i] == titulo[x]) {
                    letras_iguais[i]--;
                    break;;
                }
            }
        } else {
            for(int j = i + 1; j < tamanho_titulo; j++) {
                if(titulo[i] == titulo[j]) {
                    letras_iguais[i]++;
                }
        }
        }
    }

    for(int i = 0; i < tamanho_titulo; i++) {
        printf("%d ", letras_iguais[i]);
        if(letras_iguais[i] % 2 == 1) {
            qtd_impar++;
        }
    }

    if (qtd_impar > 1) {
        printf("Nao\n");
    } else {
        printf("Sim\n");
    }

    free(letras_iguais);
    
    return 0;
}