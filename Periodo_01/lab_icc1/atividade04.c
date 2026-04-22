#include <stdio.h>

int main() {
    int binario, decimal, d0, d1, d2, d3; //cria variáveis inteiras para a entrada binaria, cada bit do número binário e a saída decimal
    scanf("%d", &binario); //lê a entrada binária fornecida pelo usuário

    d0 = binario % 10; //'d0' recebe primeiro bit do número binário
    d1 = (binario / 10) % 10; //'d1' recebe segundo bit do número binário
    d2 = (binario / 100) % 10; //'d2' recebe terceiro bit do número binário
    d3 = binario / 1000; //'d3' recebe último bit do número binário

    decimal = d3 * 8 + d2 * 4 + d1 * 2 + d0 * 1; //decimal recebe a soma de cada bit multiplicado por 2 elevado ao seu índice

    printf("%d\n", decimal); //imprime o número decimal

    return 0;
}