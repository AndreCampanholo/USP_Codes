#include <stdio.h>

int main() {
    int numero, qtd_zeros = 0; //cria variáveis que receberá um número de entrada e outra que armazenará a quantidade de zeros 'numero' fatorial possui, inicializada com 0
    scanf("%d", &numero); //lê um número de entrada e armazena na variável 'numero'

    //laço que calcula quantidade de zeros que 'numero' fatorial possui
    while(numero >= 5) { //o laço é executado apenas se 'numero' é maior que 5, pois caso contrário, não é possível que hajam os fatores 5 e 2 que originam zeros a direita
        numero = numero / 5; //divide o número por 5 e atribui este valor à variável 'numero'
        qtd_zeros += numero; //'qtd_zeros' é incrementado com o valor resultante da variável 'numero' a cada iteração do laço
    }

    printf("%d\n", qtd_zeros); //imprime a quantidade de zeros

    return 0;
}