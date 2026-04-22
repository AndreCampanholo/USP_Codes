#include <stdio.h>

int main() {
    float numero1, numero2, resultado; //cria variáveis reais para 2 números de entrada e o resultado da operação matemática
    char operacao; //cria uma variável de caracter pra a operação matemática a ser realizada

    scanf("%f %c %f", &numero1, &operacao, &numero2); //lê, e uma única linha, uma expressão aritmética a ser calculada

    switch(operacao) { //comando switch que resulta em diferente saídas de acordo com a variável 'operacao'
        case '+':  
            resultado = numero1 + numero2;
            break;
        case '-':
            resultado = numero1 - numero2;
            break;                         //estrutura condicional que calcula o resultado de acordo com a operação informada
        case '*':                           
            resultado = numero1 * numero2;
            break;
        case '/':
            resultado = numero1 / numero2;
            break;
        default:
        return 1; //default usado em caso de erro: operação informada seja inválida ou desconhecida
    }

    printf("%.2f\n", resultado); //imprime o resultado com 2 casas decimais

    return 0;
}