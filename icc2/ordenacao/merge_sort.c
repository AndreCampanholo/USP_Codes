#include <stdio.h>

void intercala(int v[], int ini, int meio, int fim) {
    int i, j, k, n1, n2;

    n1 = meio - ini + 1;
    n2 = fim - meio;

    int L[n1 + 1], R[n2 + 1];

    for(i = 0; i < n1; i++)
        L[i] = v[ini + i];
    L[n1] = 9999;
    for(j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];
    R[n2] = 9999;
    
    i = j = 0;
    for(k = ini; k <= fim; k++) {
        if(L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
    }

    return;
}

void merge_sort(int v[], int ini, int fim) {
    int meio = (ini + fim) / 2;
    
    if(ini < fim) {
        merge_sort(v, ini, meio);
        merge_sort(v, meio + 1, fim);
        intercala(v, ini, meio, fim);
    }
}

int main() {
    int array[] = {1, 8, 19, 2, 0, 15};
    int n = sizeof(array) / sizeof(int);

    merge_sort(array, 0, n - 1);

    for(int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
}