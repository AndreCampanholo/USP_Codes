#include <stdio.h>

void swap(int *a, int *b) { //função que realiza a troca dos valores de dois inteiros por meio de uma variável temporária
    int temp; //declaração da variável temporária inteira
    temp = *a;
    *a = *b;   //troca dos valores de a e b
    *b = temp;
}

int main() {
    int canal1, canal2; //declaração das variáveis inteiras que representam os canais de cada televisão
    scanf("%d %d", &canal1, &canal2); //lê os canais de cada televisão

    int *p1, *p2; //declaração dos ponteiros para a tv1 e a tv2
    p1 = &canal1; //o ponteiro 'p1' aponta para o endereço de 'canal1'
    p2 = &canal2; //o ponteiro 'p2' aponta para o endereço de 'canal2'

    swap(p1, p2); //chama a função swap() por meio dos ponteiros 'p1' e 'p2', portanto, a e b correspondem aos valores de 'canal1' e 'canal2'

    printf("%d %d\n", canal1, canal2); //imprime os valores de 'canal1' e 'canal2' na ordem oposta a qual foram lidos

    return 0;
}