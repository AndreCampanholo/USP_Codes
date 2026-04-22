#include <stdio.h>

typedef struct tabela {
    int valor;
    int indice;
} tabela_indices;

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quicksort(int v[], int inicio, int final) {
    if (inicio < final) {
        int i = inicio, j = final;
        int pivo = v[(inicio + final) / 2];
        while (i <= j) {
            while (v[i] < pivo)
                i++;
            while (v[j] > pivo)
                j--;
            if (i <= j) {
                swap(&v[i], &v[j]);
                i++;
                j--;
            }
        }
        
        if(inicio < j){
            quicksort(v, inicio, j);
        } 
        if(i < final) {
            quicksort(v, i, final);
        }
    }
}

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

int buscar_sequencial_indexada(int v[], int n, int chave) {
    quicksort(v, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    int qtd_blocos = 3;
    int tam_blocos = n / qtd_blocos + 1;

    tabela_indices kindex[qtd_blocos];

    int k = 0;
    for(int i = 0; i < n; i += tam_blocos) {
        kindex[k].valor = v[i];
        kindex[k++].indice = i;
    }

    int indice = kindex[qtd_blocos - 1].indice, indice_chave;
    for(int i = 1; i < qtd_blocos; i++) {
        if(kindex[i].valor >= chave) {
            indice = kindex[i - 1].indice;

            indice_chave = buscar_sequencial(v + indice, n - indice, chave);
            if(indice_chave == -1) 
                return -1;
            else
                return indice + buscar_sequencial(v + indice, n - indice, chave);
        }
    }
    indice_chave = buscar_sequencial(v + indice, n - indice, chave);
    if(indice_chave == -1) 
        return -1;
    else
        return indice + buscar_sequencial(v + indice, n - indice, chave);
}

int main() {
    int v[] = {567, 592, 14, 387, 611, 876, 115, 321, 583, 38, 741, 811, 512};
    int n = sizeof(v) / sizeof(v[0]);

    int chave;
    scanf("%d", &chave);

    int indice_chave = buscar_sequencial_indexada(v, n, chave);

    printf("%d\n", indice_chave);

    return 0;
}