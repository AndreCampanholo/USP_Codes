#include <stdio.h>

int main() {
    int numero, dobro; //cria variáveis inteiras, uma para receber o número informado pelo usuário, outro para imprimir a multiplicação do número por 2
    scanf("%d", &numero); //lê um inteiro na entrada e atribui à variável 'numero'

    dobro = numero * 2; //variável 'dobro' recebe a multiplicação de 'numero' por 2

    printf("%d\n", dobro); //imprime o valor inteiro de dobro

    return 0; //indica sucesso e finaliza execução do código
}