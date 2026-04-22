#include <stdio.h>

int main() {
    int N = 99;
    while(N != 0) {
        int x = 1, y = 0, z;
        scanf("%d", &N);
        for(int i = 1; i < N; i++) {
            z = x;
            x = z + y;
            y = z;
        }
        if(N != 0) {
            printf("%d\n", x);
        }
    }

    return 0;
}