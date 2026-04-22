#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange_heap(int v[], int i, int tam_heap) {
    int aux, maior, esq, dir;

    esq = 2 * i + 1;
    dir = 2 * i + 2;
    maior = i;

    if(esq < tam_heap && v[esq] > v[maior]) 
        maior = esq;

    if(dir < tam_heap && v[dir] > v[maior]) 
        maior = dir;

    if(i != maior) {
        swap(&v[i], &v[maior]);
        rearrange_heap(v, maior, tam_heap);
    }
}

void build_heap(int v[], int tam_heap) {
    for(int i = tam_heap/2 - 1; i >= 0; i--) {
        rearrange_heap(v, i, tam_heap);
    }
}

void heap_sort(int v[], int tam_heap) {
    build_heap(v, tam_heap);

    for(int i = tam_heap - 1; i > 0; i--) {
        swap(&v[0], &v[i]);
        rearrange_heap(v, 0, i);
    }
}

int main() {
    int array[] = {9, 10, 2, 78, 23, 34, 90, -1, 80, 45, 18}; //11 elementos
    int n = sizeof(array) / sizeof(array[0]); //n = 11

    //build_heap(array, n);

    heap_sort(array, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}