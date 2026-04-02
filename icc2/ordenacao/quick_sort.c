#include <stdio.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void quick_sort(int v[], int inicio, int final) {
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
            quick_sort(v, inicio, j);
        } 
        if(i < final) {
            quick_sort(v, i, final);
        }
    }
}

int main() {
    int array[] = {1, 7, 19, 2, 0, 15};
    int n = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}