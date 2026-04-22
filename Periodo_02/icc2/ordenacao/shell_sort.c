#include <stdio.h>

void shell_sort(int v[], int n, int incrementos[], int numinc) {
    int incr, i, j, h, aux;
    for(incr = 0; incr < numinc; incr++) {
        h = incrementos[incr];
        for(i = h; i < n; i++) {
            aux = v[i];
            for(j = i - h; j >= 0 && v[j] > aux; j -= h)
                v[j + h] = v[j];
            v[j + h] = aux;
        }
    }
}

int main() {
    int array[] = {9, 10, 2, 78, 23, 34, 90, -1, 80, 45, 18}; //11 elementos
    int n = sizeof(array) / sizeof(array[0]); //n = 11

    int increments[] = {5, 3, 1};

    shell_sort(array, n, increments, 3);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}