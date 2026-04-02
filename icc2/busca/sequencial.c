#include <stdio.h>

int buscar_sequencial(int v[], int n, int chave) {
    int encontrou = 0, indice;
    for(int i = 0; i < n; i++) {
        if(v[i] == chave) {
            encontrou = 1;
            indice = i;
            break;
        }
    }
    if(encontrou) return indice;
    else return -1;
}

int main() {
    int v[] = {1, 9, 0, 8, 3, 5, 10};
    int n = sizeof(v) / sizeof(v[0]);

    int chave;
    scanf("%d", &chave);

    int indice_chave = buscar_sequencial(v, n, chave);

    printf("%d\n", indice_chave);
    
    return 0;
}