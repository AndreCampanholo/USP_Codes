#include <stdio.h>

int mdc(int m, int n) {
    if(n == 0) {
        return m;
    } else {
        return mdc(n ,m % n);
    }
}

int main() {
    printf("%d\n", mdc(36, 18));

    return 0;
}