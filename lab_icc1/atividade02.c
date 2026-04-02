#include <stdio.h>

int main() {
    char nome[50];
    scanf("%49[^\n]", nome);

    printf("Bom dia, %s!\n", nome);

    return 0;
}