#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void direct_sort_recursivo(int v[], int n) {
    int menor = 0;

    for(int j = 1; j < n; j++) {
        if(v[j] < v[menor]) {
            menor = j;
        }
    }

    if(menor != 0) {
        swap(&v[menor], &v[0]);
    }
    
    if(n - 1 > 0) direct_sort_recursivo(v+1, n - 1);
}


int main() {
    int array[] = {9, 10, 2, 78, 23, 34, 90, -1, 80, 45, 18}; //11 elementos
    int n = sizeof(array) / sizeof(array[0]); //n = 11

    direct_sort_recursivo(array, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
