#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int v[], int n) {
    for(int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        for(j = i - 1; j >= 0 && aux < v[j]; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = aux;
    }
}

int main() {
    int array[] = {9, 10, 2, 78, 23, 34, 90, -1, 80, 45, 18}; //11 elementos
    int n = sizeof(array) / sizeof(array[0]); //n = 11

    insertion_sort(array, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}