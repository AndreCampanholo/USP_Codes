#include <stdio.h>

int palindromo(char *str, int tamanho) {
    if(str[0] != str[tamanho - 1]) {
        return 0;
    } else {
        return palindromo(str + 1, tamanho - 1);
    }
}

int main() {
    char palavra[10] = "arira";

    if(palindromo(palavra, 5)) {
        printf("Sim.\n");
    } else {
        printf("Não.\n");
    }

    return 0;
}