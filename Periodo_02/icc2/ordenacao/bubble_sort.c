#include <stdio.h>

void bubble_sort(int v[], int n) {
    int aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main() {
    int array[] = {1, 7, 19, 2, 0, 15};

    bubble_sort(array, sizeof(array));

    for(int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}