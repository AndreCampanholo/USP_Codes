#include <stdio.h>

void copia_string(char string[], char nova_string[]) {
    int i;
    while(string[i++] != '\0');
    int tamanho_string = i;
    for(i = 0; i < tamanho_string; i++) {
        nova_string[i] = string[i];
    }
}

int main() {
    char str[15], *str2;
    scanf("%s", str);

    copia_string(str, str2);

    printf("%s\n", str2);

    return 0;
}