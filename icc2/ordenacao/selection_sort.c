#include <stdio.h>

void selection_sort(int v[], int n) {
    int aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int array[] = {1, 8, 19, 2, 0, 15};

    selection_sort(array, sizeof(array));

    for(int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}