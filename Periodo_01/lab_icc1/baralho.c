#include <stdio.h>

const char naipes[] = {'C', 'O', 'P', 'E'};
const char valores[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};

int main() {
    int n;
    scanf("%d", &n);

    char valor, naipe;
    
    char carta[3];

    char baralho[4][13];

    for(int x = 0; x < n; x++) {
        scanf("%s", &carta);

        if(carta[2] == 0) {
            valor = carta[0];
            naipe = carta[1];
        } else {
            valor = '1';
            naipe = carta[2];
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 13; j++) {
                if (valor == valores[j]);
            }
        }
        printf("%s %c\n", valor, naipe);
    }



    // for(int i = 0; i < 4; i++) {
    //     for(int j = 0; j < 13; j++) {
            
    //     }
    // }
}