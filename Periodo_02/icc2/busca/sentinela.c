#include <stdio.h>

int buscar_sequencial_sentinela(int v[], int n, int chave) {
    v[n - 1] = chave;

    int i = 0;
    while(v[i] != chave) i++;

    if(i != n - 1) return i;
    else return -1;
}

int main() {
    //Último elemento é inválido, será substituído pela chave de busca como sentinela dentro da função de busca
    int v[] = {9, 10, 2, 3, 1, 48, 7, -999};
    int n = sizeof(v) / sizeof(v[0]);

    int chave;
    scanf("%d", &chave);

    int indice_chave = buscar_sequencial_sentinela(v, n, chave);

    printf("%d\n", indice_chave);

    return 0;
}