#include <stdio.h>
#include <stdlib.h>

// void radix_sort(int v[], int n) {
//     int max = v[0];
//     for(int i = 1; i < n; i++) {
//         if(v[i] > max) {
//             max = v[i];
//         }
//     }



// }

// int main() {
//     int v[8] = {44,55,112,42,94,18,6,67};

//     radix_sort();

//     for(int i = 0; i < 8; i++) {
//         printf("%d ", v[i]);
//     }

//     return 0;
// }

void shellsort(int v[], int n, int incrementos[], int shells) {
int inc_atual, i, j, h, elem;
    for(inc_atual = 0; inc_atual < shells; inc_atual++) {
        h = incrementos[inc_atual];
        for(i = h; i < n; i++) {
            elem = v[i];
            for(j = i - h; j >= 0 && v[j] > elem; j -= h)
                v[j + h] = v[j];
            v[j + h] = elem;
        }
    }
}
