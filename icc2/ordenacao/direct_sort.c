#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void direct_sort(int v[], int n) {

    for(int j = 0; j < n - 1; j++) {
        int menor = j;

        for(int i = j + 1; i < n; i++) {
            if(v[i] < v[menor]) {
                menor = i;
            }
        }

        swap(&v[menor], &v[j]);
    }

}


int main() {
    int array[] = {9, 10, 2, 78, 23, 34, 90, -1, 80, 45, 18}; //11 elementos
    int n = sizeof(array) / sizeof(array[0]); //n = 11

    direct_sort(array, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
