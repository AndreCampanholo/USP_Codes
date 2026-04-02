#include <stdio.h>
#include <stdlib.h> //devido ao uso das funções de alocação dinâmica de memória devemos incluir a biblioteca stdlib.h

void swap(int *a, int *b) { //função que realiza a troca dos valores dos ponteiros 'pt1' e 'pt2' sem o uso de uma variável temporária
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int *pt1, *pt2; //cria ponteiros para inteiros
    pt1 = (int *)malloc(sizeof(int)); //aloca memória dinamicamente para um inteiro (4 bytes) para o ponteiro 'pt1'
    pt2 = (int *)malloc(sizeof(int)); //aloca memória dinamicamente para um inteiro (4 bytes) para o ponteiro 'pt2'

    scanf("%d %d", pt1, pt2); //lê valores inteiros para serem armazenados na memória alocada para os ponteiros

    printf("%d %d\n", *pt1, *pt2); //imprime os valores de 'pt1' e 'pt2' antes de serem trocados 

    swap(pt1, pt2); //chama a função swap() que troca os valores de 'pt1' e 'pt2' 

    printf("%d %d\n", *pt1, *pt2); //imprime os valores de 'pt1' e 'pt2' trocados

    free(pt1); //libera a memória alocada para 'pt1'
    free(pt2); //libera a memória alocada para 'pt2'

    return 0;
}