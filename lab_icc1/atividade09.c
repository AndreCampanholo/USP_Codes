#include <stdio.h>

int main() {
    const int a, b; //cria constantes inteiras para a posição inicial de cap e a posição de alanzoka, respectivamente
    int posicao_cap; //cria uma variável inteira para a posição de cap ao decorrer de seus deslocamentos
    float distancia = -0.5; //cria uma variável real para a distância percorrida por cap até encontrar alan, inicializada com -0.5 para que o primeiro deslocamento resulte em distância 1

    scanf("%d %d", &a, &b); //lê as posições iniciais de cap e alan
    posicao_cap = a; //inicializa a posição variável de cap como sua posição inicial

    if(a < b) { //estrutura condicional para diferenciar casos em que cap está à direita de alan a casos em que cap está à esquerda
        int i = 0, j = 1; //inicializa variáveis que serão usadas nos laços while para controlar se o deslocamento de cap será para a esquerda ou para a direita (i), e quantos passos serão dados em cada direção (j)
        while(posicao_cap < b) { 
            if(i % 2 == 0) {
                posicao_cap = a + j;
            } else {                 //se 'i', for par, cap se deslocará, a partir da posição inicial, j casas para a direita, caso contrário, j casas para a esquerda
                posicao_cap = a - j;
            }
            i++; //'i' alterna entre valores pares e ímpares
            j = j * 2; //'j' sempre é o dobro do valor anterior
            distancia = 2 * distancia + 2; //a cada movimentação de cap, a distância é multiplicada por 2 e acrescida em 2
        }
        distancia = distancia - (posicao_cap - b); //'distância' equivale a distância total percorrida menos a distância entre a posição final de cap 'posicao_cap' e alan 'b'
    } else if(a > b) {
        int i = 0, j = 1; //inicializa variáveis que serão usadas nos laços while para controlar se o deslocamento de cap será para a esquerda ou para a direita (i), e quantos passos serão dados em cada direção (j)
        while(posicao_cap > b) {
            if(i % 2 == 0) {
                posicao_cap = a + j;
            } else {                 //se 'i', for par, cap se deslocará, a partir da posição inicial, j casas para a direita, caso contrário, j casas para a esquerda
                posicao_cap = a - j;
            }
            i++; //'i' alterna entre valores pares e ímpares
            j = j * 2; //'j' sempre é o dobro do valor anterior
            distancia = 2 * distancia + 2; //a cada movimentação de cap, a distância é multiplicada por 2 e acrescida em 2
        }
        distancia = distancia - (b - posicao_cap); //'distância' equivale a distância total percorrida menos a distância entre a posição final de cap 'posicao_cap' e alan 'b'
    } else {
        distancia = 0; //caso cap e alan estejam, desde o início, na mesma posição, a distância percorrida por cap é 0 
    }

    printf("%.0f\n", distancia); //imprime a distância percorrida por cap com nenhuma casa decimal

    return 0;
}