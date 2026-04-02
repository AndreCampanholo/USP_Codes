#include <stdio.h>

void swap(int **a, int **b) { //função swap que inverte os valores de dois livros quaisquer por meio de ponteiros para ponteiros para o caso em que algum dos ponteiros aponta para NULL
    int *temp; //cria um ponteiro para inteiro temp
    temp = *a; //'temp' aponta para onde 'a' aponta, no caso, para o ponteiro que foi inserido como primeiro parâmetro 
    *a = *b; //'a' aponta para onde 'b' aponta, no caso, para o poneiro inserido como segundo parâmetro
    *b = temp; //'b' aponta para onde 'temp' aponta, no caso, para onde 'a' apontava originalmente
}

int main() {
    int livro1, livro2, livro3; //cria variáveis inteiras para os códigos dos livros 1 2 e 3
    scanf("%d %d %d", &livro1, &livro2, &livro3); //lê o código dos livros 1 2 e 3

    int *p1 = &livro1, *p2 = &livro2, *p3 = &livro3; //cria ponteiros para os livros 1 2 e 3

    int acao1, acao2, acao3; //cria variáveis inteiras que representam o que acontecerá com os livros
    scanf("%d %d %d", &acao1, &acao2, &acao3); //lê os valores inteiros que representam o que acontecerá com os livros

    switch(acao1) { //switch case que executa a ação determinada para cada livro
        case -1: //'acao1' = -1, portanto o livro será retirado da prateleira e seu ponteiro deve ser anulado
            p1 = NULL; 
            break;
        case 0: //'acao1' = 0, portanto o livro deve ter seu código atualizado, incrementando-o em 1
            *p1 += 1; 
            break;
        case 2: //'acao1' = 2, portanto o livro 1 foi trocado de lugar com o livro 2, os códigos dos ponteiros devem, portanto, serem trocados
            swap(&p1, &p2); //troca os valores de 'livro1' e 'livro2' através dos ponteiros 'p1' e 'p2', utilizando os endereços dos ponteiros pois a função swap utiliza ponteiros para ponteiros
            break;
        case 3:
            swap(&p1, &p3); //troca os valores de 'livro1' e 'livro3' através dos ponteiros 'p1' e 'p3', utilizando os endereços dos ponteiros pois a função swap utiliza ponteiros para ponteiros
            break;
        default:
            break;
    }
    switch(acao2) {
        case -1:
            p2 = NULL;
            break;
        case 0:
            *p2 += 1;
            break;
        case 1:             //idem acima
            swap(&p1, &p2);
            break;
        case 3:
            swap(&p2, &p3);
            break;
        default:
            break;
    }
    switch(acao3) {
        case -1:
            p3 = NULL;
            break;
        case 0:
            *p3 += 1;
            break;
        case 1:             //idem acima
            swap(&p1, &p3);
            break;
        case 2:
            swap(&p2, &p3);
            break;
        default:
            break;
    }

    //impressão dos cartões
    if(p1 == NULL) {
        printf("cartao1 -> Livro fora da estante\n"); //caso o 'p1' aponte para NULL, imprime que o livro está fora da estante
    } else {
        printf("cartao1 -> %d\n", *p1); //caso contrário, informa o código do livro que está no lugar
    }
    if(p2 == NULL) {
        printf("cartao2 -> Livro fora da estante\n");
    } else {                                          //idem acima
        printf("cartao2 -> %d\n", *p2);
    }
    if(p3 == NULL) {
        printf("cartao3 -> Livro fora da estante\n");
    } else {                                          //idem acima
        printf("cartao3 -> %d\n", *p3);
    }

    return 0;
}