#include <stdio.h>
#include <math.h> //incluimos a biblioteca math.h para podermos calcular a raiz do delta através da função sqrt()

int main() {
    int a, b, c; //variáveis inteiras que representam os coeficientes do polinômio do segundo grau
    float raiz1, raiz2, delta; //variáveis reais que representam as raízas da equação e o delta.
    scanf("%d", &a);
    scanf("%d", &b); //leitura dos coeficientes a partir do teclado
    scanf("%d", &c);

    delta = b * b - 4 * a * c; //varíavel 'delta' recebe o valor do delta da equação

    if(delta < 0) { 
        printf("NAO EXISTE RAIZ REAL\n"); //'delta' menor que 0 implica inexistência de raizes reais
    } else if (delta == 0) {
        raiz1 = -b / (2.0 * a); //'delta' igual a 0 implica uma única raiz real, ou entaõ duas raizes reais e iguais, como preferir
        printf("%.3f\n", raiz1); //imprime um valor único da raiz da equação com 3 casas decimais
    } else if (delta > 0) {
        raiz1 = (-b + sqrt(delta)) / (2.0 * a); //'delta' maior que 0 implica a existência de duas raizes reais e distintas
        raiz2 = (-b - sqrt(delta)) / (2.0 * a); //uma na qual subtrai-se a raiz de 'delta', e outra na qual soma-se a raiz de 'delta'
        if(raiz1 > raiz2) {
            printf("%.3f %.3f\n", raiz2, raiz1); 
        } else {                                 //imprime as raizes distintas em ordem crescente com 3 casas decimais
            printf("%.3f %.3f\n", raiz1, raiz2);
        }
    }

    return 0;
}