#include <stdio.h>

int main() {
    int N, cont = 1, qtd_par = 0, qtd_impar = 0;
    scanf("%d", &N);

    char palavra[N];
    scanf("%s", &palavra);

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(palavra[i] == palavra[j]) {
                cont++;
            }
        }
        if(cont % 2 == 0) {
            qtd_par++;
        } else {
            qtd_impar++;
        }
        cont = 1;
    }
    for(int i = N; i >= 0; i--) {
        for(int j = i - 1; j > 0; j--) {
            if(palavra[i] == palavra[j]) {
                cont++;
            }
        }
        if(cont % 2 == 0) {
            qtd_impar--;
        }
        cont = 1;
    }

    if(qtd_impar > 1) {
        printf("Nao");
    } else if(qtd_par % 2 == 0) {
        printf("Sim");
    } else if((qtd_par % 2 == 1) && (qtd_impar <= 1)) {
        printf("Sim");
    }
}