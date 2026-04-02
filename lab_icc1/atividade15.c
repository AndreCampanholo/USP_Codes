#include <stdio.h>

int main() {
    int n; //cria uma variável inteira que representará o número de vezes que a série deve ser executada
    scanf("%d", &n); //lê o valor de 'n'

    double soma = 1, fat = 1; //cria variáveis decimais longas para o valor da soma (série) e o cáclculo do fatorial no denominador
                              //ambas inicializadas com 1, pois a soma sempre começa com 1 e o fatorial não pode ser multiplicado por zero
    int j = 0; //cria a variável inteira 'j' que será usada para controlar se o novo termo deve ser somado ou subtraído da série
               //trata-se de uma variável facultativa pois este controle pode ser feita com o contador 'i' usado no laço for 

    for(int i = 2; i <= n; i++) { //laço que termina apenas quando 'i' atinge o valor de 'n', portanto, executa a série até o termo desejado
        fat = fat * i; //calcula o valor do fatorial, usado no denominador, para cada termo
        if(j % 2 == 0) {
            soma = soma + (1.0 / fat);
        } else {                       //estrutura condicional que determina se o termo será somado ou subtraído da séria, realizando esta ação
            soma = soma - (1.0 / fat);
        }
        j++; //'j' é incrementado para o próximo ciclo
    }

    printf("%lf\n", soma); //imprime o valor da soma dos termos até o termo informado

    return 0;
}