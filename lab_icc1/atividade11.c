#include <stdio.h>

int main() {
    int valor_tesouro; //cria uma variável inteira para o valor inicial do tesouro
    scanf("%d", &valor_tesouro); //lê o valor inicial do tesouro e armazena na variável 'valor_tesouro'

    printf("Valor inicial do tesouro: %d\n", valor_tesouro); //imprime o valor inicial do tesouro

    int *p; //cria o ponteiro para inteiro 'p'
    p = &valor_tesouro; //'p' aponta para o endereço de 'valor_tesouro'

    printf("Valor do tesouro usando mapa: %d\n", *p); //imprime o valor do tesouro usando o mapa, ou seja, por meio do ponteiro 'p'

    *p += 10; //adiciona 10 moedas ao tesouro por meio do ponteiro 'p', portanto, incrementa o valor de 'valor_tesouro' em 10

    printf("Valor do tesouro usando mapa depois de adicionarmos 10 moedas: %d\n", *p); //imprime o valor do tesouro usando o mapa 'p' depois de serem adicionadas 10 moedas

    int **pp; //cria o ponteiro para ponteiro inteiro 'pp'
    pp = &p; //o ponteiro para ponteiro 'pp' aponta para o endereço do ponteiro 'p', portanto, o conteúdo/valor de 'pp' corresponde ao valor de 'valor_tesouro'

    printf("Valor do tesouro usando mapa para o mapa: %d\n", **pp); //imprime o valor do tesouro usanto o mapa para o mapa 'pp'

    **pp += 10; //adiciona 10 moedas ao tesouro através do ponteiro para ponteiro 'pp', portanto, incrementa o valor de 'valor_tesouro' em 10

    printf("Valor do tesouro usando mapa para o mapa depois de adicionarmos 10 moedas: %d\n", **pp); //imprime o valor do tesouro usando o ponteiro para ponteiro 'pp'

    return 0;
}