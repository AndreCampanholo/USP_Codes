#include <stdio.h>

int main() {
    int n, soma_linhas = 0, soma_colunas = 0, soma_diagonal_principal = 0, soma_diagonal_secundaria = 0, chave_magica;
    scanf("%d", &n);

    int matriz[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    //Soma das linhas e definição do valor mágico...
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            soma_linhas += matriz[i][j];
            if(i == 0) {
                chave_magica = soma_linhas;
            }
        }
        if(soma_linhas != chave_magica) {
            printf("Sadly, this isn't a magic square...\n");
            return 1;
        }
        soma_linhas = 0;
    }

    //Soma das colunas...
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            soma_colunas += matriz[j][i];
        }
        if(soma_colunas != chave_magica) {
            printf("Sadly, this isn't a magic square...\n");
            return 1;
        }
        soma_colunas = 0;
    }

    //Soma da diagonal principal...
    for(int i = 0; i < n; i++) {
        soma_diagonal_principal += matriz[i][i];
    }
    if(soma_diagonal_principal != chave_magica) {
        printf("Sadly, this isn't a magic square...\n");
        return 1;
    } 
    
    //Soma da diagonal secundaria...
    int k = 0;
    for(int j = n - 1; j >= 0; j--) {
        soma_diagonal_secundaria += matriz[k][j];
        k++;
    }
    if(soma_diagonal_secundaria != chave_magica) {
        printf("Sadly, this isn't a magic square...\n");
        return 1;
    }   

    printf("Look! A magic square! It's magic number is %d!\n", chave_magica);

    return 0;
}